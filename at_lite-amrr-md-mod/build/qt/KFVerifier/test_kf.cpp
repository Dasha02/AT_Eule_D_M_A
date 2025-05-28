#include "test_kf.h"
#include <QFile>
#include <QTextStream>

#include "../../src/plugins/KMPZ/pz_creator/pz_creator.h"

knowledge_field_t* test_kf::create_kf(){
    knowledge_field_t *nkf = new knowledge_field_t();

    temporal_object_t *obj = (temporal_object_t*)nkf->add_object("объект1");
    int id_obj = nkf->get_object_id_by_name("объект1");
    nkf->add_type("ТИП1");
    nkf->add_type_value("ТИП1","знач11");
    nkf->add_type_value("ТИП1","знач12");
    nkf->add_type_value("ТИП1","знач13");
    nkf->add_type("ТИП2");
    nkf->add_type_value("ТИП2","знач21");
    nkf->add_type_value("ТИП2","знач22");
    nkf->add_type_value("ТИП2","знач23");

    int id_attr1 = obj->add_attr("атр1","ТИП1");
    int id_attr2 = obj->add_attr("атр2","ТИП2");


    temporal_event_t* event1 = (temporal_event_t*)nkf->add_event("Событие1");
    int id_ev1 = nkf->get_event_id_by_name("Событие1");
    condition_attr_value_const_t* cond1 = new condition_attr_value_const_t();
    cond1->set_obj_id(id_obj);
    cond1->set_attr_id(id_attr1);
    cond1->set_value("знач11");
    cond1->set_op("=");
    event1->add_condition(cond1);

    complex_condition_t* conds1 = new complex_condition_t () ;
    conds1->set_op("&");
    conds1->add_condition(cond1);

    temporal_event_t* event2 = (temporal_event_t*)nkf->add_event("Событие2");
    int id_ev2 = nkf->get_event_id_by_name("Событие2");
    condition_attr_value_const_t* cond2 = new condition_attr_value_const_t();
    cond2->set_obj_id(id_obj);
    cond2->set_attr_id(id_attr1);
    cond2->set_value("знач12");
    cond2->set_op("=");
    event2->add_condition(cond2);

    complex_condition_t* conds2 = new complex_condition_t () ;
    conds2->set_op("&");
    conds2->add_condition(cond2);

    temporal_interval_t* interval1 = (temporal_interval_t*)nkf->add_interval("Интервал1");
    interval1->set_start_condition(cond1);
    interval1->set_end_condition(cond2);
    int id_int1 = nkf->get_interval_id_by_name("Интервал1");

    action_string_t* act1 = new action_string_t();
    act1->set_object_id(id_obj);
    act1->set_attribute_id(id_attr2);
    act1->set_value("знач21");
    act1->set_op("=");

    event_event_condition_t* cond_r1 = new event_event_condition_t();
    cond_r1->set_left_event_id(id_ev1);
    cond_r1->set_right_event_id(id_ev2);
    cond_r1->set_op("e");
    complex_condition_t* ccond_r1 = new complex_condition_t();
    ccond_r1->add_condition(cond_r1);
    temporal_rule_t* r1 = (temporal_rule_t*)nkf->add_rule("Правило1");
    r1->add_condition(ccond_r1);
    r1->add_action(act1);

    event_interval_condition_t* cond_r2 = new event_interval_condition_t();
    cond_r2->set_event_id(id_ev1);
    cond_r2->set_interval_id(id_int1);
    cond_r2->set_op("b");
    complex_condition_t* ccond_r2 = new complex_condition_t();
    ccond_r2->add_condition(cond_r2);
    temporal_rule_t* r2 = (temporal_rule_t*)nkf->add_rule("Правило2");
    r2->add_condition(ccond_r2);
    r2->add_action(act1);

    event_interval_condition_t* cond_r3 = new event_interval_condition_t();
    cond_r3->set_event_id(id_ev2);
    cond_r3->set_interval_id(id_int1);
    cond_r3->set_op("a");
    complex_condition_t* ccond_r3 = new complex_condition_t();
    ccond_r3->add_condition(cond_r3);
    temporal_rule_t* r3 = (temporal_rule_t*)nkf->add_rule("Правило3");
    r3->add_condition(ccond_r3);
    r3->add_action(act1);

    event_interval_condition_t* cond_r4 = new event_interval_condition_t();
    cond_r4->set_event_id(id_ev2);
    cond_r4->set_interval_id(id_int1);
    cond_r4->set_op("s");
    complex_condition_t* ccond_r4 = new complex_condition_t();
    ccond_r4->set_op("&");
    ccond_r4->add_condition(cond_r4);
    temporal_rule_t* r4 = (temporal_rule_t*)nkf->add_rule("Правило4");

    event_interval_condition_t* cond_r5 = new event_interval_condition_t();
    cond_r5->set_event_id(id_ev1);
    cond_r5->set_interval_id(id_int1);
    cond_r5->set_op("f");
    ccond_r4->add_condition(cond_r5);
    r4->add_condition(ccond_r4);
    r4->add_action(act1);


    event_interval_condition_t* cond_r6 = new event_interval_condition_t();
    cond_r6->set_event_id(id_ev2);
    cond_r6->set_interval_id(id_int1);
    cond_r6->set_op("f");
    complex_condition_t* ccond_r6 = new complex_condition_t();
    ccond_r6->add_condition(cond_r6);

    temporal_rule_t* r6 = (temporal_rule_t*)nkf->add_rule("Правило6");
    r6->add_condition(ccond_r6);
    r6->add_action(act1);


    set_kf(nkf);
    return nkf;
    //nkf->to_xml();
}

void test_kf::writeToFile(QString filename)
{
//    std::ofstream ofs;
//    ofs.open("", std::ofstream::out | std::ofstream::trunc);("=");
//    ofs << ;
//    ofs.close();

    QFile file(filename);
        // Trying to open in WriteOnly and Text mode
        if(!file.open(QFile::WriteOnly |
                      QFile::Text))
        {
            std::cout << " Could not open file for writing";
            return;
        }

        // To write text, we use operator<<(),
        // which is overloaded to take
        // a QTextStream on the left
        // and data types (including QString) on the right

        QTextStream out(&file);

        QString a = QString::fromStdString(kf->to_xml());
//        QString result = rewrite_txt_for_pz_1(a);

//        out << result;

//        //
        out << QString::fromStdString(kf->to_xml());
        file.flush();
        file.close();

}
