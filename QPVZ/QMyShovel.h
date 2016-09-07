#pragma once
#include "QMyObject.h"

class QMyShovel :public QMyObject
{
	Q_OBJECT
protected:
	QPointF		OriginPos;			//������¼���ӵ�ԭʼλ��
	bool		status;				//��ǰ״̬��������߷���
public:
	QMyShovel(QGameAdventureMode *parent = 0);
	QMyShovel(int x, int y, QGameAdventureMode *parent = 0);
	QMyShovel(QGameNetFightMode *parent = 0);
	QMyShovel(int x, int y, QGameNetFightMode *parent = 0);
	~QMyShovel();
signals:
	//������
	void leftButtonClicked(QPointF);
public:
	//����ԭʼλ��
	void setOriginPos(QPointF);
	//������¼�
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	//����ƶ��¼�
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};