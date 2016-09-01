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
	QPoint PointinMap;//����ҪReview����ϵͳ
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
		//TODO �ȴ��̳�����д��������
	}
	void pushbackPixmap(QPixmap);
	void setMyPixmap(int);
};
