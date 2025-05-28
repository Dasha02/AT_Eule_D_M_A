#include "condition_stack.h"

QuestionAnswerStack::QuestionAnswerStack()
{}

void QuestionAnswerStack::push(const std::string& question, const std::string& answer, const std::string& symptom, int attributeId, std::vector<std::string>* temporal_lexems, std::vector<temporal_entity_t*>* entities_for_lexems)
{
    _conditions.emplace_back(question, answer, symptom, attributeId, temporal_lexems, entities_for_lexems);
}

void QuestionAnswerStack::add(const std::string& answer, const std::string& symptom, std::vector<std::string>* temporal_lexems, std::vector<temporal_entity_t*>* entities_for_lexems)
{
	_conditions.back().attributeValues.push_back(answer);
	_conditions.back().symptomValues.push_back(symptom);
    _conditions.back().temporal_lexems->push_back(temporal_lexems);
    _conditions.back().entities_for_lexems->push_back(entities_for_lexems);
}

const QuestionAnswerStack::Condition& QuestionAnswerStack::top() const
{
	return _conditions.back();
}

void QuestionAnswerStack::pop()
{
	_conditions.pop_back();
}

bool QuestionAnswerStack::empty() const
{
	return _conditions.empty();
}

const std::vector<QuestionAnswerStack::Condition>& QuestionAnswerStack::getConditions() const
{
	return _conditions;
}
