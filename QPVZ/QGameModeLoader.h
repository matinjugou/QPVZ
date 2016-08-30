#pragma once
#include "QGameMode.h"

class QGameModeLoader:public QObject
{
	Q_OBJECT
private:
	QGameMainMode *MainMode;
	QGameMode *CurrentMode;
public:
	QGameModeLoader(QWidget* parent = 0);
	~QGameModeLoader();
public:
	QGameMode* Load(GameModeNames);
	QGameMainMode* getMainMode();
	QGameMode* getCurrentMode();
signals:
	void exchangetoScene(QGraphicsScene*);
	void addItem(objectNames, Position);
	void addItem(QMyObject*);
public slots:
	void QuitMode();
};