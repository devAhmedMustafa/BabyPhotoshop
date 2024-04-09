/********************************************************************************
** Form generated from reading UI file 'BabyPhotoshop.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BABYPHOTOSHOP_H
#define UI_BABYPHOTOSHOP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BabyPhotoshopClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *BabyPhotoshopClass)
    {
        if (BabyPhotoshopClass->objectName().isEmpty())
            BabyPhotoshopClass->setObjectName("BabyPhotoshopClass");
        BabyPhotoshopClass->resize(600, 400);
        menuBar = new QMenuBar(BabyPhotoshopClass);
        menuBar->setObjectName("menuBar");
        BabyPhotoshopClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(BabyPhotoshopClass);
        mainToolBar->setObjectName("mainToolBar");
        BabyPhotoshopClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(BabyPhotoshopClass);
        centralWidget->setObjectName("centralWidget");
        BabyPhotoshopClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(BabyPhotoshopClass);
        statusBar->setObjectName("statusBar");
        BabyPhotoshopClass->setStatusBar(statusBar);

        retranslateUi(BabyPhotoshopClass);

        QMetaObject::connectSlotsByName(BabyPhotoshopClass);
    } // setupUi

    void retranslateUi(QMainWindow *BabyPhotoshopClass)
    {
        BabyPhotoshopClass->setWindowTitle(QCoreApplication::translate("BabyPhotoshopClass", "BabyPhotoshop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BabyPhotoshopClass: public Ui_BabyPhotoshopClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BABYPHOTOSHOP_H
