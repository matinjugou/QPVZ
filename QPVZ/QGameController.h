#pragma once
#include "QPlants.h"
#include "QZombies.h"
#include "QGameModeLoader.h"
#include "QGameDisplayer.h"
#include "MyVariable.h"

class QGameController :public QObject
{
public:
	QGameModeLoader		*Loader;		//ģʽ������
	QGameDisplayer		*Displayer;		//չʾ��

public:
	QGameController(QWidget* parent = 0);
	~QGameController();
};