#pragma once
#include "QMyObject.h"
#include "MyVariable.h"

class QMySunShine :public QMyObject
{
	Q_OBJECT
	Q_PROPERTY(QPointF pos READ pos WRITE setPos)
	Q_PROPERTY(qreal scale READ scale WRITE setScale)
protected:
	bool				beTaken;			//�����Ƿ��Ѿ���ʰȡ
	int					currentTime;		//��ǰ��ʱ��ʱ��
	QPropertyAnimation	*Scaleanimation;	//���Ŷ���

public:
	QMySunShine(QGraphicsScene *parent = 0);
	~QMySunShine();

signals:
	//�������ⱻȡ�ߵ��ź�
	void BeTaken();

public:
	//������¼�
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	//��ʱ���¼�
	void timerEvent(QTimerEvent *event);
	//���Ŷ���
	void SetScaleAnimation(qreal fromScale, qreal toScale, int duration);
};