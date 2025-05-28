/********************************************************************************
** Form generated from reading UI file 'diffconcepts.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIFFCONCEPTS_H
#define UI_DIFFCONCEPTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DiffConcepts
{
public:
    QPushButton *continue1;
    QLabel *label;
    QLabel *concept1;
    QLabel *label_2;
    QLabel *concept2;
    QLabel *concept3;
    QComboBox *pos_pole;
    QLabel *label_5;
    QLabel *label_3;
    QPlainTextEdit *conclusionEdit;

    void setupUi(QWidget *DiffConcepts)
    {
        if (DiffConcepts->objectName().isEmpty())
            DiffConcepts->setObjectName(QLatin1String("DiffConcepts"));
        DiffConcepts->resize(953, 368);
        continue1 = new QPushButton(DiffConcepts);
        continue1->setObjectName(QLatin1String("continue1"));
        continue1->setGeometry(QRect(740, 10, 191, 31));
        continue1->setFlat(false);
        label = new QLabel(DiffConcepts);
        label->setObjectName(QLatin1String("label"));
        label->setGeometry(QRect(20, 80, 16, 31));
        concept1 = new QLabel(DiffConcepts);
        concept1->setObjectName(QLatin1String("concept1"));
        concept1->setGeometry(QRect(40, 80, 311, 31));
        label_2 = new QLabel(DiffConcepts);
        label_2->setObjectName(QLatin1String("label_2"));
        label_2->setGeometry(QRect(20, 120, 16, 31));
        concept2 = new QLabel(DiffConcepts);
        concept2->setObjectName(QLatin1String("concept2"));
        concept2->setGeometry(QRect(40, 120, 311, 31));
        concept3 = new QLabel(DiffConcepts);
        concept3->setObjectName(QLatin1String("concept3"));
        concept3->setGeometry(QRect(40, 160, 311, 31));
        pos_pole = new QComboBox(DiffConcepts);
        pos_pole->addItem(QString());
        pos_pole->setObjectName(QLatin1String("pos_pole"));
        pos_pole->setGeometry(QRect(10, 230, 700, 25));
        pos_pole->setEditable(true);
        pos_pole->setDuplicatesEnabled(true);
        label_5 = new QLabel(DiffConcepts);
        label_5->setObjectName(QLatin1String("label_5"));
        label_5->setGeometry(QRect(10, 200, 381, 17));
        label_3 = new QLabel(DiffConcepts);
        label_3->setObjectName(QLatin1String("label_3"));
        label_3->setGeometry(QRect(20, 160, 16, 31));
        conclusionEdit = new QPlainTextEdit(DiffConcepts);
        conclusionEdit->setObjectName(QLatin1String("conclusionEdit"));
        conclusionEdit->setGeometry(QRect(10, 10, 700, 58));
        conclusionEdit->setMaximumSize(QSize(16777215, 78));
        conclusionEdit->setAutoFillBackground(false);
        conclusionEdit->setStyleSheet(QLatin1String("background-color: rgb(225, 225, 225)"));
        conclusionEdit->setReadOnly(true);

        retranslateUi(DiffConcepts);

        pos_pole->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DiffConcepts);
    } // setupUi

    void retranslateUi(QWidget *DiffConcepts)
    {
        DiffConcepts->setWindowTitle(QApplication::translate("DiffConcepts", "Form", nullptr));
        continue1->setText(QApplication::translate("DiffConcepts", "\320\224\320\260\320\273\320\265\320\265", nullptr));
        label->setText(QApplication::translate("DiffConcepts", "1)", nullptr));
        concept1->setText(QApplication::translate("DiffConcepts", "\320\227\320\260\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265", nullptr));
        label_2->setText(QApplication::translate("DiffConcepts", "2)", nullptr));
        concept2->setText(QApplication::translate("DiffConcepts", "\320\227\320\260\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265", nullptr));
        concept3->setText(QApplication::translate("DiffConcepts", "\320\227\320\260\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265", nullptr));
        pos_pole->setItemText(0, QString());

        label_5->setText(QApplication::translate("DiffConcepts", "\320\232\321\200\320\270\321\202\320\265\321\200\320\270\320\271:", nullptr));
        label_3->setText(QApplication::translate("DiffConcepts", "3)", nullptr));
        conclusionEdit->setPlainText(QApplication::translate("DiffConcepts", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\270\320\267 \321\201\320\277\320\270\321\201\320\272\320\260 \320\270\320\273\320\270 \320\262\320\262\320\265\320\264\320\270\321\202\320\265 \321\201\320\262\320\276\320\271 \320\272\321\200\320\270\321\202\320\265\321\200\320\270\320\271, \320\277\320\276 \320\272\320\276\321\202\320\276\321\200\320\276\320\274\321\203 \320\277\320\265\321\200\320\262\320\276\320\265 \320\267\320\260\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265 \320\276\321\202\320\273\320\270\321\207\320\260\320\265\321\202\321\201\321\217 \320\276\321\202 \320\264\320\262\321\203\321\205 \320\264\321\200\321\203\320\263\320\270\321\205, \320\270\320\273\320\270 \320\275\320\260\320\266\320\274\320\270\321\202\320\265 \"\320\224\320\260\320\273\320\265\320\265\",  \320\265\321\201\320\273\320\270 \321\202\320\260\320\272\320\276\320\263\320\276 \320\272\321\200\320\270\321\202\320\265\321\200\320\270\321\217 \320\275\320\265\321\202.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DiffConcepts: public Ui_DiffConcepts {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIFFCONCEPTS_H
