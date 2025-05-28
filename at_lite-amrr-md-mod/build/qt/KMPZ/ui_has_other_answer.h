/********************************************************************************
** Form generated from reading UI file 'has_other_answer.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HAS_OTHER_ANSWER_H
#define UI_HAS_OTHER_ANSWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HasOtherAnswerForm
{
public:
    QLineEdit *questionEdit;
    QPushButton *yesButton;
    QPushButton *noButton;
    QPushButton *visualiseButton;
    QPlainTextEdit *questionLabel;

    void setupUi(QWidget *HasOtherAnswerForm)
    {
        if (HasOtherAnswerForm->objectName().isEmpty())
            HasOtherAnswerForm->setObjectName(QLatin1String("HasOtherAnswerForm"));
        HasOtherAnswerForm->resize(1009, 148);
        HasOtherAnswerForm->setMaximumSize(QSize(16777215, 148));
        questionEdit = new QLineEdit(HasOtherAnswerForm);
        questionEdit->setObjectName(QLatin1String("questionEdit"));
        questionEdit->setGeometry(QRect(10, 80, 700, 25));
        questionEdit->setReadOnly(true);
        yesButton = new QPushButton(HasOtherAnswerForm);
        yesButton->setObjectName(QLatin1String("yesButton"));
        yesButton->setGeometry(QRect(740, 10, 191, 31));
        noButton = new QPushButton(HasOtherAnswerForm);
        noButton->setObjectName(QLatin1String("noButton"));
        noButton->setGeometry(QRect(740, 50, 191, 31));
        visualiseButton = new QPushButton(HasOtherAnswerForm);
        visualiseButton->setObjectName(QLatin1String("visualiseButton"));
        visualiseButton->setEnabled(false);
        visualiseButton->setGeometry(QRect(740, 90, 191, 31));
        questionLabel = new QPlainTextEdit(HasOtherAnswerForm);
        questionLabel->setObjectName(QLatin1String("questionLabel"));
        questionLabel->setEnabled(true);
        questionLabel->setGeometry(QRect(10, 10, 700, 61));
        questionLabel->setStyleSheet(QLatin1String("background-color: rgb(225, 225, 225)"));
        questionLabel->setReadOnly(true);

        retranslateUi(HasOtherAnswerForm);

        QMetaObject::connectSlotsByName(HasOtherAnswerForm);
    } // setupUi

    void retranslateUi(QWidget *HasOtherAnswerForm)
    {
        HasOtherAnswerForm->setWindowTitle(QApplication::translate("HasOtherAnswerForm", "Dialog", nullptr));
        questionEdit->setText(QString());
        yesButton->setText(QApplication::translate("HasOtherAnswerForm", "\320\224\320\260", nullptr));
        noButton->setText(QApplication::translate("HasOtherAnswerForm", "\320\235\320\265\321\202", nullptr));
        visualiseButton->setText(QApplication::translate("HasOtherAnswerForm", "\320\222\320\270\320\267\321\203\320\260\320\273\320\270\320\267\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        questionLabel->setPlainText(QApplication::translate("HasOtherAnswerForm", "\320\234\320\276\320\266\320\275\320\276 \320\273\320\270 \320\264\320\260\321\202\321\214 \320\265\321\211\320\265 \320\276\320\264\320\270\320\275 \320\276\321\202\320\262\320\265\321\202 \320\275\320\260 \320\262\320\276\320\277\321\200\320\276\321\201?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HasOtherAnswerForm: public Ui_HasOtherAnswerForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HAS_OTHER_ANSWER_H
