#ifndef CONDITION_STACK_H
#define CONDITION_STACK_H

#include <string>
#include <vector>
#include "../../../libs/KnowledgeField/knowledge_field_t.h"


class QuestionAnswerStack
{
public:
	struct Condition
	{
		std::string attributeType;
		std::vector<std::string> attributeValues;
		std::vector<std::string> symptomValues;
		int attributeId;
        std::vector<std::vector<std::string>*>* temporal_lexems;
        std::vector<std::vector<temporal_entity_t*>*>* entities_for_lexems;


        Condition(
                const std::string& _attributeType,
                const std::string& _attributeValue,
                const std::string& _symptomValue,
                int _attributeId,
                std::vector<std::string>* _temporal_lexems,
                std::vector<temporal_entity_t*>* _entities_for_lexems
            )
            : attributeType(_attributeType)
			, attributeValues({ _attributeValue })
			, symptomValues({ _symptomValue })
            , attributeId(_attributeId)
        {
            temporal_lexems = new std::vector<std::vector<std::string>*>();
            temporal_lexems->push_back(_temporal_lexems);

            entities_for_lexems = new std::vector<std::vector<temporal_entity_t*>*>();
            entities_for_lexems->push_back(_entities_for_lexems);
        }
	};

public:
	QuestionAnswerStack();

    void push(const std::string& question, const std::string& answer, const std::string& symptom, int attributeId, std::vector<std::string>* temporal_lexems, std::vector<temporal_entity_t*>* entities_for_lexems);
    void add(const std::string& answer, const std::string& symptom, std::vector<std::string>* temporal_lexems, std::vector<temporal_entity_t*>* entities_for_lexems);
	const Condition& top() const;
	void pop();
	bool empty() const;

	const std::vector<Condition>& getConditions() const;

private:
	std::vector<Condition> _conditions;
};

#endif // CONDITION_STACK_H
