#pragma once
#include "QMyObject.h"
#include "MyVariable.h"

//#include "QGameMode.h"

enum cardType{chosen, unchosen, inGame};
class QMyCard :public QMyObject
{
	Q_OBJECT
	Q_PROPERTY(QPointF pos READ pos WRITE setPos)
protected:
	int					Sunprice;			//����ֵ
	int					CD;					//��ֲ��ȴʱ��
	bool				inCD;				//�Ƿ�������ȴ��
	int					currentTime;		//ʱ�䴦�������ڵ�ʱ��
	QString				nameText;			//��Ƭ�Ļ���˵������
	cardType			chosenType;			//��Ƭ��״̬���Ƿ�ѡ�����ڲ�ս���Ƿ��Ѿ���Ϸ��ʼ
	objectNames			objectTypeName;		//��Ƭ��Ӧ��ֲ������
	QPointF				cardPosinSelector;  //�洢���ڿ�Ƭѡ�����е�λ�ã����ڻ���
	QGraphicsRectItem	CardCover;			//���ڱ�ʾ��ȴʱ�����Ӱ�ڸ�
public:
	QMyCard(QCardSelector *parent = 0);
	~QMyCard();

signals:
	void moveToBank(QMyCard*);
	//������ϢҪ���ƶ�������
	void moveToSelector(QMyCard*);
	//������ϢҪ���ƶ���ѡ����
	void ReadytoPlant(objectNames, QPointF, QMyCard*);
	//����׼����ֲ����Ϣ

public slots:
	void moveAccepted(QPointF);
	//�ƶ���Bank���ƶ����󱻽���

public:
	int getSunPrice();
	//�õ�����ֵ
	bool getInCD();
	//�õ���ȴʱ��
	void CDStart();
	//��ʼ��ȴ
	void timerEvent(QTimerEvent *event);
	//ʱ����Ӧ�¼�
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	//������¼�
	void setChosenType(cardType);
	//���õ�ǰ��Ƭ״̬
	void setCardOriginPos(QPointF);
	//���ÿ�Ƭ�ڿ�Ƭѡ���������λ��
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	//���ƺ���
};

//TODO �̳в����쿨Ƭ����

class PeaShooterCard :public QMyCard
{
public:
	PeaShooterCard(QCardSelector *parent = 0);
	~PeaShooterCard();
};

class SunFlowerCard :public QMyCard
{
public:
	SunFlowerCard(QCardSelector *parent = 0);
	~SunFlowerCard();
};

class WallNutCard :public QMyCard
{
public:
	WallNutCard(QCardSelector *parent = 0);
	~WallNutCard();
};

class CommonZombieCard :public QMyCard
{
public:
	CommonZombieCard(QCardSelector *parent = 0);
	~CommonZombieCard();
}; 

class BucketHeadZombieCard :public QMyCard
{
public:
	BucketHeadZombieCard(QCardSelector *parent = 0);
	~BucketHeadZombieCard();
};

class PoleVaultingZombieCard :public QMyCard
{
public:
	PoleVaultingZombieCard(QCardSelector *parent = 0);
	~PoleVaultingZombieCard();
};