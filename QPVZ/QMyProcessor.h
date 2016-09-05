#pragma once
#include "qgraphicsitem.h"
#include "qwidget.h"

class QGameAdventureMode;

class QMyProcessor:public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT
protected:
	qreal					totProcess;			//��ֵ
	qreal					currentProcess;		//��ǰֵ
	QVector<int>			breakPoints;		//�߳���
	QPixmap					FlagPix;		//��ʬͷͼ��
	QGraphicsPixmapItem		boardUpper;			//�ϲ��
	QGraphicsPixmapItem		boardBelow;			//�ײ��
	QGraphicsPixmapItem		ZombieHead;			//��ʬͷ
	QGraphicsPixmapItem		*Flag;				//����
public:
	QMyProcessor(QGameAdventureMode *parent = 0);
	QMyProcessor(qreal totprocess, qreal currentprocess, const QVector<int> &breakpoints,
		QGameAdventureMode *parent = 0);
	~QMyProcessor();
public:
	//��ʼ��
	void Init();
	//������ֵ
	void settotProcess(qreal totprocess);
	//���õ�ǰֵ
	void setcurrentProcess(qreal currentprocess);
	//���öϵ�
	void setbreakPoints(const QVector<int> &breakpoints);

	//��ʱ���¼�
	void timerEvent(QTimerEvent *event);
};