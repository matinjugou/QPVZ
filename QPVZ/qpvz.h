#ifndef QPVZ_H
#define QPVZ_H

#include <QtWidgets/QMainWindow>
#include "ui_qpvz.h"

class QPVZ : public QMainWindow
{
	Q_OBJECT

public:
	QPVZ(QWidget *parent = 0);
	~QPVZ();

private:
	Ui::QPVZClass ui;
};

#endif // QPVZ_H
