/********************************************************************************
** Form generated from reading UI file 'mainwinsoft.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINSOFT_H
#define UI_MAINWINSOFT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWinSoft
{
public:
    QAction *actionNew_File;
    QAction *actionOpen_File;
    QAction *actionPreferences;
    QAction *actionQuit;
    QAction *actionCopy;
    QAction *actionTheme;
    QAction *actionQuit_2;
    QAction *actionCut;
    QAction *actionResize;
    QAction *actionSettings;
    QAction *actionA_propos;
    QAction *actionManual;
    QAction *actionWebSite;
    QAction *actionComponents_Manage;
    QAction *actionSpice_Model;
    QAction *actionConfigurations;
    QAction *actionStep_by_Step_Simulation;
    QAction *actionPaste;
    QWidget *centralwidget;
    QTreeView *treeView;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuTools;
    QMenu *menuSchematic_Tools;
    QMenu *menuSimulator_Tools;
    QMenu *menuhelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWinSoft)
    {
        if (MainWinSoft->objectName().isEmpty())
            MainWinSoft->setObjectName(QString::fromUtf8("MainWinSoft"));
        MainWinSoft->resize(1309, 600);
        MainWinSoft->setStyleSheet(QString::fromUtf8(""));
        actionNew_File = new QAction(MainWinSoft);
        actionNew_File->setObjectName(QString::fromUtf8("actionNew_File"));
        actionOpen_File = new QAction(MainWinSoft);
        actionOpen_File->setObjectName(QString::fromUtf8("actionOpen_File"));
        actionPreferences = new QAction(MainWinSoft);
        actionPreferences->setObjectName(QString::fromUtf8("actionPreferences"));
        actionQuit = new QAction(MainWinSoft);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionCopy = new QAction(MainWinSoft);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("edit-copy");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionCopy->setIcon(icon);
        actionTheme = new QAction(MainWinSoft);
        actionTheme->setObjectName(QString::fromUtf8("actionTheme"));
        actionQuit_2 = new QAction(MainWinSoft);
        actionQuit_2->setObjectName(QString::fromUtf8("actionQuit_2"));
        actionCut = new QAction(MainWinSoft);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        QIcon icon1;
        iconThemeName = QString::fromUtf8("edit-cut");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionCut->setIcon(icon1);
        actionResize = new QAction(MainWinSoft);
        actionResize->setObjectName(QString::fromUtf8("actionResize"));
        actionSettings = new QAction(MainWinSoft);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        actionA_propos = new QAction(MainWinSoft);
        actionA_propos->setObjectName(QString::fromUtf8("actionA_propos"));
        actionManual = new QAction(MainWinSoft);
        actionManual->setObjectName(QString::fromUtf8("actionManual"));
        actionWebSite = new QAction(MainWinSoft);
        actionWebSite->setObjectName(QString::fromUtf8("actionWebSite"));
        actionComponents_Manage = new QAction(MainWinSoft);
        actionComponents_Manage->setObjectName(QString::fromUtf8("actionComponents_Manage"));
        actionSpice_Model = new QAction(MainWinSoft);
        actionSpice_Model->setObjectName(QString::fromUtf8("actionSpice_Model"));
        actionConfigurations = new QAction(MainWinSoft);
        actionConfigurations->setObjectName(QString::fromUtf8("actionConfigurations"));
        actionStep_by_Step_Simulation = new QAction(MainWinSoft);
        actionStep_by_Step_Simulation->setObjectName(QString::fromUtf8("actionStep_by_Step_Simulation"));
        actionPaste = new QAction(MainWinSoft);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        QIcon icon2;
        iconThemeName = QString::fromUtf8("edit-paste");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon2 = QIcon::fromTheme(iconThemeName);
        } else {
            icon2.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionPaste->setIcon(icon2);
        centralwidget = new QWidget(MainWinSoft);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        treeView = new QTreeView(centralwidget);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setGeometry(QRect(0, 0, 256, 401));
        treeView->setMinimumSize(QSize(0, 401));
        treeView->setMaximumSize(QSize(16777215, 401));
        MainWinSoft->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWinSoft);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1309, 22));
        menubar->setStyleSheet(QString::fromUtf8("qlineargradient rgb(61, 56, 70)"));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        menuSchematic_Tools = new QMenu(menuTools);
        menuSchematic_Tools->setObjectName(QString::fromUtf8("menuSchematic_Tools"));
        menuSimulator_Tools = new QMenu(menuTools);
        menuSimulator_Tools->setObjectName(QString::fromUtf8("menuSimulator_Tools"));
        menuhelp = new QMenu(menubar);
        menuhelp->setObjectName(QString::fromUtf8("menuhelp"));
        MainWinSoft->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWinSoft);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWinSoft->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuhelp->menuAction());
        menuFile->addAction(actionNew_File);
        menuFile->addAction(actionOpen_File);
        menuFile->addAction(actionPreferences);
        menuFile->addAction(actionQuit);
        menuFile->addAction(actionQuit_2);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionPaste);
        menuView->addAction(actionTheme);
        menuView->addAction(actionResize);
        menuTools->addAction(menuSchematic_Tools->menuAction());
        menuTools->addAction(menuSimulator_Tools->menuAction());
        menuTools->addAction(actionSettings);
        menuSchematic_Tools->addAction(actionComponents_Manage);
        menuSchematic_Tools->addAction(actionSpice_Model);
        menuSimulator_Tools->addAction(actionConfigurations);
        menuSimulator_Tools->addAction(actionStep_by_Step_Simulation);
        menuhelp->addAction(actionA_propos);
        menuhelp->addAction(actionManual);
        menuhelp->addAction(actionWebSite);

        retranslateUi(MainWinSoft);
        QObject::connect(actionQuit_2, SIGNAL(triggered(bool)), MainWinSoft, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWinSoft);
    } // setupUi

    void retranslateUi(QMainWindow *MainWinSoft)
    {
        MainWinSoft->setWindowTitle(QCoreApplication::translate("MainWinSoft", "MainWinSoft", nullptr));
        actionNew_File->setText(QCoreApplication::translate("MainWinSoft", "New Projects", nullptr));
        actionOpen_File->setText(QCoreApplication::translate("MainWinSoft", "Open Projects", nullptr));
        actionPreferences->setText(QCoreApplication::translate("MainWinSoft", "Save Projects", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWinSoft", "Preferences", nullptr));
        actionCopy->setText(QCoreApplication::translate("MainWinSoft", "Copy", nullptr));
        actionTheme->setText(QCoreApplication::translate("MainWinSoft", "Theme", nullptr));
        actionQuit_2->setText(QCoreApplication::translate("MainWinSoft", "Quit", nullptr));
        actionCut->setText(QCoreApplication::translate("MainWinSoft", "Cut", nullptr));
        actionResize->setText(QCoreApplication::translate("MainWinSoft", "Resize", nullptr));
        actionSettings->setText(QCoreApplication::translate("MainWinSoft", "Settings", nullptr));
        actionA_propos->setText(QCoreApplication::translate("MainWinSoft", "A propos", nullptr));
        actionManual->setText(QCoreApplication::translate("MainWinSoft", "Manual", nullptr));
        actionWebSite->setText(QCoreApplication::translate("MainWinSoft", "WebSite", nullptr));
        actionComponents_Manage->setText(QCoreApplication::translate("MainWinSoft", "Components Manage", nullptr));
        actionSpice_Model->setText(QCoreApplication::translate("MainWinSoft", "Spice Model", nullptr));
        actionConfigurations->setText(QCoreApplication::translate("MainWinSoft", "Configurations", nullptr));
        actionStep_by_Step_Simulation->setText(QCoreApplication::translate("MainWinSoft", "Step by Step Simulation", nullptr));
        actionPaste->setText(QCoreApplication::translate("MainWinSoft", "Paste", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWinSoft", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWinSoft", "Edit", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWinSoft", "View", nullptr));
        menuTools->setTitle(QCoreApplication::translate("MainWinSoft", "Tools", nullptr));
        menuSchematic_Tools->setTitle(QCoreApplication::translate("MainWinSoft", "Schematic Tools", nullptr));
        menuSimulator_Tools->setTitle(QCoreApplication::translate("MainWinSoft", "Simulator Tools", nullptr));
        menuhelp->setTitle(QCoreApplication::translate("MainWinSoft", "help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWinSoft: public Ui_MainWinSoft {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINSOFT_H
