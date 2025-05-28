#ifndef ALERTSHOW_H
#define ALERTSHOW_H

#include <QDialog>

namespace Ui {
class alertshow;
}

class alertshow : public QDialog
{
    Q_OBJECT

public:
    alertshow(QWidget *parent = nullptr);
    virtual ~alertshow();

    void set_m_act(QString str);
    void set_ss_act(QString str);
    void set_si_act(QString str);
    void set_m_pre(QString str);
    void set_ss_pre(QString str);
    void set_si_pre(QString str);

private:
    Ui::alertshow *ui;

};

#endif // ALERTSHOW_H
