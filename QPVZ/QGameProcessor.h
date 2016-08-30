#pragma once
#include "qwidget.h"
#include "QGameModeLoader.h"

class QGameProcessor :public QObject
{
private:
	QGameModeLoader *Loader;
public:
	QGameProcessor(QWidget* parent = 0);
	~QGameProcessor();
};