#include "choicekf.h"
#include "ui_choicekf.h"

choiceKF::choiceKF(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::choiceKF)
{
    ui->setupUi(this);
}

choiceKF::~choiceKF()
{
    delete ui;
}

void choiceKF::on_buttonBox_accepted()
{

}
