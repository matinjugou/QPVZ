 #pragma once
#include <QtWidgets>
#include <QtGui>
#include "qgraphicsitem.h"
#include "qvector.h"

enum objectType { Plants, Zombies, CommonObjects, Weapons};
enum objectNames { PeaShooter, CommonZombie, SunShine};

class QMyObject :public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT
	Q_PROPERTY(QPointF pos READ pos WRITE setPos)
public:
	int TimerID;
protected:
	int HP;
	int GifNumber;
	int isDead;
	QVector<QPixmap> Pictures;
	QVector<QMovie*> Gifs;
	QMovie myGif;
	objectType objectTypeName;
	QPropertyAnimation *animation;
	QTimeLine *timer;
	QPoint PointinMap;
public:
	QMyObject(QWidget* parent = 0);
	~QMyObject();
signals:
	void moveStop();
	void addtomap(objectType, QMyObject*);
	void removefrommap(objectType, QMyObject*);
public slots:
	void moveTo(int x, int y, int duration);
	void moveTo(int x, int y, int duration, QEasingCurve::Type type);
	void moveTo(QPointF targetPos, int duration);
	void moveTo(QPointF targetPos, int duration, QEasingCurve::Type type);
	void setnewPixmap();
	void setnewPixmap(int);
public:
	void setHP(int);
	void killHP(int);
	void killMyTimer()
	{
		killTimer(TimerID);
	}
	int getHP();
	void setPointinMap(int x, int y);
	void setPointinMap(QPoint);
	objectType getType();
	void setType(objectType Typename)
	{
		objectTypeName = Typename;
	}
	QPoint getPointinMap();
	virtual void Died()
	{
		//TODO µÈ´ý¼Ì³ÐÕßÖØÐ´ËÀÍö¶¯»­
	}
	void pushbackPixmap(QPixmap);
	void setMyPixmap(int);
	void setMyGif(int);
	QPixmap getPicture(int i);
};
