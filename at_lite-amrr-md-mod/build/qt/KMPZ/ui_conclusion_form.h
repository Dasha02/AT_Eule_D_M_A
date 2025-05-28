/********************************************************************************
** Form generated from reading UI file 'conclusion_form.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONCLUSION_FORM_H
#define UI_CONCLUSION_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConclusionForm
{
public:
    QPushButton *visualiseButton;
    QPushButton *inputButton;
    QPushButton *abortButton;
    QTextBrowser *textBrowser;
    QLabel *label;
    QTextBrowser *textBrowser_2;
    QPushButton *fuzzyButton;
    QLineEdit *conclusion;
    QTextBrowser *textBrowser_5;
    QPushButton *temporalButton;

    void setupUi(QWidget *ConclusionForm)
    {
        if (ConclusionForm->objectName().isEmpty())
            ConclusionForm->setObjectName(QLatin1String("ConclusionForm"));
        ConclusionForm->resize(953, 430);
        visualiseButton = new QPushButton(ConclusionForm);
        visualiseButton->setObjectName(QLatin1String("visualiseButton"));
        visualiseButton->setGeometry(QRect(740, 50, 191, 31));
        inputButton = new QPushButton(ConclusionForm);
        inputButton->setObjectName(QLatin1String("inputButton"));
        inputButton->setGeometry(QRect(740, 10, 191, 31));
        abortButton = new QPushButton(ConclusionForm);
        abortButton->setObjectName(QLatin1String("abortButton"));
        abortButton->setGeometry(QRect(740, 90, 191, 31));
        textBrowser = new QTextBrowser(ConclusionForm);
        textBrowser->setObjectName(QLatin1String("textBrowser"));
        textBrowser->setGeometry(QRect(10, 10, 700, 71));
        textBrowser->setMouseTracking(false);
        label = new QLabel(ConclusionForm);
        label->setObjectName(QLatin1String("label"));
        label->setGeometry(QRect(10, 90, 171, 16));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        textBrowser_2 = new QTextBrowser(ConclusionForm);
        textBrowser_2->setObjectName(QLatin1String("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(10, 150, 700, 71));
        textBrowser_2->setMouseTracking(false);
        fuzzyButton = new QPushButton(ConclusionForm);
        fuzzyButton->setObjectName(QLatin1String("fuzzyButton"));
        fuzzyButton->setGeometry(QRect(10, 230, 700, 31));
        conclusion = new QLineEdit(ConclusionForm);
        conclusion->setObjectName(QLatin1String("conclusion"));
        conclusion->setGeometry(QRect(10, 120, 700, 20));
        textBrowser_5 = new QTextBrowser(ConclusionForm);
        textBrowser_5->setObjectName(QLatin1String("textBrowser_5"));
        textBrowser_5->setGeometry(QRect(10, 270, 700, 71));
        textBrowser_5->setMouseTracking(false);
        textBrowser_5->setStyleSheet(QLatin1String("background-color: rgb(225, 225, 225)"));
        temporalButton = new QPushButton(ConclusionForm);
        temporalButton->setObjectName(QLatin1String("temporalButton"));
        temporalButton->setGeometry(QRect(10, 350, 700, 31));

        retranslateUi(ConclusionForm);

        QMetaObject::connectSlotsByName(ConclusionForm);
    } // setupUi

    void retranslateUi(QWidget *ConclusionForm)
    {
        visualiseButton->setText(QApplication::translate("ConclusionForm", "\320\222\320\270\320\267\321\203\320\260\320\273\320\270\320\267\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        inputButton->setText(QApplication::translate("ConclusionForm", "\320\222\320\262\320\265\321\201\321\202\320\270", nullptr));
        abortButton->setText(QApplication::translate("ConclusionForm", "\320\237\321\200\320\265\321\200\320\262\320\260\321\202\321\214", nullptr));
        textBrowser->setStyleSheet(QApplication::translate("ConclusionForm", "background-color: rgb(225, 225, 225)", nullptr));
        textBrowser->setHtml(QApplication::translate("ConclusionForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8.25pt;\">\320\241\321\204\320\276\321\200\320\274\321\203\320\273\320\270\321\200\321\203\320\271\321\202\320\265 \320\267\320\260\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265 \320\276 \321\201\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\270 \320\277\320\260\321\206\320\270\320\265\320\275\321\202\320\260, \320\272\320\276\321\202\320\276\321\200\320\276\320\265 \320\274\320\276\320\266\320\275\320\276 \321\201\320\264\320\265\320\273\320\260\321\202\321\214 \320\262 \320\264\320\260\320\275\320\275"
                        "\320\276\320\271 \321\201\320\270\321\202\321\203\320\260\321\206\320\270\320\270</span></p></body></html>", nullptr));
        label->setText(QApplication::translate("ConclusionForm", "\320\222\320\260\321\210\320\265 \320\267\320\260\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265:", nullptr));
        textBrowser_2->setStyleSheet(QApplication::translate("ConclusionForm", "background-color: rgb(225, 225, 225)", nullptr));
        textBrowser_2->setHtml(QApplication::translate("ConclusionForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8.25pt;\">\320\225\321\201\320\273\320\270 \320\222\321\213 \320\275\320\265 \321\203\320\262\320\265\321\200\320\265\320\275\321\213 \320\262 \320\264\320\276\321\201\321\202\320\276\320\262\320\265\321\200\320\275\320\276\321\201\321\202\320\270 \320\262\320\262\320\265\320\264\320\265\320\275\320\275\320\276\320\271 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\320\270, \321\202\320\276 \320\274\320\276\320\266\320\265\321\202\320\265 \320\262\320\276\321\201\320\277\320\276\320\273\321\214\320\267\320\276"
                        "\320\262\320\260\321\202\321\214\321\201\321\217 \320\272\320\275\320\276\320\277\320\272\320\276\320\271 &quot;\320\230\320\275\321\201\321\202\321\200\321\203\320\274\320\265\320\275\321\202\321\213&quot;</span></p></body></html>", nullptr));
        fuzzyButton->setText(QApplication::translate("ConclusionForm", "\320\230\320\275\321\201\321\202\321\200\321\203\320\274\320\265\320\275\321\202\321\213", nullptr));
        textBrowser_5->setHtml(QApplication::translate("ConclusionForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8.25pt;\">\320\225\321\201\320\273\320\270 \320\222\321\213 \321\205\320\276\321\202\320\270\321\202\320\265 \320\262\320\262\320\265\321\201\321\202\320\270 \320\262\321\200\320\265\320\274\320\265\320\275\320\275\321\213\320\265 \321\205\320\260\321\200\320\260\320\272\321\202\320\265\321\200\320\270\321\201\321\202\320\270\320\272\320\270, \320\262\320\276\321\201\320\277\320\276\320\273\321\214\320\267\321\203\320\271\321\202\320\265\321\201\321\214 \320\272\320\275\320\276\320\277\320\272\320\276\320\271 &quot;\320\222\321\200\320"
                        "\265\320\274\320\265\320\275\320\275\320\260\321\217 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217&quot;</span></p></body></html>", nullptr));
        temporalButton->setText(QApplication::translate("ConclusionForm", "\320\222\321\200\320\265\320\274\320\265\320\275\320\275\320\260\321\217 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", nullptr));
        Q_UNUSED(ConclusionForm);
    } // retranslateUi

};

namespace Ui {
    class ConclusionForm: public Ui_ConclusionForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONCLUSION_FORM_H
