/********************************************************************************
** Form generated from reading UI file 'EDFDEditor.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDFDEDITOR_H
#define UI_EDFDEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ADrawWidget.h"
#include "AWorkspaceWidget.h"

QT_BEGIN_NAMESPACE

class Ui_EDFDEditor
{
public:
    QAction *actionAbout;
    QAction *ASave;
    QAction *ASaveAs;
    QAction *ALoad;
    QAction *AExit;
    QAction *ANewFile;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    AWorkspaceWidget *gvDocument;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout;
    ADrawWidget *listWidget;

    void setupUi(QMainWindow *EDFDEditor)
    {
        if (EDFDEditor->objectName().isEmpty())
            EDFDEditor->setObjectName(QLatin1String("EDFDEditor"));
        EDFDEditor->resize(1052, 929);
        actionAbout = new QAction(EDFDEditor);
        actionAbout->setObjectName(QLatin1String("actionAbout"));
        ASave = new QAction(EDFDEditor);
        ASave->setObjectName(QLatin1String("ASave"));
        ASaveAs = new QAction(EDFDEditor);
        ASaveAs->setObjectName(QLatin1String("ASaveAs"));
        ALoad = new QAction(EDFDEditor);
        ALoad->setObjectName(QLatin1String("ALoad"));
        AExit = new QAction(EDFDEditor);
        AExit->setObjectName(QLatin1String("AExit"));
        ANewFile = new QAction(EDFDEditor);
        ANewFile->setObjectName(QLatin1String("ANewFile"));
        centralWidget = new QWidget(EDFDEditor);
        centralWidget->setObjectName(QLatin1String("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QLatin1String("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        gvDocument = new AWorkspaceWidget(centralWidget);
        gvDocument->setObjectName(QLatin1String("gvDocument"));

        horizontalLayout->addWidget(gvDocument);

        EDFDEditor->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(EDFDEditor);
        menuBar->setObjectName(QLatin1String("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1052, 18));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QLatin1String("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QLatin1String("menuHelp"));
        EDFDEditor->setMenuBar(menuBar);
        mainToolBar = new QToolBar(EDFDEditor);
        mainToolBar->setObjectName(QLatin1String("mainToolBar"));
        EDFDEditor->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(EDFDEditor);
        statusBar->setObjectName(QLatin1String("statusBar"));
        EDFDEditor->setStatusBar(statusBar);
        dockWidget = new QDockWidget(EDFDEditor);
        dockWidget->setObjectName(QLatin1String("dockWidget"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QLatin1String("dockWidgetContents"));
        verticalLayout = new QVBoxLayout(dockWidgetContents);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QLatin1String("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listWidget = new ADrawWidget(dockWidgetContents);
        listWidget->setObjectName(QLatin1String("listWidget"));

        verticalLayout->addWidget(listWidget);

        dockWidget->setWidget(dockWidgetContents);
        EDFDEditor->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(ANewFile);
        menuFile->addAction(ASave);
        menuFile->addAction(ASaveAs);
        menuFile->addAction(ALoad);
        menuFile->addSeparator();
        menuFile->addAction(AExit);
        menuHelp->addAction(actionAbout);

        retranslateUi(EDFDEditor);

        QMetaObject::connectSlotsByName(EDFDEditor);
    } // setupUi

    void retranslateUi(QMainWindow *EDFDEditor)
    {
        EDFDEditor->setWindowTitle(QApplication::translate("EDFDEditor", "EDFDEditor", nullptr));
        actionAbout->setText(QApplication::translate("EDFDEditor", "About", nullptr));
        ASave->setText(QApplication::translate("EDFDEditor", "Save()", nullptr));
        ASaveAs->setText(QApplication::translate("EDFDEditor", "SaveAs()", nullptr));
        ALoad->setText(QApplication::translate("EDFDEditor", "Load()", nullptr));
        AExit->setText(QApplication::translate("EDFDEditor", "Exit", nullptr));
        ANewFile->setText(QApplication::translate("EDFDEditor", "New File", nullptr));
        menuFile->setTitle(QApplication::translate("EDFDEditor", "File", nullptr));
        menuHelp->setTitle(QApplication::translate("EDFDEditor", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EDFDEditor: public Ui_EDFDEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDFDEDITOR_H
