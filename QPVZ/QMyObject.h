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

	//���Լ������ͼ�����¼�
	void addtomap(objectType, QMyObject*);
	//���Լ��ӵ�ͼ���Ƴ�
	void removefrommap(objectType, QMyObject*);

public slots:
	//�ƶ�����
	void moveTo(int x, int y, int duration);
	//�ƶ�����
	void moveTo(int x, int y, int duration, QEasingCurve::Type type);
	//�ƶ�����
	void moveTo(QPointF targetPos, int duration);
	//�ƶ�����
	void moveTo(QPointF targetPos, int duration, QEasingCurve::Type type);
	//����GIfʱ�л�֡
	void setnewPixmap();
	//����GIFʱ�л�֡
	void setnewPixmap(int);

public:
	//�õ���ǰ����ֵ
	int getHP();
	//�õ�ͼƬ�����ж�Ӧ��ͼƬ
	QPixmap getPicture(int i);
	//�õ���Ʒ������
	objectType getType();
	//�õ���Ʒ�ڵ�ͼ�ϵ�����
	QPoint getPointinMap();
	//������Ʒ�ڵ�ͼ�ڵ�����
	void setPointinMap(int x, int y);
	//������Ʒ�ڵ�ͼ�ڵ�����
	void setPointinMap(QPoint);
	//��������ֵ
	void setHP(int);
	//��������ֵ
	void killHP(int);
	//������Ʒ������
	void setType(objectType Typename);
	//�����µ�ͼƬ
	void pushbackPixmap(QPixmap);
	//����GIF����ʱ���л�֡��
	void setMyPixmap(int);
	//���ò��Ŷ�Ӧ��GIF
	void setMyGif(int);
	//��������
	virtual void Died(){}
};
