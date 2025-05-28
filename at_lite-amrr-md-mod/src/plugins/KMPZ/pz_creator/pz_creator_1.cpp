#include "pz_creator.h"

//#include "../dictionary/temporal_dictionary.h"

#include <QFile>
#include <QString>
#include <QTextCodec>
#include <QXmlStreamReader>

#include <iostream> 
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cctype>
#include <clocale>


namespace PZ {
    std::string get_path()   // получение пути
    {
        QDir dir;
        QString path = dir.currentPath();
        path.truncate(path.lastIndexOf('/'));
        path.truncate(path.lastIndexOf('/'));
        path.truncate(path.lastIndexOf('/'));
        return path.toStdString();
    }
}

PZCreator::PZCreator()
{    
    _outPath = QString((PZ::get_path() + "/resources/libTemp/output.xml").c_str());
    _bzPath = PZ::get_path() + "/resources/libTemp/bz.xml";
	_knowledgeField.add_object(_mainObjectName);
	auto object = _knowledgeField.get_object(_mainObjectName);
    //добавление атрибутов в Объект

    //попробовать без явного объявления типов
	std::string attributeName = "Атрибут" + std::to_string(_nAttributes++); //"Атрибут"
	_knowledgeField.add_attr(object, attributeName, "Диагноз"); //"Диагноз"
	_conclusionAttributeId = object->get_attr_id_by_name(attributeName);
	_knowledgeField.add_type("Диагноз");

    //создается только если отработал addTemporal
    attributeName = "Атрибут" + std::to_string(_nAttributes++);
	_knowledgeField.add_attr(object, attributeName, "Время"); //"Время"
	_eventAttributeId = object->get_attr_id_by_name(attributeName);
	_knowledgeField.add_type("Время"); //"Время"
}

void PZCreator::addQuestionAndAnswer(const std::string& question, const std::string& answer)
{
	auto attributeId = addAttributeToMainObject(question); //"Симптом"

	_atn.init(false);
    _atn.loadData(answer);
	_atn.execute();

    vector<string> tempLexemes;
    vector<string> tempObjects;
	tempLexemes.push_back(".");

    vector<temporal_entity_t*>* temporal_entites_for_lexems = addTemporal(&tempLexemes, &tempObjects);
    // теперь в temporal_entites_for_lexems по индексам совпадают темпоральные сущности с лексемами из tempLexemes

	_tempObjects[attributeId] = tempObjects;

    std::string symptom = getSymptom(tempLexemes, answer);


    /* ----------------------------------------
    САША ДОЛИДЗЕ
    ВОТ ТУТ В ПЕРЕМЕННОЙ tempLexemes ВЫДЕЛЕННЫЕ ТЕМПОРАЛЬНЫЕ ЛЕКСЕМЫ, КОТОРЫЕ МОЖНО АНАЛИЗИРОВАТЬ НА НЕ-ФАКТОРЫ
    А В ПЕРЕМЕННОЙ symptom - то, что было в предложении без темпоральных лексем

    После этого еще можно модифицировать класс QuestionAnswerStack, чтоб .push (смотри ниже) сохранял и выявленную недостоверность
    ------------------------------------------- */
    //хорошее место, чтобы включить анализ на недостоверность

    PZCreator::addNonFactor(&tempLexemes);

    tempLexemes.erase(tempLexemes.begin());

    _questionAnswerStack.push(question, answer, symptom, attributeId, &tempLexemes, temporal_entites_for_lexems); // в стэк надо добавить лексемы с их сущностями


	_knowledgeField.add_type(question); //ru("Симптом").toStdString()
	_knowledgeField.add_type_value(question, symptom);
}

void PZCreator::addAnswer(const std::string& answer)
{
	_atn.init(false);
	_atn.loadData(answer);
	_atn.execute();

    vector<string> tempLexemes;
    vector<string> tempObjects;
	tempLexemes.push_back(".");

    vector<temporal_entity_t*>* temporal_entites_for_lexems = addTemporal(&tempLexemes, &tempObjects);

	_tempObjects[_questionAnswerStack.top().attributeId] = tempObjects;

    std::string symptom = getSymptom(tempLexemes, answer);
    // std::cout << symptom << answer; // 1!!!!!!

    /* ----------------------------------------
    САША ДОЛИДЗЕ
    ВОТ ТУТ В ПЕРЕМЕННОЙ tempLexemes ВЫДЕЛЕННЫЕ ТЕМПОРАЛЬНЫЕ ЛЕКСЕМЫ, КОТОРЫЕ МОЖНО АНАЛИЗИРОВАТЬ НА НЕ-ФАКТОРЫ
    А В ПЕРЕМЕННОЙ symptom - то, что было в предложении без темпоральных лексем

    После этого еще можно модифицировать класс QuestionAnswerStack, чтоб .add (смотри ниже) сохранял и выявленную недостоверность
    ------------------------------------------- */
    tempLexemes.erase(tempLexemes.begin());

    _questionAnswerStack.add(answer, symptom, &tempLexemes, temporal_entites_for_lexems);

	_knowledgeField.add_type_value(_questionAnswerStack.top().attributeType, symptom); //"Симптом"
}

std::string PZCreator::getSymptom(const vector<string>& tempLexemes, const std::string& answer)
{
	std::string symptom = QString::fromStdString(answer).toLower().toStdString();

    //scratch tempLexemes from upcoming answer line
	for (int i = 0; i < tempLexemes.size(); i++) {
		int n = tempLexemes[i].length();
		for (int j = symptom.find(tempLexemes[i]);
            j != string::npos;
            j = symptom.find(tempLexemes[i]))
            symptom.erase(j, n+1);
	}
    symptom = QString::fromStdString(symptom).toStdString();
	return symptom;
}

void PZCreator::removeQuestion()
{
	std::cout << "PZ: " << _knowledgeField.to_string() << std::endl;

    _questionAnswerStack.pop();
}

const branch_t& PZCreator::getLastBranch() const
{
    branch_t* result = new branch_t;
    auto conditions = _questionAnswerStack.getConditions();
    for (auto condition: conditions){
        result->first.push_back(condition.attributeType + ": " + condition.attributeValues.back());
    }
    result->second = _last_branch_conclusions;
    return *result;
}

void PZCreator::removeBranchConclusions(){
    _last_branch_conclusions.clear();
}

std::string PZCreator::getBZ()
{
    return _knowledgeField.to_string();
}

std::string PZCreator::getBZXml()
{
	return _knowledgeField.to_xml();
}

void PZCreator::writeToFile()
{
	std::ofstream ofs;
    ofs.open(_bzPath, std::ofstream::out | std::ofstream::trunc);("=");
	ofs << getBZXml();
	ofs.close();
}

void PZCreator::addConclusion(const std::string& conclusion)
{
	action_string_t* action = new action_string_t;
	action->set_object_id(_knowledgeField.get_object_id_by_name(_mainObjectName));
	action->set_attribute_id(_conclusionAttributeId);
	action->set_op("=");
	action->set_value(conclusion);

	_knowledgeField.add_type_value("Диагноз", conclusion); //"Диагноз"

	auto rule = _knowledgeField.add_rule("Правило" + std::to_string(_nRules++)); //"Правило"
	_knowledgeField.add_condition(rule, getCurrentCondition());
	_knowledgeField.add_action(rule, action);
    _last_branch_conclusions.push_back(conclusion);
}

const QuestionAnswerStack::Condition& PZCreator::getLastQuestion() const
{
    return _questionAnswerStack.top(); // последний элемент стека
}

bool PZCreator::hasQuestions() const
{
    return !_questionAnswerStack.empty();  // пустой ли стек
}

complex_condition_t* PZCreator::getCurrentCondition()
{
	auto objectId = _knowledgeField.get_object_id_by_name(_mainObjectName);

	complex_condition_t* complexCondition = new complex_condition_t;
	complexCondition->set_op("&");

	for (const auto& question : _questionAnswerStack.getConditions())
	{

        // knowledge_field.h и knowledge_field.cpp писал рукоблуд мудила ссанина
        // поэтому пришлось создать класс условия-операции между объект.атрибут=значение И темпоральными сущностями (temporal_condition_operation_condition)
        // для того, чтоб можно было сделать выражение типа (Пациент.Температура="высокая") d Событие1

        condition_attr_value_const_t* condition = new condition_attr_value_const_t(objectId, question.attributeId, question.symptomValues.back());
		condition->set_op("=");
        vector<vector<temporal_entity_t*>*>* e_set = (vector<vector<temporal_entity_t*>*>*)question.entities_for_lexems;
        if (e_set->back()->size()) {
            complex_condition_t* innerCondition = new complex_condition_t;

            vector<temporal_entity_t*>* entities = e_set->back();
            innerCondition->set_op("&");
            for (temporal_entity_t* entity : *entities){

                temporal_condition_operation_condition* cond = new temporal_condition_operation_condition(condition, entity);

                if (isType<temporal_event_t, temporal_entity_t>(entity)){
                    cond->set_op("d"); // вот тут нужна операция между событиями
                } else {
                    temporal_interval_t* interval = (temporal_interval_t*)entity;

                    // тут у нас интервал
                    // можно проверить его точки на нулл и в зависимости от этого строить разные алленские действия

                    if (interval->get_begin_condition() == NULL){
                        cond->set_op("d");
                    }
                    cond->set_op("d");
                }
                innerCondition->add_condition(cond);
            }
            complexCondition->add_condition(innerCondition);
        } else{
            complexCondition->add_condition(condition);
        }
	}

	return complexCondition;
}


// trim from start (in place)
static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
        [](unsigned char ch){ return !std::isspace(ch);
    }));
}

// trim from end (in place)
static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(),
        [](unsigned char ch){ return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}

std::string BeatifyUpcoming(std::string str)
{
    //trim beginning and ending
    trim(str);
    std::string beautiful_string;
    //delete extra inner spaces
    unique_copy(str.begin(), str.end(), std::back_insert_iterator<string>(beautiful_string),
        [](char a,char b){ return isspace(a) && isspace(b);});
    return beautiful_string;
}

vector<temporal_entity_t*>* PZCreator::addTemporal(vector<string> *tempLexemes, vector<string> *tempObjects)
{
    vector<temporal_entity_t*>* entities_for_lexems = new vector<temporal_entity_t*>();
	QFile file(_outPath);
	if (file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QString xml = "";
		while (!file.atEnd()) {
			xml += file.readLine();
		}
		//setlocale(LC_ALL, "rus");

		QXmlStreamReader reader(xml);
		while (!reader.atEnd() && !reader.hasError()) {
			reader.readNext();
			if (reader.name() == "Point") {
				std::string tempObjectName = "Событие" + std::to_string(++_nEvents); //"Событие"

                temporal_entity_t* event = (temporal_event_t*)_knowledgeField.add_event(tempObjectName);
				tempObjects->push_back(tempObjectName);

				std::string strEvent = reader.attributes()[0].value().toString().toLower().toStdString();
                tempLexemes->push_back(strEvent);

				_knowledgeField.add_type_value("Время", strEvent); //"Время"

				condition_attr_value_const_t* condition = new condition_attr_value_const_t(mainObjectId(), _eventAttributeId, strEvent);
				condition->set_op("=");

				_knowledgeField.add_condition(event, condition);
                entities_for_lexems->push_back(event);

				reader.readNext();
			}
            else if (reader.name() == "Period")
            //TODO периодические правила
            {
				std::string tempObjectName = "Событие" + std::to_string(++_nEvents); //"Событие"

                temporal_entity_t* event = (temporal_event_t*)_knowledgeField.add_event(tempObjectName);
				tempObjects->push_back(tempObjectName);

				std::string strEvent = reader.attributes()[0].value().toString().toLower().toStdString();
				tempLexemes->push_back(strEvent);

				_knowledgeField.add_type_value("Время", strEvent); // "Время"

				condition_attr_value_const_t* condition = new condition_attr_value_const_t(mainObjectId(), _eventAttributeId, strEvent);
				condition->set_op("=");

				_knowledgeField.add_condition(event, condition);
                entities_for_lexems->push_back(event);
				reader.readNext();
			}
			else if (reader.name() == "Interval") {

				std::string tempObjectName = "Интервал" + std::to_string(++_nIntervals); //"Интервал"

                temporal_entity_t* interval = (temporal_interval_t*)_knowledgeField.add_interval(tempObjectName);
				tempObjects->push_back(tempObjectName);

				reader.readNext();
				reader.readNext();

				while (reader.name().toString() == "Start" || reader.name().toString() == "End"
					|| reader.name().toString() == "Duration") {

					if (reader.name() == "Start") {

						std::string strStart = reader.attributes()[0].value().toString().toLower().toStdString();
						tempLexemes->push_back(strStart);

						_knowledgeField.add_type_value("Время", strStart); //"Время"

						condition_attr_value_const_t* condition = new condition_attr_value_const_t(mainObjectId(), _eventAttributeId, strStart);
						condition->set_op("=");

						_knowledgeField.set_start_condition(interval, condition);

						reader.readNext();
					}
					else if (reader.name() == "End") {

						std::string strEnd = reader.attributes()[0].value().toString().toLower().toStdString();
						tempLexemes->push_back(strEnd);

						_knowledgeField.add_type_value("Время", strEnd); //"Время"

						condition_attr_value_const_t* condition = new condition_attr_value_const_t(mainObjectId(), _eventAttributeId, strEnd);
						condition->set_op("=");

						_knowledgeField.set_end_condition(interval, condition);

						reader.readNext();
					}
					else if (reader.name() == "Duration") {

						std::string strDuration = reader.attributes()[0].value().toString().toLower().toStdString();
						tempLexemes->push_back(strDuration);

						_knowledgeField.add_type_value("Время", strDuration); //"Время"

						condition_attr_value_const_t* condition = new condition_attr_value_const_t(mainObjectId(), _eventAttributeId, strDuration);
						condition->set_op("=");

						_knowledgeField.set_duration_condition(interval, condition);

						reader.readNext();
					}

					reader.readNext();
				}
                entities_for_lexems->push_back(interval);
            }
		}
	}

	file.close();
    return entities_for_lexems;
}

void PZCreator::addNonFactor(vector<string> *negfactorLexemes)
{
    QFile file(_outPath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QString xml = "";
        while (!file.atEnd()) {
            xml += file.readLine();
        }
        QXmlStreamReader reader(xml);
        while (!reader.atEnd() && !reader.hasError()) {
            reader.readNext();
            if (reader.name() == "Indistinct"){
                std::cout << "Обнаружена нечеткость";
//                _knowledgeField.add_type_value("Время", "");
                reader.readNext();
            }
            if (reader.name() == "Inaccurate"){
                std::cout << "Обнаружена неточность";
                reader.readNext();
            }
            // if (reader.name() == "Indefinite"){
            if (reader.name() == "Indefinite_00_10"){
                QString val = reader.attributes().value("val").toString();
                std::cout << "Обнаружена неопределенность: интервал 0 10\n лексема = " << val.toStdString();
                reader.readNext();
            }

            if (reader.name() == "Indefinite_05_20"){
                std::cout << "Обнаружена неопределенность: интервал 5 20\n";
                reader.readNext();
            }

            if (reader.name() == "Indefinite_25_40"){
                std::cout << "Обнаружена неопределенность: интервал 25 40\n";
                reader.readNext();
            }


            if (reader.name() == "Indefinite_40_60"){
                std::cout << "Обнаружена неопределенность: интервал 40 60\n";
                reader.readNext();
            }

            if (reader.name() == "Indefinite_50_75"){
                std::cout << "Обнаружена неопределенность: интервал 50 75\n";
                reader.readNext();
            }

            if (reader.name() == "Indefinite_80_90"){
                std::cout << "Обнаружена неопределенность: интервал 80 90\n";
                reader.readNext();
            }

            if (reader.name() == "Indefinite_90_100"){
                std::cout << "Обнаружена неопределенность: интервал 90 100\n";
                reader.readNext();
            }

        }
    }
}

int PZCreator::addAttributeToMainObject(const std::string& attrType)
{
	auto attributeName = "Атрибут" + std::to_string(_nAttributes++); //"Атрибут"
	auto object = _knowledgeField.get_object(_mainObjectName);
	_knowledgeField.add_attr(object, attributeName, attrType);
	auto attributeId = object->get_attr_id_by_name(attributeName);

	return attributeId;
}

int PZCreator::mainObjectId() const
{
	return _knowledgeField.get_object_id_by_name(_mainObjectName);
}

void PZCreator::addRule()
{
	if (_conclusions.empty())
		return;

	// TODO
    std::cout << "ПРАВИЛО:\nЕСЛИ_1\n";
	for (auto& condition : _questionAnswerStack.getConditions())
        std::cout << "    Пациент." << condition.attributeType << " = " << condition.attributeValues.back() <<"\n";

	std::cout << "ТО\n";
	for (auto& conclusion : _conclusions)
		std::cout << "    " << conclusion << "\n";

	std::cout << std::endl;


	_conclusions.clear();
}

//Для корректного отображения русского текста в Qt
QString PZCreator::ru(const char * text)
{
	return QTextCodec::codecForName("CP1251")->toUnicode(text);
}
