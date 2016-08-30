/********************************************************************************
** Form generated from reading UI file 'qpvz.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QPVZ_H
#define UI_QPVZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QPVZClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QPVZClass)
    {
        if (QPVZClass->objectName().isEmpty())
            QPVZClass->setObjectName(QStringLiteral("QPVZClass"));
        QPVZClass->resize(900, 600);
        menuBar = new QMenuBar(QPVZClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        QPVZClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QPVZClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QPVZClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QPVZClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QPVZClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QPVZClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QPVZClass->setStatusBar(statusBar);

        retranslateUi(QPVZClass);

        QMetaObject::connectSlotsByName(QPVZClass);
    } // setupUi

    void retranslateUi(QMainWindow *QPVZClass)
    {
        QPVZClass->setWindowTitle(QApplication::translate("QPVZClass", "QPVZ", 0));
    } // retranslateUi

};

namespace Ui {
    class QPVZClass: public Ui_QPVZClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QPVZ_H
