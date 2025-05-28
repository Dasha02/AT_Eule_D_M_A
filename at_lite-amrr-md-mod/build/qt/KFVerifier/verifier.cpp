#include "verifier.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>
#include <QString>


#include <QFile>
#include <QDebug>
#include <QTextCodec>
#include <QTextStream>
#include <QXmlStreamReader>

#include "../../src/plugins/KMPZ/pz_creator/pz_creator.h"

verifier::verifier(){ }

void verifier::add_event_ids(vector<int>& uses_events_ids, condition_t* cond) {
    if (isType< event_event_condition_t, condition_t>(cond)) {
        // если правило событие d событие
        int left_id;
        left_id = dynamic_cast<event_event_condition_t*>(cond)->get_left_event_id();
        std::cout << " " << left_id << " " << kf->get_event_name_by_id(left_id) << " |";
        uses_events_ids.push_back(left_id);

        int right_id;
        right_id = dynamic_cast<event_event_condition_t*>(cond)->get_right_event_id();
        std::cout << " " << right_id << " " << kf->get_event_name_by_id(right_id) << " |";
        uses_events_ids.push_back(right_id);

    } else
    if (isType< temporal_condition_operation_condition, condition_t>(cond)) {
        // если событие d артибут=значение

        temporal_entity_t* entity = dynamic_cast<temporal_condition_operation_condition*>(cond)->get_entity();

        if (isType< temporal_event_t, temporal_entity_t>(entity)) {
            std::cout << " " << entity->get_id() << " "  << entity->get_name() << " |";
            uses_events_ids.push_back(entity->get_id());
        } /*else {
            std::cout << "not event!\n";
        }*/
        condition_t* cond_new = dynamic_cast<temporal_condition_operation_condition*>(cond)->get_condition_t();
        add_event_ids(uses_events_ids, cond_new);

    } else
    if (isType< event_interval_condition_t, condition_t>(cond)) {
        // если правило событие d событие
        int id;
        id = dynamic_cast<event_interval_condition_t*>(cond)->get_event_id();
        std::cout << " " << id << " " << kf->get_event_name_by_id(id) << " |";
        uses_events_ids.push_back(id);
    } else if (isType<complex_condition_t, condition_t>(cond)) {

        for (int i = 0; i < dynamic_cast<complex_condition_t*>(cond)->get_number_of_conditions(); i++) {
            add_event_ids(uses_events_ids, dynamic_cast<complex_condition_t*>(cond)->get_condition_t(i));
        }
    }
}

string verifier::verifyEventsWithoutRef() {
    std::cout << "**Поиск аномалии 'События без ссылок'**\n";
    // вектор событий, у которых есть ссылки
    vector<int> uses_events_ids;
    // для каждого правила получаем список событий, которые в нем используются
    for (temporal_rule_t* rule : kf->getRules()){
        if (rule->is_temporal()) {
            std::cout << rule->to_string(*(kf));
            std::cout << "**" << rule->get_name() << ":";
            // получаем условия (или вектор условий) из правила
            condition_t* conds = rule->get_condition_t();
            // проходимся по условиям в поисках событий, которые добавляются в массив
            add_event_ids(uses_events_ids, conds);
            std::cout << std::endl << std::endl;
        }
    }

    // вектор всех событий
    vector<int> all_events_id;
    vector<temporal_event_t*> events = kf->getEvents();
    if (events.size() > 0) {
        for (temporal_event_t* event : events) {
            all_events_id.push_back(event->get_id());
        }
    }

    std::sort(uses_events_ids.begin(), uses_events_ids.end());
    uses_events_ids.erase(unique(uses_events_ids.begin(), uses_events_ids.end()), uses_events_ids.end());

    std::cout << "Все события: ";
    for (int i: all_events_id) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "Исп события: ";
    for (int i: uses_events_ids) {
        std::cout << i << " ";
    }
    std::cout << std::endl;


    vector<int> not_uses_events_id;
    std::set_difference(all_events_id.begin(), all_events_id.end(),
                        uses_events_ids.begin(), uses_events_ids.end(),
                                                      std::back_inserter(not_uses_events_id));

    std::cout << "   Разность: ";
    for (int i: not_uses_events_id) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    if (!not_uses_events_id.empty()) {
        QString res = "";
        for (int i: not_uses_events_id) {
            res = res + QString::fromStdString ("\tСобытие '");
            res = res + QString::fromStdString (kf->get_event(i)->get_name());
            res = res + QString::fromStdString ("'\n");
        }
        //std::cout << res.toStdString();
        return res.toStdString();
    } else {
        //std::cout << "\tне найдено\n";
        return "\tне найдено\n";
    }
}

vector<int> verifier::verifyEventsIdsWithoutRef() {
    std::cout << "**Поиск аномалии 'События без ссылок'**\n";
    // вектор событий, у которых есть ссылки

    vector<int> uses_events_ids;
    // для каждого правила получаем список событий, которые в нем используются
    for (temporal_rule_t* rule : kf->getRules()){
        if (rule->is_temporal()) {
            std::cout << rule->to_string(*(kf));
            std::cout << "**" << rule->get_name() << ":";
            // получаем условия (или вектор условий) из правила
            condition_t* conds = rule->get_condition_t();
            // проходимся по условиям в поисках событий, которые добавляются в массив
            add_event_ids(uses_events_ids, conds);
            std::cout << std::endl << std::endl;
        }
    }

    // вектор всех событий
    vector<int> all_events_id;
    vector<temporal_event_t*> events = kf->getEvents();
    if (events.size() > 0) {
        for (temporal_event_t* event : kf->getEvents()) {
            all_events_id.push_back(event->get_id());
        }
    }

    std::sort(uses_events_ids.begin(), uses_events_ids.end());
    uses_events_ids.erase(unique(uses_events_ids.begin(), uses_events_ids.end()), uses_events_ids.end());

    std::cout << "Все события: ";
    for (int i: all_events_id) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "Исп события: ";
    for (int i: uses_events_ids) {
        std::cout << i << " ";
    }
    std::cout << std::endl;


    vector<int> not_uses_events_id;
    std::set_difference(all_events_id.begin(), all_events_id.end(),
                        uses_events_ids.begin(), uses_events_ids.end(),
                                                      std::back_inserter(not_uses_events_id));

    std::cout << "   Разность: ";
    for (int i: not_uses_events_id) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return not_uses_events_id;

}

void verifier::add_interval_ids(vector<int>& uses_interval_ids, condition_t* cond) {
    if (isType< condition_interval_duration_t, condition_t>(cond)) {
        // если правило интервал.длительность = значение
        int id;
        id = dynamic_cast<condition_interval_duration_t*>(cond)->get_interval_id();
        std::cout << " " << id << " " << kf->get_interval_name_by_id(id) << " |";
        uses_interval_ids.push_back(id);

    } else
    if (isType< temporal_condition_operation_condition, condition_t>(cond)) {
        // если событие d артибут=значение

        temporal_entity_t* entity = dynamic_cast<temporal_condition_operation_condition*>(cond)->get_entity();

        if (isType< temporal_interval_t, temporal_entity_t>(entity)) {
            std::cout << " " << entity->get_id() << " " << entity->get_name() << " |";
            uses_interval_ids.push_back(entity->get_id());
        } /*else {
            std::cout << "not interval!\n";
        }*/
        condition_t* cond_new = dynamic_cast<temporal_condition_operation_condition*>(cond)->get_condition_t();
        add_interval_ids(uses_interval_ids, cond_new);
    } else

    if (isType< event_interval_condition_t, condition_t>(cond)) {
        int id;
        id = dynamic_cast<event_interval_condition_t*>(cond)->get_interval_id();
        std::cout << " " << id << " " << kf->get_interval_name_by_id(id) << " |";
        uses_interval_ids.push_back(id);
    } else if (isType<complex_condition_t, condition_t>(cond)) {
        // если правило событие d событие
        for (int i = 0; i < dynamic_cast<complex_condition_t*>(cond)->get_number_of_conditions(); i++) {
            add_interval_ids(uses_interval_ids, dynamic_cast<complex_condition_t*>(cond)->get_condition_t(i));
        }
    }
    return;
}

string verifier::verifyIntervalsWithoutRef() {
    vector<int> uses_interval_ids;

    std::cout << "**Поиск аномалии 'Интервалы без ссылок'**\n";

    for (temporal_rule_t* rule : kf->getRules()){
        std::cout << rule->to_string(*(kf));
        std::cout << "**" << rule->get_name() << ":";
        // получаем условия (или вектор условий) из правила
        condition_t* conds = rule->get_condition_t();
        // проходимся по условиям в поисках интервалов, которые добавляются в массив
        add_interval_ids(uses_interval_ids, conds);
        std::cout << std::endl << std::endl;
    }

    vector<int> all_interval_id;
    for (temporal_interval_t* interval : kf->getIntervals()) {
        all_interval_id.push_back(interval->get_id());
    }

    std::sort(uses_interval_ids.begin(), uses_interval_ids.end());
    std::sort(all_interval_id.begin(), all_interval_id.end());
    uses_interval_ids.erase(unique(uses_interval_ids.begin(), uses_interval_ids.end()), uses_interval_ids.end());

    std::cout << "Все интервалы: ";
    for (int i: all_interval_id) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "Исп интервалы: ";
    for (int i: uses_interval_ids) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    vector<int> not_uses_intervals_id;
    std::set_difference(all_interval_id.begin(), all_interval_id.end(),
                        uses_interval_ids.begin(), uses_interval_ids.end(),
                                                      std::back_inserter(not_uses_intervals_id));

    std::cout << "     Разность: ";
    for (int i: not_uses_intervals_id) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    if (!not_uses_intervals_id.empty()) {
        QString res = "";
        for (int i: not_uses_intervals_id) {
            res = res + QString::fromStdString ("\tИнтервал '");
            res = res + QString::fromStdString (kf->get_interval(i)->get_name());
            res = res + QString::fromStdString ("'\n");
        }
        //std::cout << res.toStdString();
        return res.toStdString();
    } else {
        //std::cout << "\tне найдено\n";
        return "\tне найдено\n";
    }

}

vector<int> verifier::verifyIntervalsIdsWithoutRef() {
    vector<int> uses_interval_ids;

    std::cout << "**Поиск аномалии 'Интервалы без ссылок'**\n";

    for (temporal_rule_t* rule : kf->getRules()){
        std::cout << rule->to_string(*(kf));
        std::cout << "**" << rule->get_name() << ":";
        // получаем условия (или вектор условий) из правила
        condition_t* conds = rule->get_condition_t();
        // проходимся по условиям в поисках интервалов, которые добавляются в массив
        add_interval_ids(uses_interval_ids, conds);
        std::cout << std::endl << std::endl;
    }

    vector<int> all_interval_id;
    for (temporal_interval_t* interval : kf->getIntervals()) {
        all_interval_id.push_back(interval->get_id());
    }

    std::sort(uses_interval_ids.begin(), uses_interval_ids.end());
    std::sort(all_interval_id.begin(), all_interval_id.end());
    uses_interval_ids.erase(unique(uses_interval_ids.begin(), uses_interval_ids.end()), uses_interval_ids.end());

    std::cout << "Все интервалы: ";
    for (int i: all_interval_id) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "Исп интервалы: ";
    for (int i: uses_interval_ids) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    vector<int> not_uses_intervals_id;
    std::set_difference(all_interval_id.begin(), all_interval_id.end(),
                        uses_interval_ids.begin(), uses_interval_ids.end(),
                                                      std::back_inserter(not_uses_intervals_id));

    std::cout << "     Разность: ";
    for (int i: not_uses_intervals_id) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return not_uses_intervals_id;

//    if (!not_uses_intervals_id.empty()) {
//        QString res = "";
//        for (int i: not_uses_intervals_id) {
//            res = res + QString::fromStdString ("\tИнтервал '");
//            res = res + QString::fromStdString (kf->get_interval(i)->get_name());
//            res = res + QString::fromStdString ("'\n");
//        }
//        //std::cout << res.toStdString();
//        return res.toStdString();
//    } else {
//        //std::cout << "\tне найдено\n";
//        return "\tне найдено\n";
//    }

}

std::vector<const temporal_rule_t*> verifier::verifyImpossiblePositioning() {
    std::vector<const temporal_rule_t*> res;

    for (temporal_rule_t* rule: kf->getRules()) {
        if (rule->is_temporal()) {
            if (isType< complex_condition_t, condition_t>((condition_t*)rule->get_condition())) {
                complex_condition_t* ccond = (complex_condition_t*)rule->get_condition();
                for (int i = 0; i < ccond->get_number_of_conditions(); i++){
                    condition_t* cond_n = (condition_t*)ccond->get_condition(i);
                    if (isType< event_event_condition_t, condition_t>(cond_n)) {
                        event_event_condition_t* cond = (event_event_condition_t*)cond_n;

                        temporal_event_t* ev1 = (temporal_event_t*)kf->get_event(cond->get_left_event_id());
                        temporal_event_t* ev2 = (temporal_event_t*)kf->get_event(cond->get_right_event_id());
                        condition_attr_value_const_t* cond1 = (condition_attr_value_const_t*)ev1->get_condition();
                        condition_attr_value_const_t* cond2 = (condition_attr_value_const_t*)ev2->get_condition();
                        //
                        if (cond->get_op() == "e") {

                            if ((cond1->get_obj_id() == cond2->get_obj_id()) &&
                                    (cond1->get_attr_id() == cond2->get_attr_id()) &&
                                    (cond1->get_value() != cond2->get_value())) {
                                res.push_back(rule);
                            }
                        }
        //                else if (cond->get_op() == "b") {

        //                }
                    } else
                    // если Event e Interval
                    if (isType< event_interval_condition_t, condition_t>((condition_t*)cond_n)) {
                        event_interval_condition_t* cond = (event_interval_condition_t*)cond_n;

                        temporal_event_t* event = (temporal_event_t*)kf->get_event(cond->get_event_id());
                        temporal_interval_t* interval = (temporal_interval_t*)kf->get_interval(cond->get_interval_id());

                        condition_attr_value_const_t* condev = (condition_attr_value_const_t*)event->get_condition();
                        condition_attr_value_const_t* condbeg = (condition_attr_value_const_t*)interval->get_begin_condition_t();
                        condition_attr_value_const_t* condend = (condition_attr_value_const_t*)interval->get_end_condition_t();

                        if (cond->get_op() == "b") {
                            if ((condev->get_obj_id() == condbeg->get_obj_id()) &&
                                    (condev->get_attr_id() == condbeg->get_attr_id()) &&
                                    (condev->get_value() == condbeg->get_value())) {
                                res.push_back(rule);
                            }
                        } else if (cond->get_op() == "a") {
                            if ((condev->get_obj_id() == condend->get_obj_id()) &&
                                    (condev->get_attr_id() == condend->get_attr_id()) &&
                                    (condev->get_value() == condend->get_value())) {
                                res.push_back(rule);
                            }
                        } else if (cond->get_op() == "s") {
                            if ((condev->get_obj_id() == condbeg->get_obj_id()) &&
                                    (condev->get_attr_id() == condbeg->get_attr_id()) &&
                                    (condev->get_value() != condbeg->get_value())) {
                                res.push_back(rule);
                            }
                        } else if (cond->get_op() == "f") {
                            if ((condev->get_obj_id() == condend->get_obj_id()) &&
                                    (condev->get_attr_id() == condend->get_attr_id()) &&
                                    (condev->get_value() != condend->get_value())) {
                                res.push_back(rule);
                            }
                        }
                    }
                }
            } else {
                if (isType< event_event_condition_t, condition_t>((condition_t*)rule->get_condition())) {
                    event_event_condition_t* cond = (event_event_condition_t*)rule->get_condition();

                    temporal_event_t* ev1 = (temporal_event_t*)kf->get_event(cond->get_left_event_id());
                    temporal_event_t* ev2 = (temporal_event_t*)kf->get_event(cond->get_right_event_id());
                    condition_attr_value_const_t* cond1 = (condition_attr_value_const_t*)ev1->get_condition();
                    condition_attr_value_const_t* cond2 = (condition_attr_value_const_t*)ev2->get_condition();
                    //
                    if (cond->get_op() == "e") {

                        if ((cond1->get_obj_id() == cond2->get_obj_id()) &&
                                (cond1->get_attr_id() == cond2->get_attr_id()) &&
                                (cond1->get_value() != cond2->get_value())) {
                            res.push_back(rule);
                        }
                    }
    //                else if (cond->get_op() == "b") {

    //                }
                } else
                // если Event e Interval
                if (isType< event_interval_condition_t, condition_t>((condition_t*)rule->get_condition())) {
                    event_interval_condition_t* cond = (event_interval_condition_t*)rule->get_condition();

                    temporal_event_t* event = (temporal_event_t*)kf->get_event(cond->get_event_id());
                    temporal_interval_t* interval = (temporal_interval_t*)kf->get_interval(cond->get_interval_id());

                    condition_attr_value_const_t* condev = (condition_attr_value_const_t*)event->get_condition();
                    condition_attr_value_const_t* condbeg = (condition_attr_value_const_t*)interval->get_begin_condition_t();
                    condition_attr_value_const_t* condend = (condition_attr_value_const_t*)interval->get_end_condition_t();

                    if (cond->get_op() == "b") {
                        if ((condev->get_obj_id() == condbeg->get_obj_id()) &&
                                (condev->get_attr_id() == condbeg->get_attr_id()) &&
                                (condev->get_value() == condbeg->get_value())) {
                            res.push_back(rule);
                        }
                    } else if (cond->get_op() == "a") {
                        if ((condev->get_obj_id() == condend->get_obj_id()) &&
                                (condev->get_attr_id() == condend->get_attr_id()) &&
                                (condev->get_value() == condend->get_value())) {
                            res.push_back(rule);
                        }
                    } else if (cond->get_op() == "s") {
                        if ((condev->get_obj_id() == condbeg->get_obj_id()) &&
                                (condev->get_attr_id() == condbeg->get_attr_id()) &&
                                (condev->get_value() != condbeg->get_value())) {
                            res.push_back(rule);
                        }
                    } else if (cond->get_op() == "f") {
                        if ((condev->get_obj_id() == condend->get_obj_id()) &&
                                (condev->get_attr_id() == condend->get_attr_id()) &&
                                (condev->get_value() != condend->get_value())) {
                            res.push_back(rule);
                        }
                    }
                }
            }
            // если Event e Event

        }
    }
    //impossiblePositioning = res;
    return res;
};

std::vector<std::pair<const temporal_rule_t*, std::pair<const temporal_entity_t*, const temporal_entity_t*>>> verifier::verifyImpossiblePositioningII() {
    std::vector<std::pair<const temporal_rule_t*, std::pair<const temporal_entity_t*, const temporal_entity_t*>>> res;

    for (temporal_rule_t* rule: kf->getRules()) {
        if (rule->is_temporal()) {
            if (isType< complex_condition_t, condition_t>((condition_t*)rule->get_condition())) {
                complex_condition_t* ccond = (complex_condition_t*)rule->get_condition();
                for (int i = 0; i < ccond->get_number_of_conditions(); i++){
                    condition_t* cond_n = (condition_t*)ccond->get_condition(i);
                    if (isType< event_event_condition_t, condition_t>(cond_n)) {
                        event_event_condition_t* cond = (event_event_condition_t*)cond_n;

                        temporal_event_t* ev1 = (temporal_event_t*)kf->get_event(cond->get_left_event_id());
                        temporal_event_t* ev2 = (temporal_event_t*)kf->get_event(cond->get_right_event_id());
                        condition_attr_value_const_t* cond1 = (condition_attr_value_const_t*)ev1->get_condition();
                        condition_attr_value_const_t* cond2 = (condition_attr_value_const_t*)ev2->get_condition();
                        //
                        if (cond->get_op() == "e") {

                            if ((cond1->get_obj_id() == cond2->get_obj_id()) &&
                                    (cond1->get_attr_id() == cond2->get_attr_id()) &&
                                    (cond1->get_value() != cond2->get_value())) {
                                std::pair<const temporal_entity_t*, const temporal_entity_t*> ents (ev1,ev2);
                                std::pair<const temporal_rule_t*,std::pair<const temporal_entity_t*, const temporal_entity_t*>> prule (rule,ents);
                                res.push_back(prule);
                            }
                        }
                    } else
                    // если Event e Interval
                    if (isType< event_interval_condition_t, condition_t>((condition_t*)cond_n)) {
                        event_interval_condition_t* cond = (event_interval_condition_t*)cond_n;

                        temporal_event_t* event = (temporal_event_t*)kf->get_event(cond->get_event_id());
                        temporal_interval_t* interval = (temporal_interval_t*)kf->get_interval(cond->get_interval_id());

                        condition_attr_value_const_t* condev = (condition_attr_value_const_t*)event->get_condition();
                        condition_attr_value_const_t* condbeg = (condition_attr_value_const_t*)interval->get_begin_condition_t();
                        condition_attr_value_const_t* condend = (condition_attr_value_const_t*)interval->get_end_condition_t();

                        if (cond->get_op() == "b") {
                            if ((condev->get_obj_id() == condbeg->get_obj_id()) &&
                                    (condev->get_attr_id() == condbeg->get_attr_id()) &&
                                    (condev->get_value() == condbeg->get_value())) {
                                std::pair<const temporal_entity_t*, const temporal_entity_t*> ents (event,interval);
                                std::pair<const temporal_rule_t*,std::pair<const temporal_entity_t*, const temporal_entity_t*>> prule (rule,ents);
                                res.push_back(prule);
                            }
                        } else if (cond->get_op() == "a") {
                            if ((condev->get_obj_id() == condend->get_obj_id()) &&
                                    (condev->get_attr_id() == condend->get_attr_id()) &&
                                    (condev->get_value() == condend->get_value())) {
                                std::pair<const temporal_entity_t*, const temporal_entity_t*> ents (event,interval);
                                std::pair<const temporal_rule_t*,std::pair<const temporal_entity_t*, const temporal_entity_t*>> prule (rule,ents);
                                res.push_back(prule);
                            }
                        } else if (cond->get_op() == "s") {
                            if ((condev->get_obj_id() == condbeg->get_obj_id()) &&
                                    (condev->get_attr_id() == condbeg->get_attr_id()) &&
                                    (condev->get_value() != condbeg->get_value())) {
                                std::pair<const temporal_entity_t*, const temporal_entity_t*> ents (event,interval);
                                std::pair<const temporal_rule_t*,std::pair<const temporal_entity_t*, const temporal_entity_t*>> prule (rule,ents);
                                res.push_back(prule);
                            }
                        } else if (cond->get_op() == "f") {
                            if ((condev->get_obj_id() == condend->get_obj_id()) &&
                                    (condev->get_attr_id() == condend->get_attr_id()) &&
                                    (condev->get_value() != condend->get_value())) {
                                std::pair<const temporal_entity_t*, const temporal_entity_t*> ents (event,interval);
                                std::pair<const temporal_rule_t*,std::pair<const temporal_entity_t*, const temporal_entity_t*>> prule (rule,ents);
                                res.push_back(prule);
                            }
                        }
                    }
                }
            } else {
                if (isType< event_event_condition_t, condition_t>((condition_t*)rule->get_condition())) {
                    event_event_condition_t* cond = (event_event_condition_t*)rule->get_condition();

                    temporal_event_t* ev1 = (temporal_event_t*)kf->get_event(cond->get_left_event_id());
                    temporal_event_t* ev2 = (temporal_event_t*)kf->get_event(cond->get_right_event_id());
                    condition_attr_value_const_t* cond1 = (condition_attr_value_const_t*)ev1->get_condition();
                    condition_attr_value_const_t* cond2 = (condition_attr_value_const_t*)ev2->get_condition();
                    //
                    if (cond->get_op() == "e") {

                        if ((cond1->get_obj_id() == cond2->get_obj_id()) &&
                                (cond1->get_attr_id() == cond2->get_attr_id()) &&
                                (cond1->get_value() != cond2->get_value())) {
                            std::pair<const temporal_entity_t*, const temporal_entity_t*> ents (ev1,ev2);
                            std::pair<const temporal_rule_t*,std::pair<const temporal_entity_t*, const temporal_entity_t*>> prule (rule,ents);
                            res.push_back(prule);
                        }
                    }
    //                else if (cond->get_op() == "b") {

    //                }
                } else
                // если Event e Interval
                if (isType< event_interval_condition_t, condition_t>((condition_t*)rule->get_condition())) {
                    event_interval_condition_t* cond = (event_interval_condition_t*)rule->get_condition();

                    temporal_event_t* event = (temporal_event_t*)kf->get_event(cond->get_event_id());
                    temporal_interval_t* interval = (temporal_interval_t*)kf->get_interval(cond->get_interval_id());

                    condition_attr_value_const_t* condev = (condition_attr_value_const_t*)event->get_condition();
                    condition_attr_value_const_t* condbeg = (condition_attr_value_const_t*)interval->get_begin_condition_t();
                    condition_attr_value_const_t* condend = (condition_attr_value_const_t*)interval->get_end_condition_t();

                    if (cond->get_op() == "b") {
                        if ((condev->get_obj_id() == condbeg->get_obj_id()) &&
                                (condev->get_attr_id() == condbeg->get_attr_id()) &&
                                (condev->get_value() == condbeg->get_value())) {
                            std::pair<const temporal_entity_t*, const temporal_entity_t*> ents (event,interval);
                            std::pair<const temporal_rule_t*,std::pair<const temporal_entity_t*, const temporal_entity_t*>> prule (rule,ents);
                            res.push_back(prule);
                        }
                    } else if (cond->get_op() == "a") {
                        if ((condev->get_obj_id() == condend->get_obj_id()) &&
                                (condev->get_attr_id() == condend->get_attr_id()) &&
                                (condev->get_value() == condend->get_value())) {
                            std::pair<const temporal_entity_t*, const temporal_entity_t*> ents (event,interval);
                            std::pair<const temporal_rule_t*,std::pair<const temporal_entity_t*, const temporal_entity_t*>> prule (rule,ents);
                            res.push_back(prule);
                        }
                    } else if (cond->get_op() == "s") {
                        if ((condev->get_obj_id() == condbeg->get_obj_id()) &&
                                (condev->get_attr_id() == condbeg->get_attr_id()) &&
                                (condev->get_value() != condbeg->get_value())) {
                            std::pair<const temporal_entity_t*, const temporal_entity_t*> ents (event,interval);
                            std::pair<const temporal_rule_t*,std::pair<const temporal_entity_t*, const temporal_entity_t*>> prule (rule,ents);
                            res.push_back(prule);
                        }
                    } else if (cond->get_op() == "f") {
                        if ((condev->get_obj_id() == condend->get_obj_id()) &&
                                (condev->get_attr_id() == condend->get_attr_id()) &&
                                (condev->get_value() != condend->get_value())) {
                            std::pair<const temporal_entity_t*, const temporal_entity_t*> ents (event,interval);
                            std::pair<const temporal_rule_t*,std::pair<const temporal_entity_t*, const temporal_entity_t*>> prule (rule,ents);
                            res.push_back(prule);
                        }
                    }
                }
            }
            // если Event e Event

        }
    }
    impossiblePositioning = res;
    return res;
};


int verifier::true_values(condition_t* condition, knowledge_field_t* kf) {
    int obj,attr; // объект и атрибут, который используется в условии
    QString value,type_attr;
    std::set<string> values;
    int res = 0;
    if (isType<condition_attr_value_const_t, condition_t>(condition)) {
        if (condition == nullptr) {
            return 0;
        }
        // получаем объект и атрибут
        obj = dynamic_cast<condition_attr_value_const_t*>(condition)->get_obj_id();
        attr = dynamic_cast<condition_attr_value_const_t*>(condition)->get_attr_id();

        // получаем значение, которое используется в типе
        std::cout << "\t" << kf->get_object(obj)->get_attr_name_by_id(attr) << " ~ ";
        value = QString::fromStdString (dynamic_cast<condition_attr_value_const_t*>(condition)->get_value() );
        std::cout << value.toStdString() << "\n";
        // получаем тип атрибута
        type_attr = QString::fromStdString (kf->get_object(obj)->get_attr_type_by_id(attr) );
        std::cout << "\t" << type_attr.toStdString() << " ~ ";
        // получаем значения данного атрибута
        values = kf->get_type_values(type_attr.toStdString());
        for (string it : values) {
            std::cout << " " << it << " |";
        }
        std::cout << std::endl;
        //  проверка на совпадение
        if (values.find(value.toStdString()) == values.end()) {
            std::cout << "\tсовпадений не найдено!\n";
            //std::cout << it->get_name() << std::endl;
            res += 1;
        } /*else {
            //std::cout << "event_nope" << std::endl;
        }*/
    } else
        if (isType<complex_condition_t, condition_t>(condition))
    {
        for (int i = 0; i < dynamic_cast<complex_condition_t*>(condition)->get_number_of_conditions(); i++) {
            condition_t* cond = dynamic_cast<complex_condition_t*>(condition)->get_condition_t(i);
            res = res + true_values(cond,kf);
        }
    }
    return res;
};

vector<pair<QString, QString>> verifier::true_values_str(condition_t* condition, knowledge_field_t* kf) {
    int obj,attr; // объект и атрибут, который используется в условии
    QString value,type_attr;
    std::set<string> values;
    //int res = 0;

    vector<pair<QString, QString>> res;

    if (isType<condition_attr_value_const_t, condition_t>(condition)) {
        if (condition == nullptr) {
            return res;
        }
        // получаем объект и атрибут
        obj = dynamic_cast<condition_attr_value_const_t*>(condition)->get_obj_id();
        attr = dynamic_cast<condition_attr_value_const_t*>(condition)->get_attr_id();

        // получаем значение, которое используется в типе
        std::cout << "\t" << kf->get_object(obj)->get_attr_name_by_id(attr) << " ~ ";
        value = QString::fromStdString (dynamic_cast<condition_attr_value_const_t*>(condition)->get_value() );
        std::cout << value.toStdString() << "\n";

        // получаем тип атрибута
        type_attr = QString::fromStdString (kf->get_object(obj)->get_attr_type_by_id(attr) );
        std::cout << "\t" << type_attr.toStdString() << " ~ ";

        // получаем значения данного атрибута
        values = kf->get_type_values(type_attr.toStdString());
        for (string it : values) {
            std::cout << " " << it << " |";
        }

        std::cout << std::endl;
        //  проверка на совпадение
        if (values.find(value.toStdString()) == values.end()) {
            std::cout << "\tсовпадений не найдено!\n";
            //std::cout << it->get_name() << std::endl;
            pair<QString,QString> item (type_attr,value);
            res.insert(res.end(),item);
        }
    } else
        if (isType<complex_condition_t, condition_t>(condition))
    {
        for (int i = 0; i < dynamic_cast<complex_condition_t*>(condition)->get_number_of_conditions(); i++) {
            condition_t* cond = dynamic_cast<complex_condition_t*>(condition)->get_condition_t(i);
            vector<pair<QString, QString>> addit = true_values_str(cond,kf);
            res.insert(res.end(),addit.begin(),addit.end());
        }
    }
    return res;
};

std::set<temporal_entity_t*> verifier::verifyWrongAttributesValues() {

    std::cout << "\n**Поиск аномалии 'Неверные значения атрибутов'**\n";
    vector<string> types = kf->get_all_types();
    vector<temporal_event_t*> events = kf->getEvents();
    vector<temporal_interval_t*> intervals = kf->getIntervals();
    //string res;

    //int obj,attr;
    string value,type_attr;
    std::set<string> values;

    std::set<temporal_entity_t*> res;

    for (temporal_event_t* it : events) {
        condition_t* condition = it->get_condition_t();
        std::cout << it->get_name() << ": " << std::endl;
        if (true_values(condition, dynamic_cast<knowledge_field_t*>(kf)) > 0) {
            std::cout << it->get_name() << " отмечено как содержащее аномалию." << std::endl << std::endl;
            res.insert(it);
        }
    }

    for (temporal_interval_t* it : intervals) {
        std::cout << it->get_name() << ": " << std::endl;
        condition_t* condition = it->get_begin_condition_t();
        if (true_values(condition,dynamic_cast<knowledge_field_t*>(kf)) > 0) {
            std::cout << it->get_name() << " отмечено как содержащее аномалию." << std::endl << std::endl;
            res.insert(it);
        }
        condition = it->get_end_condition_t();
        if (true_values(condition,dynamic_cast<knowledge_field_t*>(kf)) > 0) {
            std::cout << it->get_name() << " отмечено как содержащее аномалию." << std::endl << std::endl;
            res.insert(it);
        }
        condition = it->get_duration_condition_t();
        if (true_values(condition,dynamic_cast<knowledge_field_t*>(kf)) > 0) {
            std::cout << it->get_name() << " отмечено как содержащее аномалию." << std::endl << std::endl;
            res.insert(it);
        }
    }
    return res;
}

bool verifier::arr_inter(std::vector<std::pair<int, std::string> > &v1, std::vector<std::pair<int, std::string> > &v2) {
    // да, если массивы пересекаются, иначе нет
    std::vector< std::pair<int,std::string>> inter;

    set_intersection(v1.begin(), v1.end(),
                     v2.begin(), v2.end(),
                     std::back_inserter(inter));
    if (inter.size() > 0)
        return true;
    else
        return false;
}

bool verifier::arr_diff(std::vector< std::pair<int,std::string>> &v1, std::vector< std::pair<int,std::string>> &v2) {
    std::vector< std::pair<int,std::string>> diff;
    set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(),
                   std::inserter(diff, diff.begin()));
    if (diff.size() > 0)
        return true;
    else
        return false;
}

bool arr_interII(std::vector<std::pair<std::pair<int,int>, std::string> > &v1, std::vector<std::pair<std::pair<int,int>, std::string> > &v2) {
    // да, если массивы пересекаются, иначе нет
    std::vector< std::pair<std::pair<int,int>,std::string>> inter;

    set_intersection(v1.begin(), v1.end(),
                     v2.begin(), v2.end(),
                     std::back_inserter(inter));
    if (inter.size() > 0)
        return true;
    else
        return false;
}

bool arr_diffII(std::vector< std::pair<std::pair<int,int>,std::string>> &v1, std::vector< std::pair<std::pair<int,int>,std::string>> &v2) {
    std::vector< std::pair<std::pair<int,int>,std::string>> diff;
    set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(),
                   std::inserter(diff, diff.begin()));
    if (diff.size() > 0)
        return true;
    else
        return false;
}

std::string verifier::verifyExcessiveRules() {
    std::cout << "\nПоиск избыточных правил." << std::endl;

    std::vector<
            std::pair<
            std::vector< std::pair<int,std::string> >, std::pair <int,std::string>
            >
            > res;

    std::vector<int> ids_rules;

    std::string ress = "";

    std::vector< std::pair<const temporal_rule_t*, const temporal_rule_t*> > res_rules;

    for (int i = 0; i < kf->get_number_of_rules(); i++) {

        std::vector< std::pair< int, std::string> > conds;

        temporal_rule_t* rule_t = (temporal_rule_t*)kf->get_rule(i);

        if (!rule_t->is_temporal()) {
            complex_condition_t* cond_i = static_cast<complex_condition_t*>(rule_t->get_condition_t());
            //std::cout << "\t" << rule_t->get_name() << " базовое!\n";
            int cond_num = cond_i->get_number_of_conditions();

            for (int j = 0; j < cond_num; j++) {
                condition_attr_value_const_t* cond_ij = static_cast<condition_attr_value_const_t*>(cond_i->get_condition_t(j));


                std::pair< int, std::string> p (cond_ij->get_attr_id(), cond_ij->get_value());

                conds.push_back( p );
            }
            const action_string_t* act = static_cast<const action_string_t*>(rule_t->get_action());
            //std::cout << "\tРезультат: " << act->get_obj_id() << "." << act->get_attr_id() << " " <<
            // act->get_op() << " " << act->get_value() << std::endl;

            std::pair<int, std::string> acts (act->get_attr_id(), act->get_value());
            std::pair< std::vector< std::pair< int, std::string> >, std::pair<int, std::string> > r (conds, acts);

            ids_rules.push_back(i);
            res.push_back(r);
        }
        //std::cout << "QUACK! Next!" << std::endl;
    }
    //std::cout << "QUACK! Всего " << res.size() << " правила." << std::endl;

    for (int i = 0; i < (int)res.size() - 1; i++) {
        //std::cout << "HI! i = "<< i <<std::endl ;
        for (int j = i + 1; j < (int)res.size(); j++) {
            //std::cout << "\tHI! j = "<< j << std::endl;
            if (
                    std::get<1>(res[i]) == std::get<1>(res[j]) &&
                    arr_inter(std::get<0>(res[i]), std::get<0>(res[j])) &&
                    !(
                        arr_diff(std::get<0>(res[i]), std::get<0>(res[j])) &&
                        arr_diff(std::get<0>(res[j]), std::get<0>(res[i])) )
                    )
            {
                std::cout << "Правила " << i+1 << " и " << j+1 << " избыточны.\n";
                ress += "\tПравила " + std::to_string(i+1)+ " и " + std::to_string(j+1) + " избыточны.\n";
                std::pair< const temporal_rule_t*, const temporal_rule_t*> st (kf->get_rule(ids_rules[i]),kf->get_rule(ids_rules[j]));
                res_rules.push_back(st);
            }
            else
                std::cout << "Правила " << i+1 << " и " << j+1 << " не являются избыточными.\n";

        }
    }

    for (std::pair<const temporal_rule_t*, const temporal_rule_t*> st : res_rules) {
        std::cout << "Следующие правила избыточны:" << std::endl;
        std::cout << std::get<0>(st)->to_string(*kf) << std::endl;
        std::cout << std::get<1>(st)->to_string(*kf) << std::endl;
    }

    //return res_rules;
    if (ress.length() > 0){
        return ress;
    } else {
        return "Не найдено\n";
    }

}

std::vector<std::pair<const temporal_rule_t*, const temporal_rule_t*>> verifier::verifyPairsExcessiveRules() {
//std::string verifier::verifyExcessiveRules() {
    std::cout << "\nПоиск избыточных правил." << std::endl;

    std::vector<
            std::pair<
            std::vector< std::pair<int,std::string> >, std::pair <int,std::string>
            >
            > res;

    std::vector<int> ids_rules;

    //std::string ress = "";

    std::vector<std::pair<const temporal_rule_t*, const temporal_rule_t*> > res_rules;

    for (int i = 0; i < kf->get_number_of_rules(); i++) {

        std::vector< std::pair< int, std::string> > conds;

        temporal_rule_t* rule_t = (temporal_rule_t*)kf->get_rule(i);

        if (!rule_t->is_temporal()) {
            complex_condition_t* cond_i = static_cast<complex_condition_t*>(rule_t->get_condition_t());
            //std::cout << "\t" << rule_t->get_name() << " базовое!\n";
            int cond_num = cond_i->get_number_of_conditions();

            for (int j = 0; j < cond_num; j++) {
                condition_attr_value_const_t* cond_ij = static_cast<condition_attr_value_const_t*>(cond_i->get_condition_t(j));


                std::pair< int, std::string> p (cond_ij->get_attr_id(), cond_ij->get_value());

                conds.push_back( p );
            }
            const action_string_t* act = static_cast<const action_string_t*>(rule_t->get_action());
            //std::cout << "\tРезультат: " << act->get_obj_id() << "." << act->get_attr_id() << " " <<
            // act->get_op() << " " << act->get_value() << std::endl;

            std::pair<int, std::string> acts (act->get_attr_id(), act->get_value());
            std::pair< std::vector< std::pair< int, std::string> >, std::pair<int, std::string> > r (conds, acts);

            ids_rules.push_back(i);
            res.push_back(r);
        }
        //std::cout << "QUACK! Next!" << std::endl;
    }
    //std::cout << "QUACK! Всего " << res.size() << " правила." << std::endl;

    for (int i = 0; i < (int)res.size() - 1; i++) {
        //std::cout << "HI! i = "<< i <<std::endl ;
        for (int j = i + 1; j < (int)res.size(); j++) {
            //std::cout << "\tHI! j = "<< j << std::endl;
            if (
                    std::get<1>(res[i]) == std::get<1>(res[j]) &&
                    arr_inter(std::get<0>(res[i]), std::get<0>(res[j])) &&
                    !(
                        arr_diff(std::get<0>(res[i]), std::get<0>(res[j])) &&
                        arr_diff(std::get<0>(res[j]), std::get<0>(res[i])) )
                    )
            {
                std::cout << "Правила " << i+1 << " и " << j+1 << " избыточны.\n";
                //ress += "\tПравила " + std::to_string(i+1)+ " и " + std::to_string(j+1) + " избыточны.\n";
                std::pair< const temporal_rule_t*, const temporal_rule_t*> st (kf->get_rule(ids_rules[i]),kf->get_rule(ids_rules[j]));
                res_rules.push_back(st);
            }
            else
                std::cout << "Правила " << i+1 << " и " << j+1 << " не являются избыточными.\n";

        }
    }

    for (std::pair<const temporal_rule_t*, const temporal_rule_t*> st : res_rules) {
        std::cout << "Следующие правила избыточны:" << std::endl;
        std::cout << std::get<0>(st)->to_string(*kf) << std::endl;
        std::cout << std::get<1>(st)->to_string(*kf) << std::endl;
    }

    return res_rules;
//    if (ress.length() > 0){
//        return ress;
//    } else {
//        return "Не найдено\n";
//    }

}

std::vector<std::pair<const temporal_rule_t*, const temporal_rule_t*>> verifier::verifyPairsExcessiveRulesII() {
//std::string verifier::verifyExcessiveRules() {
    std::cout << "\nПоиск избыточных правил." << std::endl;

    // вектор пар формата <[<<об,атр>,знач>], <<об,атр>,знач >
    std::vector<
            std::pair<
            std::vector<
                    std::pair<std::pair<int,int>,string>
                 >, std::pair<std::pair<int,int>,std::string>
            >
            > res;

    std::vector<int> ids_rules;

    //std::string ress = "";

    std::vector<std::pair<const temporal_rule_t*, const temporal_rule_t*> > res_rules;

    // рассмотрим все правила по порядку
    for (int i = 0; i < kf->get_number_of_rules(); i++) {

        temporal_rule_t* rule_t = (temporal_rule_t*)kf->get_rule(i);
        // если правиило базовое
        if (!rule_t->is_temporal()) {
            // условие в формате об,атр,знач
            std::vector < std::pair< std::pair<int,int>, string > > conds;
            // берем условие
            complex_condition_t* cond_i = (complex_condition_t*)rule_t->get_condition_t();
            int cond_num = cond_i->get_number_of_conditions();
            // проходимся по каждому условию
            for (int j = 0; j < cond_num; j++) {
                // условие j правила i
                condition_attr_value_const_t* cond_ij = (condition_attr_value_const_t*)cond_i->get_condition_t(j);
                std::pair<int,int> p_attr (cond_ij->get_obj_id(), cond_ij->get_attr_id());
                std::pair< std::pair<int,int>, std::string> p (p_attr, cond_ij->get_value());
                // добавляем в вектор условий
                conds.push_back( p );
            }
            // берем действие
            const action_string_t* act = static_cast<const action_string_t*>(rule_t->get_action());

            std::pair<int,int> act_attr (act->get_obj_id(),act->get_attr_id());

            std::pair< std::pair<int,int>, std::string> acts (act_attr, act->get_value());
            std::pair< std::vector<std::pair<std::pair<int,int>,string> >, std::pair<std::pair<int,int>,std::string> > r (conds, acts);

            ids_rules.push_back(i);
            res.push_back(r);
        }
        //std::cout << "QUACK! Next!" << std::endl;
    }
    //std::cout << "QUACK! Всего " << res.size() << " правила." << std::endl;
    // таким образом для каждого правила составляем пары <условия, действие>
    for (int i = 0; i < (int)res.size() - 1; i++) {
        //std::cout << "HI! i = "<< i <<std::endl ;
        for (int j = i + 1; j < (int)res.size(); j++) {
            //std::cout << "\tHI! j = "<< j << std::endl;
            if (
                    std::get<1>(res[i]) == std::get<1>(res[j]) &&
                    arr_interII(std::get<0>(res[i]), std::get<0>(res[j])) &&
                    !(
                        arr_diffII(std::get<0>(res[i]), std::get<0>(res[j])) &&
                        arr_diffII(std::get<0>(res[j]), std::get<0>(res[i])) )
                    )
            {
                std::cout << "Правила " << i+1 << " и " << j+1 << " избыточны.\n";
                //ress += "\tПравила " + std::to_string(i+1)+ " и " + std::to_string(j+1) + " избыточны.\n";
                std::pair< const temporal_rule_t*, const temporal_rule_t*> st (kf->get_rule(ids_rules[i]),kf->get_rule(ids_rules[j]));
                res_rules.push_back(st);
            }
            else
                std::cout << "Правила " << i+1 << " и " << j+1 << " не являются избыточными.\n";

        }
    }

    for (std::pair<const temporal_rule_t*, const temporal_rule_t*> st : res_rules) {
        std::cout << "Следующие правила избыточны:" << std::endl;
        std::cout << std::get<0>(st)->to_string(*kf) << std::endl;
        std::cout << std::get<1>(st)->to_string(*kf) << std::endl;
    }

    excessiveRules = res_rules;
    return res_rules;
//    if (ress.length() > 0){
//        return ress;
//    } else {
//        return "Не найдено\n";
//    }

}


//std::vector< std::pair<temporal_rule_t*, temporal_rule_t*>> verifier::verifyIntersecionRules() {
std::string verifier::verifyIntersecionRules() {
    std::cout << "Поиск пересекающихся правил." << std::endl;

    std::vector<
            std::pair<
            std::vector< std::pair<int,std::string> >, std::pair <int,std::string>
            >
            > res;

    std::string ress = "";

    std::vector< std::pair<temporal_rule_t*, temporal_rule_t*> > res_rules;

    for (int i = 0; i < kf->get_number_of_rules(); i++) {

        std::vector< std::pair< int, std::string> > conds;

        complex_condition_t* cond_i = static_cast<complex_condition_t*>(kf->getRules()[i]->get_condition_t());

        int cond_num = cond_i->get_number_of_conditions();

        for (int j = 0; j < cond_num; j++) {
            condition_attr_value_const_t* cond_ij = static_cast<condition_attr_value_const_t*>(cond_i->get_condition_t(j));
            //std::cout << "\t";
            // std::cout << cond_ij->get_obj_id() << "." << cond_ij->get_attr_id() << " " <<
            // cond_ij->get_op() << " " << cond_ij->get_value() << std::endl;

            std::pair<
                    int, std::string> p (cond_ij->get_attr_id(), cond_ij->get_value());

            conds.push_back( p );

        }

        const action_string_t* act = static_cast<const action_string_t*>(kf->getRules()[i]->get_action());
        //std::cout << "\tРезультат: " << act->get_obj_id() << "." << act->get_attr_id() << " " <<
        // act->get_op() << " " << act->get_value() << std::endl;

        std::pair<int, std::string> acts (act->get_attr_id(), act->get_value());
        std::pair< std::vector< std::pair< int, std::string> >, std::pair<int, std::string> > r (conds, acts);

        res.push_back(r);

        //std::cout << "QUACK! Next!" << std::endl;

    }

    //std::cout << "QUACK! Всего " << res.size() << " правила." << std::endl;

    for (int i = 0; i < (int)res.size() - 1; i++) {
        //std::cout << "HI! i = "<< i <<std::endl ;
        for (int j = i + 1; j < (int)res.size(); j++) {
            //std::cout << "\tHI! j = "<< j << std::endl;
            if (
                    (std::get<1>(res[i]) == std::get<1>(res[j]) && !(arr_inter(std::get<0>(res[i]), std::get<0>(res[j]))))
                    ||
                    ( std::get<1>(res[i]) != std::get<1>(res[j]) &&
                      arr_inter(std::get<0>(res[i]), std::get<0>(res[j])) &&
                      !(
                          arr_diff(std::get<0>(res[i]), std::get<0>(res[j])) &&
                          arr_diff(std::get<0>(res[j]), std::get<0>(res[i])) ) )
                    )
            {
                std::cout << "Правила " << i+1 << " и " << j+1 << " пересекаются.\n";
                ress += "\tПравила " + std::to_string(i+1) + " и " + std::to_string(j+1) + " пересекаются.\n";
                std::pair<temporal_rule_t*, temporal_rule_t*> st (kf->getRules()[i],kf->getRules()[j]);
                res_rules.push_back(st);
            }
            else
                std::cout << "Правила " << i+1 << " и " << j+1 << " не являются пересекающимися.\n";

        }
    }

    for (std::pair<temporal_rule_t*, temporal_rule_t*> st : res_rules) {
        std::cout << "Следующие правила пересекаются:" << std::endl;
        std::cout << std::get<0>(st)->to_string(*kf) << std::endl;
        std::cout << std::get<1>(st)->to_string(*kf) << std::endl;
        std::cout << std::endl;
    }

    //return res_rules;
    if (ress.length() > 0){
        return ress;
    } else {
        return "не найдено\n";
        //return "Не нвйдено";
    }
}

std::vector< std::pair<const temporal_rule_t*, const temporal_rule_t*>> verifier::verifyPairsIntersecionRules() {
//std::string verifier::verifyIntersecionRules() {
    std::cout << "Поиск пересекающихся правил." << std::endl;

    std::vector<
            std::pair<
            std::vector< std::pair<int,std::string> >, std::pair <int,std::string>
            >
            > res;

    std::string ress = "";

    std::vector< std::pair<const temporal_rule_t*,const temporal_rule_t*> > res_rules;

    for (int i = 0; i < kf->get_number_of_rules(); i++) {

        std::vector< std::pair< int, std::string> > conds;

        complex_condition_t* cond_i = static_cast<complex_condition_t*>(kf->getRules()[i]->get_condition_t());

        int cond_num = cond_i->get_number_of_conditions();

        for (int j = 0; j < cond_num; j++) {
            condition_attr_value_const_t* cond_ij = static_cast<condition_attr_value_const_t*>(cond_i->get_condition_t(j));
            //std::cout << "\t";
            // std::cout << cond_ij->get_obj_id() << "." << cond_ij->get_attr_id() << " " <<
            // cond_ij->get_op() << " " << cond_ij->get_value() << std::endl;

            std::pair<
                    int, std::string> p (cond_ij->get_attr_id(), cond_ij->get_value());

            conds.push_back( p );

        }

        const action_string_t* act = static_cast<const action_string_t*>(kf->getRules()[i]->get_action());
        //std::cout << "\tРезультат: " << act->get_obj_id() << "." << act->get_attr_id() << " " <<
        // act->get_op() << " " << act->get_value() << std::endl;

        std::pair<int, std::string> acts (act->get_attr_id(), act->get_value());
        std::pair< std::vector< std::pair< int, std::string> >, std::pair<int, std::string> > r (conds, acts);

        res.push_back(r);

        //std::cout << "QUACK! Next!" << std::endl;

    }

    //std::cout << "QUACK! Всего " << res.size() << " правила." << std::endl;

    for (int i = 0; i < (int)res.size() - 1; i++) {
        //std::cout << "HI! i = "<< i <<std::endl ;
        for (int j = i + 1; j < (int)res.size(); j++) {
            //std::cout << "\tHI! j = "<< j << std::endl;
            if (
                    (std::get<1>(res[i]) == std::get<1>(res[j]) && !(arr_inter(std::get<0>(res[i]), std::get<0>(res[j]))))
                    ||
                    ( std::get<1>(res[i]) != std::get<1>(res[j]) &&
                      arr_inter(std::get<0>(res[i]), std::get<0>(res[j])) &&
                      !(
                          arr_diff(std::get<0>(res[i]), std::get<0>(res[j])) &&
                          arr_diff(std::get<0>(res[j]), std::get<0>(res[i])) ) )
                    )
            {
                std::cout << "Правила " << i+1 << " и " << j+1 << " пересекаются.\n";
                ress += "\tПравила " + std::to_string(i+1) + " и " + std::to_string(j+1) + " пересекаются.\n";
                std::pair<temporal_rule_t*, temporal_rule_t*> st (kf->getRules()[i],kf->getRules()[j]);
                res_rules.push_back(st);
            }
            else
                std::cout << "Правила " << i+1 << " и " << j+1 << " не являются пересекающимися.\n";

        }
    }

    for (std::pair<const temporal_rule_t*, const temporal_rule_t*> st : res_rules) {
        std::cout << "Следующие правила пересекаются:" << std::endl;
        std::cout << std::get<0>(st)->to_string(*kf) << std::endl;
        std::cout << std::get<1>(st)->to_string(*kf) << std::endl;
        std::cout << std::endl;
    }

    intersectionRules = res_rules;
    return res_rules;
//    if (ress.length() > 0){
//        return ress;
//    } else {
//        return "Не нвйдено";
//    }
}

std::vector< std::pair<const temporal_rule_t*, const temporal_rule_t*>> verifier::verifyPairsIntersecionRulesII() {

    std::cout << "Поиск пересекающихся правил." << std::endl;
    // вектор пар формата <[<<об,атр>,знач>], <<об,атр>,знач >
        std::vector<
                std::pair<
                std::vector<
                        std::pair<std::pair<int,int>,string>
                     >, std::pair<std::pair<int,int>,std::string>
                >
                > res;

        std::vector<int> ids_rules;

        //std::string ress = "";

        std::vector<std::pair<const temporal_rule_t*, const temporal_rule_t*> > res_rules;

        // рассмотрим все правила по порядку
        for (int i = 0; i < kf->get_number_of_rules(); i++) {

            temporal_rule_t* rule_t = (temporal_rule_t*)kf->get_rule(i);
            // если правиило базовое
            if (!rule_t->is_temporal()) {
                // условие в формате об,атр,знач
                std::vector < std::pair< std::pair<int,int>, string > > conds;
                // берем условие
                complex_condition_t* cond_i = (complex_condition_t*)rule_t->get_condition_t();
                int cond_num = cond_i->get_number_of_conditions();
                // проходимся по каждому условию
                for (int j = 0; j < cond_num; j++) {
                    // условие j правила i
                    condition_attr_value_const_t* cond_ij = (condition_attr_value_const_t*)cond_i->get_condition_t(j);
                    std::pair<int,int> p_attr (cond_ij->get_obj_id(), cond_ij->get_attr_id());
                    std::pair< std::pair<int,int>, std::string> p (p_attr, cond_ij->get_value());
                    // добавляем в вектор условий
                    conds.push_back( p );
                }
                // берем действие
                const action_string_t* act = static_cast<const action_string_t*>(rule_t->get_action());

                std::pair<int,int> act_attr (act->get_obj_id(),act->get_attr_id());

                std::pair< std::pair<int,int>, std::string> acts (act_attr, act->get_value());
                std::pair< std::vector<std::pair<std::pair<int,int>,string> >, std::pair<std::pair<int,int>,std::string> > r (conds, acts);

                ids_rules.push_back(i);
                res.push_back(r);
            }
            //std::cout << "QUACK! Next!" << std::endl;
        }
        //std::cout << "QUACK! Всего " << res.size() << " правила." << std::endl;
        // таким образом для каждого правила составляем пары <условия, действие>
        for (int i = 0; i < (int)res.size() - 1; i++) {
            for (int j = i + 1; j < (int)res.size(); j++) {
                if (
                        (std::get<1>(res[i]) == std::get<1>(res[j]) && !(arr_interII(std::get<0>(res[i]), std::get<0>(res[j]))))
                        ||
                        ( std::get<1>(res[i]) != std::get<1>(res[j]) &&
                          arr_interII(std::get<0>(res[i]), std::get<0>(res[j])) &&
                          !(
                              arr_diffII(std::get<0>(res[i]), std::get<0>(res[j])) &&
                              arr_diffII(std::get<0>(res[j]), std::get<0>(res[i])) ) )
                        )
                {
                    std::cout << "Правила " << i+1 << " и " << j+1 << " пересекаются.\n";
                    std::pair<const temporal_rule_t*, const temporal_rule_t*> st (kf->get_rule(ids_rules[i]),kf->get_rule(ids_rules[j]));
                    res_rules.push_back(st);
                }
                else
                    std::cout << "Правила " << i+1 << " и " << j+1 << " не являются пересекающимися.\n";

            }
        }

        for (std::pair<const temporal_rule_t*, const temporal_rule_t*> st : res_rules) {
            std::cout << "Следующие правила пересекаются:" << std::endl;
            std::cout << std::get<0>(st)->to_string(*kf) << std::endl;
            std::cout << std::get<1>(st)->to_string(*kf) << std::endl;
        }

        intersectionRules = res_rules;
        return res_rules;
    //    if (ress.length() > 0){
    //        return ress;
    //    } else {
    //        return "Не найдено\n";
    //    }
}


std::string verifier::getBZXml()
{
    return kf->to_xml();
}

void verifier::writeToFile(QString filename)
{
//    std::ofstream ofs;
//    ofs.open("", std::ofstream::out | std::ofstream::trunc);("=");
//    ofs << ;
//    string  kf_d = rewrite_txt_for_pz(kf_new);
//    ofs.close();

    QFile file(filename);
        // Trying to open in WriteOnly and Text mode
        if(!file.open(QFile::WriteOnly |
                      QFile::Text))
        {
            qDebug() << " Could not open file for writing";
            return;
        }

        // To write text, we use operator<<(),
        // which is overloaded to take
        // a QTextStream on the left
        // and data types (including QString) on the right

        QTextStream out(&file);

        QString a = QString::fromStdString(getBZXml());
//        QString result = rewrite_txt_for_pz_1(a);

//        out << result;

//        //
        out << QString::fromStdString(getBZXml());
        file.flush();
        file.close();

}

knowledge_field_t* verifier::readFromFile(QString filename) {

    knowledge_field_t* kf_t = new knowledge_field_t();

    QDomDocument document;
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        std::cout << "Failed to open the file for reading."<< '\n';
        return nullptr;
    }
    else
    {
        // loading
        if(!document.setContent(&file))
        {
            std::cout << "Failed to load the file for reading."<< '\n';
            return nullptr;
        }
        file.close();
    }
    //std::cout << "QUACK! I'M ALIVE!\n";
    QDomElement root = document.firstChildElement();
    QDomNodeList types = root.elementsByTagName("types");
    for(int i = 0; i < types.count(); i++)
    {
        QDomNode nodtypes = types.at(i);
        QDomElement type = nodtypes.toElement();
        QDomNodeList litype = root.elementsByTagName("type");
        for(int i = 0; i < litype.count(); i++)
        {
        QDomNode nodtype = litype.at(i);
        if(nodtype.isElement())
        {
            QDomElement type = nodtype.toElement();
            readTypeFromFile(type, kf_t);
        }
            //std::cout << '\t' << e.attribute(att).toStdString() << '\n';
        }
    }
    std::cout << '\n';
    std::cout << kf_t->types_to_string();
    std::cout << '\n';
    QDomNodeList objects = root.elementsByTagName("classes");
    QDomNodeList liobject;
    for(int i = 0; i < objects.count(); i++)
    {
        QDomNode nodobjects = objects.at(i);
        QDomElement object = nodobjects.toElement();
        liobject = object.elementsByTagName("class");
        for(int i = 0; i < liobject.count(); i++)
        {
        QDomNode nodobject = liobject.at(i);
        if(nodobject.isElement())
        {
            QDomElement object = nodobject.toElement();
            readObjectFromFile(object, kf_t);
        }
            //std::cout << '\t' << e.attribute(att).toStdString() << '\n';
        }
    }
    std::cout << '\n';
    std::cout << kf_t->objects_to_string();
    std::cout << '\n';

    QDomNodeList events = root.elementsByTagName("IntervalsAndEvents").at(0).toElement().elementsByTagName("Events");
    //std::cout << "\tQUACK! events num is " << events.count();
    QDomNodeList lievent = events.at(0).toElement().elementsByTagName("Event");
    //std::cout << "\tQUACK! event num is " << lievent.count();
    for(int i = 0; i < lievent.count(); i++)
    {
        QDomNode nodevent = lievent.at(i);
        if(nodevent.isElement())
        {
            QDomElement event = nodevent.toElement();
            readEventFromFile(event, kf_t);
        }
        //std::cout << '\t' << e.attribute(att).toStdString() << '\n';
    }
    std::cout << '\n';
    std::cout << kf_t->events_to_string();
    std::cout << '\n';

    QDomNodeList intervals = root.elementsByTagName("IntervalsAndEvents").at(0).toElement().elementsByTagName("Intervals");
    //std::cout << "\tQUACK! events num is " << events.count();
    QDomNodeList liinterval = intervals.at(0).toElement().elementsByTagName("Interval");
    //std::cout << "\tQUACK! event num is " << lievent.count();
    for(int i = 0; i < liinterval.count(); i++)
    {
        QDomNode nodinterval = liinterval.at(i);
        if(nodinterval.isElement())
        {
            QDomElement interval = nodinterval.toElement();
            readIntervalFromFile(interval,kf_t);
        }
        //std::cout << '\t' << e.attribute(att).toStdString() << '\n';
    }
    std::cout << '\n';
    std::cout << kf_t->intervals_to_string();
    std::cout << '\n';

    QDomNodeList rules = liobject.at(liobject.count()-1).toElement().elementsByTagName("rules");
    QDomNodeList lirule = rules.at(0).toElement().elementsByTagName("rule");
    for(int i = 0; i < lirule.count(); i++)
    {
        QDomNode nodrule = lirule.at(i);
        if(nodrule.isElement())
        {
            QDomElement rule = nodrule.toElement();
            readRuleFromFile(rule,kf_t);
        }
        //std::cout << '\t' << e.attribute(att).toStdString() << '\n';
    }
    std::cout << '\n';
    //std::cout << kf_t->rules_to_string();
    //std::cout << '\n';
    file.close();
    return kf_t;
}

void verifier::readTypeFromFile(QDomElement type, knowledge_field_t* kf) {
    std::cout << "QUACK! Тип:\t";
    std::cout << type.attribute("id").toStdString() << '\n';
    std::cout << type.attribute("meta").toStdString() << '\n';
    if ((type.attribute("meta") == "string") or (type.attribute("meta") == "fuzzy")) {
        kf->add_type(type.attribute("id").toStdString());

        QDomNodeList values = type.elementsByTagName("value");
        for(int i = 0; i < values.count(); i++) {
            QDomNode nodvalue = values.at(i);
            if(nodvalue.isElement())
            {
                std::cout << '\t' << nodvalue.toElement().text().toStdString() << '\n';
                kf->add_type_value(type.attribute("id").toStdString(),nodvalue.toElement().text().toStdString());
            }
        }
    } else {
        QDomNodeList values = type.elementsByTagName("from");
        QDomNode nodvalue = values.at(0);
        std::cout << '\t' << nodvalue.toElement().text().toStdString() << '\n';
        values = type.elementsByTagName("to");
        nodvalue = values.at(0);
        std::cout << '\t' << nodvalue.toElement().text().toStdString() << '\n';
    }
}

void verifier::readObjectFromFile(QDomElement object, knowledge_field_t* kf) {
    std::cout << "QUACK! Объект\t";
    std::cout << object.attribute("id").toStdString() << '\t';
    std::cout << object.attribute("desc").toStdString() << '\n';

    if (object.attribute("id") != "world") {
        const temporal_object_t* object_t = (temporal_object_t*)kf->add_object(object.attribute("id").toStdString());
        QDomNodeList properties = object.elementsByTagName("properties");
        QDomNode nodproperty = properties.at(0);
        QDomNodeList liproperty = nodproperty.toElement().elementsByTagName("property");
        for(int i = 0; i < liproperty.count(); i++) {
            QDomNode nodproperty = liproperty.at(i);
            if(nodproperty.isElement())
            {
                std::cout << '\t' << nodproperty.toElement().attribute("id").toStdString();
                std::cout << '\t' << nodproperty.toElement().attribute("type").toStdString();
                std::cout << '\t' << nodproperty.toElement().attribute("desc").toStdString() << '\n';

                kf->add_attr(object_t,nodproperty.toElement().attribute("id").toStdString(),nodproperty.toElement().attribute("type").toStdString());
            }
        }
    } else {
        // конкретные объекты одного определенного класса объектов
        QDomNodeList properties = object.elementsByTagName("properties");
        QDomNode nodproperty = properties.at(0);
        QDomNodeList liproperty = nodproperty.toElement().elementsByTagName("property");
        for(int i = 0; i < liproperty.count(); i++) {
            // конкретный объект одного определенного класса объектов
            QDomNode nodproperty = liproperty.at(i);
            if(nodproperty.isElement())
            {
                if (nodproperty.toElement().attribute("id").toStdString() != nodproperty.toElement().attribute("type").toStdString()) {
                    temporal_object_t* object_t1 = (temporal_object_t*)kf->add_object(nodproperty.toElement().attribute("id").toStdString());
                    std::cout << '\t' << nodproperty.toElement().attribute("id").toStdString();

                    temporal_object_t* object_t2 = (temporal_object_t*)kf->get_object(nodproperty.toElement().attribute("type").toStdString());
                    std::cout << '\t' << nodproperty.toElement().attribute("type").toStdString();

                    std::cout << '\t' << nodproperty.toElement().attribute("desc").toStdString() << '\n';

                    int num_of_attrs = object_t2->get_number_of_attrs();
                    for (int j = 0; j < num_of_attrs; ++j) {
                        string str_attr = object_t2->get_attr_name_by_id(j);
                        string str_type = object_t2->get_attr_type_by_id(j);
                        std::cout << "\t\t" << str_attr << "\t" << str_type << "\n";

                        kf->add_attr(object_t1,str_attr,str_type);
                    }
                }
                //std::cout << "\n";
                //kf->add_attr(object_t,nodproperty.toElement().attribute("id").toStdString(),nodproperty.toElement().attribute("type").toStdString());
            }
        }

    }


}

void readCondFromFile(QDomNode condition, knowledge_field_t* kf,temporal_rule_t* rule_t, condition_t* old_cond=nullptr) {
    string res = "";
    QDomNodeList childe_conds = condition.childNodes();
    //std::cout << "\tQUACK! childe conds num is " << childe_conds.count() << '\n';
    //res = "\tQUACK! childe conds num is " + childe_conds.count();

    for (int i = 0; i < childe_conds.count(); i++) {
        // если это комплексное условие
        if (childe_conds.at(i).toElement().tagName() == "and") {
            if (old_cond == nullptr){
                complex_condition_t* cond_t = new complex_condition_t();
                cond_t->set_op("&");
                readCondFromFile(childe_conds.at(i),kf,rule_t,cond_t);
                kf->add_condition(rule_t,cond_t);
            } else {
                readCondFromFile(childe_conds.at(i),kf,rule_t,old_cond);
            }
        }
        else if (childe_conds.at(i).toElement().tagName() == "eq") {
            // условие вида об.атр = знач
            condition_attr_value_const_t* cond_t = new condition_attr_value_const_t();
            cond_t->set_op("=");

            QDomNode eq_cond = childe_conds.at(i);
            QDomNodeList refs = eq_cond.toElement().elementsByTagName("ref");
            std::cout << refs.at(0).toElement().attribute("id").toStdString() << "." << refs.at(1).toElement().attribute("id").toStdString();
            res = refs.at(0).toElement().attribute("id").toStdString() + "." + refs.at(1).toElement().attribute("id").toStdString();

            const temporal_object_t* object_t = kf->get_object(refs.at(0).toElement().attribute("id").toStdString());
            int object_id = kf->get_object_id_by_name(refs.at(0).toElement().attribute("id").toStdString());
            int attr_id = object_t->get_attr_id_by_name(refs.at(1).toElement().attribute("id").toStdString());

            cond_t->set_obj_id(object_id);
            cond_t->set_attr_id(attr_id);

            QDomNodeList values = eq_cond.toElement().elementsByTagName("value");
            //std::cout << "\tQUACK!values num is " << values.count();
            std::cout << "=" << values.at(0).toElement().text().toStdString() << "\n\t";

            cond_t->set_value(values.at(0).toElement().text().toStdString());

            if (old_cond == nullptr) {
                complex_condition_t* res_cond = new complex_condition_t();
                res_cond->set_op("&");
                res_cond->add_condition(cond_t);
                kf->add_condition(rule_t,res_cond);
            } else {
                static_cast<complex_condition_t*>(old_cond)->add_condition(cond_t);
            }

        } else if (childe_conds.at(i).toElement().tagName() == "CondEvRel") {
            // условие вида (об.атр = знач) d Событие
            QDomNode CondEvRel_cond = childe_conds.at(i);

            condition_attr_value_const_t* eq_cond_t = new condition_attr_value_const_t();
            eq_cond_t->set_op("=");

            QDomNode eq_cond = CondEvRel_cond.toElement().elementsByTagName("eq").at(0);
            QDomNodeList refs = eq_cond.toElement().elementsByTagName("ref");
            if (refs.size() == 0) {
                std::cout << "QUACK! ПУСТО!\n";
            } else {
                std::cout << refs.at(0).toElement().attribute("id").toStdString() << "." << refs.at(1).toElement().attribute("id").toStdString();
            }
            const temporal_object_t* object_t = kf->get_object(refs.at(0).toElement().attribute("id").toStdString());
            int object_id = kf->get_object_id_by_name(refs.at(0).toElement().attribute("id").toStdString());
            int attr_id = object_t->get_attr_id_by_name(refs.at(1).toElement().attribute("id").toStdString());

            eq_cond_t->set_obj_id(object_id);
            eq_cond_t->set_attr_id(attr_id);

            QDomNodeList values = eq_cond.toElement().elementsByTagName("value");
            std::cout << "=" << values.at(0).toElement().text().toStdString() << " ";
            std::cout << CondEvRel_cond.toElement().attribute("Value").toStdString() << " ";

            eq_cond_t->set_value(values.at(0).toElement().text().toStdString());

            QDomNode event = CondEvRel_cond.toElement().elementsByTagName("Event").at(0);
            std::cout << event.toElement().attribute("Name").toStdString() << "\n\t";

            int event_id = kf->get_event_id_by_name(event.toElement().attribute("Name").toStdString());

            if (event_id < 0) {
                std::cout << "QUACK! Event " << event.toElement().attribute("Name").toStdString() << " is not found.\n";
                event_id = 0;
            }

            temporal_event_t* event_t = (temporal_event_t*)kf->get_event(event_id);
            temporal_condition_operation_condition* cond_t = new temporal_condition_operation_condition(eq_cond_t,event_t);
            cond_t->set_op(CondEvRel_cond.toElement().attribute("Value").toStdString());

            if (old_cond == nullptr) {
                complex_condition_t* res_cond = new complex_condition_t();
                res_cond->set_op("&");
                res_cond->add_condition(cond_t);
                kf->add_condition(rule_t,res_cond);
            } else {
                static_cast<complex_condition_t*>(old_cond)->add_condition(cond_t);
            }


        } else if (childe_conds.at(i).toElement().tagName() == "CondIntRel") {
             // условие вида (об.атр = знач) d Интервал
            QDomNode CondEvRel_cond = childe_conds.at(i);

            condition_attr_value_const_t* eq_cond_t = new condition_attr_value_const_t();
            eq_cond_t->set_op("=");

            QDomNode eq_cond = CondEvRel_cond.toElement().elementsByTagName("eq").at(0);
            QDomNodeList refs = eq_cond.toElement().elementsByTagName("ref");
            std::cout << refs.at(0).toElement().attribute("id").toStdString() << "." << refs.at(1).toElement().attribute("id").toStdString();

            const temporal_object_t* object_t = kf->get_object(refs.at(0).toElement().attribute("id").toStdString());
            int object_id = kf->get_object_id_by_name(refs.at(0).toElement().attribute("id").toStdString());
            int attr_id = object_t->get_attr_id_by_name(refs.at(1).toElement().attribute("id").toStdString());

            eq_cond_t->set_obj_id(object_id);
            eq_cond_t->set_attr_id(attr_id);

            QDomNodeList values = eq_cond.toElement().elementsByTagName("value");
            std::cout << "=" << values.at(0).toElement().text().toStdString() << " ";
            std::cout << CondEvRel_cond.toElement().attribute("Value").toStdString() << " ";

            eq_cond_t->set_value(values.at(0).toElement().text().toStdString());

            QDomNode interval = CondEvRel_cond.toElement().elementsByTagName("Interval").at(0);
            std::cout << interval.toElement().attribute("Name").toStdString() << "\n";

            int interval_id = kf->get_interval_id_by_name(interval.toElement().attribute("Name").toStdString());

            if (interval_id < 0) {
                std::cout << "QUACK! Interval " << interval.toElement().attribute("Name").toStdString() << " is not found.\n";
                interval_id = 0;
            }

            //std::cout << "QUACK! int ID id :" << interval_id << '\n';
            temporal_interval_t* interval_t = (temporal_interval_t*)kf->get_interval(interval_id);
            temporal_condition_operation_condition* cond_t = new temporal_condition_operation_condition(eq_cond_t,interval_t);
            cond_t->set_op(CondEvRel_cond.toElement().attribute("Value").toStdString());

            if (old_cond == nullptr) {
                complex_condition_t* res_cond = new complex_condition_t();
                res_cond->set_op("&");
                res_cond->add_condition(cond_t);
                kf->add_condition(rule_t,res_cond);
            } else {
                static_cast<complex_condition_t*>(old_cond)->add_condition(cond_t);
            }
        } else if (childe_conds.at(i).toElement().tagName() == "EvIntRel") {
            // string res = "";
            // условие вида Событие d Интервал
            QDomNode EvIntRel_cond = childe_conds.at(i);

            event_interval_condition_t* cond_t = new event_interval_condition_t();

            QDomNode interval = EvIntRel_cond.toElement().elementsByTagName("Interval").at(0);
            int interval_id = kf->get_interval_id_by_name(interval.toElement().attribute("Name").toStdString());

            if (interval_id < 0) {
                std::cout << "QUACK! Interval " << interval.toElement().attribute("Name").toStdString() << " is not found.\n";
                interval_id = 0;
            }

             res = res + "\tQUACK! Интервал: " + interval.toElement().attribute("Name").toStdString() + "\n";
            //const temporal_interval_t* interval_t = kf->get_interval(interval_id);

            QDomNode event = EvIntRel_cond.toElement().elementsByTagName("Event").at(0);
            int event_id = kf->get_event_id_by_name(event.toElement().attribute("Name").toStdString());

            if (event_id < 0) {
                std::cout << "QUACK! Event " << event.toElement().attribute("Name").toStdString() << " is not found.\n";
                event_id = 0;
            }

            res = res + "\t\tQUACK! Событие: " + event.toElement().attribute("Name").toStdString() + "\n";
            //const temporal_event_t* event_t = kf->get_event(event_id);

            cond_t->set_op(EvIntRel_cond.toElement().attribute("Value").toStdString());
            res = res + "\tQUACK! Операция: " + EvIntRel_cond.toElement().attribute("Value").toStdString() + "\n";
            std::cout << res;
            cond_t->set_event_id(event_id);
            cond_t->set_interval_id(interval_id);

            if (old_cond == nullptr) {
                complex_condition_t* res_cond = new complex_condition_t();
                res_cond->set_op("&");
                res_cond->add_condition(cond_t);
                kf->add_condition(rule_t,res_cond);
            } else {
                static_cast<complex_condition_t*>(old_cond)->add_condition(cond_t);
            }
        }
    }

}

void verifier::readRuleFromFile(QDomElement rule, knowledge_field_t* kf) {
    string res = "";
    std::cout << "\nQUACK! Правило\t";
    std::cout << rule.attribute("id").toStdString() << '\t';
    std::cout << rule.attribute("desc").toStdString() << '\n';

    temporal_rule_t* rule_t = (temporal_rule_t*)kf->add_rule("Правило "+rule.attribute("id").toStdString());

    std::cout << "\tЕСЛИ\n\t";
    QDomNodeList liconditions = rule.elementsByTagName("condition");
    readCondFromFile(liconditions.at(0),kf,rule_t);

    std::cout << "\tTO\n\t";
    QDomNode nodaction = rule.elementsByTagName("action").at(0).toElement().elementsByTagName("assign").at(0);

    QDomNodeList refs = nodaction.toElement().elementsByTagName("ref");
    std::cout << refs.at(0).toElement().attribute("id").toStdString() << "." << refs.at(1).toElement().attribute("id").toStdString();
    //res = refs.at(0).toElement().attribute("id").toStdString() + "." + refs.at(1).toElement().attribute("id").toStdString();

    const temporal_object_t* object_t = kf->get_object(refs.at(0).toElement().attribute("id").toStdString());
    int object_id = kf->get_object_id_by_name(refs.at(0).toElement().attribute("id").toStdString());
    int attr_id = object_t->get_attr_id_by_name(refs.at(1).toElement().attribute("id").toStdString());

    QDomNodeList values = nodaction.toElement().elementsByTagName("value");
    //std::cout << "\tQUACK!values num is " << values.count();
    std::cout << "=" << values.at(0).toElement().text().toStdString() << "\n";

    action_string_t* action = new action_string_t();
    action->set_object_id(object_id);
    action->set_attribute_id(attr_id);
    action->set_value(values.at(0).toElement().text().toStdString());
    action->set_op("=");

    kf->add_action(rule_t,action);

    //std::cout << rule_t->to_string(*kf);

}

void verifier::readEventFromFile(QDomElement event, knowledge_field_t* kf) {
    std::cout << "\nQUACK! Событие: \t";
    std::cout << event.attribute("Name").toStdString() << '\n';

    temporal_event_t* event_t = (temporal_event_t*)kf->add_event(event.attribute("Name").toStdString());

    QDomNode EqOp = event.firstChild().firstChild();
    std::cout << EqOp.firstChild().toElement().attribute("Value").toStdString() << "=" << EqOp.lastChild().toElement().attribute("Value").toStdString() << "\n";

    int pos = EqOp.firstChild().toElement().attribute("Value").toStdString().find(".");
    string str_obj = EqOp.firstChild().toElement().attribute("Value").toStdString().substr(0,pos);
    string str_attr = EqOp.firstChild().toElement().attribute("Value").toStdString().substr(pos+1);

    int id_obj = kf->get_object_id_by_name(str_obj);
    const temporal_object_t* object_t = kf->get_object(id_obj);
    int attr_id = object_t->get_attr_id_by_name(str_attr);
    condition_attr_value_const_t* cond = new condition_attr_value_const_t(id_obj, attr_id, EqOp.lastChild().toElement().attribute("Value").toStdString());
    cond->set_op("=");

    event_t->add_condition(cond);
}

void verifier::readIntervalFromFile(QDomElement interval, knowledge_field_t* kf) {
    std::cout << "\nQUACK! Interval: " << interval.attribute("Name").toStdString() << '\n';

    temporal_interval_t* interval_t = (temporal_interval_t*)kf->add_interval(interval.attribute("Name").toStdString());

    if (interval.firstChild().toElement().tagName() == "Open") {
        QDomNode EqOp = interval.firstChild().firstChild();
        std::cout << "\tQUACK! Open: \t";
        std::cout << EqOp.firstChild().toElement().attribute("Value").toStdString() << "=" << EqOp.lastChild().toElement().attribute("Value").toStdString() << "\n";

        //выделяем объект и атрибут
        int pos = EqOp.firstChild().toElement().attribute("Value").toStdString().find(".");
        string str_obj = EqOp.firstChild().toElement().attribute("Value").toStdString().substr(0,pos);
        string str_attr = EqOp.firstChild().toElement().attribute("Value").toStdString().substr(pos+1);

        int id_obj = kf->get_object_id_by_name(str_obj);
        const temporal_object_t* object_t = kf->get_object(id_obj);
        int attr_id = object_t->get_attr_id_by_name(str_attr);
        condition_attr_value_const_t* cond = new condition_attr_value_const_t(id_obj, attr_id, EqOp.lastChild().toElement().attribute("Value").toStdString());
        cond->set_op("=");

        interval_t->set_start_condition(cond);

        EqOp = interval.lastChild().firstChild();
        std::cout << "\tQUACK! Close: \t";
        std::cout << EqOp.firstChild().toElement().attribute("Value").toStdString() << "=" << EqOp.lastChild().toElement().attribute("Value").toStdString() << "\n";

        id_obj = kf->get_object_id_by_name(str_obj);
        object_t = kf->get_object(id_obj);
        attr_id = object_t->get_attr_id_by_name(str_attr);
        cond = new condition_attr_value_const_t(id_obj, attr_id, EqOp.lastChild().toElement().attribute("Value").toStdString());
        cond->set_op("=");

        interval_t->set_end_condition(cond);

    } else {

        QDomNode EqOp = interval.firstChild().firstChild();
        std::cout << "\tQUACK! Duration: \t";
        std::cout << EqOp.firstChild().toElement().attribute("Value").toStdString() << "=" << EqOp.lastChild().toElement().attribute("Value").toStdString() << "\n";

        int pos = EqOp.firstChild().toElement().attribute("Value").toStdString().find(".");
        string str_obj = EqOp.firstChild().toElement().attribute("Value").toStdString().substr(0,pos);
        string str_attr = EqOp.firstChild().toElement().attribute("Value").toStdString().substr(pos+1);

        int id_obj = kf->get_object_id_by_name(str_obj);
        const temporal_object_t* object_t = kf->get_object(id_obj);
        int attr_id = object_t->get_attr_id_by_name(str_attr);
        condition_attr_value_const_t* cond = new condition_attr_value_const_t(id_obj, attr_id, EqOp.lastChild().toElement().attribute("Value").toStdString());
        cond->set_op("=");

        interval_t->set_duration_condition(cond);
    }

}






