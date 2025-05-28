/********************************************************************************
** Form generated from reading UI file 'confirm.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIRM_H
#define UI_CONFIRM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Confirm
{
public:
    QPushButton *acceptButton;
    QTextEdit *textEdit;
    QPlainTextEdit *conclusionEdit;
    QPushButton *skipButton;

    void setupUi(QWidget *Confirm)
    {
        if (Confirm->objectName().isEmpty())
            Confirm->setObjectName(QLatin1String("Confirm"));
        Confirm->resize(950, 678);
        acceptButton = new QPushButton(Confirm);
        acceptButton->setObjectName(QLatin1String("acceptButton"));
        acceptButton->setGeometry(QRect(740, 10, 191, 31));
        textEdit = new QTextEdit(Confirm);
        textEdit->setObjectName(QLatin1String("textEdit"));
        textEdit->setGeometry(QRect(10, 90, 700, 291));
        conclusionEdit = new QPlainTextEdit(Confirm);
        conclusionEdit->setObjectName(QLatin1String("conclusionEdit"));
        conclusionEdit->setGeometry(QRect(10, 10, 700, 71));
        conclusionEdit->setMaximumSize(QSize(16777215, 78));
        conclusionEdit->setAutoFillBackground(false);
        conclusionEdit->setStyleSheet(QLatin1String("background-color: rgb(225, 225, 225)"));
        conclusionEdit->setReadOnly(true);
        skipButton = new QPushButton(Confirm);
        skipButton->setObjectName(QLatin1String("skipButton"));
        skipButton->setGeometry(QRect(740, 50, 191, 31));

        retranslateUi(Confirm);

        QMetaObject::connectSlotsByName(Confirm);
    } // setupUi

    void retranslateUi(QWidget *Confirm)
    {
        Confirm->setWindowTitle(QApplication::translate("Confirm", "Form", nullptr));
        acceptButton->setText(QApplication::translate("Confirm", "\320\237\321\200\320\276\320\264\320\276\320\273\320\266\320\270\321\202\321\214", nullptr));
        conclusionEdit->setPlainText(QApplication::translate("Confirm", "\320\241\320\276\320\263\320\273\320\260\321\201\320\275\321\213 \320\273\320\270 \320\222\321\213 \321\201 \320\277\320\276\320\273\321\203\321\207\320\265\320\275\320\275\321\213\320\274 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\320\276\320\274?\n"
"\320\225\321\201\320\273\320\270 \320\275\320\265\321\202, \321\202\320\276 \320\262\321\213 \320\274\320\276\320\266\320\265\321\202\320\265 \321\201\320\272\320\276\321\200\321\200\320\265\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202 \320\270\320\273\320\270 \320\275\320\265 \321\201\320\276\321\205\321\200\320\260\320\275\321\217\321\202\321\214 \320\265\320\263\320\276, \320\275\320\260\320\266\320\260\320\262 \320\272\320\275\320\276\320\277\320\272\321\203 \"\320\237\321\200\320\276\320\277\321\203\321\201\321\202\320\270\321\202\321\214\".", nullptr));
        skipButton->setText(QApplication::translate("Confirm", "\320\237\321\200\320\276\320\277\321\203\321\201\321\202\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Confirm: public Ui_Confirm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRM_H
