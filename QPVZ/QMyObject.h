 #pragma once
#include <QtWidgets>
#include <QtGui>
#include "qgraphicsitem.h"
#include "qgraphicsscene.h"
#include "qvector.h"
#include "MyVariable.h"



class QGameMode;
class QCardBank;
class QCardSelector;
class QPlants;
class QZombies;
class QWeapons;
class QEquipments;
class QFightMethods;
class QMySunShine;

class QMyObject :public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT
	Q_PROPERTY(QPointF pos READ pos WRITE setPos)
protected:
	int						TimerID;		//��ʱ��ID
	int						HP;				//Ѫ��
	int						GifNumber;		//Ҫ���ŵ�GIF�ı��
	int						isDead;			//�Ƿ�����
	QVector<QPixmap>		Pictures;		//ͼƬ����
	QVector<QMovie*>		Gifs;			//GIF����
	QMovie					myGif;			//GIF
	objectType				objectTypeName; //��Ʒ����
	QPropertyAnimation		*animation;		//����
	QPoint					PointinMap;		//��Ʒ�ڵ�ͼ�ϵ�λ��

public:
	QMyObject(QObject *parent = 0);
	QMyObject(QGameMode *parent = 0);
	QMyObject(QCardBank *parent = 0);
	QMyObject(QCardSelector *parent = 0);
	QMyObject(QPlants *parent = 0);
	QMyObject(QZombies *parent = 0);
	QMyObject(QGraphicsScene *parent = 0);
	~QMyObject();

signals:
	void addtomap(objectType, QMyObject*);
	//���Լ������ͼ�����¼�
	void removefrommap(objectType, QMyObject*);
	//���Լ��ӵ�ͼ���Ƴ�

public slots:
	void moveTo(int x, int y, int duration);
	//�ƶ�����
	void moveTo(int x, int y, int duration, QEasingCurve::Type type);
	//�ƶ�����
	void moveTo(QPointF targetPos, int duration);
	//�ƶ�����
	void moveTo(QPointF targetPos, int duration, QEasingCurve::Type type);
	//�ƶ�����
	void setnewPixmap();
	//����GIfʱ�л�֡
	void setnewPixmap(int);
	//����GIFʱ�л�֡

public:
	int getHP();
	//�õ���ǰ����ֵ
	QPixmap getPicture(int i);
	//�õ�ͼƬ�����ж�Ӧ��ͼƬ
	objectType getType();
	//�õ���Ʒ������
	QPoint getPointinMap();
	//�õ���Ʒ�ڵ�ͼ�ϵ�����
	void setPointinMap(int x, int y);
	//������Ʒ�ڵ�ͼ�ڵ�����
	void setPointinMap(QPoint);
	//������Ʒ�ڵ�ͼ�ڵ�����
	void setHP(int);
	//��������ֵ
	void killHP(int);
	//��������ֵ
	void setType(objectType Typename);
	//������Ʒ������
	void pushbackPixmap(QPixmap);
	//�����µ�ͼƬ
	void setMyPixmap(int);
	//����GIF����ʱ���л�֡��
	void setMyGif(int);
	//���ò��Ŷ�Ӧ��GIF
	virtual void Died(){}
	//��������
};
