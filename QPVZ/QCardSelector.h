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
	QCardSelector(int totcard, const QVector<objectNames> &cardlist, QGameMode *parent = 0);
	QCardSelector(int totcard, const QVector<objectNames> &cardlist, QGameAdventureMode *parent = 0);
	~QCardSelector();

signals:
	//�������Կ�Ƭ���ƶ�����
	void moveRequest(QMyCard*);
	//֪ͨBank����Ƭ����
	void removeInform(QMyCard*);
	//֪ͨMode��ʼ��Ϸ
	void startGameNow();

public slots:
	//��������Bank��ȷ���ƶ���Ϣ������Ƭ�Ƶ�bank��
	void moveAccepted(QPointF, QMyCard*);
	//�������Կ�Ƭ�Ľ���Ƭ���·Żص���Ϣ
	void resetIn(QMyCard*);

public:
	//�ƶ�����
	void moveTo(QPointF targetPos, int duration);
	//�ƶ�����
	void moveTo(int x, int y, int duration);
	//����µĿ�Ƭ
	void addNewCard(objectNames);
};