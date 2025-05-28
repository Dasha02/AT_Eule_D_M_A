#ifndef TEST_KF_H
#define TEST_KF_H

#include "../../src/libs/KnowledgeField/knowledge_field_t.h"
#include <QString>

class test_kf
{
public:
    test_kf() {}
    test_kf(knowledge_field_t *kf_in) : kf(kf_in) {}

private:
    knowledge_field_t *kf;

public:
    knowledge_field_t *get_kf() { return kf; }
    void set_kf(knowledge_field_t *hop) { kf = hop; }
    knowledge_field_t *create_kf();
    void writeToFile(QString filename);
};

#endif // TEST_KF_H
