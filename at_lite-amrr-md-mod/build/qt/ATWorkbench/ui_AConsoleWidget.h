/********************************************************************************
** Form generated from reading UI file 'AConsoleWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACONSOLEWIDGET_H
#define UI_ACONSOLEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AConsoleWidget
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QLineEdit *edInput;

    void setupUi(QWidget *AConsoleWidget)
    {
        if (AConsoleWidget->objectName().isEmpty())
            AConsoleWidget->setObjectName(QStringLiteral("AConsoleWidget"));
        AConsoleWidget->resize(550, 394);
        verticalLayout = new QVBoxLayout(AConsoleWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(AConsoleWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);

        edInput = new QLineEdit(AConsoleWidget);
        edInput->setObjectName(QStringLiteral("edInput"));

        verticalLayout->addWidget(edInput);


        retranslateUi(AConsoleWidget);

        QMetaObject::connectSlotsByName(AConsoleWidget);
    } // setupUi

    void retranslateUi(QWidget *AConsoleWidget)
    {
        AConsoleWidget->setWindowTitle(QApplication::translate("AConsoleWidget", "AOuputWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AConsoleWidget: public Ui_AConsoleWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACONSOLEWIDGET_H
