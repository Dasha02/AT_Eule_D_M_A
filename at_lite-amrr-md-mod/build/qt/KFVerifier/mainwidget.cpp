#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <iostream>
#include <QMessageBox>
#include <QDialog>
#include "windowres.h"

#include "test_kf.h"


MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::on_verifyButton_clicked()
{

    Dialog *windowres = new Dialog();
    windowres->set_verifier(ver);
    QString str;

    for (QString it: anomList) {

        if (it == "События без ссылок:\n") {
            str = str + it + QString::fromStdString (ver->verifyEventsWithoutRef() + "\n");
            windowres->add_temp_anom("События без ссылок");
        }
        else if (it == "Интервалы без ссылок:\n") {
            str = str + it + QString::fromStdString (ver->verifyIntervalsWithoutRef() + "\n");
            windowres->add_temp_anom("Интервалы без ссылок");
        }
        else if (it == "Неверное значение атрибута: \n") {
            str = str + it;
            std::set<temporal_entity_t*> false_values = ver->verifyWrongAttributesValues();
            if (false_values.size() > 0) {
                for (temporal_entity_t* entity : false_values) {
                    str = str + QString::fromStdString ("\t" + entity->get_name() + "\n");
                }
                str = str + QString::fromStdString ("\n");
            } else {
                str = str + it + QString::fromStdString ("\tне найдено\n\n");
            }
            windowres->add_temp_anom("Неверное значение атрибута");
        }
        else if (it == "Невозможное взаиморасположение событий и интервалов: \n") {
            // str = str + it + QString::fromStdString (ver->verifyIntersecionRules() + "\n");
            windowres->add_temp_anom("Невозможное взаиморасположение событий и интервалов");
        }
        else if (it == "Избыточные правила: \n") {
            str = str + it + QString::fromStdString (ver->verifyExcessiveRules() + "\n");
            windowres->add_base_anom("Избыточные правила");
        }
        else if (it == "Пересекающиеся правила: \n") {
            //str = str + it + QString::fromStdString (ver->verifyIntersecionRules() + "\n");
            windowres->add_base_anom("Пересекающиеся правила");
        }
        else {
            str = str + it + QString::fromStdString ("\tне найдено\n\n");
        }
    }
    windowres->show();
    //ATVerifier atV = new ATVerifier(kf);
    QMessageBox *msg = new QMessageBox;
    msg->setStyleSheet("QLabel{min-width: 400px;}");

    msg->setInformativeText(str+"\n\nПосмотреть поле знаний:\n");

    msg->setDetailedText(QString::fromStdString(ver->get_kf()->to_string()));
    msg->show();
    // std::cout << kf->to_string();

    int non_t_count = 0;
    int t_count = 0;
    vector<temporal_rule_t*> rules = ver->get_kf()->getRules();
    for (temporal_rule_t* rule : rules){
        rule->is_temporal() ? t_count++ : non_t_count++;
    }
    ui->non_t_count_le->setText(QString::fromStdString(std::to_string(non_t_count)));
    ui->t_count_le->setText(QString::fromStdString(std::to_string(t_count)));
}



void MainWidget::on_checkEventsWithoutRef_stateChanged(int arg1)
{
    if (arg1 > 0) {
        anomList << "События без ссылок:\n";
    } else {
        anomList.removeAll("События без ссылок:\n");
    }
}

void MainWidget::on_checkIntervalsWithoutRef_stateChanged(int arg1)
{
    if (arg1 > 0) {
        anomList << "Интервалы без ссылок:\n";
    } else {
        anomList.removeAll("Интервалы без ссылок:\n");
    }
}

void MainWidget::on_checkWrongAttributesValues_stateChanged(int arg1)
{
    if (arg1 > 0) {
        anomList << "Неверное значение атрибута: \n";
    } else {
        anomList.removeAll("Неверное значение атрибута: \n");
    }
}

void MainWidget::on_checkExcessiveRules_stateChanged(int arg1)
{
    if (arg1 > 0) {
        anomList << "Избыточные правила: \n";
    } else {
        anomList.removeAll("Избыточные правила: \n");
    }
}

void MainWidget::on_checkIntersecionRules_stateChanged(int arg1)
{
    if (arg1 > 0) {
        anomList << "Пересекающиеся правила: \n";
    } else {
        anomList.removeAll("Пересекающиеся правила: \n");
    }
}
// показываем тут пз
void MainWidget::on_seeKFButtom_clicked()
{

    if (ver == nullptr) {
        QMessageBox *msg = new QMessageBox();
        msg->setText("Поле знаний не задано");
        msg->exec();
    } else {
        QWidget *kfwin = new QWidget();
        QVBoxLayout *lay = new QVBoxLayout(kfwin);
        QTextBrowser *kftext = new QTextBrowser();
        //kftext->setBaseSize(400,800);
        kftext->setText(QString::fromStdString(ver->get_kf()->to_string()));
        lay->addWidget(kftext);

        kfwin->setBaseSize(400,800);
        kfwin->show();
    }

}

void MainWidget::on_comboBox_currentTextChanged(const QString &arg1)
{
    ver = new verifier();
    //Dialog *windowres = new Dialog();

    //QString filename = "/home/helga/Bobrovskaya/KFVefifier/kf.xml";
    //QString filename = "/home/helga/Downloads/TKBnewforAT.xml";
    //QString filename = "/home/helga/Downloads/temp_reasoner_fucking_kb.xml";

    if ( arg1 == "kf" )
    {
        filename = "/home/helga/Bobrovskaya/AT_Eule/at_lite-amrr-md-mod/resources/libTemp/bz.xml";
    } else if ( arg1 == "test_kf" ) {

         filename = "/home/helga/Downloads/new_temp_reasoner_fucking_kb.xml";

    }
     knowledge_field_t* kf_new = ver->readFromFile(filename);
     std::cout << "///////////////////////////////////////////////////////////////////";
     std::cout << "-------------------------------------------------------------------";

     //knowledge_field_t*  kf_d = rewrite_txt_for_pz(kf_new);

     std::cout << kf_new->to_string();
     ver->set_kf(kf_new);
}

void MainWidget::on_checkImpossiblePositioning_stateChanged(int arg1)
{
    if (arg1 > 0) {
        anomList << "Невозможное взаиморасположение событий и интервалов: \n";
    } else {
        anomList.removeAll("Невозможное взаиморасположение событий и интервалов: \n");
    }
}



