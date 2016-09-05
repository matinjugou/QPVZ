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
	bool					isPlantedMap[12][5];	//�Ƿ���ֲ
	QMyObject				*objectPointMap[12][5];	//�ڴ˴���ֲ����Ʒָ��
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
	//��scene�м�һ����Ʒ
	void addItem(objectNames, QPointF);
	//������ֲ��������ϵ���Ϣ
	void RequestDone();
	//������ֲ������ȡ������Ϣ
	void RequestCancelled();
	//��ͼ�ϵ����ⱻ����
	void SunShineAdded();

public slots:
	//������ֲ
	void Plantrequest_Ready(objectNames, QPointF);
	//������ʾ��Ҫ��ֲλ�õ���Ʒ��λ��
	void Plantrequest_Update(QPointF);
	//������ֲ
	void Plantrequest_Try();
	//��ֲ���
	void Plantrequest_Done();
	//��ֲȡ��
	void Plantrequest_Cancelled();

	//��������displayer����Ʒ�����ɵ���Ϣ
	void Itemadded(QMyObject*);
	//���´�����ֲ���ʬ�����������ͼ�Ĺ���������
	void addtoMap(objectType, QMyObject*);
	//��ֲ���ʬ�������ӵ�ͼ�Ĺ���������ȥ��
	void removefromMap(objectType, QMyObject*);

	//���ղ�����Ϣ
	void ShovelMessage(QPointF);

public:
	QMyMap(QGameMode *parent = 0);
	~QMyMap();

public:

	//�����������Ʒ��������ʾλ�õ���Ʒ��ͼƬת���ɶ�Ӧֲ���
	void changePixmap(objectNames);
	//ʱ����Ӧ�¼�
	void timerEvent(QTimerEvent *event);
	//����ͼ�ϵĳ�ͻ�¼�
	void examineMap();
	
	//�õ���ֱ�߽��ߵ�sceneλ��
	qreal getVerticalLine(int i);
	//�õ�ˮƽ�߽��ߵ�sceneλ��
	qreal getHorizontalLine(int i);
	//��scene�е�λ�õ�ת��Ϊ��ͼ�������
	QPoint PostoPoint(QPointF);
	//����ͼ�������ת��Ϊscene�е�λ�õ�
	QPointF PointtoPos(QPoint);
	//��õ�ͼ�ķ�Χ
	QRectF getRect();
};