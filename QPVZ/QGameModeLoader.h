#pragma once
#include "QGameMode.h"

class QGameModeLoader:public QObject
{
	Q_OBJECT
private:
	QGameMainMode *MainMode;
	QGameMode *CurrentMode;
	QGraphicsView *LoaderView;
public:
	QGameModeLoader(QWidget* parent = 0);
	~QGameModeLoader();
public:
	QGameMainMode* getMainMode();
	QGameMode* getCurrentMode();
signals:
	void exchangetoScene(QGraphicsScene*);
	void addItem(objectNames, QPointF);
	void addItem(QMyObject*);
	void Itemadded(QMyObject*);
public slots:
	QGameMode* Load(GameModeNames);
	void LoadAdventure();
	void QuitMode();
	void setView(QGraphicsView*);
};