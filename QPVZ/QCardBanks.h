#pragma once
#include "QMyCard.h"
#include "MyVariable.h"

class QCardBank :public QObject, public QGraphicsItemGroup
{
	Q_OBJECT
	Q_PROPERTY(QPointF pos READ pos WRITE setPos)
private:
	int sunshineNum;
	QGraphicsPixmapItem		*Board;
	QGraphicsTextItem		*sunshineText;
	QPropertyAnimation		*animation;
	QMyCard					*cardList[8];
	QMyCard					*cardReadytoPlant;
	int						totCard;

public:
	QCardBank(QGameMode *parent = 0);
	~QCardBank();

signals:
	void moveAccepted(QPointF, QMyCard*);		
	//����Selector�п�Ƭ���������󲢻ش�λ�ø���Ƭ
	void ReadytoPlant(objectNames, QPointF);	
	//��map����׼����ֲ����Ϣ

public slots:
	void moveRequested(QMyCard*);				
	//���տ�Ƭ���������󣬲��õ���Ƭ��ַ���ڻش�
	void removeConfirm(QMyCard*);				
	//���տ�Ƭ���뿪���󣬲��õ���Ƭ�ĵ�ַ���ڴ�group�г�ȥ
	
	void Initconnection();						
	//��ʼ�����������п�Ƭ��bank֮��������ֲ��ֲ�������
	
	void ReadytoPlantFromCard(objectNames, QPointF, QMyCard*);
	//���ܴӿ�Ƭ������׼����ֲ����Ϣ������󴫸�map������ֲ
	void plantRequestDone();
	//��ֲ���������
	
	void SunShineAdded();
	//��������ֵ

public:
	void moveTo(int x, int y, int duration);
	void moveTo(QPointF targetPos, int duration);
	void timerEvent(QTimerEvent *event);

};