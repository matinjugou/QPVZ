 #pragma once
#include <QtWidgets>
#include <QtGui>
#include "qgraphicsitem.h"
#include "qvector.h"

enum objectType { Plants, Zombies, CommonObjects };
enum objectNames { PeaShooter, Zombie };

class QMyObject :public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT
protected:
	QVector<QPixmap> Pictures;
	objectType objectTypeName;
	QGraphicsItemAnimation *animation;
	QTimeLine *timer;
	QPointF Pos;
	QPoint PointinMap;//后期要Review坐标系统
public:
	QMyObject(QWidget* parent = 0);
	~QMyObject();
signals:
	void moveStop();
public slots:
	void moveTo(int x, int y, int speed);
public:
	objectType getType();
	virtual void Died()
	{
		//TODO 等待继承者重写死亡动画
	}
	void pushbackPixmap(QPixmap);
	void setMyPixmap(int);
};
