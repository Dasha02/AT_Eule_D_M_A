#include "alertshow.h"
#include "ui_alertshow.h"

alertshow::alertshow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::alertshow)
{
    ui->setupUi(this);
}

alertshow::~alertshow()
{
    delete ui;
}

void alertshow::set_m_act(QString str) {
    ui->m_act->setText(str);
    return;
}

void alertshow::set_ss_act(QString str) {
    ui->ss_act->setText(str);
    return;
}

void alertshow::set_si_act(QString str) {
    ui->si_act->setText(str);
    return;
}

void alertshow::set_m_pre(QString str) {
    ui->m_pre->setText(str);
    return;
}

void alertshow::set_ss_pre(QString str) {
    ui->ss_pre->setText(str);
    return;
}

void alertshow::set_si_pre(QString str) {
    ui->si_pre->setText(str);
    return;
}
