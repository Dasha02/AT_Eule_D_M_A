/********************************************************************************
** Form generated from reading UI file 'question_answer_form.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUESTION_ANSWER_FORM_H
#define UI_QUESTION_ANSWER_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QuestionAnswerForm
{
public:
    QPushButton *nextButton;
    QPushButton *visualizeButton;
    QTextBrowser *textBrowser_3;
    QPushButton *nefactorsButton;
    QPushButton *tempInfoButton;
    QLineEdit *questionEdit;
    QLineEdit *answerEdit;
    QPlainTextEdit *questionLabel;
    QPlainTextEdit *answerLabel;

    void setupUi(QWidget *QuestionAnswerForm)
    {
        if (QuestionAnswerForm->objectName().isEmpty())
            QuestionAnswerForm->setObjectName(QLatin1String("QuestionAnswerForm"));
        QuestionAnswerForm->resize(952, 493);
        QFont font;
        font.setFamily(QLatin1String("MS Shell Dlg 2"));
        font.setPointSize(8);
        QuestionAnswerForm->setFont(font);
        nextButton = new QPushButton(QuestionAnswerForm);
        nextButton->setObjectName(QLatin1String("nextButton"));
        nextButton->setGeometry(QRect(740, 10, 191, 31));
        visualizeButton = new QPushButton(QuestionAnswerForm);
        visualizeButton->setObjectName(QLatin1String("visualizeButton"));
        visualizeButton->setEnabled(false);
        visualizeButton->setGeometry(QRect(740, 50, 191, 31));
        textBrowser_3 = new QTextBrowser(QuestionAnswerForm);
        textBrowser_3->setObjectName(QLatin1String("textBrowser_3"));
        textBrowser_3->setGeometry(QRect(10, 210, 700, 71));
        textBrowser_3->setMouseTracking(false);
        textBrowser_3->setStyleSheet(QLatin1String("background-color: rgb(225, 225, 225)"));
        nefactorsButton = new QPushButton(QuestionAnswerForm);
        nefactorsButton->setObjectName(QLatin1String("nefactorsButton"));
        nefactorsButton->setEnabled(false);
        nefactorsButton->setGeometry(QRect(10, 290, 700, 31));
        tempInfoButton = new QPushButton(QuestionAnswerForm);
        tempInfoButton->setObjectName(QLatin1String("tempInfoButton"));
        tempInfoButton->setGeometry(QRect(740, 90, 191, 31));
        questionEdit = new QLineEdit(QuestionAnswerForm);
        questionEdit->setObjectName(QLatin1String("questionEdit"));
        questionEdit->setGeometry(QRect(10, 80, 700, 20));
        answerEdit = new QLineEdit(QuestionAnswerForm);
        answerEdit->setObjectName(QLatin1String("answerEdit"));
        answerEdit->setGeometry(QRect(10, 180, 700, 20));
        questionLabel = new QPlainTextEdit(QuestionAnswerForm);
        questionLabel->setObjectName(QLatin1String("questionLabel"));
        questionLabel->setEnabled(true);
        questionLabel->setGeometry(QRect(10, 10, 700, 61));
        questionLabel->setStyleSheet(QLatin1String("background-color: rgb(225, 225, 225)"));
        questionLabel->setReadOnly(true);
        answerLabel = new QPlainTextEdit(QuestionAnswerForm);
        answerLabel->setObjectName(QLatin1String("answerLabel"));
        answerLabel->setGeometry(QRect(10, 110, 700, 61));
        answerLabel->setStyleSheet(QLatin1String("background-color: rgb(225, 225, 225)"));
        answerLabel->setReadOnly(true);

        retranslateUi(QuestionAnswerForm);

        QMetaObject::connectSlotsByName(QuestionAnswerForm);
    } // setupUi

    void retranslateUi(QWidget *QuestionAnswerForm)
    {
        QuestionAnswerForm->setWindowTitle(QApplication::translate("QuestionAnswerForm", "\320\224\320\270\320\260\320\263\320\275\320\276\321\201\321\202\320\270\320\272\320\260 \320\266\320\270\320\262\321\213\321\205 \320\276\320\261\321\212\320\265\320\272\321\202\320\276\320\262", nullptr));
        nextButton->setText(QApplication::translate("QuestionAnswerForm", "\320\224\320\260\320\273\320\265\320\265", nullptr));
        visualizeButton->setText(QApplication::translate("QuestionAnswerForm", "\320\222\320\270\320\267\321\203\320\260\320\273\320\270\320\267\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        textBrowser_3->setHtml(QApplication::translate("QuestionAnswerForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt;\">\320\225\321\201\320\273\320\270 \320\222\321\213 \320\275\320\265 \321\203\320\262\320\265\321\200\320\265\320\275\321\213 \320\262 \320\264\320\276\321\201\321\202\320\276\320\262\320\265\321\200\320\275\320\276\321\201\321\202\320\270 \320\262\320\262\320\265\320\264\320\265\320\275\320\275\320\276\320\271 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\320\270, \320\262\320\276\321\201\320\277\320\276\320\273\321\214\320\267\321\203\320\271\321\202\320\265\321\201\321"
                        "\214 \320\272\320\275\320\276\320\277\320\272\320\276\320\271 &quot;\320\230\320\275\321\201\321\202\321\200\321\203\320\274\320\265\320\275\321\202\321\213&quot;</span></p></body></html>", nullptr));
        nefactorsButton->setText(QApplication::translate("QuestionAnswerForm", "\320\230\320\275\321\201\321\202\321\200\321\203\320\274\320\265\320\275\321\202\321\213", nullptr));
        tempInfoButton->setText(QApplication::translate("QuestionAnswerForm", "\320\222\321\200\320\265\320\274\320\265\320\275\320\275\320\260\321\217 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", nullptr));
        questionEdit->setInputMask(QString());
        questionEdit->setText(QString());
        questionEdit->setPlaceholderText(QString());
        answerEdit->setText(QString());
        answerEdit->setPlaceholderText(QString());
        questionLabel->setPlainText(QApplication::translate("QuestionAnswerForm", "\320\243\320\272\320\260\320\266\320\270\321\202\320\265 \321\201\320\270\320\274\320\277\321\202\320\276\320\274", nullptr));
        answerLabel->setPlainText(QApplication::translate("QuestionAnswerForm", "\320\243\320\272\320\260\320\266\320\270\321\202\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \321\201\320\270\320\274\320\277\321\202\320\276\320\274\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QuestionAnswerForm: public Ui_QuestionAnswerForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESTION_ANSWER_FORM_H
