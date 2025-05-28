/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataMiningWindow
{
public:
    QWidget *centralWidget;
    QLabel *table_name_label;
    QLabel *properties_label;
    QLineEdit *table_name_value;
    QTextEdit *properties_text;
    QLabel *class_table_name_label;
    QLineEdit *class_table_name_value;
    QPushButton *open_db_button;
    QLabel *database_name_label;
    QLineEdit *database_name_value;
    QLabel *log_label;
    QTextEdit *log_value;
    QPushButton *parse_names_button;
    QLabel *id_column_name_label;
    QLabel *time_column_name_label;
    QLineEdit *id_column_name_value;
    QLineEdit *time_column_name_value;
    QLabel *class_column_name_label;
    QLineEdit *class_column_name_value;
    QLabel *add_tree_label;
    QLineEdit *add_tree_value;
    QPushButton *add_tree_button;
    QLabel *serialize_name_label;
    QLineEdit *serialize_name_value;
    QLabel *rules_name_label;
    QLineEdit *rules_name_value;
    QPushButton *save_trees_button;
    QLabel *inner_name_label;
    QLineEdit *inner_name_value;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QWidget *DataMiningWindow)
    {
        if (DataMiningWindow->objectName().isEmpty())
            DataMiningWindow->setObjectName(QLatin1String("DataMiningWindow"));
        DataMiningWindow->resize(729, 779);
        centralWidget = new QWidget(DataMiningWindow);
        centralWidget->setObjectName(QLatin1String("centralWidget"));
        centralWidget->setGeometry(QRect(0, 0, 740, 710));
        table_name_label = new QLabel(centralWidget);
        table_name_label->setObjectName(QLatin1String("table_name_label"));
        table_name_label->setGeometry(QRect(20, 60, 130, 30));
        table_name_label->setTextFormat(Qt::AutoText);
        table_name_label->setAlignment(Qt::AlignCenter);
        properties_label = new QLabel(centralWidget);
        properties_label->setObjectName(QLatin1String("properties_label"));
        properties_label->setGeometry(QRect(20, 180, 130, 30));
        properties_label->setAlignment(Qt::AlignCenter);
        table_name_value = new QLineEdit(centralWidget);
        table_name_value->setObjectName(QLatin1String("table_name_value"));
        table_name_value->setGeometry(QRect(180, 60, 370, 30));
        properties_text = new QTextEdit(centralWidget);
        properties_text->setObjectName(QLatin1String("properties_text"));
        properties_text->setGeometry(QRect(180, 180, 370, 90));
        class_table_name_label = new QLabel(centralWidget);
        class_table_name_label->setObjectName(QLatin1String("class_table_name_label"));
        class_table_name_label->setGeometry(QRect(20, 290, 130, 30));
        class_table_name_label->setAlignment(Qt::AlignCenter);
        class_table_name_value = new QLineEdit(centralWidget);
        class_table_name_value->setObjectName(QLatin1String("class_table_name_value"));
        class_table_name_value->setGeometry(QRect(180, 290, 370, 30));
        open_db_button = new QPushButton(centralWidget);
        open_db_button->setObjectName(QLatin1String("open_db_button"));
        open_db_button->setGeometry(QRect(570, 20, 150, 30));
        database_name_label = new QLabel(centralWidget);
        database_name_label->setObjectName(QLatin1String("database_name_label"));
        database_name_label->setGeometry(QRect(20, 20, 130, 30));
        database_name_label->setTextFormat(Qt::AutoText);
        database_name_label->setAlignment(Qt::AlignCenter);
        database_name_value = new QLineEdit(centralWidget);
        database_name_value->setObjectName(QLatin1String("database_name_value"));
        database_name_value->setGeometry(QRect(180, 20, 370, 30));
        log_label = new QLabel(centralWidget);
        log_label->setObjectName(QLatin1String("log_label"));
        log_label->setGeometry(QRect(20, 530, 130, 30));
        log_label->setAlignment(Qt::AlignCenter);
        log_value = new QTextEdit(centralWidget);
        log_value->setObjectName(QLatin1String("log_value"));
        log_value->setGeometry(QRect(20, 570, 530, 120));
        log_value->setReadOnly(true);
        parse_names_button = new QPushButton(centralWidget);
        parse_names_button->setObjectName(QLatin1String("parse_names_button"));
        parse_names_button->setEnabled(false);
        parse_names_button->setGeometry(QRect(570, 330, 150, 30));
        id_column_name_label = new QLabel(centralWidget);
        id_column_name_label->setObjectName(QLatin1String("id_column_name_label"));
        id_column_name_label->setGeometry(QRect(20, 100, 130, 30));
        id_column_name_label->setTextFormat(Qt::AutoText);
        id_column_name_label->setAlignment(Qt::AlignCenter);
        time_column_name_label = new QLabel(centralWidget);
        time_column_name_label->setObjectName(QLatin1String("time_column_name_label"));
        time_column_name_label->setGeometry(QRect(20, 140, 130, 30));
        time_column_name_label->setTextFormat(Qt::AutoText);
        time_column_name_label->setAlignment(Qt::AlignCenter);
        id_column_name_value = new QLineEdit(centralWidget);
        id_column_name_value->setObjectName(QLatin1String("id_column_name_value"));
        id_column_name_value->setGeometry(QRect(180, 100, 370, 30));
        time_column_name_value = new QLineEdit(centralWidget);
        time_column_name_value->setObjectName(QLatin1String("time_column_name_value"));
        time_column_name_value->setGeometry(QRect(180, 140, 370, 30));
        class_column_name_label = new QLabel(centralWidget);
        class_column_name_label->setObjectName(QLatin1String("class_column_name_label"));
        class_column_name_label->setGeometry(QRect(20, 330, 130, 30));
        class_column_name_label->setTextFormat(Qt::AutoText);
        class_column_name_label->setAlignment(Qt::AlignCenter);
        class_column_name_value = new QLineEdit(centralWidget);
        class_column_name_value->setObjectName(QLatin1String("class_column_name_value"));
        class_column_name_value->setGeometry(QRect(180, 330, 370, 30));
        add_tree_label = new QLabel(centralWidget);
        add_tree_label->setObjectName(QLatin1String("add_tree_label"));
        add_tree_label->setGeometry(QRect(20, 370, 130, 30));
        add_tree_label->setTextFormat(Qt::AutoText);
        add_tree_label->setAlignment(Qt::AlignCenter);
        add_tree_value = new QLineEdit(centralWidget);
        add_tree_value->setObjectName(QLatin1String("add_tree_value"));
        add_tree_value->setGeometry(QRect(180, 370, 370, 30));
        add_tree_button = new QPushButton(centralWidget);
        add_tree_button->setObjectName(QLatin1String("add_tree_button"));
        add_tree_button->setEnabled(false);
        add_tree_button->setGeometry(QRect(570, 370, 150, 30));
        serialize_name_label = new QLabel(centralWidget);
        serialize_name_label->setObjectName(QLatin1String("serialize_name_label"));
        serialize_name_label->setGeometry(QRect(20, 410, 130, 30));
        serialize_name_label->setTextFormat(Qt::AutoText);
        serialize_name_label->setAlignment(Qt::AlignCenter);
        serialize_name_value = new QLineEdit(centralWidget);
        serialize_name_value->setObjectName(QLatin1String("serialize_name_value"));
        serialize_name_value->setGeometry(QRect(180, 410, 370, 30));
        rules_name_label = new QLabel(centralWidget);
        rules_name_label->setObjectName(QLatin1String("rules_name_label"));
        rules_name_label->setGeometry(QRect(20, 450, 130, 30));
        rules_name_label->setTextFormat(Qt::AutoText);
        rules_name_label->setAlignment(Qt::AlignCenter);
        rules_name_value = new QLineEdit(centralWidget);
        rules_name_value->setObjectName(QLatin1String("rules_name_value"));
        rules_name_value->setGeometry(QRect(180, 450, 370, 30));
        save_trees_button = new QPushButton(centralWidget);
        save_trees_button->setObjectName(QLatin1String("save_trees_button"));
        save_trees_button->setEnabled(false);
        save_trees_button->setGeometry(QRect(570, 490, 150, 30));
        inner_name_label = new QLabel(centralWidget);
        inner_name_label->setObjectName(QLatin1String("inner_name_label"));
        inner_name_label->setGeometry(QRect(20, 490, 130, 30));
        inner_name_label->setTextFormat(Qt::AutoText);
        inner_name_label->setAlignment(Qt::AlignCenter);
        inner_name_value = new QLineEdit(centralWidget);
        inner_name_value->setObjectName(QLatin1String("inner_name_value"));
        inner_name_value->setGeometry(QRect(180, 490, 370, 30));
        menuBar = new QMenuBar(DataMiningWindow);
        menuBar->setObjectName(QLatin1String("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 729, 19));
        menu = new QMenu(menuBar);
        menu->setObjectName(QLatin1String("menu"));
        mainToolBar = new QToolBar(DataMiningWindow);
        mainToolBar->setObjectName(QLatin1String("mainToolBar"));
        mainToolBar->setGeometry(QRect(0, 0, 8, 17));
        statusBar = new QStatusBar(DataMiningWindow);
        statusBar->setObjectName(QLatin1String("statusBar"));
        statusBar->setGeometry(QRect(0, 0, 3, 22));

        menuBar->addAction(menu->menuAction());

        retranslateUi(DataMiningWindow);

        QMetaObject::connectSlotsByName(DataMiningWindow);
    } // setupUi

    void retranslateUi(QWidget *DataMiningWindow)
    {
        DataMiningWindow->setWindowTitle(QApplication::translate("DataMiningWindow", "MainWindow", nullptr));
        table_name_label->setText(QApplication::translate("DataMiningWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\202\320\260\320\261\320\273\320\270\321\206\321\213\n"
"\321\201\320\276 \321\201\320\262\320\276\320\271\321\201\321\202\320\262\320\260\320\274\320\270", nullptr));
        properties_label->setText(QApplication::translate("DataMiningWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\321\217 \321\201\320\262\320\276\320\271\321\201\321\202\320\262", nullptr));
        table_name_value->setText(QApplication::translate("DataMiningWindow", "objects", nullptr));
        properties_text->setHtml(QApplication::translate("DataMiningWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans Serif'; font-size:9pt;\">x1</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Sans Serif'; font-size:9pt;\">x2</span></p></body></html>", nullptr));
        class_table_name_label->setText(QApplication::translate("DataMiningWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\202\320\260\320\261\320\273\320\270\321\206\321\213\n"
"\321\201 \320\272\320\273\320\260\321\201\321\201\320\260\320\274\320\270", nullptr));
        class_table_name_value->setText(QApplication::translate("DataMiningWindow", "classes", nullptr));
        open_db_button->setText(QApplication::translate("DataMiningWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\261\320\260\320\267\321\203 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        database_name_label->setText(QApplication::translate("DataMiningWindow", "\320\230\320\274\321\217 \321\204\320\260\320\271\320\273\321\213\n"
"\321\201 \320\261\320\260\320\267\320\276\320\271 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        database_name_value->setText(QApplication::translate("DataMiningWindow", "test.sqlite", nullptr));
        log_label->setText(QApplication::translate("DataMiningWindow", "\320\233\320\276\320\263 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\213", nullptr));
        parse_names_button->setText(QApplication::translate("DataMiningWindow", "\320\237\321\200\320\276\321\207\320\270\321\202\320\260\321\202\321\214 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\321\217", nullptr));
        id_column_name_label->setText(QApplication::translate("DataMiningWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\201\321\202\320\276\320\273\320\261\321\206\320\260\n"
"\321\201 id", nullptr));
        time_column_name_label->setText(QApplication::translate("DataMiningWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\201\321\202\320\276\320\273\320\261\321\206\320\260\n"
"\321\201 \321\202\320\260\320\272\321\202\320\260\320\274\320\270", nullptr));
        id_column_name_value->setText(QApplication::translate("DataMiningWindow", "id", nullptr));
        time_column_name_value->setText(QApplication::translate("DataMiningWindow", "time", nullptr));
        class_column_name_label->setText(QApplication::translate("DataMiningWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\201\321\202\320\276\320\273\320\261\321\206\320\260\n"
"\321\201 \320\272\320\273\320\260\321\201\321\201\320\260\320\274\320\270", nullptr));
        class_column_name_value->setText(QApplication::translate("DataMiningWindow", "class", nullptr));
        add_tree_label->setText(QApplication::translate("DataMiningWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276\n"
"\320\264\320\265\321\200\320\265\320\262\321\214\320\265\320\262", nullptr));
        add_tree_value->setText(QApplication::translate("DataMiningWindow", "1", nullptr));
        add_tree_button->setText(QApplication::translate("DataMiningWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\264\320\265\321\200\320\265\320\262\321\214\321\217", nullptr));
        serialize_name_label->setText(QApplication::translate("DataMiningWindow", "\320\230\320\274\321\217 \321\204\320\260\320\271\320\273\320\260 \321\201\n"
"\321\201\320\265\321\200\320\270\320\260\320\273\320\270\320\267\320\260\321\206\320\270\320\265\320\271", nullptr));
        serialize_name_value->setText(QApplication::translate("DataMiningWindow", "serialized", nullptr));
        rules_name_label->setText(QApplication::translate("DataMiningWindow", "\320\230\320\274\321\217 \321\204\320\260\320\271\320\273\320\260 \321\201\n"
"\320\276\320\277\320\270\321\201\320\260\320\275\320\270\320\265\320\274 \320\275\320\260 \320\257\320\237\320\227", nullptr));
        rules_name_value->setText(QApplication::translate("DataMiningWindow", "rules", nullptr));
        save_trees_button->setText(QApplication::translate("DataMiningWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\264\320\265\321\200\320\265\320\262\321\214\321\217", nullptr));
        inner_name_label->setText(QApplication::translate("DataMiningWindow", "\320\230\320\274\321\217 \321\204\320\260\320\271\320\273\320\260 \321\201\n"
" \320\264\320\260\320\274\320\277\320\276\320\274 \320\237\320\227", nullptr));
        inner_name_value->setText(QApplication::translate("DataMiningWindow", "inner", nullptr));
        menu->setTitle(QApplication::translate("DataMiningWindow", "\320\223\320\273\320\260\320\262\320\275\320\276\320\265 \320\276\320\272\320\275\320\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DataMiningWindow: public Ui_DataMiningWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
