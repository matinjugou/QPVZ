#pragma once
#include "qgraphicsview.h"
#include "qgraphicsscene.h"
#include "QMyObject.h"
#include "MyVariable.h"


class QGameDisplayer:public QObject
{
	Q_OBJECT
private:
	QGraphicsView		*mainView;		//����ͼ
	QGraphicsScene		*currentScene;	//��ǰ��ͼ

public:
	QGameDisplayer(QObject* parent = 0);
	QGameDisplayer(QGraphicsScene *scene, QObject* parent = 0);
	~QGameDisplayer();

signals:
	//���´�����Ʒ�Ѿ���ӵ��ź�
	void Itemadded(QMyObject*);

public slots:
	//���õ�ǰ�ĳ���
	void setScene(QGraphicsScene* scene);
	//�����Ʒ������
	void addItem(objectNames, QPointF);

public:
	//�õ���ǰ����ͼ
	QGraphicsView* getView();
	//�õ���ǰ�ĳ���
	QGraphicsScene* getCurrentScene();
};