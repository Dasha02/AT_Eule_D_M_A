/********************************************************************************
** Form generated from reading UI file 'DSFEditor.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DSFEDITOR_H
#define UI_DSFEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ADSFEditor
{
public:
    QLabel *label;

    void setupUi(QWidget *ADSFEditor)
    {
        if (ADSFEditor->objectName().isEmpty())
            ADSFEditor->setObjectName(QLatin1String("ADSFEditor"));
        ADSFEditor->resize(400, 300);
        label = new QLabel(ADSFEditor);
        label->setObjectName(QLatin1String("label"));
        label->setGeometry(QRect(120, 140, 241, 16));

        retranslateUi(ADSFEditor);

        QMetaObject::connectSlotsByName(ADSFEditor);
    } // setupUi

    void retranslateUi(QWidget *ADSFEditor)
    {
        ADSFEditor->setWindowTitle(QApplication::translate("ADSFEditor", "ADSFEditor", nullptr));
        label->setText(QApplication::translate("ADSFEditor", "Dialogue Scenario Editor", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ADSFEditor: public Ui_ADSFEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DSFEDITOR_H
