#pragma once
#include "QMyObject.h"
#include "QZombies.h"
#include "QPlants.h"
#include "qgraphicsscene.h"
#include "QMyButton.h"

enum GameModeNames{Surface, Adventure, NetFight};
class QGameMode :public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT
protected:
	QGraphicsScene *Scene;
signals:
	void exit();
	void exchangetoScene(QGraphicsScene*);
public:
	QGameMode(QWidget *parent = 0);
	~QGameMode();
public:
	QGraphicsScene* getScene();
};

class QGameMainMode :public QGameMode
{
	Q_OBJECT
public:
	QGameMainMode(QWidget* parent = 0);
	~QGameMainMode();
signals:
	void AdventureMode_Start();
	void NetFightMode_Start();
	void Help_Start();
	void Setting_Options();
	void Quit_Game();
public:
	void timerEvent(QTimerEvent* event);
private:
	QMyObject *Background;
	QMyButton *StartGame_Adventure;
	QMyButton *StartGame_NetFight;
	QMyButton *Options;
	QMyButton *Help;
	QMyButton *Quit;
	QMyObject *Name_Card;
	QMyButton *Name_Change;
};