/********************************************************************************
** Form generated from reading UI file 'task_type_alert_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASK_TYPE_ALERT_DIALOG_H
#define UI_TASK_TYPE_ALERT_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TaskTypeAlertDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *TaskTypeAlertDialog)
    {
        if (TaskTypeAlertDialog->objectName().isEmpty())
            TaskTypeAlertDialog->setObjectName(QLatin1String("TaskTypeAlertDialog"));
        TaskTypeAlertDialog->resize(247, 101);
        TaskTypeAlertDialog->setMaximumSize(QSize(16777215, 250));
        verticalLayout = new QVBoxLayout(TaskTypeAlertDialog);
        verticalLayout->setObjectName(QLatin1String("verticalLayout"));
        label = new QLabel(TaskTypeAlertDialog);
        label->setObjectName(QLatin1String("label"));

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(TaskTypeAlertDialog);
        lineEdit->setObjectName(QLatin1String("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(TaskTypeAlertDialog);
        pushButton->setObjectName(QLatin1String("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(TaskTypeAlertDialog);

        QMetaObject::connectSlotsByName(TaskTypeAlertDialog);
    } // setupUi

    void retranslateUi(QDialog *TaskTypeAlertDialog)
    {
        TaskTypeAlertDialog->setWindowTitle(QApplication::translate("TaskTypeAlertDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("TaskTypeAlertDialog", "\320\242\320\270\320\277 \321\200\320\265\321\210\320\260\320\265\320\274\320\276\320\271 \320\267\320\260\320\264\320\260\321\207\320\270:", nullptr));
        pushButton->setText(QApplication::translate("TaskTypeAlertDialog", "\320\224\320\260\320\273\320\265\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskTypeAlertDialog: public Ui_TaskTypeAlertDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASK_TYPE_ALERT_DIALOG_H
