/********************************************************************************
** Form generated from reading UI file 'no_diff_warning.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NO_DIFF_WARNING_H
#define UI_NO_DIFF_WARNING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_No_diff_warning
{
public:
    QPushButton *returnButton;
    QPushButton *endButton;
    QPlainTextEdit *conclusionEdit;

    void setupUi(QWidget *No_diff_warning)
    {
        if (No_diff_warning->objectName().isEmpty())
            No_diff_warning->setObjectName(QLatin1String("No_diff_warning"));
        No_diff_warning->resize(943, 276);
        returnButton = new QPushButton(No_diff_warning);
        returnButton->setObjectName(QLatin1String("returnButton"));
        returnButton->setGeometry(QRect(740, 10, 191, 31));
        endButton = new QPushButton(No_diff_warning);
        endButton->setObjectName(QLatin1String("endButton"));
        endButton->setGeometry(QRect(740, 50, 191, 31));
        conclusionEdit = new QPlainTextEdit(No_diff_warning);
        conclusionEdit->setObjectName(QLatin1String("conclusionEdit"));
        conclusionEdit->setGeometry(QRect(10, 10, 700, 121));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(conclusionEdit->sizePolicy().hasHeightForWidth());
        conclusionEdit->setSizePolicy(sizePolicy);
        conclusionEdit->setMaximumSize(QSize(16777215, 200));
        conclusionEdit->setAutoFillBackground(false);
        conclusionEdit->setStyleSheet(QLatin1String("background-color: rgb(225, 225, 225)"));
        conclusionEdit->setReadOnly(true);

        retranslateUi(No_diff_warning);

        QMetaObject::connectSlotsByName(No_diff_warning);
    } // setupUi

    void retranslateUi(QWidget *No_diff_warning)
    {
        No_diff_warning->setWindowTitle(QApplication::translate("No_diff_warning", "Form", nullptr));
        returnButton->setText(QApplication::translate("No_diff_warning", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214\321\201\321\217", nullptr));
        endButton->setText(QApplication::translate("No_diff_warning", "\320\227\320\260\320\262\320\265\321\200\321\210\320\270\321\202\321\214", nullptr));
        conclusionEdit->setPlainText(QApplication::translate("No_diff_warning", "\320\243\320\262\320\260\320\266\320\260\320\265\320\274\321\213\320\271 \321\215\320\272\321\201\320\277\320\265\321\200\321\202, \320\262 \321\205\320\276\320\264\320\265 \320\262\321\213\320\277\320\276\320\273\320\275\320\265\320\275\320\270\321\217 \320\264\320\260\320\275\320\275\320\276\320\263\320\276 \320\272\320\276\320\274\320\277\320\276\320\275\320\265\320\275\321\202\320\260, \320\262\321\213 \320\275\320\265 \320\262\320\262\320\265\320\273\320\270 \320\275\320\270 \320\276\320\264\320\275\320\276\320\263\320\276 \320\272\321\200\320\270\321\202\320\265\321\200\320\270\321\217, \320\272\320\276\321\202\320\276\321\200\321\213\320\271 \320\277\320\276\320\267\320\262\320\276\320\273\320\270\320\273 \320\261\321\213 \321\200\320\260\320\267\320\273\320\270\320\270\321\202\321\214 \321\201\321\205\320\276\320\266\320\270\320\265 \320\267\320\260\320\272\320\273\321\216\321\207\320\265\320\275\320\270\321\217. \n"
"\320\225\321\201\320\273\320\270 \320\262\321\213 \321\205\320\276\321\202\320\270\321"
                        "\202\320\265 \320\262\320\265\321\200\320\275\321\203\321\202\321\214\321\201\321\217 \320\272 \320\262\321\213\320\264\320\265\320\273\320\265\320\275\320\270\321\216 \320\264\320\260\320\275\320\275\321\213\321\205 \320\272\321\200\320\270\321\202\320\265\321\200\320\265\320\262, \321\202\320\276 \320\275\320\260\320\266\320\274\320\270\321\202\320\265 \320\275\320\260 \320\272\320\275\320\276\320\277\320\272\321\203 \"\320\222\320\265\321\200\320\275\321\203\321\202\321\214\321\201\321\217\". \n"
"\320\225\321\201\320\273\320\270 \320\262\321\213 \321\205\320\276\321\202\320\270\321\202\320\265 \320\267\320\260\320\262\320\265\321\200\321\210\320\270\321\202\321\214 \320\264\320\260\320\275\320\275\321\213\320\271 \321\215\321\202\320\260\320\277 \320\270 \320\277\320\265\321\200\320\265\320\271\321\202\320\270 \320\272 \321\201\320\273\320\265\320\264\321\203\321\216\321\211\320\265\320\274\321\203 \321\215\321\202\320\260\320\277\321\203, \321\202\320\276 \320\275\320\260\320\266\320\274\320\270\321\202\320"
                        "\265 \"\320\227\320\260\320\262\320\265\321\200\321\210\320\270\321\202\321\214\"", nullptr));
    } // retranslateUi

};

namespace Ui {
    class No_diff_warning: public Ui_No_diff_warning {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NO_DIFF_WARNING_H
