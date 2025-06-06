#include "pz_creator.h"

//#include "../dictionary/temporal_dictionary.h"

#include <QFile>
#include <QString>
#include <QTextCodec>
#include <QXmlStreamReader>
#include <QVector>

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cctype>
#include <clocale>


#include <QDomDocument>
#include <QDomElement>
#include <QTextStream>

#include <QCoreApplication>
#include <QRegularExpression>
#include <QDebug>

#include <cmath>  // Для std::floor

#include <QTextStream>



void appendToFile(string text) {
    std::ofstream file("/home/helga/Bobrovskaya/AT_Eule/at_lite-amrr-md-mod/resources/libTemp/MA.txt"); // Открытие файла в режиме добавления

    if (file.is_open()) {
        file << text << '\n'; // Запись текста + переход на новую строку
        file.close();
    } else {
        std::cerr << "Не удалось открыть файл!!!!!" << std::endl;
    }
}


void appendToFile_2(string text) {
    std::ofstream file("/home/helga/Bobrovskaya/AT_Eule/at_lite-amrr-md-mod/resources/libTemp/SSA.txt"); // Открытие файла в режиме добавления

    if (file.is_open()) {
        file << text << '\n'; // Запись текста + переход на новую строку
        file.close();
    } else {
        std::cerr << "Не удалось открыть файл!!!!!" << std::endl;
    }
}
void appendToFile_3(string text) {
    std::ofstream file("/home/helga/Bobrovskaya/AT_Eule/at_lite-amrr-md-mod/resources/libTemp/SI.txt"); // Открытие файла в режиме добавления

    if (file.is_open()) {
        file << text << '\n'; // Запись текста + переход на новую строку
        file.close();
    } else {
        std::cerr << "Не удалось открыть файл!!!!!" << std::endl;
    }
}



std::vector<indefinite> indef;

std::vector<inaccuracy> inacc;

std::vector<fuzzy> fuzzyL;

string MA_result = "";

string SSA_result = "";

string SI_result = "";



int bz_rewrite_to_xml() {
    QFile file("/home/helga/Bobrovskaya/AT_Eule/at_lite-amrr-md-mod/resources/libTemp/bz.xml");  // Имя файла XML
    if (!file.open(QIODevice::ReadOnly)) {
        std::cerr << "Ошибка: не удалось открыть файл" << std::endl;
        return 1;
    }

    QDomDocument doc;
    if (!doc.setContent(&file)) {
        std::cerr << "Ошибка: файл не содержит валидный XML" << std::endl;
        file.close();
        return 1;
    }
    file.close();  // Прочли, можно закрыть

    int flag = 0;
    int count_writes_vector_indef = indef.size();
    int count_writes_vector_inacc = inacc.size();
    std::cout << count_writes_vector_indef << "   " << count_writes_vector_inacc;
    if (indef.empty()){
        return 1;
    }


    // Ищем все теги <rule>
    QDomNodeList ruleList = doc.elementsByTagName("rule");
    for (int i = 0; i < ruleList.count(); ++i) {
        QDomElement ruleElem = ruleList.at(i).toElement();

        // Ищем тег <condition> внутри <rule>
        QDomNodeList conditionList = ruleElem.elementsByTagName("condition");
        for (int j = 0; j < conditionList.count(); ++j) {
            QDomElement conditionElem = conditionList.at(j).toElement();

            // Ищем <eq> внутри <condition>
            QDomNodeList eqList = conditionElem.elementsByTagName("eq");
            for (int k = 0; k < eqList.count(); ++k) {
                QDomElement eqElem = eqList.at(k).toElement();

                // Найдём <value> внутри <eq>
                QDomNodeList valueList = eqElem.elementsByTagName("value");
                for (int m = 0; m < valueList.count(); ++m) {
                    QDomElement valueElem = valueList.at(m).toElement();

                    QString valueText = valueElem.text();  // <-- Вот здесь значение из <value>

                    string text_from_value = valueText.toStdString();

                    // Пример: печатаем его в консоль
                    std::cout << "\nЗначение <value>: " << valueText.toStdString() << std::endl;

                    int flag= 0;
                    for (int nn = 0; nn < count_writes_vector_indef; nn++){
                        //for (int mm = 0; nn < count_writes_vector_inacc; nn++){
                            if (indef[nn].set_symptom == text_from_value)
                            {   //and (inacc[nn].set_symptom == text_from_value)){
                                 QDomElement withElem = doc.createElement("with");

                                 withElem.setAttribute("belief", indef[nn].min_val );
                                 withElem.setAttribute("probability", indef[nn].max_val);
                                 withElem.setAttribute("accuracy", indef[nn].error_rate);
                                 //withElem.setAttribute("accuracy", "0");
                                 eqElem.insertAfter(withElem, valueElem);
                                 break;
                                 flag = 1;
                            }
                            /*if (flag == 1){
                                break;
                            }
                        }*/
                    }
                    /*

                    for (int mm = 0; mm < count_writes_vector_inacc; mm++){
                        //for (int mm = 0; nn < count_writes_vector_indef; nn++){
                            if (inacc[mm].set_symptom == text_from_value){ // and inacc[mm].set_symptom == text_from_value){
                                 QDomElement withElem = doc.createElement("with");

                                 //withElem.setAttribute("belief", indef[nn].min_val );
                                 //withElem.setAttribute("probability", indef[nn].max_val);
                                 withElem.setAttribute("accuracy", inacc[mm].error_rate);
                                 //withElem.setAttribute("accuracy", "0");
                                 eqElem.insertAfter(withElem, valueElem);
                                 break;
                            }
                    }

                    */


                    // Вставляем <with> сразу после <value>
                    // QDomElement withElem = doc.createElement("with");

                    /*if (flag > count_writes_vector){
                        std::cout << "ERROR Вектор закончился!!!!!!!!!!!!!!!!!!!!1";
                        return 1;

                    }*/

                    /*withElem.setAttribute("belief", indef[flag].min_val );
                    withElem.setAttribute("probability", indef[flag].max_val);
                    withElem.setAttribute("accuracy", "0");
                    flag ++;*/


                    // Вставка в DOM — после <value>
                    //eqElem.insertAfter(withElem, valueElem);
                }
            }
        }
    }
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        std::cerr << "Ошибка: не удалось открыть файл для записи" << std::endl;
        return 1;
    }
    QTextStream out(&file);
    out << doc.toString();
    file.close();

    return 0;
}


int bz_rewrite_to_xml_1() {
    QFile file("/home/helga/Bobrovskaya/AT_Eule/at_lite-amrr-md-mod/resources/libTemp/bz.xml");
    if (!file.open(QIODevice::ReadOnly)) {
        std::cerr << "Ошибка: не удалось открыть файл" << std::endl;
        return 1;
    }

    QDomDocument doc;
    if (!doc.setContent(&file)) {
        std::cerr << "Ошибка: файл не содержит валидный XML" << std::endl;
        file.close();
        return 1;
    }
    file.close();

    if (indef.empty() || inacc.empty()) {
        std::cerr << "Векторы indef или inacc пусты" << std::endl;
        return 1;
    }

    QDomNodeList ruleList = doc.elementsByTagName("rule");
    for (int i = 0; i < ruleList.count(); ++i) {
        QDomElement ruleElem = ruleList.at(i).toElement();
        QDomNodeList conditionList = ruleElem.elementsByTagName("condition");

        for (int j = 0; j < conditionList.count(); ++j) {
            QDomElement conditionElem = conditionList.at(j).toElement();
            QDomNodeList eqList = conditionElem.elementsByTagName("eq");

            for (int k = 0; k < eqList.count(); ++k) {
                QDomElement eqElem = eqList.at(k).toElement();
                QDomNodeList valueList = eqElem.elementsByTagName("value");

                for (int m = 0; m < valueList.count(); ++m) {
                    QDomElement valueElem = valueList.at(m).toElement();
                    QString valueText = valueElem.text();
                    std::string text_from_value = valueText.toStdString();

                    // Ищем соответствующие элементы в обоих векторах
                    auto indef_it = std::find_if(indef.begin(), indef.end(), [&](const indefinite& el) {
                        return el.set_symptom == text_from_value;
                    });

                    auto inacc_it = std::find_if(inacc.begin(), inacc.end(), [&](const inaccuracy& el) {
                        return el.set_symptom == text_from_value;
                    });

                    if (indef_it != indef.end() && inacc_it != inacc.end()) {
                        QDomElement withElem = doc.createElement("with");

                        withElem.setAttribute("belief", indef_it->min_val);
                        withElem.setAttribute("probability", indef_it->max_val);
                        withElem.setAttribute("accuracy", inacc_it->error_rate);

                        eqElem.insertAfter(withElem, valueElem);
                    }
                }
            }
        }
    }

    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        std::cerr << "Ошибка: не удалось открыть файл для записи" << std::endl;
        return 1;
    }

    QTextStream out(&file);
    doc.save(out, 4);
    file.close();

    std::cout << "Тег <with> успешно добавлен с belief, probability и accuracy" << std::endl;
    return 0;
}

string bz_rewrite_in_knowledge(string value)
{
    int count_writes_vector_indef = indef.size();

    for (int nn = 0; nn < count_writes_vector_indef; nn++){
            if (indef[nn].set_symptom == value)
            {
                string a = "";
                a += " УВЕРЕННОСТЬ [";
                a += std::to_string(indef[nn].min_val) + ";";
                a += std::to_string(indef[nn].max_val) + "] " ;
                a += "ТОЧНОСТЬ " + std::to_string(indef[nn].error_rate);
                return a;
            }
    }
}

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
    _FuzzyPath = QString((PZ::get_path() + "/resources/libTemp/fuzzy.xml").c_str());
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

    _atn.init(false);
    _atn.loadData(answer);
    _atn.execute();

    vector<string> tempLexemes;
    vector<string> tempObjects;
    tempLexemes.push_back(".");

    std::string symptom = getSymptom(tempLexemes, answer);

    PZCreator::addNonFactor_3(&tempLexemes, symptom, answer);

    int attributeId;
    if (fuzzyL.back().fuzzyLex.term !="") {
         attributeId = addAttributeToMainObject(fuzzyL.back().fuzzyLex.lvName.toStdString()); //"Симптом"
    } else {
         attributeId = addAttributeToMainObject(question); //"Симптом"
    }

    vector<temporal_entity_t*>* temporal_entites_for_lexems = addTemporal(&tempLexemes, &tempObjects);
    // теперь в temporal_entites_for_lexems по индексам совпадают темпоральные сущности с лексемами из tempLexemes

    _tempObjects[attributeId] = tempObjects;


    //std::cout << answer << "ANSWERANSWERANSWERANSWERANSWERANSWER" ;

    //std::cout << symptom << "СИМПТОМСИМПТОМСИМПТОМСИМПТОМСИМПТОМСИМПТОМСИМПТОМСИМПТОМСИМПТОМ" ;

    //std::cout << tempLexemes.back() << "ТЕМПОРАЛЬНАЯ ЛЕКСЕМА ТЕМПОРАЛЬНАЯ ЛЕКСЕМА ТЕМПОРАЛЬНАЯ ЛЕКСЕМА ";

    //std::cout << tempObjects.back() << "ТЕМПОРАЛЬНЫЙ ОБЪЕКТ ТЕМПОРАЛЬНЫЙ ОБЪЕКТ ТЕМПОРАЛЬНЫЙ ОБЪЕКТ ";

    /* ----------------------------------------
    САША ДОЛИДЗЕ
    ВОТ ТУТ В ПЕРЕМЕННОЙ tempLexemes ВЫДЕЛЕННЫЕ ТЕМПОРАЛЬНЫЕ ЛЕКСЕМЫ, КОТОРЫЕ МОЖНО АНАЛИЗИРОВАТЬ НА НЕ-ФАКТОРЫ
    А В ПЕРЕМЕННОЙ symptom - то, что было в предложении без темпоральных лексем

    После этого еще можно модифицировать класс QuestionAnswerStack, чтоб .push (смотри ниже) сохранял и выявленную недостоверность
    ------------------------------------------- */
    //хорошее место, чтобы включить анализ на недостоверность

    PZCreator::addNonFactor_1(&tempLexemes, symptom, answer);
    PZCreator::addNonFactor_2(&tempLexemes, symptom, answer);
    PZCreator::calculateErrorRates();
    PZCreator::rewrite_indef();

    //MA_result += "Ответ Пациента: " + answer + "\n";
    //MA_result += "Темпоральные лексемы: " + tempLexemes.back() + "\n";
    //MA_result += "Лексемы для НЕ-факторов: " + indef.back().indefinite_lemma + " " + inacc.back().term + " " + inacc.back().units_of_measurement + "\n";
    //MA_result = std::to_string(MA_result);
    appendToFile(MA_result);

    std::cout << std::endl << std::endl << MA_result << std::endl  << std::endl ;

    MA_in_txt(tempLexemes, answer);

    // ////////////////////////////////////////////////////////////////////////

    //SSA_result+= "НЕ-фактор неопределенность: " + indef.back().indefinite_lemma + "\n";

    //SSA_result+= "НЕ-фактор неточность: " + inacc.back().term + " " + /*(inacc.back().number_1.toString)?*/ inacc.back().units_of_measurement + "\n";

    //appendToFile_2(SSA_result);

    SSA_in_txt(tempLexemes, tempObjects, answer);


    tempLexemes.erase(tempLexemes.begin());

    _questionAnswerStack.push(question, answer, symptom, attributeId, &tempLexemes, temporal_entites_for_lexems); // в стэк надо добавить лексемы с их сущностями

    if (fuzzyL.back().fuzzyLex.term !="") {
        _knowledgeField.add_type(fuzzyL.back()); //ru("Симптом").toStdString()

        _knowledgeField.add_type_value(fuzzyL.back());
    } else {
        _knowledgeField.add_type(question); //ru("Симптом").toStdString()

        _knowledgeField.add_type_value(question, symptom);
    }


    std::cout << std::endl << std::endl << _knowledgeField.to_xml() << std::endl  << std::endl;
}

void PZCreator::addAnswer(const std::string& answer)
{
    _atn.init(false);
    _atn.loadData(answer);
    _atn.execute();



    vector<string> tempLexemes;
    vector<string> tempObjects;
    tempLexemes.push_back(".");
     std::string symptom = getSymptom(tempLexemes, answer);

    PZCreator::addNonFactor_3(&tempLexemes, symptom, answer);

    if (fuzzyL.back().fuzzyLex.term !="") {
        auto attributeId = addAttributeToMainObject(fuzzyL.back().fuzzyLex.lvName.toStdString()); //"Симптом"
    }

    vector<temporal_entity_t*>* temporal_entites_for_lexems = addTemporal(&tempLexemes, &tempObjects);

    _tempObjects[_questionAnswerStack.top().attributeId] = tempObjects;



    //std::cout << symptom << answer << "СИМПТОМ ОТВЕТ СИМПТОМ ОТВЕТ"; // 1!!!!!!

    /* ----------------------------------------
    САША ДОЛИДЗЕ
    ВОТ ТУТ В ПЕРЕМЕННОЙ tempLexemes ВЫДЕЛЕННЫЕ ТЕМПОРАЛЬНЫЕ ЛЕКСЕМЫ, КОТОРЫЕ МОЖНО АНАЛИЗИРОВАТЬ НА НЕ-ФАКТОРЫ
    А В ПЕРЕМЕННОЙ symptom - то, что было в предложении без темпоральных лексем

    После этого еще можно модифицировать класс QuestionAnswerStack, чтоб .add (смотри ниже) сохранял и выявленную недостоверность
    ------------------------------------------- */

    PZCreator::addNonFactor_1(&tempLexemes, symptom, answer);
    PZCreator::addNonFactor_2(&tempLexemes, symptom, answer);
    PZCreator::calculateErrorRates();
    PZCreator::rewrite_indef();

    /*
    MA_result += "Ответ Пациента: " + answer + "\n";
    MA_result += "Темпоральные лексемы: " + tempLexemes.back() + "\n";
    MA_result += "Лексемы для НЕ-факторов: " + indef.back().indefinite_lemma + " " + inacc.back().term + " " + inacc.back().units_of_measurement + "\n";
    //MA_result = std::to_string(MA_result);
    appendToFile(MA_result);

    std::cout << std::endl << std::endl << MA_result << std::endl  << std::endl ;
*/
    MA_in_txt(tempLexemes, answer);

    SSA_in_txt(tempLexemes, tempObjects, answer);


    tempLexemes.erase(tempLexemes.begin());

    if (fuzzyL.back().fuzzyLex.term !="") {
        _knowledgeField.add_type(fuzzyL.back()); //ru("Симптом").toStdString()

        _knowledgeField.add_type_value(fuzzyL.back());
    } else {
        _questionAnswerStack.add(answer, symptom, &tempLexemes, temporal_entites_for_lexems);

        _knowledgeField.add_type_value(_questionAnswerStack.top().attributeType, symptom); //"Симптом"
    }
    std::cout << std::endl << std::endl << _knowledgeField.to_xml() << std::endl  << std::endl;
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
    std::cout << "fgsfgggggggggggggggggggggggggggggggggggggg" << std::endl;
     std::cout << getBZXml() << std::endl;
     std::cout << "fgsfgggggggggggggggggggggggggggggggggggggg" << std::endl;
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
            if (reader.name() == "FuzzyLexeme"){
                std::cout << "Обнаружена нечеткость";
//                _knowledgeField.add_type_value("Время", "");
                reader.readNext();
            }
            if (reader.name() == "FuzzyInaccurateLexeme"){
                std::cout << "Обнаружена неточность";
                reader.readNext();
            }
            // if (reader.name() == "Indefinite"){ рррр
            if (reader.name() == "FuzzyIndefiniteLexeme")
            {
                reader.readNext();
                if (reader.name() == "Indefinite_00_10"){
                    QString val = reader.attributes().value("val").toString();
                    indefinite item1 = {val.toStdString(), 0, 10};
                    std::cout << "Обнаружена неопределенность: интервал 0 10\n лексема = " << val.toStdString() << "\n";
                    std::cout << "лексема = "<< item1.indefinite_lemma << "интервал: ["<< item1.min_val << "," << item1.max_val << "]\n";
                    indef.push_back(item1);
                    std::cout << "лексема = "<< indef.back().indefinite_lemma << "интервал: ["<< indef.back().min_val << "," << indef.back().max_val << "]\n";
                    reader.readNext();
                }

                 if (reader.name() == "Indefinite_05_20"){
                    std::cout << "Обнаружена неопределенность: интервал 5 20\n";

                    QString val = reader.attributes().value("val").toString();
                    indefinite item1 = {val.toStdString(), 5, 20};
                    //std::cout << "Обнаружена неопределенность: интервал 5 20\n лексема = " << val.toStdString() << "\n";
                    std::cout << "лексема = "<< item1.indefinite_lemma << "интервал: ["<< item1.min_val << "," << item1.max_val << "]\n";
                    indef.push_back(item1);
                    std::cout << "лексема = "<< indef.back().indefinite_lemma << "интервал: ["<< indef.back().min_val << "," << indef.back().max_val << "]\n";
                    reader.readNext();
                }

                 if (reader.name() == "Indefinite_25_40"){
                    std::cout << "Обнаружена неопределенность: интервал 25 40\n";

                    QString val = reader.attributes().value("val").toString();
                    indefinite item1 = {val.toStdString(), 25, 40};
                    std::cout << "лексема = "<< item1.indefinite_lemma << "интервал: ["<< item1.min_val << "," << item1.max_val << "]\n";
                    indef.push_back(item1);
                    std::cout << "лексема = "<< indef.back().indefinite_lemma << "интервал: ["<< indef.back().min_val << "," << indef.back().max_val << "]\n";
                    //std::cout << "лексема = "<< indef[2].indefinite_lemma << "интервал: ["<< indef[2].min_val << "," << indef[2].max_val << "]\n";
                    reader.readNext();
                }


                 if (reader.name() == "Indefinite_40_60"){
                    std::cout << "Обнаружена неопределенность: интервал 40 60\n";

                    QString val = reader.attributes().value("val").toString();
                    indefinite item1 = {val.toStdString(), 40, 60};
                    indef.push_back(item1);
                    std::cout << "лексема = "<< item1.indefinite_lemma << "интервал: ["<< item1.min_val << "," << item1.max_val << "]\n";
                    indef.push_back(item1);
                    std::cout << "лексема = "<< indef.back().indefinite_lemma << "интервал: ["<< indef.back().min_val << "," << indef.back().max_val << "]\n";
                    reader.readNext();
                }

                 if (reader.name() == "Indefinite_50_75"){
                    std::cout << "Обнаружена неопределенность: интервал 50 75\n";

                    QString val = reader.attributes().value("val").toString();
                    indefinite item1 = {val.toStdString(), 50, 75};
                    indef.push_back(item1);
                    std::cout << "лексема = "<< indef.back().indefinite_lemma << "интервал: ["<< indef.back().min_val << "," << indef.back().max_val << "]\n";
                    reader.readNext();
                }

                 if (reader.name() == "Indefinite_80_90"){
                    std::cout << "Обнаружена неопределенность: интервал 80 90\n";

                    QString val = reader.attributes().value("val").toString();
                    indefinite item1 = {val.toStdString(), 80, 90};
                    indef.push_back(item1);
                    std::cout << "лексема = "<< indef.back().indefinite_lemma << "интервал: ["<< indef.back().min_val << "," << indef.back().max_val << "]\n";
                    reader.readNext();
                }

                 if (reader.name() == "Indefinite_90_100"){
                    std::cout << "Обнаружена неопределенность: интервал 90 100\n";

                    QString val = reader.attributes().value("val").toString();
                    indefinite item1 = {val.toStdString(), 90, 100};
                    indef.push_back(item1);
                    std::cout << "лексема = "<< indef.back().indefinite_lemma << "интервал: ["<< indef.back().min_val << "," << indef.back().max_val << "]\n";
                    reader.readNext();
                }
            }
            else {
                std::cout << "Неопределенность не обнаружена: интервал 50 100\n";

                indefinite item1 = {"", 50, 100};
                indef.push_back(item1);
                std::cout << "лексема = "<< indef.back().indefinite_lemma << "интервал: ["<< indef.back().min_val << "," << indef.back().max_val << "]\n";
            }

        }
    }
}

// Загружает типовые ФП (typical-mf) из файла
QMap<QString, QVector<Part>> loadTypicalMFs(const QDomDocument &doc) {
    QMap<QString, QVector<Part>> typicalMFs;
    QDomNodeList typicalMFList = doc.elementsByTagName("typical-mf");

    for (int i = 0; i < typicalMFList.count(); ++i) {
        QDomElement mfElem = typicalMFList.at(i).toElement();
        QString id = mfElem.attribute("id");
        QVector<Part> points;

        QDomNodeList pointList = mfElem.elementsByTagName("point");
        for (int j = 0; j < pointList.count(); ++j) {
            QDomElement pointElem = pointList.at(j).toElement();
            Part p;
            p.x = pointElem.attribute("x").replace(",", ".").toDouble();
            p.y = pointElem.attribute("y").replace(",", ".").toDouble();
            points.append(p);
        }

        typicalMFs[id] = points;
    }

    return typicalMFs;
}

// Загружает все LV из файла
QMap<QString, LVData> loadAllLVs(const QDomDocument &doc, const QMap<QString, QVector<Part>> &typicalMFs) {
    QMap<QString, LVData> lvMap;
    QDomNodeList lvList = doc.elementsByTagName("lv");

    for (int i = 0; i < lvList.count(); ++i) {
        QDomElement lvElem = lvList.at(i).toElement();
        LVData lvData;
        lvData.name = lvElem.attribute("name").toLower(); // Для удобства сравнения
        lvData.minValue = lvElem.attribute("min-value").toDouble();
        lvData.maxValue = lvElem.attribute("max-value").toDouble();
        lvData.measureItem = lvElem.attribute("measure-item");

        // Также можно добавить обработку alias, если нужно

        lvMap[lvData.name] = lvData;
    }

    return lvMap;
}

/*QVector<FuzzyLexemeResult> parseFuzzyLexemes(const QDomDocument &doc,
                                            const QMap<QString, LVData> &lvMap,
                                            const QMap<QString, QVector<Part>> &typicalMFs) {
    QVector<FuzzyLexemeResult> results;
    QDomNodeList fuzzyList = doc.elementsByTagName("FuzzyLexeme");

    for (int i = 0; i < fuzzyList.count(); ++i) {
        QDomElement fuzzyElem = fuzzyList.at(i).toElement();
        QDomNode child = fuzzyElem.firstChild();

        while (!child.isNull()) {
            QDomElement childElem = child.toElement();
            QString tagName = childElem.tagName();

            if (tagName.startsWith("Fuzzy")) {
                QString val = childElem.attribute("val");
                QStringList valParts = val.split(' ', QString::SkipEmptyParts);

                if (valParts.size() < 2) {
                    qWarning() << "Skipping invalid val:" << val;
                    continue;
                }

                FuzzyLexemeResult result;
                result.term = valParts[0].toLower(); // Первое слово (терм)
                result.lvName = valParts.mid(1).join(" ").toLower(); // Остальные слова (LV)

                // Извлекаем тип из названия тега (например, "FuzzyT3" -> "type3")
                result.type = "type" + tagName.mid(5).remove("T");

                // Ищем LV во втором файле
                if (lvMap.contains(result.lvName)) {
                    result.lvData = lvMap[result.lvName];
                    // Добавляем точки ФП
                    if (typicalMFs.contains(result.type)) {
                        result.lvData.points = typicalMFs[result.type];
                    } else {
                        qWarning() << "Typical MF not found:" << result.type;
                    }
                    results.append(result);
                } else {
                    qWarning() << "LV not found:" << result.lvName;
                }
            }

            child = child.nextSibling();
        }
    }

    return results;
}*/


void PZCreator::addNonFactor_1(vector<string> *negfactorLexemes, std::string symptom, std::string answer)
{
    QFile file(_outPath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        std::cerr << "Не удалось открыть файл\n";
        return;
    }

    QString xmlContent = file.readAll();
    file.close();

    QDomDocument doc;
    if (!doc.setContent(xmlContent)) {
        std::cerr << "Ошибка разбора XML\n";
        return;
    }

    QDomNodeList fuzzyIndefiniteList = doc.elementsByTagName("FuzzyIndefiniteLexeme");

    if (fuzzyIndefiniteList.isEmpty()) {
        std::cout << "Неопределенность не обнаружена: интервал 50 100\n";
        indefinite defaultItem = {"", 50, 100, symptom, answer};
        indef.push_back(defaultItem);
        std::cout << "лексема = " << defaultItem.indefinite_lemma
                  << " интервал: [" << defaultItem.min_val << "," << defaultItem.max_val << "]\n"
                  << "симптом = " << defaultItem.set_symptom << "весь отве пациекнта" << defaultItem.set_answer << endl;
        return;
    }

    for (int i = 0; i < fuzzyIndefiniteList.count(); ++i) {
        QDomElement fuzzyElem = fuzzyIndefiniteList.at(i).toElement();

        QDomNode child = fuzzyElem.firstChild();
        while (!child.isNull()) {
            QDomElement childElem = child.toElement();
            QString tagName = childElem.tagName();

            if (tagName.startsWith("Indefinite_")) {
                QString val = childElem.attribute("val");
                QStringList range = tagName.mid(QString("Indefinite_").length()).split("_");

                if (range.size() == 2) {
                    int minVal = range[0].toInt();
                    int maxVal = range[1].toInt();

                    indefinite item = {val.toLower().toStdString(), minVal, maxVal, symptom, answer};
                    indef.push_back(item);

                    std::cout << "Обнаружена неопределенность: интервал "
                              << minVal << " " << maxVal << "\n";
                    std::cout << "лексема = " << item.indefinite_lemma
                              << " интервал: [" << item.min_val << "," << item.max_val << "]\n"
                              << "симптом = " << item.set_symptom << "весь ответ пациента" << item.set_answer << endl;
                }
            }
            child = child.nextSibling();
        }
    }
}

void PZCreator::addNonFactor_2(vector<string> *negfactorLexemes, std::string symptom, std::string answer)
{
    QFile file(_outPath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        std::cerr << "Не удалось открыть файл\n";
        return;
    }

    QString xmlContent = file.readAll();
    file.close();

    QDomDocument doc;
    if (!doc.setContent(xmlContent)) {
        std::cerr << "Ошибка разбора XML\n";
        return;
    }

    QDomNodeList fuzzyInaccurateList = doc.elementsByTagName("FuzzyInaccurateLexeme");

    if (fuzzyInaccurateList.isEmpty()) {
        // Добавляем пустую запись с только заполненными симптомом, ответом и error_rate
        inaccuracy emptyItem;
        emptyItem.term = "";
        emptyItem.number_1 = -1.0;
        emptyItem.number_2 = -1.0;
        emptyItem.units_of_measurement = "";
        emptyItem.set_symptom = symptom;
        emptyItem.set_answer = answer;
        emptyItem.error_rate = -1;
        emptyItem.category = "";

        inacc.push_back(emptyItem);

        std::cout << "\nНеточность не найдена. Добавлена пустая запись.\n";
        std::cout << "Термин = " << emptyItem.term << "\nЧисло 1 = " << emptyItem.number_1 << "\nЧисло 2 = " << emptyItem.number_2 ;
        std::cout << "\n единицы измерения = " << emptyItem.units_of_measurement << "категория измерения" << emptyItem.category;

        return;
    }

    for (int i = 0; i < fuzzyInaccurateList.count(); ++i) {
        QDomElement elem = fuzzyInaccurateList.at(i).toElement();

        QString term;
        QString category;
        float number1 = -1.0;
        float number2 = -1.0;
        QString units;

        QDomNode child = elem.firstChild();
        while (!child.isNull()) {
            QDomElement childElem = child.toElement();
            QString tag = childElem.tagName();
            QString val = childElem.attribute("val");

            if (tag.endsWith("_lemma")) {
                term = val;
                category = tag.left(tag.length() - QString("_lemma").length());
            }
            else if (tag == "number1") {
                number1 = val.toFloat();
            }
            else if (tag == "number2") {
                number2 = val.toFloat();
            }
            else if (tag.endsWith("_unit")) {
                units = val;
            }

            child = child.nextSibling();
        }

        inaccuracy item;
        item.term = term.toLower().toStdString();
        item.number_1 = number1;
        item.number_2 = number2;
        item.units_of_measurement = units.toLower().toStdString();
        item.set_symptom = symptom;
        item.set_answer = answer;
        item.error_rate = -1;
        item.category = category.toStdString();

        inacc.push_back(item);

        std::cout << "\n\nДобавлена запись: " << item.term
                  << "\n number1 = " << item.number_1
                  << "\n number2 = " << item.number_2
                  << "\n unit = " << item.units_of_measurement
                  << "\n category = " << item.category << std::endl;
    }
}

QString calculateFP(double minVal, double maxVal, const QVector<Part>& points) {
    QString result = "{ ";
    int num = 5;
    for (int i = 0; i <= 10; ++i) {
        double x = minVal + i * (maxVal - minVal) / 10.0;
        double xNorm = (x - minVal) / (maxVal - minVal);

        double y = 0.0;
        for (int j = 0; j < points.size() - 1; ++j) {
            if (xNorm >= points[j].x && xNorm <= points[j+1].x) {
                const Part& p1 = points[j];
                const Part& p2 = points[j+1];
                y = p1.y + (xNorm - p1.x) * (p2.y - p1.y) / (p2.x - p1.x);
                break;
            }
        }

        result += QString("%1|%2").arg(x, 0, 'f', 1).arg(y, 0, 'f', 2);
        result += "; ";
    }
    result += "}";
    return result;
}

// Основная функция парсинга
vector<FuzzyLexemeResult> parseData(const QDomDocument& fuzzyDoc, const QDomDocument& lvDoc) {
    vector<FuzzyLexemeResult> results;
    auto typicalMFs = loadTypicalMFs(lvDoc);

    // Собираем все LV с термами
    QMap<QString, vector<LVData>> lvMap;
    QDomNodeList lvNodes = lvDoc.elementsByTagName("lv");

    for (int i = 0; i < lvNodes.count(); ++i) {
        QDomElement lvElem = lvNodes.at(i).toElement();
        QString lvName = lvElem.attribute("name").toLower();
        double minVal = lvElem.attribute("min-value").toDouble();
        double maxVal = lvElem.attribute("max-value").toDouble();
        QString measure = lvElem.attribute("measure-item");

        QDomNodeList mfNodes = lvElem.elementsByTagName("mf");
        for (int j = 0; j < mfNodes.count(); ++j) {
            QDomElement mfElem = mfNodes.at(j).toElement();
            LVData term;
            term.name = mfElem.attribute("name");
            term.type = mfElem.attribute("typical");
            term.minValue = minVal;
            term.maxValue = maxVal;
            term.measureItem = measure;
            term.points = typicalMFs.value(term.type);
            term.resultFP = calculateFP(minVal, maxVal, term.points);

            lvMap[lvName].push_back(term);
        }
    }

    // Парсим FuzzyLexeme
    QDomNodeList fuzzyNodes = fuzzyDoc.elementsByTagName("FuzzyLexeme");
    for (int i = 0; i < fuzzyNodes.count(); ++i) {
        QDomElement fuzzyElem = fuzzyNodes.at(i).toElement();
        QDomNode child = fuzzyElem.firstChild();

        while (!child.isNull()) {
            QDomElement childElem = child.toElement();
            if (childElem.tagName().startsWith("Fuzzy")) {
                QString val = childElem.attribute("val");
                QStringList parts = val.split(' ', QString::SkipEmptyParts);
                if (parts.size() < 2) continue;

                FuzzyLexemeResult res;
                res.term = parts[0].toLower();
                res.lvName = parts.mid(1).join(" ").toLower();
                res.type = "type" + childElem.tagName().mid(5).remove("T");
                res.currentlvData = -1;

                if (lvMap.contains(res.lvName)) {
                    res.lvData = lvMap[res.lvName];
                    // Находим индекс текущего терма
                    for (size_t j = 0; j < res.lvData.size(); ++j) {
                        if (res.lvData[j].type.toLower() == res.type) {
                            res.lvData[j].name = res.term;
                            res.currentlvData = static_cast<int>(j);
                            break;
                        }
                    }
                    results.push_back(res);
                }
            }
            child = child.nextSibling();
        }
    }

    return results;
}

void PZCreator::addNonFactor_3(vector<string> *negfactorLexemes, std::string symptom, std::string answer)
{
    QFile file(_outPath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        std::cerr << "Не удалось открыть файл\n";
        return;
    }
    QString xmlContent = file.readAll();
    file.close();
    QDomDocument doc;
    if (!doc.setContent(xmlContent)) {
        std::cerr << "Ошибка разбора XML\n";
        return;
    }


    QDomNodeList fuzzyList = doc.elementsByTagName("FuzzyLexeme");

    if (fuzzyList.isEmpty()) {
        std::cout << "Нечеткость не обнаружена\n";
        class fuzzy emptyItem;
        emptyItem.fuzzyLex.term = "";
        emptyItem.set_answer = answer;
        emptyItem.set_symptom = symptom;

        fuzzyL.push_back(emptyItem);

        std::cout << "\nНечеткость не найдена. Добавлена пустая запись.\n";

        //std::cout << "\n единицы измерения = " << emptyItem.units_of_measurement << "категория измерения" << emptyItem.category;

        return;
    }

    QFile fuzzyFile(_FuzzyPath);
    if (!fuzzyFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        std::cerr << "Не удалось открыть файл\n";
        return;
    }
    QString xmlContentFuzzy = fuzzyFile.readAll();
    fuzzyFile.close();

    QDomDocument docFuzzy;
    if (!docFuzzy.setContent(xmlContentFuzzy)) {
        std::cerr << "Ошибка разбора XML\n";
        return;
    }

    auto typicalMFs = loadTypicalMFs(docFuzzy);
    auto lvMap = loadAllLVs(docFuzzy, typicalMFs);

    auto results = parseData(doc, docFuzzy);

    for (const auto& result : results) {
        class fuzzy item;
        item.fuzzyLex = result;
        item.set_symptom = symptom;
        item.set_answer = answer;
        fuzzyL.push_back(item);

     }
}

void PZCreator::calculateErrorRates() {
    for (auto& item : inacc) {
        std::string cat = item.category;
        float val1 = item.number_1;
        float val2 = item.number_2;

        float error_percent = -1.0;

        // ===== 1. Случай: два числа и не давление =====
        if (val1 != -1.0 && val2 != -1.0 && cat != "pressure") {
            float avg = (val1 + val2) / 2.0;
            if (avg != 0.0) {
                error_percent = std::abs((val2 - val1) / avg) * 100.0;
            }
        }

        // ===== 2. Один показатель, не давление =====
        else if (val1 != -1.0 && val2 == -1.0 && cat != "pressure") {
            float abs_error = 0.0;

            if (cat == "rost") abs_error = 0.5;
            else if (cat == "weight") abs_error = 0.2;
            else if (cat == "saturation") abs_error = 2.0;
            else if (cat == "temperature") abs_error = 0.1;
            else if (cat == "pulse") abs_error = 2.0;
            else if (cat == "sugar") abs_error = 0.5;

            if (abs_error > 0.0 && val1 != 0.0) {
                error_percent = (abs_error / val1) * 100.0;
            }
        }

        // ===== 3. Давление =====
        else if (cat == "pressure" && val1 != -1.0 && val2 != -1.0) {
            float abs_error = 3.0;
            if (val1 != 0.0) {
                error_percent = (abs_error / val1) * 100.0;
            }
        }

        // ==== 4. Не обнаружена неточность ====

        else {
            error_percent = 100.0;
        }

        // ===== Финальный расчёт =====
        if (error_percent >= 0.0) {
            item.error_rate = static_cast<int>(std::floor(100.0f - error_percent));
        } else {
            item.error_rate = 0; // Ошибка / отсутствие данных
        }
        /*
        emptyItem.term = "";
        emptyItem.number_1 = -1.0;
        emptyItem.number_2 = -1.0;
        emptyItem.units_of_measurement = "";
        emptyItem.set_symptom = symptom;
        emptyItem.set_answer = answer;
        emptyItem.error_rate = -1;
        emptyItem.category = "";
         */

        std::cout << "///////////////////////////////////////////////////////////////////";
        std::cout << "-------------------------------------------------------------------";
        std::cout << "Вывод про точность\n";
        std::cout << "термин = " << item.term << "\n";
        std::cout << "первое число = " << item.number_1 << "\n";
        std::cout << "второе число = " << item.number_2 << "\n";
        std::cout << "единицы измерения = " << item.units_of_measurement << "\n";
        std::cout << "симптом = " << item.set_symptom << "\n";
        std::cout << "весь ответ = " << item.set_answer << "\n";
        std::cout << "погрешность = " << item.error_rate << "\n";
        std::cout << "категория = " << item.category << "\n";
        std::cout << "-------------------------------------------------------------------";
        std::cout << "///////////////////////////////////////////////////////////////////";
    }
}

int PZCreator::addAttributeToMainObject(const std::string& attrType)
{
    auto attributeName = "Атрибут" + std::to_string(_nAttributes++); //"Атрибут"
    auto object = _knowledgeField.get_object(_mainObjectName);
     std::cout << attrType << std::endl;
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


void PZCreator::rewrite_indef() {

    for (auto& item_1 : indef){
        for (auto& item_2 : inacc){
            if (item_1.set_symptom == item_2.set_symptom){
                item_1.error_rate = item_2.error_rate;

                //std::cout << "\nЗначение item_1.set_symptom = " << item_1.set_symptom;
                //std::cout << "\nЗначение item_1.error_rate = " << item_1.error_rate;
                //std::cout << "\nЗначение item_1.set_symptom = " << item_2.set_symptom;
                //std::cout << "\nЗначение item_1.error_rate = " << item_2.error_rate;

                break;
            }
        }

    }

}

string PZCreator::getAllFuzzyValues() const{
    return _knowledgeField.getAllFuzzyValues();
}


string rewrite_txt_for_pz(string a)
{
    QString result = QString::fromStdString(a); // твой исходный текст
    QRegularExpression regex(R"(\(Пациент\.Атрибут\d+=([^()]+?)\))");

    int offset = 0; // текущая позиция по строке
    while (true) {
        QRegularExpressionMatch match = regex.match(result, offset);
        if (!match.hasMatch()) break;

        QString fullMatch = match.captured(0); // (Пациент.АтрибутN=что-то)
        QString symptom = match.captured(1);   // значение после =


        bool replaced = false;
        // Найдём объект Indefinite с подходящим set_symptom
        for (const indefinite& item : indef) {
            if (QString::fromStdString(item.set_symptom) == symptom) {
                QString insertText = QString(" УВЕРЕННОСТЬ [%1;%2] ТОЧНОСТЬ %3")
                                        .arg(item.min_val)
                                        .arg(item.max_val)
                                        .arg(item.error_rate);

                // Вставим перед закрывающей скобкой
                QString newMatch = fullMatch;
                newMatch.insert(newMatch.length() - 1, insertText);

                // Заменим найденное совпадение в исходной строке
                result.replace(match.capturedStart(0), fullMatch.length(), newMatch);

                // Перейдём к следующей позиции, после текущей замены
                offset = match.capturedStart(0) + newMatch.length();
                replaced = true;
                break;
            }
        }

        if (!replaced){
            offset = match.capturedEnd(0);// продолжить после текукщего совпадения
        }

    }
    return result.toStdString();
}



void MA_in_txt(std::vector<string> tempLexemes, const std::string &answer){

    MA_result += "Ответ Пациента: " + answer + "\n";

    if (indef.back().indefinite_lemma !="")
        {
                MA_result += "Лексемы для НЕ-факторов: " + indef.back().indefinite_lemma + " ";
        }

        else if (inacc.back().term !="" and indef.back().indefinite_lemma !="")
        {
                MA_result += inacc.back().term + " " + inacc.back().units_of_measurement + "\n";
        }
        else if (inacc.back().term !="" and indef.back().indefinite_lemma =="")
        {
                MA_result += "Лексемы для НЕ-факторов: " + inacc.back().term + " " + inacc.back().units_of_measurement + "\n";
        }
    if (fuzzyL.back().fuzzyLex.term !="" and indef.back().indefinite_lemma !="") {
            // Даш я поняти я не имею как ты хочешь чтобы это выводилось.
            MA_result += fuzzyL.back().fuzzyLex.term.toStdString() + " " + fuzzyL.back().fuzzyLex.lvName.toStdString() + "\n";
    }
    else if (fuzzyL.back().fuzzyLex.term !="" and indef.back().indefinite_lemma =="")
    {
        MA_result += "Лексемы для НЕ-факторов: " + fuzzyL.back().fuzzyLex.term.toStdString() + " " + fuzzyL.back().fuzzyLex.lvName.toStdString() + "\n";
    }

    /* if (indef.back().indefinite_lemma !="")
            {
                    MA_result += "Лексемы для НЕ-факторов: " + indef.back().indefinite_lemma + " ";
            }

            else if (fuzzyL.back().fuzzyLex.term !="" and indef.back().indefinite_lemma != "")
            {
                    // Даш, я поняти я не имею как ты хочешь чтобы это выводилось.
                    MA_result += fuzzyL.back().fuzzyLex.term.toStdString() + " " + fuzzyL.back().fuzzyLex.lvName.toStdString() + "\n";
            }

            else if (inacc.back().term !="" and indef.back().indefinite_lemma !="")
            {
                    MA_result += inacc.back().term + " " + inacc.back().units_of_measurement + "\n";
            }
            else if (inacc.back().term !="" and indef.back().indefinite_lemma =="")
            {
                    MA_result += "Лексемы для НЕ-факторов: " + inacc.back().term + " " + inacc.back().units_of_measurement + "\n";
            }

            else if (fuzzyL.back().fuzzyLex.term !="" and indef.back().indefinite_lemma =="")
            {
                    // Даш я поняти я не имею как ты хочешь чтобы это выводилось.
                    MA_result += "Лексемы для НЕ-факторов: " + fuzzyL.back().fuzzyLex.term.toStdString() + " " + fuzzyL.back().fuzzyLex.lvName.toStdString() + "\n";
            }
    */

    if (tempLexemes.back()!="."){
        MA_result += "\nТемпоральные лексемы: " + tempLexemes.back() + "\n";
    }
    // MA_result += "Лексемы для НЕ-факторов: " + indef.back().indefinite_lemma + " " + inacc.back().term + " " + inacc.back().units_of_measurement + "\n";
    //MA_result = std::to_string(MA_result);

    MA_result += "\n";

    appendToFile(MA_result);

    std::cout << std::endl << std::endl << MA_result << std::endl  << std::endl ;
}






void SSA_in_txt(std::vector<string> tempLexemes, std::vector<string> tempObjects, const std::string &answer){

    if (indef.back().indefinite_lemma !="") {
        SSA_result+= "НЕ-фактор неопределенность: " + indef.back().indefinite_lemma + "\n";
    }

    if (inacc.back().term !="") {
        SSA_result+= "НЕ-фактор неточность: " + inacc.back().term + " " + /*(inacc.back().number_1.toString)?*/ inacc.back().units_of_measurement + "\n";

    }
    if (fuzzyL.back().fuzzyLex.term  !="") {
            SSA_result+= "НЕ-фактор нечёткость: " + fuzzyL.back().fuzzyLex.term.toStdString() + " " + fuzzyL.back().fuzzyLex.lvName.toStdString() + "\n";
    }

    if ((tempLexemes.back() != ".") and (tempObjects.back().rfind("Событие", 0) == 0))
    {
        SSA_result += "Событие: " + tempLexemes.back() + "\n";
    }

    if ((tempLexemes.back() != ".") and (tempObjects.back().rfind("Интервал", 0) == 0))
    {
        SSA_result += "Интервал: " + tempLexemes.back() + "\n";
    }


    SSA_result += "\n";

    appendToFile_2(SSA_result);

    std::cout << std::endl << std::endl << MA_result << std::endl  << std::endl ;
}





//void SI_in_txt(std::vector<string> tempLexemes, const std::string &answer){
//    if (fuzzy.back().term !="") {
//            SI_result+= "НЕЧЕТКИЙ АТРИБУТ \n"
//                        "ЗНАЧЕНИЯ\n"+fuzzy.back().term+" "+fuzzy.back().result+"\n"+
//                        "ДИАПАЗОН "+std::to_string(fuzzy.back().min_val)+" "+std::to_string(fuzzy.back().max_val)+"\n"+
//                        "ЕДИНИЦЫ ИЗМЕРЕНИЯ "+fuzzy.back().units_of_measurement+"\n"+
//                        "КОММЕНТАРИЙ "+answer+"\n"
//                    ;
//    };
//    appendToFile_3(SI_result);
//}

std::vector<std::string> extractEventIntervalBlocksUpToComment(const std::string& input) {
    std::vector<std::string> blocks;
    std::istringstream iss(input);
    std::string line;

    std::ostringstream currentBlock;
    bool inTargetBlock = false;

    while (std::getline(iss, line)) {
        // --- Проверяем начало блока Событие или Интервал ---
        if (std::regex_search(line, std::regex(R"(^ОБЪЕКТ\s+\"(?:Событие|Интервал)\d*\")"))) {
            inTargetBlock = true;
            currentBlock << line << "\n";
            continue;
        }

        // --- Если внутри нужного блока — добавляем строку ---
        if (inTargetBlock) {
            currentBlock << line << "\n";

            // --- Если нашли слово "КОММЕНТАРИЙ" — завершаем блок ---
            if (line.find("КОММЕНТАРИЙ") != std::string::npos) {
                blocks.push_back(currentBlock.str());
                currentBlock.str(""); currentBlock.clear();
                inTargetBlock = false;
            }
        }
    }

    // --- На случай, если файл закончился, а КОММЕНТАРИЙ так и не встретился ---
    if (inTargetBlock && !currentBlock.str().empty())
        blocks.push_back(currentBlock.str());

    return blocks;
}



void SI_in_txt_1(std::string a, string fuz) {
    // === Сначала извлекаем блоки СобытиеN / ИнтервалN до КОММЕНТАРИЙ ===
    std::vector<std::string> rawBlocks = extractEventIntervalBlocksUpToComment(a);

    // === Преобразуем их в QString для объединения с основным выводом ===
    QString newResult;
    for (const auto& block : rawBlocks) {
        newResult += QString::fromStdString(block + "\n\n");
    }

    // === Далее оригинальная логика ===
    QString input = QString::fromStdString(a);
    QString originalResult;

    // == Блок Алексея (начало)
    QString resultFuzzy = QString::fromStdString(fuz);
    // == Блок Алексея (конец)

    QRegularExpression regex(R"(\(Пациент\.Атрибут\d+=([^()]+?)\))");
    int offset = 0;

    while (true) {
        QRegularExpressionMatch match = regex.match(input, offset);
        if (!match.hasMatch()) break;

        QString fullMatch = match.captured(0);
        QString symptom = match.captured(1).trimmed();

        QString cleanSymptom = symptom;
        int index = symptom.indexOf("УВЕРЕННОСТЬ");
        if (index != -1)
            cleanSymptom = symptom.left(index).trimmed();

        bool match_found = false;

        for (const indefinite& item : indef) {
            QString itemSymptom = QString::fromStdString(item.set_symptom).trimmed();

            if (itemSymptom == cleanSymptom) {
                if (!item.indefinite_lemma.empty() || item.error_rate != 0) {
                    originalResult += fullMatch + "\n\n";
                    match_found = true;
                    break;
                }
            }
        }

        if (!match_found) {
            // Ничего не делаем
        }

        offset = match.capturedEnd(0);
    }

    // === Объединяем результаты и пишем в файл за один раз ===
    QString finalResult;

    if (!newResult.isEmpty() && !originalResult.isEmpty()) {
        finalResult = newResult + resultFuzzy + originalResult + "\n";
    } else if (!newResult.isEmpty()) {
        finalResult = newResult + resultFuzzy;
    } else if (!originalResult.isEmpty()) {
        finalResult = resultFuzzy + originalResult + "\n";
    } else {
        finalResult = resultFuzzy+ "\n";
    }

    if (!finalResult.isEmpty()) {
        appendToFile_3(finalResult.toStdString());
    }
}
