/********************************************************************************
** Form generated from reading UI file 'qmydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QMYDIALOG_H
#define UI_QMYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QRadioButton *radioButton_Server;
    QRadioButton *radioButton_Client;
    QGroupBox *groupBox_2;
    QLabel *IPLabel;
    QLineEdit *IPLineEdit;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->setWindowModality(Qt::NonModal);
        Dialog->resize(398, 206);
        Dialog->setAutoFillBackground(false);
        Dialog->setSizeGripEnabled(false);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(50, 170, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 381, 71));
        radioButton_Server = new QRadioButton(groupBox);
        radioButton_Server->setObjectName(QStringLiteral("radioButton_Server"));
        radioButton_Server->setGeometry(QRect(20, 20, 121, 16));
        radioButton_Server->setChecked(false);
        radioButton_Client = new QRadioButton(groupBox);
        radioButton_Client->setObjectName(QStringLiteral("radioButton_Client"));
        radioButton_Client->setGeometry(QRect(20, 50, 131, 16));
        radioButton_Client->setChecked(true);
        groupBox_2 = new QGroupBox(Dialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setEnabled(true);
        groupBox_2->setGeometry(QRect(10, 100, 381, 61));
        IPLabel = new QLabel(groupBox_2);
        IPLabel->setObjectName(QStringLiteral("IPLabel"));
        IPLabel->setGeometry(QRect(10, 20, 61, 21));
        IPLineEdit = new QLineEdit(groupBox_2);
        IPLineEdit->setObjectName(QStringLiteral("IPLineEdit"));
        IPLineEdit->setGeometry(QRect(70, 20, 311, 20));

        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));
        QObject::connect(radioButton_Client, SIGNAL(clicked()), groupBox_2, SLOT(show()));
        QObject::connect(radioButton_Server, SIGNAL(clicked()), groupBox_2, SLOT(hide()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "InitTcpConnection", 0));
        groupBox->setTitle(QApplication::translate("Dialog", "GroupBox", 0));
        radioButton_Server->setText(QApplication::translate("Dialog", "\346\234\254\346\234\272\344\275\234\344\270\272\346\234\215\345\212\241\345\231\250", 0));
        radioButton_Client->setText(QApplication::translate("Dialog", "\346\234\254\346\234\272\344\275\234\344\270\272\345\256\242\346\210\267\347\253\257", 0));
        groupBox_2->setTitle(QApplication::translate("Dialog", "GroupBox", 0));
        IPLabel->setText(QApplication::translate("Dialog", "IP\345\234\260\345\235\200", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QMYDIALOG_H
