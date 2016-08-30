#pragma once
#include "QPlants.h"
#include "QZombies.h"
#include "QGameModeLoader.h"
#include "QGameDisplayer.h"

class QGameController :public QObject
{
	Q_OBJECT
public:
	QGameController(QWidget* parent = 0);
	~QGameController();
	QGameModeLoader *Loader;
	QGameDisplayer *Displayer;
public slots:
public:
	void exec();
};