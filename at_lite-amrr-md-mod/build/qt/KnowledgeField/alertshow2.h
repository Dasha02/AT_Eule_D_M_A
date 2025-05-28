#ifndef ALERTSHOW2_H
#define ALERTSHOW2_H

#include <QDialog>

namespace Ui {
class alertshow2;
}

class alertshow2 : public QDialog
{
   Q_OBJECT

public:
   alertshow2(QWidget *parent = nullptr);
   virtual ~alertshow2();
   void set_m_pre(QString str);
   void set_ss_pre(QString str);
   void set_si_pre(QString str);

private:
   Ui::alertshow2 *ui;

};

#endif // ALERTSHOW2_H


