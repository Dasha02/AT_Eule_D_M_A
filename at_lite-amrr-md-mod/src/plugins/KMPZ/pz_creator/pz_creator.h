#ifndef PZ_CREATOR_H
#define PZ_CREATOR_H

#include "condition_stack.h"
#include "../atn/atn.h"

//#include "../libs/KnowledgeField/knowledge_field_t.h"
#include "../../../libs/KnowledgeField/knowledge_field_t.h"

#include <memory>
#include <QDir>

#include <QCoreApplication>
#include <QRegularExpression>
#include <QDebug>
#include <QString>



typedef std::pair<std::vector<std::string>, std::vector<std::string>> branch_t;
int bz_rewrite_to_xml();
void MA_in_txt(std::vector<string> tempLexemes, const std::string &answer);
void SSA_in_txt(std::vector<string> tempLexemes, std::vector<string> tempObjects, const std::string &answer);
string extract_txt_for_pz(string a);
void SI_in_txt(string a);
void SI_in_txt_1(string a, string fuz);
void SI_in_txt_2(string a);
string bz_rewrite_in_knowledge(string value);

class indefinite{
public:
    string indefinite_lemma;
    int min_val;
    int max_val;
    string set_symptom;
    string set_answer;
    int error_rate;
};

class inaccuracy{
public:
    string term;
    float number_1;
    float number_2;
    string units_of_measurement;
    string set_symptom;
    string set_answer;
    int error_rate;
    string category;
};
//std::vector<indefinite> indef;

string rewrite_txt_for_pz(string a);
int bz_rewrite_to_xml_1();
void appendToFile();
void appendToFile_2();
void appendToFile_3();
string rewrite_txt_for_pz(string a);

class PZCreator
{
public:
    PZCreator();
    void addNonFactor(vector<string> *negfactorLexemes);
    void addNonFactor_1(vector<string> *negfactorLexemes, std::string symptom, std::string answer); // поиск неопределенности
    void addNonFactor_2(vector<string> *negfactorLexemes, std::string symptom, std::string answer); // поиск неточности
    void addNonFactor_3(vector<string> *negfactorLexemes, std::string symptom, std::string answer);
    void calculateErrorRates();
    void rewrite_indef();
    void addQuestionAndAnswer(const std::string& question, const std::string& answer);
    void addAnswer(const std::string& answer);
    void removeQuestion();
    void addRule();
    const branch_t& getLastBranch() const;
    void removeBranchConclusions();
    std::string getBZ();
    std::string getBZXml();
//	void PZCreator::writeToFile();
    void writeToFile();

    void addConclusion(const std::string& conclusion);

    const QuestionAnswerStack::Condition& getLastQuestion() const;
    const std::vector<std::string> getLastAnswers() const;
    bool hasQuestions() const;
    string getAllFuzzyValues() const;

    //void MA_in_txt(std::vector<string> tempLexemes, const               std::string &answer);

private:
    complex_condition_t* getCurrentCondition();

    vector<temporal_entity_t*>* addTemporal(vector<string> *tempLexemes, vector<string> *tempObjects);
    void addNegFactor(vector<string> *negfactorLexemes);
//	std::string PZCreator::getSymptom(const vector<string>& tempLexemes, const std::string& answer);
    std::string getSymptom(const vector<string>& tempLexemes, const std::string& answer);

    int addAttributeToMainObject(const std::string& attrType);
    int mainObjectId() const;

    QString ru(const char * text);

private:
    ATN _atn;
    QuestionAnswerStack _questionAnswerStack;
    std::vector<std::string> _conclusions;
    std::vector<std::string> _last_branch_conclusions;

    std::map<int, std::vector<string>> _tempObjects;

    std::string _lastQuestion;

    knowledge_field_t _knowledgeField;

    const std::string _mainObjectName = "Пациент";

    int _conclusionAttributeId;
    int _eventAttributeId;
    //int _durationAttributeId;
    //int _periodAttributeId;

    size_t _nAttributes = 1;
    size_t _nRules = 1;
    size_t _nEvents = 0;
    size_t _nIntervals = 0;

    QString _outPath;
    QString _FuzzyPath;
    std::string _bzPath;
};

#endif // PZ_CREATOR_H
