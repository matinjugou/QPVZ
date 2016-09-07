#pragma once
#include <QtWidgets/QMainWindow>
#include "qdialog.h"
#include "ui_qmydialog.h"

class QMyDialog : public QDialog
{
	Q_OBJECT

public:
	QMyDialog(QWidget *parent = 0);
	~QMyDialog();

public:
	Ui::Dialog ui;
};

