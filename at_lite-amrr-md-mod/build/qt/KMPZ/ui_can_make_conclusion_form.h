/********************************************************************************
** Form generated from reading UI file 'can_make_conclusion_form.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAN_MAKE_CONCLUSION_FORM_H
#define UI_CAN_MAKE_CONCLUSION_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CanMakeConclusionForm
{
public:
    QPlainTextEdit *conclusionEdit;
    QLabel *questionLabel;
    QLineEdit *questionEdit;
    QLabel *answerLabel;
    QLineEdit *answerEdit;
    QPushButton *yesButton;
    QPushButton *noButton;
    QPushButton *visualiseButton;

    void setupUi(QWidget *CanMakeConclusionForm)
    {
        if (CanMakeConclusionForm->objectName().isEmpty())
            CanMakeConclusionForm->setObjectName(QLatin1String("CanMakeConclusionForm"));
        CanMakeConclusionForm->resize(957, 210);
        CanMakeConclusionForm->setMaximumSize(QSize(16777215, 210));
        QFont font;
        font.setFamily(QLatin1String("MS Shell Dlg 2"));
        font.setPointSize(8);
        CanMakeConclusionForm->setFont(font);
        conclusionEdit = new QPlainTextEdit(CanMakeConclusionForm);
        conclusionEdit->setObjectName(QLatin1String("conclusionEdit"));
        conclusionEdit->setGeometry(QRect(10, 10, 700, 58));
        conclusionEdit->setMaximumSize(QSize(16777215, 78));
        conclusionEdit->setAutoFillBackground(false);
        conclusionEdit->setStyleSheet(QLatin1String("background-color: rgb(225, 225, 225)"));
        conclusionEdit->setReadOnly(true);
        questionLabel = new QLabel(CanMakeConclusionForm);
        questionLabel->setObjectName(QLatin1String("questionLabel"));
        questionLabel->setGeometry(QRect(10, 80, 81, 19));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        questionLabel->setFont(font1);
        questionLabel->setTextFormat(Qt::RichText);
        questionEdit = new QLineEdit(CanMakeConclusionForm);
        questionEdit->setObjectName(QLatin1String("questionEdit"));
        questionEdit->setGeometry(QRect(10, 110, 700, 25));
        questionEdit->setMaximumSize(QSize(16777215, 16777215));
        questionEdit->setReadOnly(true);
        answerLabel = new QLabel(CanMakeConclusionForm);
        answerLabel->setObjectName(QLatin1String("answerLabel"));
        answerLabel->setGeometry(QRect(10, 140, 71, 19));
        answerLabel->setFont(font1);
        answerEdit = new QLineEdit(CanMakeConclusionForm);
        answerEdit->setObjectName(QLatin1String("answerEdit"));
        answerEdit->setGeometry(QRect(10, 170, 700, 25));
        answerEdit->setMaximumSize(QSize(16777215, 16777215));
        answerEdit->setReadOnly(true);
        yesButton = new QPushButton(CanMakeConclusionForm);
        yesButton->setObjectName(QLatin1String("yesButton"));
        yesButton->setGeometry(QRect(740, 10, 191, 31));
        noButton = new QPushButton(CanMakeConclusionForm);
        noButton->setObjectName(QLatin1String("noButton"));
        noButton->setGeometry(QRect(740, 50, 191, 31));
        visualiseButton = new QPushButton(CanMakeConclusionForm);
        visualiseButton->setObjectName(QLatin1String("visualiseButton"));
        visualiseButton->setEnabled(false);
        visualiseButton->setGeometry(QRect(740, 90, 191, 31));

        retranslateUi(CanMakeConclusionForm);

        QMetaObject::connectSlotsByName(CanMakeConclusionForm);
    } // setupUi

    void retranslateUi(QWidget *CanMakeConclusionForm)
    {
        CanMakeConclusionForm->setWindowTitle(QApplication::translate("CanMakeConclusionForm", "Dialog", nullptr));
        conclusionEdit->setPlainText(QApplication::translate("CanMakeConclusionForm", "\320\234\320\276\320\266\320\265\321\202\320\265 \320\273\320\270 \320\222\321\213 \321\201\320\264\320\265\320\273\320\260\321\202\321\214 \320\267\320\260\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265?", nullptr));
        questionLabel->setText(QApplication::translate("CanMakeConclusionForm", "\320\222\320\276\320\277\321\200\320\276\321\201:", nullptr));
        questionEdit->setText(QString());
        answerLabel->setText(QApplication::translate("CanMakeConclusionForm", "\320\236\321\202\320\262\320\265\321\202:", nullptr));
        answerEdit->setText(QString());
        yesButton->setText(QApplication::translate("CanMakeConclusionForm", "\320\224\320\260", nullptr));
        noButton->setText(QApplication::translate("CanMakeConclusionForm", "\320\235\320\265\321\202", nullptr));
        visualiseButton->setText(QApplication::translate("CanMakeConclusionForm", "\320\222\320\270\320\267\321\203\320\260\320\273\320\270\320\267\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CanMakeConclusionForm: public Ui_CanMakeConclusionForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAN_MAKE_CONCLUSION_FORM_H
