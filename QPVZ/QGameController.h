#pragma once
#include "QPlants.h"
#include "QZombies.h"
#include "QGameModeLoader.h"
#include "QGameDisplayer.h"
#include "MyVariable.h"

class QGameController :public QObject
{
public:
	QGameModeLoader		*Loader;		//模式加载器
	QGameDisplayer		*Displayer;		//展示器

public:
	QGameController(QWidget* parent = 0);
	~QGameController();
};