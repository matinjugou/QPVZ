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
	QMySunShine(QGameMode *parent = 0);
	~QMySunShine();

signals:
	void BeTaken();
	//�������ⱻȡ�ߵ��ź�

public:
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	//������¼�
	void timerEvent(QTimerEvent *event);
	//��ʱ���¼�
	void SetScaleAnimation(qreal fromScale, qreal toScale, int duration);
	//���Ŷ���
};