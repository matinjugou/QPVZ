#pragma once
#include "QMyCard.h"
#include "QMyButton.h"
#include "MyVariable.h"

class QMyCard;
class QMyButton;
class QGameAdventureMode;

class QCardSelector :public QObject, public QGraphicsItemGroup
{
	Q_OBJECT
	Q_PROPERTY(QPointF pos READ pos WRITE setPos)
private:
	QGraphicsPixmapItem		*Board;			//������
	int						maxX;			//�������Ƭ����
	int						maxY;			//�������Ƭ����
	QPoint					currentPos;		//��¼��ǰ�滭��Ƭ�������
	int						totCard;		//�ܿ�Ƭ��
	QMyCard					*newCard;		//���ڴ����¿�Ƭ��ָ��
	QMyCard					*newCardBoard;	//���ڴ����¿�Ƭ�������ָ��
	QMyButton				*startGame;		//��ʼ��Ϸ��ť
	QPropertyAnimation		*animation;		//����

public:
	QCardSelector(QGameMode *parent = 0);
	QCardSelector(QGameAdventureMode *parent = 0);
	QCardSelector(int totcard, const objectNames cardlist[], QGameMode *parent = 0);
	QCardSelector(int totcard, const objectNames cardlist[], QGameAdventureMode *parent = 0);
	~QCardSelector();

signals:
	void moveRequest(QMyCard*);
	//�������Կ�Ƭ���ƶ�����
	void removeInform(QMyCard*);
	//֪ͨBank����Ƭ����
	void startGameNow();
	//֪ͨMode��ʼ��Ϸ

public slots:
	void moveAccepted(QPointF, QMyCard*);
	//��������Bank��ȷ���ƶ���Ϣ������Ƭ�Ƶ�bank��
	void resetIn(QMyCard*);
	//�������Կ�Ƭ�Ľ���Ƭ���·Żص���Ϣ

public:
	void moveTo(QPointF targetPos, int duration);
	//�ƶ�����
	void moveTo(int x, int y, int duration);
	//�ƶ�����
	void addNewCard(objectNames);
	//����µĿ�Ƭ
};