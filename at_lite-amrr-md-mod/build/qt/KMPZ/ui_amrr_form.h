/********************************************************************************
** Form generated from reading UI file 'amrr_form.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AMRR_FORM_H
#define UI_AMRR_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AMRR_form
{
public:
    QPushButton *to_amrr;
    QPushButton *close_amrr;

    void setupUi(QWidget *AMRR_form)
    {
        if (AMRR_form->objectName().isEmpty())
            AMRR_form->setObjectName(QLatin1String("AMRR_form"));
        AMRR_form->resize(942, 300);
        to_amrr = new QPushButton(AMRR_form);
        to_amrr->setObjectName(QLatin1String("to_amrr"));
        to_amrr->setGeometry(QRect(740, 10, 191, 31));
        close_amrr = new QPushButton(AMRR_form);
        close_amrr->setObjectName(QLatin1String("close_amrr"));
        close_amrr->setGeometry(QRect(740, 50, 191, 31));

        retranslateUi(AMRR_form);

        QMetaObject::connectSlotsByName(AMRR_form);
    } // setupUi

    void retranslateUi(QWidget *AMRR_form)
    {
        AMRR_form->setWindowTitle(QApplication::translate("AMRR_form", "Form", nullptr));
        to_amrr->setText(QApplication::translate("AMRR_form", "\320\227\320\260\320\277\321\203\321\201\321\202\320\270\321\202\321\214 \320\220\320\234\320\240\320\240", nullptr));
        close_amrr->setText(QApplication::translate("AMRR_form", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214 \320\220\320\234\320\240\320\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AMRR_form: public Ui_AMRR_form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AMRR_FORM_H
