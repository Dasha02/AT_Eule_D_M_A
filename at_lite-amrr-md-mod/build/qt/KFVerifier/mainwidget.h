#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "verifier.h"


namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private slots:
    void on_verifyButton_clicked();

    void on_checkExcessiveRules_stateChanged(int arg1);
    void on_checkIntersecionRules_stateChanged(int arg1);

    void on_checkEventsWithoutRef_stateChanged(int arg1);
    void on_checkIntervalsWithoutRef_stateChanged(int arg1);
//    void on_checkImpossiblePositioning_stateChanged(int arg1);
    void on_checkWrongAttributesValues_stateChanged(int arg1);


    void on_seeKFButtom_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_checkImpossiblePositioning_stateChanged(int arg1);

private:
    Ui::MainWidget *ui;
    QStringList anomList;
    verifier* ver;
    QString filename = "/home/helga/Bobrovskaya/AT_Eule/at_lite-amrr-md-mod/resources/libTemp/bz.xml";
};

#endif // MAINWIDGET_H
