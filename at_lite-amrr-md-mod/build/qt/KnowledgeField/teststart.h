#ifndef TESTSTART_H
#define TESTSTART_H

#include "alertshow.h"
#include "alertshow2.h"
#include <QDialog>
#include <QWidget>

namespace Ui {
class TestStart;
}

class TestStart : public QDialog
{
    Q_OBJECT

public:
    explicit TestStart(QWidget *parent = nullptr);
    ~TestStart();

private slots:
   alertshow2* on_pushButton_clicked();

   alertshow* on_pushButton_2_clicked();

   alertshow* on_pushButton_3_clicked();


private:
    Ui::TestStart *ui;
};

#endif // TESTSTART_H
