#include "alertshow2.h"
#include "ui_alertshow2.h"

alertshow2::alertshow2(QWidget *parent) :
   QDialog(parent),
   ui(new Ui::alertshow2)
{
   ui->setupUi(this);
}

alertshow2::~alertshow2()
{
   delete ui;
}

void alertshow2::set_m_pre(QString str) {
   ui->m_pre->setText(str);
   return;
}

void alertshow2::set_ss_pre(QString str) {
   ui->ss_pre->setText(str);
   return;
}

void alertshow2::set_si_pre(QString str) {
   ui->si_pre->setText(str);
   return;
}

//alertshow2::~alertshow2()
//{
//    delete ui;
//}


