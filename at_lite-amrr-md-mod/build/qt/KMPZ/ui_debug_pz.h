/********************************************************************************
** Form generated from reading UI file 'debug_pz.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEBUG_PZ_H
#define UI_DEBUG_PZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DebugPZ
{
public:
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *DebugPZ)
    {
        if (DebugPZ->objectName().isEmpty())
            DebugPZ->setObjectName(QLatin1String("DebugPZ"));
        DebugPZ->resize(716, 803);
        QFont font;
        font.setPointSize(12);
        DebugPZ->setFont(font);
        verticalLayout = new QVBoxLayout(DebugPZ);
        verticalLayout->setObjectName(QLatin1String("verticalLayout"));
        plainTextEdit = new QPlainTextEdit(DebugPZ);
        plainTextEdit->setObjectName(QLatin1String("plainTextEdit"));

        verticalLayout->addWidget(plainTextEdit);

        pushButton = new QPushButton(DebugPZ);
        pushButton->setObjectName(QLatin1String("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(DebugPZ);

        QMetaObject::connectSlotsByName(DebugPZ);
    } // setupUi

    void retranslateUi(QDialog *DebugPZ)
    {
        DebugPZ->setWindowTitle(QApplication::translate("DebugPZ", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("DebugPZ", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DebugPZ: public Ui_DebugPZ {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEBUG_PZ_H
