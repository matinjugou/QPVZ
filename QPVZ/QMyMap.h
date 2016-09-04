#pragma once
#include "QMyObject.h"
#include "QItemShades.h"
#include "QPlants.h"
#include "QZombies.h"
#include "QWeapons.h"
#include "QGameMode.h"
#include "MyVariable.h"

class QItemShade;

class QMyMap :public QMyObject
{
	Q_OBJECT
private:
	int						debugweek = 0;			//�ȴ�ɾ��
	QGraphicsTextItem		QStatusString;			//��������Ϣ���ȴ�ɾ��

	QGraphicsScene			*Mapscene;				//mode��scene,�ؽ�������ϵͳ֮�����ɾ��
	bool					isPlantedMap[12][5];	//��ʼ��Ϊȫfalse
	QRectF					MapRect;				//��ͼ����
	QPoint					pointNewItemtoPlantOn;	//��¼һ���µ�ֲ��Ҫ���õĵص�
	qreal					verticalLines[12];		//��ֱ�߽���
	qreal					horizontalLines[5];		//ˮƽ�߽���
	QItemShade				*ReadytoPlant;			//������ֲʱ��������ƶ�����Ʒ
	QItemShade				*ReadytoPlant_Shadow;	//������ֲʱ��ʾ��Ҫ���µ�λ�õ���Ʒ
	QVector<QPlants*>		PlantsinMap;			//ֲ������
	QVector<QZombies*>		ZombiesinMap;			//��ʬ����
	QVector<QWeapons*>		WeaponsinMap;			//�ӵ�����

signals:
	void addItem(objectNames, QPointF);
	//��scene�м�һ����Ʒ
	void RequestDone();
	//������ֲ��������ϵ���Ϣ

public slots:
	void Plantrequest_Ready(objectNames, QPointF);
	//������ֲ
	void Plantrequest_Update(QPointF);
	//������ʾ��Ҫ��ֲλ�õ���Ʒ��λ��
	void Plantrequest_Try();
	//������ֲ
	void Plantrequest_Done();
	//��ֲ���

	void Itemadded(QMyObject*);
	//��������displayer����Ʒ�����ɵ���Ϣ
	void addtoMap(objectType, QMyObject*);
	//���´�����ֲ���ʬ�����������ͼ�Ĺ���������
	void removefromMap(objectType, QMyObject*);
	//��ֲ���ʬ�������ӵ�ͼ�Ĺ���������ȥ��

public:
	QMyMap(QGameMode *parent = 0);
	~QMyMap();

public:

	void changePixmap(objectNames);
	//�����������Ʒ��������ʾλ�õ���Ʒ��ͼƬת���ɶ�Ӧֲ���
	void timerEvent(QTimerEvent *event);
	//ʱ����Ӧ�¼�
	void examineMap();
	//����ͼ�ϵĳ�ͻ�¼�
	
	qreal getVerticalLine(int i);
	//�õ���ֱ�߽��ߵ�sceneλ��
	qreal getHorizontalLine(int i);
	//�õ�ˮƽ�߽��ߵ�sceneλ��
	QPoint PostoPoint(QPointF);
	//��scene�е�λ�õ�ת��Ϊ��ͼ�������
	QPointF PointtoPos(QPoint);
	//����ͼ�������ת��Ϊscene�е�λ�õ�
	QRectF getRect();
	//��õ�ͼ�ķ�Χ
	
	void setScene(QGraphicsScene* scene);
	//����map��scene�����ڿ������ö�����ɾ��
};