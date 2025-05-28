#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "verifier.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

public:
    Ui::Dialog *ui;
    verifier *ver = nullptr;
    QStringList temp_anom;
    QStringList base_anom;

private slots:
    //void on_listanoms_currentTextChanged(const QString &currentText);
//    void on_listres_currentTextChanged(const QString &currentText);
    void on_listres_currentRowChanged(int currentRow);
    void on_tableanoms_cellClicked(int row, int column);
    void on_exitButton_clicked();
    void on_tableanoms_2_cellClicked(int row, int column);
    void on_listres_2_currentRowChanged(int currentRow);

public:
    void set_verifier(verifier *ver_new) { ver = ver_new; }
    verifier* get_verifier() { return ver; }
    void set_temp_anom(QStringList a) { temp_anom = a; }
    void add_temp_anom(QString str) ;
    void add_base_anom(QString str) ;
    void set_base_anom(QStringList a) { base_anom = a; }
};

#endif // DIALOG_H
