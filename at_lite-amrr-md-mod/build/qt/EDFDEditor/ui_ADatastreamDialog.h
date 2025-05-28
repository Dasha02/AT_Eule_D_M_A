/********************************************************************************
** Form generated from reading UI file 'ADatastreamDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADATASTREAMDIALOG_H
#define UI_ADATASTREAMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ADatastreamWidget.h"

QT_BEGIN_NAMESPACE

class Ui_ADatastreamDialog_dialogClass
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    ADatastreamWidget *inc_data_list;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    ADatastreamWidget *out_data_list;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *cancel_button;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QPushButton *done_button;

    void setupUi(QDialog *ADatastreamDialog_dialogClass)
    {
        if (ADatastreamDialog_dialogClass->objectName().isEmpty())
            ADatastreamDialog_dialogClass->setObjectName(QLatin1String("ADatastreamDialog_dialogClass"));
        ADatastreamDialog_dialogClass->resize(744, 402);
        verticalLayoutWidget = new QWidget(ADatastreamDialog_dialogClass);
        verticalLayoutWidget->setObjectName(QLatin1String("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 361, 31));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QLatin1String("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QLatin1String("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        verticalLayoutWidget_2 = new QWidget(ADatastreamDialog_dialogClass);
        verticalLayoutWidget_2->setObjectName(QLatin1String("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(380, 0, 361, 31));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QLatin1String("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName(QLatin1String("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        horizontalLayoutWidget = new QWidget(ADatastreamDialog_dialogClass);
        horizontalLayoutWidget->setObjectName(QLatin1String("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 40, 361, 321));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QLatin1String("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        inc_data_list = new ADatastreamWidget(horizontalLayoutWidget);
        inc_data_list->setObjectName(QLatin1String("inc_data_list"));

        horizontalLayout->addWidget(inc_data_list);

        horizontalLayoutWidget_2 = new QWidget(ADatastreamDialog_dialogClass);
        horizontalLayoutWidget_2->setObjectName(QLatin1String("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(380, 40, 361, 321));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QLatin1String("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        out_data_list = new ADatastreamWidget(horizontalLayoutWidget_2);
        out_data_list->setObjectName(QLatin1String("out_data_list"));

        horizontalLayout_2->addWidget(out_data_list);

        verticalLayoutWidget_3 = new QWidget(ADatastreamDialog_dialogClass);
        verticalLayoutWidget_3->setObjectName(QLatin1String("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(380, 370, 361, 31));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QLatin1String("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        cancel_button = new QPushButton(verticalLayoutWidget_3);
        cancel_button->setObjectName(QLatin1String("cancel_button"));

        verticalLayout_3->addWidget(cancel_button);

        verticalLayoutWidget_4 = new QWidget(ADatastreamDialog_dialogClass);
        verticalLayoutWidget_4->setObjectName(QLatin1String("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(0, 370, 361, 31));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QLatin1String("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        done_button = new QPushButton(verticalLayoutWidget_4);
        done_button->setObjectName(QLatin1String("done_button"));
        done_button->setCheckable(false);

        verticalLayout_4->addWidget(done_button);


        retranslateUi(ADatastreamDialog_dialogClass);
        QObject::connect(cancel_button, SIGNAL(pressed()), ADatastreamDialog_dialogClass, SLOT(close()));

        QMetaObject::connectSlotsByName(ADatastreamDialog_dialogClass);
    } // setupUi

    void retranslateUi(QDialog *ADatastreamDialog_dialogClass)
    {
        ADatastreamDialog_dialogClass->setWindowTitle(QApplication::translate("ADatastreamDialog_dialogClass", "Datastream editor", nullptr));
        label->setText(QApplication::translate("ADatastreamDialog_dialogClass", "Incoming data", nullptr));
        label_2->setText(QApplication::translate("ADatastreamDialog_dialogClass", "Outgoing data", nullptr));
        cancel_button->setText(QApplication::translate("ADatastreamDialog_dialogClass", "Cancel", nullptr));
        done_button->setText(QApplication::translate("ADatastreamDialog_dialogClass", "Done", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ADatastreamDialog_dialogClass: public Ui_ADatastreamDialog_dialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADATASTREAMDIALOG_H
