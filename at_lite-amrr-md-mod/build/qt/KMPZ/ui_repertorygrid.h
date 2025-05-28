/********************************************************************************
** Form generated from reading UI file 'repertorygrid.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPERTORYGRID_H
#define UI_REPERTORYGRID_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RepertoryGrid
{
public:
    QTableWidget *repertory_grid;
    QTextBrowser *textBrowser;
    QTableWidget *left_construct;
    QPushButton *OKButton;

    void setupUi(QWidget *RepertoryGrid)
    {
        if (RepertoryGrid->objectName().isEmpty())
            RepertoryGrid->setObjectName(QLatin1String("RepertoryGrid"));
        RepertoryGrid->resize(970, 485);
        repertory_grid = new QTableWidget(RepertoryGrid);
        if (repertory_grid->columnCount() < 10)
            repertory_grid->setColumnCount(10);
        if (repertory_grid->rowCount() < 20)
            repertory_grid->setRowCount(20);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        repertory_grid->setItem(0, 0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        repertory_grid->setItem(2, 0, __qtablewidgetitem1);
        repertory_grid->setObjectName(QLatin1String("repertory_grid"));
        repertory_grid->setGeometry(QRect(160, 100, 550, 336));
        repertory_grid->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        repertory_grid->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        repertory_grid->setAutoScroll(true);
        repertory_grid->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
        repertory_grid->setTabKeyNavigation(true);
        repertory_grid->setProperty("showDropIndicator", QVariant(true));
        repertory_grid->setDragDropOverwriteMode(true);
        repertory_grid->setSelectionMode(QAbstractItemView::SingleSelection);
        repertory_grid->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        repertory_grid->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        repertory_grid->setShowGrid(true);
        repertory_grid->setGridStyle(Qt::SolidLine);
        repertory_grid->setRowCount(20);
        repertory_grid->setColumnCount(10);
        repertory_grid->horizontalHeader()->setVisible(true);
        repertory_grid->horizontalHeader()->setCascadingSectionResizes(false);
        repertory_grid->horizontalHeader()->setStretchLastSection(true);
        repertory_grid->verticalHeader()->setVisible(false);
        repertory_grid->verticalHeader()->setStretchLastSection(false);
        textBrowser = new QTextBrowser(RepertoryGrid);
        textBrowser->setObjectName(QLatin1String("textBrowser"));
        textBrowser->setGeometry(QRect(10, 10, 700, 81));
        left_construct = new QTableWidget(RepertoryGrid);
        if (left_construct->columnCount() < 1)
            left_construct->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        left_construct->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        if (left_construct->rowCount() < 11)
            left_construct->setRowCount(11);
        left_construct->setObjectName(QLatin1String("left_construct"));
        left_construct->setGeometry(QRect(10, 121, 151, 301));
        left_construct->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        left_construct->setSelectionMode(QAbstractItemView::SingleSelection);
        left_construct->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        left_construct->setCornerButtonEnabled(true);
        left_construct->setRowCount(11);
        left_construct->setColumnCount(1);
        left_construct->horizontalHeader()->setVisible(false);
        left_construct->horizontalHeader()->setStretchLastSection(true);
        left_construct->verticalHeader()->setVisible(false);
        left_construct->verticalHeader()->setStretchLastSection(false);
        OKButton = new QPushButton(RepertoryGrid);
        OKButton->setObjectName(QLatin1String("OKButton"));
        OKButton->setGeometry(QRect(740, 10, 191, 31));

        retranslateUi(RepertoryGrid);

        QMetaObject::connectSlotsByName(RepertoryGrid);
    } // setupUi

    void retranslateUi(QWidget *RepertoryGrid)
    {
        RepertoryGrid->setWindowTitle(QApplication::translate("RepertoryGrid", "Form", nullptr));

        const bool __sortingEnabled = repertory_grid->isSortingEnabled();
        repertory_grid->setSortingEnabled(false);
        repertory_grid->setSortingEnabled(__sortingEnabled);

        textBrowser->setHtml(QApplication::translate("RepertoryGrid", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">\320\227\320\260\320\277\320\276\320\273\320\275\320\270\321\202\320\265 \321\202\320\260\320\261\320\273\320\270\321\206\321\203 \320\277\320\276 100-\320\261\320\260\320\273\321\214\320\275\320\276\320\271 \321\210\320\272\320\260\320\273\320\265, \320\263\320\264\320\265:</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">0 - \320\272\321\200\320\270\320\265\321\202\321"
                        "\200\320\270\320\271 \320\275\320\265 \321\201\320\262\320\276\320\271\321\201\321\202\320\262\320\265\320\275\320\265\320\275 \320\267\320\260\320\272\320\273\321\216\321\207\320\265\320\275\320\270\321\216;</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">50 - \320\272\321\200\320\270\320\265\321\202\321\200\320\270\320\271 \321\207\320\260\321\201\321\202\320\270\321\207\320\275\320\276 \321\201\320\262\320\276\320\271\321\201\321\202\320\262\320\265\320\275\320\265\320\275 \320\267\320\260\320\272\320\273\321\216\321\207\320\265\320\275\320\270\321\216;</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu';\">100 - \320\272\321\200\320\270\320\265\321\202\321\200\320\270\320\271 \321\201\320\262\320\276\320\271\321\201\321\202\320\262"
                        "\320\265\320\275\320\265\320\275 \320\267\320\260\320\272\320\273\321\216\321\207\320\265\320\275\320\270\321\216.</span></p></body></html>", nullptr));
        QTableWidgetItem *___qtablewidgetitem = left_construct->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("RepertoryGrid", "New Column", nullptr));
        OKButton->setText(QApplication::translate("RepertoryGrid", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RepertoryGrid: public Ui_RepertoryGrid {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPERTORYGRID_H
