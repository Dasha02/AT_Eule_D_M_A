#ifndef VERIFIER_H
#define VERIFIER_H

#include "../../src/libs/KnowledgeField/knowledge_field_t.h"
#include <QString>
#include <QDomDocument>

class verifier
{
public:
    verifier();
    verifier(knowledge_field_t* kf_in) : kf(kf_in) {}

private:
    knowledge_field_t* kf = nullptr;
    std::vector<std::pair<const temporal_rule_t*, const temporal_rule_t*>> excessiveRules;
    std::vector<std::pair<const temporal_rule_t*, const temporal_rule_t*>> intersectionRules;
    std::vector<std::pair<const temporal_rule_t*, std::pair<const temporal_entity_t*, const temporal_entity_t*>>> impossiblePositioning;

public:
    void set_kf(knowledge_field_t* kf_in){
        kf = kf_in;
        return;
    }
    knowledge_field_t* get_kf() { return kf; }
    std::vector<std::pair<const temporal_rule_t*, const temporal_rule_t*>> get_excessiveRules() {return excessiveRules; }
    std::vector<std::pair<const temporal_rule_t*, const temporal_rule_t*>> get_intersectionRules() {return intersectionRules; }
    std::vector<std::pair<const temporal_rule_t*, std::pair<const temporal_entity_t*, const temporal_entity_t*>>> get_impossiblePositioning() {return impossiblePositioning; }

    knowledge_field_t* readFromFile(QString filename);

    std::vector<const temporal_rule_t*> verifyImpossiblePositioning();
    std::vector<std::pair<const temporal_rule_t*, std::pair<const temporal_entity_t*, const temporal_entity_t*>>> verifyImpossiblePositioningII();
    std::set<temporal_entity_t*> verifyWrongAttributesValues();
    vector<int> verifyEventsIdsWithoutRef();
    vector<int> verifyIntervalsIdsWithoutRef();
    std::vector<std::pair<const temporal_rule_t*, const temporal_rule_t*>> verifyPairsExcessiveRulesII();
    std::vector<std::pair<const temporal_rule_t*, const temporal_rule_t*>> verifyPairsIntersecionRulesII();

    void add_event_ids(vector<int>& uses_events_ids, condition_t* cond);
    void add_interval_ids(vector<int>& uses_interval_ids, condition_t* cond);
    int true_values(condition_t* condition, knowledge_field_t* kf);
    vector<pair<QString, QString>> true_values_str(condition_t* condition, knowledge_field_t* kf);

    string verifyEventsWithoutRef();
    string verifyIntervalsWithoutRef();    

    std::vector<std::pair<const temporal_rule_t*, const temporal_rule_t*>> verifyPairsExcessiveRules();
    std::vector< std::pair<const temporal_rule_t*, const temporal_rule_t*>> verifyPairsIntersecionRules();
    string verifyExcessiveRules();
    string verifyIntersecionRules();

    bool arr_inter(std::vector< std::pair<int,std::string>> &v1, std::vector< std::pair<int,std::string>> &v2);
    bool arr_diff(std::vector< std::pair<int,std::string>> &v1, std::vector< std::pair<int,std::string>> &v2);

    std::string getBZXml();

    void writeToFile(QString filename);


    void readTypeFromFile(QDomElement type, knowledge_field_t* kf);
    void readObjectFromFile(QDomElement object, knowledge_field_t* kf);
    void readRuleFromFile(QDomElement rule, knowledge_field_t* kf);
    void readEventFromFile(QDomElement event, knowledge_field_t* kf);
    void readIntervalFromFile(QDomElement interval, knowledge_field_t* kf);

};

#endif // VERIFIER_H
