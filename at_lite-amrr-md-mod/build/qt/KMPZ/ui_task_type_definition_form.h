/********************************************************************************
** Form generated from reading UI file 'task_type_definition_form.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASK_TYPE_DEFINITION_FORM_H
#define UI_TASK_TYPE_DEFINITION_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskTypeDefinitionForm
{
public:
    QPushButton *nextButton;
    QPushButton *newVocabularyButton;
    QLabel *label;
    QPlainTextEdit *problemEdit;

    void setupUi(QWidget *TaskTypeDefinitionForm)
    {
        if (TaskTypeDefinitionForm->objectName().isEmpty())
            TaskTypeDefinitionForm->setObjectName(QLatin1String("TaskTypeDefinitionForm"));
        TaskTypeDefinitionForm->resize(767, 382);
        QFont font;
        font.setFamily(QLatin1String("MS Shell Dlg 2"));
        font.setPointSize(8);
        TaskTypeDefinitionForm->setFont(font);
        nextButton = new QPushButton(TaskTypeDefinitionForm);
        nextButton->setObjectName(QLatin1String("nextButton"));
        nextButton->setGeometry(QRect(40, 300, 191, 31));
        newVocabularyButton = new QPushButton(TaskTypeDefinitionForm);
        newVocabularyButton->setObjectName(QLatin1String("newVocabularyButton"));
        newVocabularyButton->setGeometry(QRect(490, 300, 191, 31));
        label = new QLabel(TaskTypeDefinitionForm);
        label->setObjectName(QLatin1String("label"));
        label->setGeometry(QRect(10, 10, 701, 31));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        problemEdit = new QPlainTextEdit(TaskTypeDefinitionForm);
        problemEdit->setObjectName(QLatin1String("problemEdit"));
        problemEdit->setGeometry(QRect(10, 47, 700, 241));

        retranslateUi(TaskTypeDefinitionForm);

        QMetaObject::connectSlotsByName(TaskTypeDefinitionForm);
    } // setupUi

    void retranslateUi(QWidget *TaskTypeDefinitionForm)
    {
        TaskTypeDefinitionForm->setWindowTitle(QApplication::translate("TaskTypeDefinitionForm", "Dialog", nullptr));
        nextButton->setText(QApplication::translate("TaskTypeDefinitionForm", "\320\237\321\200\320\276\320\264\320\276\320\273\320\266\320\270\321\202\321\214", nullptr));
        newVocabularyButton->setText(QApplication::translate("TaskTypeDefinitionForm", "\320\235\320\276\320\262\320\260\321\217 \320\273\320\265\320\272\321\201\320\270\320\272\320\260", nullptr));
        label->setText(QApplication::translate("TaskTypeDefinitionForm", "\320\243\320\262\320\260\320\266\320\260\320\265\320\274\321\213\320\271 \321\215\320\272\321\201\320\277\320\265\321\200\321\202, \320\276\320\277\320\270\321\210\320\270\321\202\320\265, \320\277\320\276\320\266\320\260\320\273\321\203\320\271\321\201\321\202\320\260, \321\200\320\265\321\210\320\260\320\265\320\274\321\203\321\216 \320\222\320\260\320\274\320\270 \320\277\321\200\320\276\320\261\320\273\320\265\320\274\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskTypeDefinitionForm: public Ui_TaskTypeDefinitionForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASK_TYPE_DEFINITION_FORM_H
