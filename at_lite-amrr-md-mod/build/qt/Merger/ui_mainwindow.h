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
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MergerWindow
{
public:
    QWidget *centralWidget;
    QLabel *left_filename_label;
    QLabel *right_filename_label;
    QLabel *textout_label;
    QLabel *xmlout_label;
    QLabel *innerout_label;
    QLineEdit *left_filename_value;
    QLineEdit *right_filename_value;
    QLineEdit *textout_value;
    QLineEdit *xmlout_value;
    QLineEdit *innerout_value;
    QPushButton *load_button;
    QPushButton *merge_types_button;
    QLabel *log_label;
    QLineEdit *log_value;
    QPushButton *fill_button;
    QPushButton *merge_objects_button;
    QPushButton *save_button;
    QPushButton *merge_events_button;
    QPushButton *merge_intervals_button;
    QPushButton *merge_rules_button;
    QPushButton *show_rtr_button;
    QPushButton *show_dists_button;
    QLabel *rtr_label;
    QLabel *dists_label;
    QLineEdit *rtr_value;
    QLineEdit *dists_value;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QWidget *MergerWindow)
    {
        if (MergerWindow->objectName().isEmpty())
            MergerWindow->setObjectName(QLatin1String("MergerWindow"));
        MergerWindow->resize(729, 779);
        centralWidget = new QWidget(MergerWindow);
        centralWidget->setObjectName(QLatin1String("centralWidget"));
        centralWidget->setGeometry(QRect(0, 0, 740, 710));
        left_filename_label = new QLabel(centralWidget);
        left_filename_label->setObjectName(QLatin1String("left_filename_label"));
        left_filename_label->setGeometry(QRect(10, 30, 141, 31));
        right_filename_label = new QLabel(centralWidget);
        right_filename_label->setObjectName(QLatin1String("right_filename_label"));
        right_filename_label->setGeometry(QRect(10, 70, 141, 31));
        textout_label = new QLabel(centralWidget);
        textout_label->setObjectName(QLatin1String("textout_label"));
        textout_label->setGeometry(QRect(10, 440, 311, 31));
        xmlout_label = new QLabel(centralWidget);
        xmlout_label->setObjectName(QLatin1String("xmlout_label"));
        xmlout_label->setGeometry(QRect(10, 480, 311, 31));
        innerout_label = new QLabel(centralWidget);
        innerout_label->setObjectName(QLatin1String("innerout_label"));
        innerout_label->setGeometry(QRect(10, 520, 371, 31));
        left_filename_value = new QLineEdit(centralWidget);
        left_filename_value->setObjectName(QLatin1String("left_filename_value"));
        left_filename_value->setGeometry(QRect(230, 30, 221, 31));
        right_filename_value = new QLineEdit(centralWidget);
        right_filename_value->setObjectName(QLatin1String("right_filename_value"));
        right_filename_value->setGeometry(QRect(230, 70, 221, 31));
        textout_value = new QLineEdit(centralWidget);
        textout_value->setObjectName(QLatin1String("textout_value"));
        textout_value->setGeometry(QRect(400, 440, 221, 31));
        xmlout_value = new QLineEdit(centralWidget);
        xmlout_value->setObjectName(QLatin1String("xmlout_value"));
        xmlout_value->setGeometry(QRect(400, 480, 221, 31));
        innerout_value = new QLineEdit(centralWidget);
        innerout_value->setObjectName(QLatin1String("innerout_value"));
        innerout_value->setGeometry(QRect(400, 520, 221, 31));
        load_button = new QPushButton(centralWidget);
        load_button->setObjectName(QLatin1String("load_button"));
        load_button->setGeometry(QRect(10, 120, 161, 31));
        merge_types_button = new QPushButton(centralWidget);
        merge_types_button->setObjectName(QLatin1String("merge_types_button"));
        merge_types_button->setEnabled(false);
        merge_types_button->setGeometry(QRect(10, 160, 161, 31));
        log_label = new QLabel(centralWidget);
        log_label->setObjectName(QLatin1String("log_label"));
        log_label->setGeometry(QRect(10, 590, 371, 31));
        log_value = new QLineEdit(centralWidget);
        log_value->setObjectName(QLatin1String("log_value"));
        log_value->setGeometry(QRect(400, 590, 221, 31));
        fill_button = new QPushButton(centralWidget);
        fill_button->setObjectName(QLatin1String("fill_button"));
        fill_button->setGeometry(QRect(510, 30, 211, 31));
        merge_objects_button = new QPushButton(centralWidget);
        merge_objects_button->setObjectName(QLatin1String("merge_objects_button"));
        merge_objects_button->setEnabled(false);
        merge_objects_button->setGeometry(QRect(10, 200, 161, 31));
        save_button = new QPushButton(centralWidget);
        save_button->setObjectName(QLatin1String("save_button"));
        save_button->setEnabled(false);
        save_button->setGeometry(QRect(10, 630, 151, 31));
        merge_events_button = new QPushButton(centralWidget);
        merge_events_button->setObjectName(QLatin1String("merge_events_button"));
        merge_events_button->setEnabled(false);
        merge_events_button->setGeometry(QRect(10, 240, 161, 31));
        merge_intervals_button = new QPushButton(centralWidget);
        merge_intervals_button->setObjectName(QLatin1String("merge_intervals_button"));
        merge_intervals_button->setEnabled(false);
        merge_intervals_button->setGeometry(QRect(10, 280, 161, 31));
        merge_rules_button = new QPushButton(centralWidget);
        merge_rules_button->setObjectName(QLatin1String("merge_rules_button"));
        merge_rules_button->setEnabled(false);
        merge_rules_button->setGeometry(QRect(10, 320, 161, 31));
        show_rtr_button = new QPushButton(centralWidget);
        show_rtr_button->setObjectName(QLatin1String("show_rtr_button"));
        show_rtr_button->setEnabled(false);
        show_rtr_button->setGeometry(QRect(190, 240, 161, 111));
        show_dists_button = new QPushButton(centralWidget);
        show_dists_button->setObjectName(QLatin1String("show_dists_button"));
        show_dists_button->setEnabled(false);
        show_dists_button->setGeometry(QRect(390, 240, 161, 111));
        rtr_label = new QLabel(centralWidget);
        rtr_label->setObjectName(QLatin1String("rtr_label"));
        rtr_label->setGeometry(QRect(10, 360, 311, 31));
        dists_label = new QLabel(centralWidget);
        dists_label->setObjectName(QLatin1String("dists_label"));
        dists_label->setGeometry(QRect(10, 400, 311, 31));
        rtr_value = new QLineEdit(centralWidget);
        rtr_value->setObjectName(QLatin1String("rtr_value"));
        rtr_value->setGeometry(QRect(400, 360, 221, 31));
        dists_value = new QLineEdit(centralWidget);
        dists_value->setObjectName(QLatin1String("dists_value"));
        dists_value->setGeometry(QRect(400, 400, 221, 31));
        menuBar = new QMenuBar(MergerWindow);
        menuBar->setObjectName(QLatin1String("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 729, 19));
        menu = new QMenu(menuBar);
        menu->setObjectName(QLatin1String("menu"));
        mainToolBar = new QToolBar(MergerWindow);
        mainToolBar->setObjectName(QLatin1String("mainToolBar"));
        mainToolBar->setGeometry(QRect(0, 0, 8, 17));
        statusBar = new QStatusBar(MergerWindow);
        statusBar->setObjectName(QLatin1String("statusBar"));
        statusBar->setGeometry(QRect(0, 0, 3, 22));

        menuBar->addAction(menu->menuAction());

        retranslateUi(MergerWindow);

        QMetaObject::connectSlotsByName(MergerWindow);
    } // setupUi

    void retranslateUi(QWidget *MergerWindow)
    {
        MergerWindow->setWindowTitle(QApplication::translate("MergerWindow", "MainWindow", nullptr));
        left_filename_label->setText(QApplication::translate("MergerWindow", "\320\237\320\265\321\200\320\262\321\213\320\271 \321\204\321\200\320\260\320\263\320\274\320\265\320\275\321\202 \320\237\320\227", nullptr));
        right_filename_label->setText(QApplication::translate("MergerWindow", "\320\222\321\202\320\276\321\200\320\276\320\271 \321\204\321\200\320\260\320\263\320\274\320\265\320\275\321\202 \320\237\320\227", nullptr));
        textout_label->setText(QApplication::translate("MergerWindow", "\320\230\320\274\321\217 \321\204\320\260\320\271\320\273\320\260 \321\201 \320\276\320\261\321\212\320\265\320\264\320\270\320\275\321\221\320\275\320\275\321\213\320\274 \320\237\320\227 \320\262 \321\204\320\276\321\200\320\274\320\260\321\202\320\265 \320\257\320\237\320\227", nullptr));
        xmlout_label->setText(QApplication::translate("MergerWindow", "\320\230\320\274\321\217 \321\204\320\260\320\271\320\273\320\260 \321\201 \320\276\320\261\321\212\320\265\320\264\320\270\320\275\321\221\320\275\320\275\321\213\320\274 \320\237\320\227 \320\262 \321\204\320\276\321\200\320\274\320\260\321\202\320\265 XML", nullptr));
        innerout_label->setText(QApplication::translate("MergerWindow", "\320\230\320\274\321\217 \321\204\320\260\320\271\320\273\320\260 \321\201 \320\276\320\261\321\212\320\265\320\264\320\270\320\275\321\221\320\275\320\275\321\213\320\274 \320\237\320\227 \320\275\320\260 \320\262\320\275\321\203\321\202\321\200\320\265\320\275\320\275\320\265\320\274 \321\204\320\276\321\200\320\274\320\260\321\202\320\265", nullptr));
        left_filename_value->setText(QApplication::translate("MergerWindow", "first", nullptr));
        right_filename_value->setText(QApplication::translate("MergerWindow", "second", nullptr));
        textout_value->setText(QApplication::translate("MergerWindow", "merged_rules", nullptr));
        xmlout_value->setText(QApplication::translate("MergerWindow", "merged_xml", nullptr));
        innerout_value->setText(QApplication::translate("MergerWindow", "merged_inner", nullptr));
        load_button->setText(QApplication::translate("MergerWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \321\204\321\200\320\260\320\263\320\274\320\265\320\275\321\202\321\213", nullptr));
        merge_types_button->setText(QApplication::translate("MergerWindow", "\320\236\320\261\321\212\320\265\320\264\320\270\320\275\320\270\321\202\321\214 \321\202\320\270\320\277\321\213", nullptr));
        log_label->setText(QApplication::translate("MergerWindow", "\320\244\320\260\320\271\320\273 \321\201 \320\273\320\276\320\263\320\276\320\274 \321\200\320\260\320\261\320\276\321\202\321\213", nullptr));
        log_value->setText(QApplication::translate("MergerWindow", "merger_log", nullptr));
        fill_button->setText(QApplication::translate("MergerWindow", "\320\227\320\260\320\277\320\276\320\273\320\275\320\270\321\202\321\214 \321\202\320\265\321\201\321\202\320\276\320\262\321\213\320\274\320\270 \320\264\320\260\320\275\320\275\321\213\320\274\320\270", nullptr));
        merge_objects_button->setText(QApplication::translate("MergerWindow", "\320\236\320\261\321\212\320\265\320\264\320\270\320\275\320\270\321\202\321\214 \320\236\320\261\321\212\320\265\320\272\321\202\321\213", nullptr));
        save_button->setText(QApplication::translate("MergerWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202", nullptr));
        merge_events_button->setText(QApplication::translate("MergerWindow", "\320\236\320\261\321\212\320\265\320\264\320\270\320\275\320\270\321\202\321\214 \320\241\320\276\320\261\321\213\321\202\320\270\321\217", nullptr));
        merge_intervals_button->setText(QApplication::translate("MergerWindow", "\320\236\320\261\321\212\320\265\320\264\320\270\320\275\320\270\321\202\321\214 \320\230\320\275\321\202\320\265\321\200\320\262\320\260\320\273\321\213", nullptr));
        merge_rules_button->setText(QApplication::translate("MergerWindow", "\320\236\320\261\321\212\320\265\320\264\320\270\320\275\320\270\321\202\321\214 \320\237\321\200\320\260\320\262\320\270\320\273\320\260", nullptr));
        show_rtr_button->setText(QApplication::translate("MergerWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\240\320\242\320\240", nullptr));
        show_dists_button->setText(QApplication::translate("MergerWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \321\202\320\260\320\261\320\273\320\270\321\206\321\203\n"
" \320\274\320\265\321\200 \321\201\321\205\320\276\320\266\320\265\321\201\321\202\320\270", nullptr));
        rtr_label->setText(QApplication::translate("MergerWindow", "\320\230\320\274\321\217 \321\204\320\260\320\271\320\273\320\260 \321\201 \320\276\320\277\320\270\321\201\320\260\320\275\320\270\320\265\320\274 \320\240\320\242\320\240 \320\262 \321\204\320\276\321\200\320\274\320\260\321\202\320\265 csv", nullptr));
        dists_label->setText(QApplication::translate("MergerWindow", "\320\230\320\274\321\217 \321\204\320\260\320\271\320\273\320\260 \321\201 \320\276\320\277\320\270\321\201\320\260\320\275\320\270\320\265\320\274 \321\202\320\260\320\261\320\273\320\270\321\206\321\213 \320\274\320\265\321\200 \321\201\321\205\320\276\320\266\320\265\321\201\321\202\320\270", nullptr));
        rtr_value->setText(QApplication::translate("MergerWindow", "extended_table", nullptr));
        dists_value->setText(QApplication::translate("MergerWindow", "dists_table", nullptr));
        menu->setTitle(QApplication::translate("MergerWindow", "\320\223\320\273\320\260\320\262\320\275\320\276\320\265 \320\276\320\272\320\275\320\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MergerWindow: public Ui_MergerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
