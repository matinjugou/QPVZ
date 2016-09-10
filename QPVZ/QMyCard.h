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
	//������ϢҪ���ƶ�������
	void moveToBank(QMyCard*);
	//������ϢҪ���ƶ���ѡ����
	void moveToSelector(QMyCard*);
	//����׼����ֲ����Ϣ
	void ReadytoPlant(objectNames, QPointF, QMyCard*);

public slots:
	//�ƶ���Bank���ƶ����󱻽���
	void moveAccepted(QPointF);

public:
	//�õ�����ֵ
	int getSunPrice();
	//�õ���ȴʱ��
	bool getInCD();
	//��ʼ��ȴ
	void CDStart();
	//ʱ����Ӧ�¼�
	void timerEvent(QTimerEvent *event);
	//������¼�
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	//���õ�ǰ��Ƭ״̬
	void setChosenType(cardType);
	//���ÿ�Ƭ�ڿ�Ƭѡ���������λ��
	void setCardOriginPos(QPointF);
	//���ƺ���
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
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

class CherryBombCard :public QMyCard
{
public:
	CherryBombCard(QCardSelector *parent = 0);
	~CherryBombCard();
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