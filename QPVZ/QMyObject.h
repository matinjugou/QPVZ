 #pragma once
#include <QtWidgets>
#include <QtGui>
#include "qgraphicsitem.h"
#include "qvector.h"
#include "QMyGif.h"

enum objectType { Plants, Zombies, CommonObjects };
enum objectNames { PeaShooter, Zombie };

struct Position
{
	int x;
	int y;
};

class QMyObject :public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT
protected:
	QVector<QPixmap> Pictures;
	QVector<QMyGif> Gif;
	objectType Type;
	QGraphicsItemAnimation *animation;
	QTimeLine *timer;
public:
	QMyObject(QWidget* parent = 0);
	~QMyObject();
signals:
	void moveStop();
public:
	objectType getType();
	virtual void timerEvent(QTimerEvent *event); //TODO 检测生命值、改变动画状态
	virtual void Died();
	void moveTo(int x, int y, int speed);
	void pushbackPixmap(QPixmap);
};
