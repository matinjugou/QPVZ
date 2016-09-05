#pragma once
#include "qgraphicsitem.h"
#include "qwidget.h"

class QGameAdventureMode;

class QMyProcessor:public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT
	Q_PROPERTY(qreal opacity READ opacity WRITE setOpacity)
protected:
	int						TimerID;			//��ʱ��ID
	qreal					totProcess;			//��ֵ
	qreal					currentProcess;		//��ǰֵ
	QVector<int>			breakPoints;		//�߳���
	QPixmap					FlagPix;			//��ʬͷͼ��
	QPixmap					boardUpperPix;		//�ϲ��ͼ��
	QGraphicsPixmapItem		boardUpper;			//�ϲ��
	QGraphicsPixmapItem		boardBelow;			//�ײ��
	QGraphicsPixmapItem		ZombieHead;			//��ʬͷ
	QGraphicsPixmapItem		TextBoard;			//���ְ�
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
	//���ӵ�ǰֵ
	void addtocurrentProcess(qreal percent);
	//���öϵ�
	void setbreakPoints(const QVector<int> &breakpoints);

	//��ʱ���¼�
	void timerEvent(QTimerEvent *event);
};