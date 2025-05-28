/********************************************************************************
** Form generated from reading UI file 'instruction.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSTRUCTION_H
#define UI_INSTRUCTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Instruction
{
public:
    QTextBrowser *infoToExpert;
    QPushButton *okButton;
    QPushButton *skipButton;

    void setupUi(QWidget *Instruction)
    {
        if (Instruction->objectName().isEmpty())
            Instruction->setObjectName(QLatin1String("Instruction"));
        Instruction->resize(953, 297);
        infoToExpert = new QTextBrowser(Instruction);
        infoToExpert->setObjectName(QLatin1String("infoToExpert"));
        infoToExpert->setGeometry(QRect(10, 10, 700, 261));
        okButton = new QPushButton(Instruction);
        okButton->setObjectName(QLatin1String("okButton"));
        okButton->setGeometry(QRect(740, 10, 191, 31));
        skipButton = new QPushButton(Instruction);
        skipButton->setObjectName(QLatin1String("skipButton"));
        skipButton->setGeometry(QRect(740, 50, 191, 31));

        retranslateUi(Instruction);

        QMetaObject::connectSlotsByName(Instruction);
    } // setupUi

    void retranslateUi(QWidget *Instruction)
    {
        Instruction->setWindowTitle(QApplication::translate("Instruction", "Form", nullptr));
        infoToExpert->setHtml(QApplication::translate("Instruction", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">\320\243\320\262\320\260\320\266\320\260\320\265\320\274\321\213\320\271 \321\215\320\272\321\201\320\277\320\265\321\200\321\202, \320\222\321\213 \320\262\320\262\320\265\320\273\320\270 \320\275\320\265\321\201\320\272\320\276\320\273\321\214\320\272\320\276 \320\267\320\260\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\271 \320\264\320\273\321\217 \320\276\320\264\320\275\320\270\321\205 \320\270 \321\202\320\265\321\205 \320\266\320\265 \321\203\321\201\320\273\320\276\320\262\320\270"
                        "\320\271. <br /></span></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">\320\222 \321\202\320\265\320\272\321\203\321\211\320\265\320\274 \320\272\320\276\320\274\320\277\320\276\320\275\320\265\320\275\321\202\320\265 \320\222\320\260\320\274 \320\261\321\203\320\264\321\203\321\202 \320\277\321\200\320\265\320\264\321\201\321\202\320\260\320\262\320\273\320\265\320\275\321\213 \321\200\320\260\320\267\320\273\320\270\321\207\320\275\321\213\320\265 \320\272\320\276\320\274\320\261\320\270\320\275\320\260\321\206\320\270\320\270 \320\262\320\262\320\265\320\264\320\265\320\275\320\275\321\213\321\205 \320\222\320\260\320\274\320\270 \321\200\320\260\320\275\320\265\320\265 \320\267\320\260\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\271 \321\201 \321\206\320\265\320\273\321\214\321\216 \320\262\321\213\321\217\320\262\320\273\320\265\320\275\320\270\321"
                        "\217 \320\277\321\200\320\270\320\267\320\275\320\260\320\272\320\276\320\262, \320\277\320\276\320\267\320\262\320\276\320\273\321\217\321\216\321\211\320\270\321\205 \320\270\321\205 \320\262 \320\264\320\260\320\273\321\214\320\275\320\265\320\271\321\210\320\265\320\274 \320\276\321\202\320\273\320\270\321\207\320\270\321\202\321\214 \320\264\321\200\321\203\320\263 \320\276\321\202 \320\264\321\200\321\203\320\263\320\260.</span></p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2';\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">\320\222\320\260\320\274 \320\261\321\203\320\264\320\265\321\202 \320\275\320\265\320\276\320\261\321\205\320\276\320\264\320\270\320\274\320\276 \321\201\320\272\320\260\320\267\320"
                        "\260\321\202\321\214, \320\276\321\202\320\273\320\270\321\207\320\260\320\265\321\202\321\201\321\217 \320\273\320\270 \320\277\320\265\321\200\320\262\321\213\320\271 \321\201\320\270\320\274\320\277\321\202\320\276\320\274 \320\262 \321\202\321\200\320\276\320\271\320\272\320\265 \320\276\321\202 \320\264\320\262\321\203\321\205 \320\276\321\201\321\202\320\260\320\262\321\210\320\270\321\205\321\201\321\217, \320\270 \320\265\321\201\320\273\320\270 \320\276\321\202\320\273\320\270\321\207\320\260\320\265\321\202\321\201\321\217, \321\202\320\276 \320\277\320\276 \320\272\320\260\320\272\320\276\320\274\321\203 \320\272\321\200\320\270\321\202\320\265\321\200\320\270\321\216.</span></p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2';\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-in"
                        "dent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">\320\237\320\276\321\201\320\273\320\265 \320\277\320\276\320\272\320\260\320\267\320\260 \320\262\321\201\320\265\321\205 \320\272\320\276\320\274\320\261\320\270\320\275\320\260\321\206\320\270\320\271 \320\222\320\260\320\274 \320\275\320\265\320\276\320\261\321\205\320\276\320\264\320\270\320\274\320\276 \320\261\321\203\320\264\320\265\321\202 \320\267\320\260\320\277\320\276\320\273\320\275\320\270\321\202\321\214 \321\202\320\260\320\261\320\273\320\270\321\206\321\203 \320\277\320\276 \320\270\320\275\321\201\321\202\321\200\321\203\320\272\321\206\320\270\320\270, \321\200\320\260\321\201\320\277\320\276\320\273\320\276\320\266\320\265\320\275\320\275\320\276\320\271 \321\200\321\217\320\264\320\276\320\274 \321\201 \320\275\320\265\320\271.</span></p>\n"
"<p align=\"justify\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'"
                        "MS Shell Dlg 2';\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">\320\235\320\260\320\266\320\274\320\270\321\202\320\265 &quot;\320\224\320\260\320\273\320\265\320\265&quot;, \321\207\321\202\320\276\320\261\321\213 \320\275\320\260\321\207\320\260\321\202\321\214, \320\270\320\273\320\270 &quot;\320\237\321\200\320\276\320\277\321\203\321\201\321\202\320\270\321\202\321\214&quot;, \321\207\321\202\320\276\320\261\321\213 \320\277\321\200\320\276\320\277\321\203\321\201\321\202\320\270\321\202\321\214 \320\264\320\260\320\275\320\275\321\213\320\271 \320\274\320\276\320\264\321\203\320\273\321\214.</span></p></body></html>", nullptr));
        okButton->setText(QApplication::translate("Instruction", "\320\224\320\260\320\273\320\265\320\265", nullptr));
        skipButton->setText(QApplication::translate("Instruction", "\320\237\321\200\320\276\320\277\321\203\321\201\321\202\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Instruction: public Ui_Instruction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSTRUCTION_H
