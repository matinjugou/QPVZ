 #pragma once
#include <QtWidgets>
#include <QtGui>
#include "qgraphicsitem.h"
#include "qvector.h"

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
	objectType Type;
	QGraphicsItemAnimation *animation;
	QTimeLine *timer;
	Position Pos;
public:
	QMyObject(QWidget* parent = 0);
	~QMyObject();
signals:
	void moveStop();
public:
	objectType getType();
	virtual void Died()
	{
		//TODO µÈ´ý¼Ì³ÐÕßÖØÐ´ËÀÍö¶¯»­
	}
	void moveTo(int x, int y, int speed);
	void pushbackPixmap(QPixmap);
	void setMyPixmap(int);
};
