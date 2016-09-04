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
	void Itemadded(QMyObject*);
	//���´�����Ʒ�Ѿ���ӵ��ź�

public slots:
	void setScene(QGraphicsScene* scene);
	//���õ�ǰ�ĳ���
	void addItem(objectNames, QPointF);
	//�����Ʒ������

public:
	QGraphicsView* getView();
	//�õ���ǰ����ͼ
	QGraphicsScene* getCurrentScene();
	//�õ���ǰ�ĳ���
};