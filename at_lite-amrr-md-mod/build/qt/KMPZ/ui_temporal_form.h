/********************************************************************************
** Form generated from reading UI file 'temporal_form.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEMPORAL_FORM_H
#define UI_TEMPORAL_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TemporalForm
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QWidget *parsedInfoLayout;
    QFormLayout *layout;
    QLineEdit *questionEdit;
    QLabel *label_6;
    QLineEdit *answerEdit;
    QLabel *label_8;
    QTableView *tableView;
    QVBoxLayout *verticalLayout_2;
    QPushButton *inputButton;
    QPushButton *cancelButton;
    QPushButton *helpButton;
    QPushButton *fuzzyButton;
    QPushButton *timeLineButton;

    void setupUi(QDialog *TemporalForm)
    {
        if (TemporalForm->objectName().isEmpty())
            TemporalForm->setObjectName(QLatin1String("TemporalForm"));
        TemporalForm->resize(808, 250);
        TemporalForm->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout_2 = new QHBoxLayout(TemporalForm);
        horizontalLayout_2->setObjectName(QLatin1String("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QLatin1String("verticalLayout"));
        parsedInfoLayout = new QWidget(TemporalForm);
        parsedInfoLayout->setObjectName(QLatin1String("parsedInfoLayout"));
        layout = new QFormLayout(parsedInfoLayout);
        layout->setObjectName(QLatin1String("layout"));
        questionEdit = new QLineEdit(parsedInfoLayout);
        questionEdit->setObjectName(QLatin1String("questionEdit"));
        questionEdit->setEnabled(true);
        questionEdit->setReadOnly(true);

        layout->setWidget(0, QFormLayout::FieldRole, questionEdit);

        label_6 = new QLabel(parsedInfoLayout);
        label_6->setObjectName(QLatin1String("label_6"));

        layout->setWidget(1, QFormLayout::LabelRole, label_6);

        answerEdit = new QLineEdit(parsedInfoLayout);
        answerEdit->setObjectName(QLatin1String("answerEdit"));
        answerEdit->setEnabled(true);
        answerEdit->setReadOnly(true);

        layout->setWidget(1, QFormLayout::FieldRole, answerEdit);

        label_8 = new QLabel(parsedInfoLayout);
        label_8->setObjectName(QLatin1String("label_8"));

        layout->setWidget(0, QFormLayout::LabelRole, label_8);


        verticalLayout->addWidget(parsedInfoLayout);

        tableView = new QTableView(TemporalForm);
        tableView->setObjectName(QLatin1String("tableView"));
        tableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableView->setShowGrid(false);
        tableView->horizontalHeader()->setVisible(false);
        tableView->horizontalHeader()->setStretchLastSection(true);
        tableView->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tableView);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QLatin1String("verticalLayout_2"));
        inputButton = new QPushButton(TemporalForm);
        inputButton->setObjectName(QLatin1String("inputButton"));
        inputButton->setAutoDefault(false);

        verticalLayout_2->addWidget(inputButton);

        cancelButton = new QPushButton(TemporalForm);
        cancelButton->setObjectName(QLatin1String("cancelButton"));
        cancelButton->setAutoDefault(false);

        verticalLayout_2->addWidget(cancelButton);

        helpButton = new QPushButton(TemporalForm);
        helpButton->setObjectName(QLatin1String("helpButton"));
        helpButton->setEnabled(false);

        verticalLayout_2->addWidget(helpButton);

        fuzzyButton = new QPushButton(TemporalForm);
        fuzzyButton->setObjectName(QLatin1String("fuzzyButton"));
        fuzzyButton->setEnabled(false);

        verticalLayout_2->addWidget(fuzzyButton);

        timeLineButton = new QPushButton(TemporalForm);
        timeLineButton->setObjectName(QLatin1String("timeLineButton"));
        timeLineButton->setEnabled(false);

        verticalLayout_2->addWidget(timeLineButton);


        horizontalLayout_2->addLayout(verticalLayout_2);


        retranslateUi(TemporalForm);

        QMetaObject::connectSlotsByName(TemporalForm);
    } // setupUi

    void retranslateUi(QDialog *TemporalForm)
    {
        TemporalForm->setWindowTitle(QApplication::translate("TemporalForm", "Dialog", nullptr));
        label_6->setText(QApplication::translate("TemporalForm", "\320\236\321\202\320\262\320\265\321\202", nullptr));
        label_8->setText(QApplication::translate("TemporalForm", "\320\222\320\276\320\277\321\200\320\276\321\201", nullptr));
        inputButton->setText(QApplication::translate("TemporalForm", "\320\222\320\262\320\265\321\201\321\202\320\270", nullptr));
        cancelButton->setText(QApplication::translate("TemporalForm", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        helpButton->setText(QApplication::translate("TemporalForm", "\320\237\320\276\320\274\320\276\321\211\321\214", nullptr));
        fuzzyButton->setText(QApplication::translate("TemporalForm", "\320\230\320\275\321\201\321\202\321\200\321\203\320\274\320\265\320\275\321\202\321\213", nullptr));
        timeLineButton->setText(QApplication::translate("TemporalForm", "\320\240\320\260\321\201\320\277\320\276\320\273\320\276\320\266\320\270\321\202\321\214 \320\275\320\260 \320\262\321\200\320\265\320\274\320\265\320\275\320\275\320\276\320\271 \320\276\321\201\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TemporalForm: public Ui_TemporalForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEMPORAL_FORM_H
