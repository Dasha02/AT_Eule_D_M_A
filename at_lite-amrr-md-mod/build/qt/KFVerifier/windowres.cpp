#include "windowres.h"
#include "ui_windowres.h"
#include <QString>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);    
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::add_temp_anom(QString str) {
    temp_anom << str;
    //ui->listanoms->addItem(str);
    ui->tableanoms->setRowCount(ui->tableanoms->rowCount()+1);
    QTableWidgetItem *item1 = new QTableWidgetItem(str);
    ui->tableanoms->setItem(ui->tableanoms->rowCount()-1,0,item1);
    int num = 0;
    if (str == "События без ссылок") {
        vector<int> res_id = ver->verifyEventsIdsWithoutRef();
        num = res_id.size();
    } else if (str == "Интервалы без ссылок") {
        vector<int> res_id = ver->verifyIntervalsIdsWithoutRef();
        num = res_id.size();
    } else if (str == "Неверное значение атрибута") {
        std::set<temporal_entity_t*> false_values = ver->verifyWrongAttributesValues();
        num = false_values.size();
    } else if (str == "Невозможное взаиморасположение событий и интервалов") {
        std::vector<std::pair<const temporal_rule_t*, std::pair<const temporal_entity_t*, const temporal_entity_t*>>> res = ver->verifyImpossiblePositioningII();
        num = res.size();
    }
    QTableWidgetItem *item2 = new QTableWidgetItem(QString::number(num));
    item2->setTextAlignment(Qt::AlignCenter);
    ui->tableanoms->setItem(ui->tableanoms->rowCount()-1,1,item2);
};

void Dialog::add_base_anom(QString str) {
    base_anom << str;
    //ui->listanoms_2->addItem(str);
    ui->tableanoms_2->setRowCount(ui->tableanoms_2->rowCount()+1);
    QTableWidgetItem *item1 = new QTableWidgetItem(str);
    ui->tableanoms_2->setItem(ui->tableanoms_2->rowCount()-1,0,item1);
    int num = 0;
    if (str == "Избыточные правила") {
        vector<pair<const temporal_rule_t*, const temporal_rule_t*>> res = ver->verifyPairsExcessiveRulesII();
        num = res.size();
    } else if (str == "Пересекающиеся правила") {
        vector<pair<const temporal_rule_t*, const temporal_rule_t*>> res = ver->verifyPairsIntersecionRulesII();
        num = res.size();
    }
    QTableWidgetItem *item2 = new QTableWidgetItem(QString::number(num));
    item2->setTextAlignment(Qt::AlignCenter);
    ui->tableanoms_2->setItem(ui->tableanoms_2->rowCount()-1,1,item2);
};

void Dialog::on_listres_currentRowChanged(int currentRow)
{
    if (currentRow > -1) {
    if (ui->groupres->title() == "События без ссылок" and ui->listres->count() > 0) {
        vector<int> res_id = ver->verifyEventsIdsWithoutRef();
        ui->textBrowser->setText(QString::fromStdString(ver->get_kf()->get_event(res_id[currentRow])->to_string(*(ver->get_kf()))));
    }
    else if (ui->groupres->title() == "Интервалы без ссылок" and ui->listres->count() > 0) {
        vector<int> res_id = ver->verifyIntervalsIdsWithoutRef();
        ui->textBrowser->setText(QString::fromStdString(ver->get_kf()->get_interval(res_id[currentRow])->to_string(*(ver->get_kf()))));
    }
    else if (ui->groupres->title() == "Неверное значение атрибута" and ui->listres->count() > 0)
    {
        std::set<temporal_entity_t*> false_values = ver->verifyWrongAttributesValues();
        if (ui->listres->currentItem()->text().contains("Событие")) {
            int ev_id = ver->get_kf()->get_event_id_by_name(ui->listres->currentItem()->text().toStdString());
            temporal_event_t *event_t = (temporal_event_t*)ver->get_kf()->get_event(ev_id);
            //ui->textBrowser->setText(QString::fromStdString(event_t->to_string(*(ver->get_kf()))));

            vector<pair<QString,QString>> res = ver->true_values_str(event_t->get_condition_t(),ver->get_kf());
            string res_str;
            for (pair<QString,QString> p : res) {
                res_str += "Тип " + p.first.toStdString() + " не имеет значения \"" + p.second.toStdString() + "\".\n";
            }
            ui->textBrowser->setText(QString::fromStdString(event_t->to_string(*(ver->get_kf())) + "\n" + res_str));
        } else {
            int in_id = ver->get_kf()->get_interval_id_by_name(ui->listres->currentItem()->text().toStdString());
            temporal_interval_t *interval_t = (temporal_interval_t*)ver->get_kf()->get_interval(in_id);
            //ui->textBrowser->setText(QString::fromStdString(interval_t->to_string(*(ver->get_kf()))));


            vector<pair<QString,QString>> res = ver->true_values_str(interval_t->get_begin_condition_t(),ver->get_kf());
            string res_str;
            for (pair<QString,QString> p : res) {
                res_str += "Тип " + p.first.toStdString() + " не имеет значения \"" + p.second.toStdString() + "\".\n";
            }
            res = ver->true_values_str(interval_t->get_end_condition_t(),ver->get_kf());
            //string res_str;
            for (pair<QString,QString> p : res) {
                res_str += "Тип " + p.first.toStdString() + " не имеет значения \"" + p.second.toStdString() + "\".\n";
            }
            res = ver->true_values_str(interval_t->get_duration_condition_t(),ver->get_kf());
            //string res_str;
            for (pair<QString,QString> p : res) {
                res_str += "Тип " + p.first.toStdString() + " не имеет значения \"" + p.second.toStdString() + "\".\n";
            }
            ui->textBrowser->setText(QString::fromStdString(interval_t->to_string(*(ver->get_kf())) + "\n" + res_str));
        }

    }
    else if (ui->groupres->title() == "Невозможное взаиморасположение событий и интервалов" and ui->listres->count() > 0) {
        std::vector<std::pair<const temporal_rule_t*, std::pair<const temporal_entity_t*, const temporal_entity_t*>>> res = ver->get_impossiblePositioning();
        std::string str = res.at(currentRow).first->to_string(*(ver->get_kf())) + "\n\n" + res.at(currentRow).second.first->to_string(*(ver->get_kf())) + "\n\n" + res.at(currentRow).second.second->to_string(*(ver->get_kf()));
        ui->textBrowser->setText(QString::fromStdString(str));
    }
    } else { ui->textBrowser->clear(); }
}
void Dialog::on_tableanoms_cellClicked(int row, int column)
{
    ui->textBrowser->clear();
    ui->listres->clear();
    ui->groupres->setTitle(ui->tableanoms->item(row,0)->text());
    if (ui->tableanoms->item(row,0)->text() == "События без ссылок" and ui->tableanoms->item(row,1)->text() != "0") {
        vector<int> res_id = ver->verifyEventsIdsWithoutRef();
        if ( res_id.empty()) {
            ui->textBrowser->setText("Не найдено");
        } else {
            for (int id : res_id) {
                ui->listres->addItem(QString::fromStdString(ver->get_kf()->get_event_name_by_id(id)));
            }
        }
    }
    else if (ui->tableanoms->item(row,0)->text() == "Интервалы без ссылок" and ui->tableanoms->item(row,1)->text() != "0")
    {
        vector<int> res_id = ver->verifyIntervalsIdsWithoutRef();
        if (res_id.empty()) {
            ui->textBrowser->setText("Не найдено");
        } else {
            for (int id : res_id) {
                ui->listres->addItem(QString::fromStdString(ver->get_kf()->get_interval_name_by_id(id)));
            }
        }
    }
    else if (ui->tableanoms->item(row,0)->text() == "Неверное значение атрибута")
    {
        std::set<temporal_entity_t*> false_values = ver->verifyWrongAttributesValues();
        if (false_values.empty()) {
            ui->textBrowser->setText("Не найдено");
        } else {
            for (temporal_entity_t* entity : false_values) {
                ui->listres->addItem(QString::fromStdString(entity->get_name()));
            }
        }
    }
    else if (ui->tableanoms->item(row,0)->text() == "Невозможное взаиморасположение событий и интервалов")
    {
        std::vector<std::pair<const temporal_rule_t*, std::pair<const temporal_entity_t*, const temporal_entity_t*>>> res = ver->get_impossiblePositioning();
        if (res.empty()) {
            ui->textBrowser->setText("Не найдено");
        } else {
            for (std::pair<const temporal_rule_t*, std::pair<const temporal_entity_t*, const temporal_entity_t*>> rule : res) {
                ui->listres->addItem(QString::fromStdString(rule.first->get_name()));
            }
        }
    }
    else
    {
        ui->textBrowser->setText("Не найдено");
    }
}

void Dialog::on_exitButton_clicked()
{
    this->close();
}

void Dialog::on_tableanoms_2_cellClicked(int row, int column)
{
    ui->textBrowser_2->clear();
    ui->listres_2->clear();
    ui->groupres_2->setTitle(ui->tableanoms_2->item(row,0)->text());
    if (ui->tableanoms_2->item(row,0)->text() == "Избыточные правила") {
        vector<pair<const temporal_rule_t*, const temporal_rule_t*>> res = ver->get_excessiveRules();
        if ( res.empty()) {
            ui->textBrowser_2->setText("Не найдено");
        } else {
            for (pair<const temporal_rule_t*, const temporal_rule_t*> p : res) {
                ui->listres_2->addItem(QString::fromStdString(p.first->get_name() + " и " + p.second->get_name()));
            }
        }
    } else if (ui->tableanoms_2->item(row,0)->text() == "Пересекающиеся правила") {
        vector<pair<const temporal_rule_t*, const temporal_rule_t*>> res = ver->get_intersectionRules();
        if ( res.empty()) {
            ui->textBrowser_2->setText("Не найдено");
        } else {
            for (pair<const temporal_rule_t*, const temporal_rule_t*> p : res) {
                ui->listres_2->addItem(QString::fromStdString(p.first->get_name() + " и " + p.second->get_name()));
            }
        }
    }
}
void Dialog::on_listres_2_currentRowChanged(int currentRow)
{
    if (currentRow > -1) {
        if (ui->groupres_2->title() == "Избыточные правила" and ui->listres_2->count() > 0) {
            vector<pair<const temporal_rule_t*, const temporal_rule_t*>> res = ver->get_excessiveRules();
            pair<const temporal_rule_t*, const temporal_rule_t*> p = res.at(currentRow);
            ui->textBrowser_2->setText(QString::fromStdString("Следующие правила избыточны: \n" + p.first->to_string(*(ver->get_kf())) + "\n" + p.second->to_string(*(ver->get_kf()))));
        }
        else if (ui->groupres_2->title() == "Пересекающиеся правила" and ui->listres_2->count() > 0) {
            vector<pair<const temporal_rule_t*, const temporal_rule_t*>> res = ver->get_intersectionRules();
            pair<const temporal_rule_t*, const temporal_rule_t*> p = res.at(currentRow);
            ui->textBrowser_2->setText(QString::fromStdString("Следующие правила пересекаются: \n" + p.first->to_string(*(ver->get_kf())) + "\n" + p.second->to_string(*(ver->get_kf()))));
        }
    }
     else {
        ui->textBrowser_2->clear();
    }
}
