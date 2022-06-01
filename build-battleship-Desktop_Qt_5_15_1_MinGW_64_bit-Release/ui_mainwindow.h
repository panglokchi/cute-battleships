/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <playergrid.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    PlayerGrid *opponentGrid;
    QWidget *playerShipList;
    QPushButton *playerShipCV;
    QPushButton *playerShipBB;
    QPushButton *playerShipCA;
    QPushButton *playerShipSS;
    QPushButton *playerShipDD;
    QWidget *opponentShipList;
    QPushButton *opponentShipCA;
    QPushButton *opponentShipDD;
    QPushButton *opponentShipSS;
    QPushButton *opponentShipBB;
    QPushButton *opponentShipCV;
    QPushButton *randomDeploy;
    QPushButton *resetShips;
    PlayerGrid *playerGrid;
    QPushButton *begin;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(700, 500);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        opponentGrid = new PlayerGrid(centralwidget);
        opponentGrid->setObjectName(QString::fromUtf8("opponentGrid"));
        opponentGrid->setGeometry(QRect(360, 130, 256, 256));
        opponentGrid->setMouseTracking(true);
        playerShipList = new QWidget(centralwidget);
        playerShipList->setObjectName(QString::fromUtf8("playerShipList"));
        playerShipList->setGeometry(QRect(50, 30, 256, 80));
        playerShipList->setStyleSheet(QString::fromUtf8("background-image:url(:/images/ship_images/empty.png)"));
        playerShipCV = new QPushButton(playerShipList);
        playerShipCV->setObjectName(QString::fromUtf8("playerShipCV"));
        playerShipCV->setGeometry(QRect(0, 0, 16, 80));
        playerShipCV->setStyleSheet(QString::fromUtf8("background-image:url(:/images/ship_images/ship_5_green.png)"));
        playerShipCV->setAutoDefault(false);
        playerShipCV->setFlat(true);
        playerShipBB = new QPushButton(playerShipList);
        playerShipBB->setObjectName(QString::fromUtf8("playerShipBB"));
        playerShipBB->setGeometry(QRect(32, 0, 16, 80));
        playerShipBB->setStyleSheet(QString::fromUtf8("background-image:url(:/images/ship_images/ship_4_green.png)"));
        playerShipBB->setAutoDefault(false);
        playerShipBB->setFlat(true);
        playerShipCA = new QPushButton(playerShipList);
        playerShipCA->setObjectName(QString::fromUtf8("playerShipCA"));
        playerShipCA->setGeometry(QRect(64, 0, 16, 80));
        playerShipCA->setStyleSheet(QString::fromUtf8("background-image:url(:/images/ship_images/ship_3_green.png)"));
        playerShipCA->setAutoDefault(false);
        playerShipCA->setFlat(true);
        playerShipSS = new QPushButton(playerShipList);
        playerShipSS->setObjectName(QString::fromUtf8("playerShipSS"));
        playerShipSS->setGeometry(QRect(96, 0, 16, 80));
        playerShipSS->setStyleSheet(QString::fromUtf8("background-image:url(:/images/ship_images/ship_3_green.png)"));
        playerShipSS->setAutoDefault(false);
        playerShipSS->setFlat(true);
        playerShipDD = new QPushButton(playerShipList);
        playerShipDD->setObjectName(QString::fromUtf8("playerShipDD"));
        playerShipDD->setGeometry(QRect(128, 0, 16, 80));
        playerShipDD->setStyleSheet(QString::fromUtf8("background-image:url(:/images/ship_images/ship_2_green.png)"));
        playerShipDD->setAutoDefault(false);
        playerShipDD->setFlat(true);
        opponentShipList = new QWidget(centralwidget);
        opponentShipList->setObjectName(QString::fromUtf8("opponentShipList"));
        opponentShipList->setGeometry(QRect(360, 30, 256, 80));
        opponentShipList->setStyleSheet(QString::fromUtf8("background-image: url(:/images/ship_images/empty.png)"));
        opponentShipCA = new QPushButton(opponentShipList);
        opponentShipCA->setObjectName(QString::fromUtf8("opponentShipCA"));
        opponentShipCA->setGeometry(QRect(64, 0, 16, 80));
        opponentShipCA->setStyleSheet(QString::fromUtf8("background-image:url(:/images/ship_images/ship_3_red.png)"));
        opponentShipCA->setAutoDefault(false);
        opponentShipCA->setFlat(true);
        opponentShipDD = new QPushButton(opponentShipList);
        opponentShipDD->setObjectName(QString::fromUtf8("opponentShipDD"));
        opponentShipDD->setGeometry(QRect(128, 0, 16, 80));
        opponentShipDD->setStyleSheet(QString::fromUtf8("background-image:url(:/images/ship_images/ship_2_red.png)"));
        opponentShipDD->setAutoDefault(false);
        opponentShipDD->setFlat(true);
        opponentShipSS = new QPushButton(opponentShipList);
        opponentShipSS->setObjectName(QString::fromUtf8("opponentShipSS"));
        opponentShipSS->setGeometry(QRect(96, 0, 16, 80));
        opponentShipSS->setStyleSheet(QString::fromUtf8("background-image:url(:/images/ship_images/ship_3_red.png)"));
        opponentShipSS->setAutoDefault(false);
        opponentShipSS->setFlat(true);
        opponentShipBB = new QPushButton(opponentShipList);
        opponentShipBB->setObjectName(QString::fromUtf8("opponentShipBB"));
        opponentShipBB->setGeometry(QRect(32, 0, 16, 80));
        opponentShipBB->setStyleSheet(QString::fromUtf8("background-image:url(:/images/ship_images/ship_4_red.png)"));
        opponentShipBB->setAutoDefault(false);
        opponentShipBB->setFlat(true);
        opponentShipCV = new QPushButton(opponentShipList);
        opponentShipCV->setObjectName(QString::fromUtf8("opponentShipCV"));
        opponentShipCV->setGeometry(QRect(0, 0, 16, 80));
        opponentShipCV->setStyleSheet(QString::fromUtf8("background-image:url(:/images/ship_images/ship_5_red.png)"));
        opponentShipCV->setAutoDefault(false);
        opponentShipCV->setFlat(true);
        randomDeploy = new QPushButton(centralwidget);
        randomDeploy->setObjectName(QString::fromUtf8("randomDeploy"));
        randomDeploy->setGeometry(QRect(50, 400, 80, 20));
        resetShips = new QPushButton(centralwidget);
        resetShips->setObjectName(QString::fromUtf8("resetShips"));
        resetShips->setGeometry(QRect(140, 400, 80, 20));
        playerGrid = new PlayerGrid(centralwidget);
        playerGrid->setObjectName(QString::fromUtf8("playerGrid"));
        playerGrid->setGeometry(QRect(50, 130, 256, 256));
        playerGrid->setMouseTracking(true);
        begin = new QPushButton(centralwidget);
        begin->setObjectName(QString::fromUtf8("begin"));
        begin->setGeometry(QRect(230, 400, 80, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 700, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        playerShipCV->setDefault(false);
        playerShipBB->setDefault(false);
        playerShipCA->setDefault(false);
        playerShipSS->setDefault(false);
        playerShipDD->setDefault(false);
        opponentShipCA->setDefault(false);
        opponentShipDD->setDefault(false);
        opponentShipSS->setDefault(false);
        opponentShipBB->setDefault(false);
        opponentShipCV->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        playerShipCV->setText(QString());
        playerShipBB->setText(QString());
        playerShipCA->setText(QString());
        playerShipSS->setText(QString());
        playerShipDD->setText(QString());
        opponentShipCA->setText(QString());
        opponentShipDD->setText(QString());
        opponentShipSS->setText(QString());
        opponentShipBB->setText(QString());
        opponentShipCV->setText(QString());
        randomDeploy->setText(QCoreApplication::translate("MainWindow", "Random", nullptr));
        resetShips->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        begin->setText(QCoreApplication::translate("MainWindow", "Begin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
