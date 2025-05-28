/********************************************************************************
** Form generated from reading UI file 'clearifying_information_form.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLEARIFYING_INFORMATION_FORM_H
#define UI_CLEARIFYING_INFORMATION_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClearifyingInformationForm
{
public:
    QPushButton *inputButton;
    QPushButton *visualiseButton;
    QTextBrowser *textBrowser;
    QLabel *label;
    QComboBox *comboBox_sex;
    QLabel *label_2;
    QComboBox *comboBox_profVrednost;
    QLabel *label_3;
    QComboBox *comboBox_oslozhneniya;
    QLabel *label_5;
    QComboBox *comboBox_perenesZabol;
    QLabel *label_4;
    QComboBox *comboBox_age;

    void setupUi(QWidget *ClearifyingInformationForm)
    {
        if (ClearifyingInformationForm->objectName().isEmpty())
            ClearifyingInformationForm->setObjectName(QLatin1String("ClearifyingInformationForm"));
        ClearifyingInformationForm->resize(985, 300);
        inputButton = new QPushButton(ClearifyingInformationForm);
        inputButton->setObjectName(QLatin1String("inputButton"));
        inputButton->setGeometry(QRect(740, 10, 191, 31));
        visualiseButton = new QPushButton(ClearifyingInformationForm);
        visualiseButton->setObjectName(QLatin1String("visualiseButton"));
        visualiseButton->setEnabled(false);
        visualiseButton->setGeometry(QRect(740, 50, 191, 31));
        textBrowser = new QTextBrowser(ClearifyingInformationForm);
        textBrowser->setObjectName(QLatin1String("textBrowser"));
        textBrowser->setGeometry(QRect(10, 10, 700, 81));
        textBrowser->setMouseTracking(false);
        label = new QLabel(ClearifyingInformationForm);
        label->setObjectName(QLatin1String("label"));
        label->setGeometry(QRect(10, 150, 41, 16));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        comboBox_sex = new QComboBox(ClearifyingInformationForm);
        comboBox_sex->setObjectName(QLatin1String("comboBox_sex"));
        comboBox_sex->setGeometry(QRect(330, 150, 381, 22));
        label_2 = new QLabel(ClearifyingInformationForm);
        label_2->setObjectName(QLatin1String("label_2"));
        label_2->setGeometry(QRect(10, 190, 291, 21));
        label_2->setFont(font);
        comboBox_profVrednost = new QComboBox(ClearifyingInformationForm);
        comboBox_profVrednost->setObjectName(QLatin1String("comboBox_profVrednost"));
        comboBox_profVrednost->setGeometry(QRect(330, 190, 381, 22));
        label_3 = new QLabel(ClearifyingInformationForm);
        label_3->setObjectName(QLatin1String("label_3"));
        label_3->setGeometry(QRect(10, 270, 371, 21));
        label_3->setFont(font);
        comboBox_oslozhneniya = new QComboBox(ClearifyingInformationForm);
        comboBox_oslozhneniya->setObjectName(QLatin1String("comboBox_oslozhneniya"));
        comboBox_oslozhneniya->setGeometry(QRect(330, 270, 381, 22));
        label_5 = new QLabel(ClearifyingInformationForm);
        label_5->setObjectName(QLatin1String("label_5"));
        label_5->setGeometry(QRect(10, 230, 261, 21));
        label_5->setFont(font);
        comboBox_perenesZabol = new QComboBox(ClearifyingInformationForm);
        comboBox_perenesZabol->setObjectName(QLatin1String("comboBox_perenesZabol"));
        comboBox_perenesZabol->setGeometry(QRect(330, 230, 381, 22));
        label_4 = new QLabel(ClearifyingInformationForm);
        label_4->setObjectName(QLatin1String("label_4"));
        label_4->setGeometry(QRect(10, 110, 181, 21));
        label_4->setFont(font);
        comboBox_age = new QComboBox(ClearifyingInformationForm);
        comboBox_age->setObjectName(QLatin1String("comboBox_age"));
        comboBox_age->setGeometry(QRect(330, 110, 381, 22));

        retranslateUi(ClearifyingInformationForm);

        QMetaObject::connectSlotsByName(ClearifyingInformationForm);
    } // setupUi

    void retranslateUi(QWidget *ClearifyingInformationForm)
    {
        ClearifyingInformationForm->setWindowTitle(QApplication::translate("ClearifyingInformationForm", "\320\222\320\262\320\276\320\264 \321\203\321\207\320\265\321\202\320\275\320\276\320\271 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\320\270 \320\276\320\261\321\212\320\265\320\272\321\202\320\260 \320\270\321\201\321\201\320\273\320\265\320\264\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        inputButton->setText(QApplication::translate("ClearifyingInformationForm", "\320\222\320\262\320\265\321\201\321\202\320\270", nullptr));
        visualiseButton->setText(QApplication::translate("ClearifyingInformationForm", "\320\222\320\270\320\267\321\203\320\260\320\273\320\270\320\267\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        textBrowser->setStyleSheet(QApplication::translate("ClearifyingInformationForm", "background-color: rgb(225, 225, 225)", nullptr));
        textBrowser->setHtml(QApplication::translate("ClearifyingInformationForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8.25pt;\">\320\235\320\260 \320\264\320\260\320\275\320\275\320\276\320\274 \321\215\321\202\320\260\320\277\320\265 \320\277\321\200\320\265\320\264\320\273\320\260\320\263\320\260\320\265\321\202\321\201\321\217, \320\265\321\201\320\273\320\270 \320\222\321\213 \321\201\321\207\320\270\321\202\320\260\320\265\321\202\320\265 \321\215\321\202\320\276 \320\275\320\265\320\276\320\261\321\205\320\276\320\264\320\270\320\274\321\213\320\274, \320\262\320\262\320\265\321\201\321\202\320\270 \321\203\321\207\320\265\321\202\320\275\321"
                        "\203\321\216 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\216 \320\276 \320\277\320\260\321\206\320\270\320\265\320\275\321\202\320\265, \320\272\320\276\321\202\320\276\321\200\320\260\321\217 \320\276\320\272\320\260\320\267\321\213\320\262\320\260\320\265\321\202 \321\201\321\203\321\211\320\265\321\201\321\202\320\262\320\265\320\275\320\275\320\276\320\265 \320\262\320\273\320\270\321\217\320\275\320\270\320\265 \320\275\320\260 \320\262\321\213\320\262\320\276\320\264 \320\267\320\260\320\272\320\273\321\216\321\207\320\265\320\275\320\270\321\217</span></p></body></html>", nullptr));
        label->setText(QApplication::translate("ClearifyingInformationForm", "\320\237\320\276\320\273", nullptr));
        label_2->setText(QApplication::translate("ClearifyingInformationForm", "\320\237\321\200\320\276\321\204\320\265\321\201\321\201\320\270\320\276\320\275\320\260\320\273\321\214\320\275\320\260\321\217 \320\262\321\200\320\265\320\264\320\275\320\276\321\201\321\202\321\214", nullptr));
        label_3->setText(QApplication::translate("ClearifyingInformationForm", "\320\236\321\201\320\273\320\276\320\266\320\275\320\265\320\275\320\270\321\217 \320\277\320\265\321\200\320\265\320\275\320\265\321\201\320\265\320\275\320\275\321\213\321\205 \320\267\320\260\320\261\320\276\320\273\320\265\320\262\320\260\320\275\320\270\320\271", nullptr));
        label_5->setText(QApplication::translate("ClearifyingInformationForm", "\320\237\320\265\321\200\320\265\320\275\320\265\321\201\320\265\320\275\320\275\321\213\320\265 \320\267\320\260\320\261\320\276\320\273\320\265\320\262\320\260\320\275\320\270\321\217", nullptr));
        label_4->setText(QApplication::translate("ClearifyingInformationForm", "\320\222\320\276\320\267\321\200\320\260\321\201\321\202 \320\277\320\260\321\206\320\270\320\265\320\275\321\202\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClearifyingInformationForm: public Ui_ClearifyingInformationForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLEARIFYING_INFORMATION_FORM_H
