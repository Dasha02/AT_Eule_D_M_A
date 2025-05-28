#include "teststart.h"
#include "ui_teststart.h"
#include <QDebug>
#include <QWidget>

#include <QFile>
#include <QString>
#include <QTextStream>

TestStart::TestStart(QWidget *parent) :
   QDialog(parent),
   ui(new Ui::TestStart)
{
   qDebug() << "";
   ui->setupUi(this);
}

TestStart::~TestStart()
{
   delete ui;
}

alertshow2* TestStart::on_pushButton_clicked()
{
   alertshow2* al = new alertshow2(nullptr);
   al->show();
   QFile file_1("/home/helga/Bobrovskaya/AT_Eule/at_lite-amrr-md-mod/resources/libTemp/MA.txt");

   if (file_1.open(QIODevice::ReadOnly | QIODevice::Text)) {
           QTextStream in(&file_1);
           QString content = in.readAll(); // считывает весь файл в одну строку
           file_1.close();

           al->set_m_pre(content);

           qDebug() << content; // выводит содержимое файла
       } else {
           qDebug() << "Не удалось открыть файл";
       }


   QFile file_2("/home/helga/Bobrovskaya/AT_Eule/at_lite-amrr-md-mod/resources/libTemp/SSA.txt");

   if (file_2.open(QIODevice::ReadOnly | QIODevice::Text)) {
           QTextStream in(&file_2);
           QString content = in.readAll(); // считывает весь файл в одну строку
           file_2.close();

           al->set_ss_pre(content);

           qDebug() << content; // выводит содержимое файла
       } else {
           qDebug() << "Не удалось открыть файл";
       }



   //al->set_ss_pre(QString("Indefinite: какой-то\n"));
   //al->set_si_pre(QString("Атрибут1 = какая-то боль в горле УВЕРЕННОСТЬ 90\n\n"));

   QFile file_3("/home/helga/Bobrovskaya/AT_Eule/at_lite-amrr-md-mod/resources/libTemp/SI.txt");

   if (file_3.open(QIODevice::ReadOnly | QIODevice::Text)) {
           QTextStream in(&file_3);
           QString content = in.readAll(); // считывает весь файл в одну строку
           file_3.close();

           al->set_si_pre(content);

           qDebug() << content; // выводит содержимое файла
       } else {
           qDebug() << "Не удалось открыть файл";
       }


   return al;
}





alertshow* TestStart::on_pushButton_2_clicked()
{
    alertshow* al = new alertshow(nullptr);
    al->show();
    QFile file_1("/home/helga/Bobrovskaya/AT_Eule/at_lite-amrr-md-mod/resources/libTemp/MA.txt");

    if (file_1.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file_1);
            QString content = in.readAll(); // считывает весь файл в одну строку
            file_1.close();

            al->set_m_pre(content);

            qDebug() << content; // выводит содержимое файла
        } else {
            qDebug() << "Не удалось открыть файл";
        }


    QFile file_2("/home/helga/Bobrovskaya/AT_Eule/at_lite-amrr-md-mod/resources/libTemp/SSA.txt");

    if (file_2.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file_2);
            QString content = in.readAll(); // считывает весь файл в одну строку
            file_2.close();

            al->set_ss_pre(content);

            qDebug() << content; // выводит содержимое файла
        } else {
            qDebug() << "Не удалось открыть файл";
        }



    //al->set_ss_pre(QString("Indefinite: какой-то\n"));
    al->set_si_pre(QString("Атрибут1 = какая-то боль в горле УВЕРЕННОСТЬ 90\n\n"));

    return al;
}

//alertshow* TestStart::on_pushButton_3_clicked()
//{
//   alertshow* al = new alertshow(nullptr);
//   al->show();
//   al->set_m_act(QString("Symptom: Количество эритроцитов превысило норму\nFuzzyLexems: видимо\nSymptom: Скорость инфенцирования\nFuzzyLexems: высокая\nSymptom: Боль ощущалась\nFuzzyLexems: 2-3 час\n"));
//   al->set_ss_act(QString("Indefinite: видимо\nFuzzy: высокий\nInaccurate: 2-3 час"));
//   //al->set_si_act(QString("Атрибут1 = какая-то боль в горле УВЕРЕННОСТЬ 90\n\nНЕЧЕТКИЙ АТРИБУТ\nЗНАЧЕНИЯ\n     незначительная\nКОММЕНТАРИЙ боль в горле\n\nПациент.Атрибут2 = Температура 37 градусов ТОЧНОСТЬ 99\n\n"));
//}


