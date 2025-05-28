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

alertshow* TestStart::on_pushButton_clicked()
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



    //al->set_si_pre(QString("Атрибут1 = какая-то боль в горле УВЕРЕННОСТЬ 90\n\n"));

    return al;
}

