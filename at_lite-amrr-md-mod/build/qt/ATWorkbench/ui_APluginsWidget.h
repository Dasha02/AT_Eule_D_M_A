/********************************************************************************
** Form generated from reading UI file 'APluginsWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APLUGINSWIDGET_H
#define UI_APLUGINSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_APluginsWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTreeWidget *treePlugins;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QWidget *APluginsWidget)
    {
        if (APluginsWidget->objectName().isEmpty())
            APluginsWidget->setObjectName(QStringLiteral("APluginsWidget"));
        APluginsWidget->resize(400, 300);
        verticalLayout = new QVBoxLayout(APluginsWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        treePlugins = new QTreeWidget(APluginsWidget);
        treePlugins->setObjectName(QStringLiteral("treePlugins"));

        verticalLayout->addWidget(treePlugins);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(APluginsWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(APluginsWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(APluginsWidget);

        QMetaObject::connectSlotsByName(APluginsWidget);
    } // setupUi

    void retranslateUi(QWidget *APluginsWidget)
    {
        APluginsWidget->setWindowTitle(QApplication::translate("APluginsWidget", "ATEnvironment - Plugins", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treePlugins->headerItem();
        ___qtreewidgetitem->setText(2, QApplication::translate("APluginsWidget", "Path", nullptr));
        ___qtreewidgetitem->setText(1, QApplication::translate("APluginsWidget", "Description", nullptr));
        ___qtreewidgetitem->setText(0, QApplication::translate("APluginsWidget", "Name", nullptr));
        pushButton_2->setText(QApplication::translate("APluginsWidget", "Cancel", nullptr));
        pushButton->setText(QApplication::translate("APluginsWidget", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class APluginsWidget: public Ui_APluginsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APLUGINSWIDGET_H
