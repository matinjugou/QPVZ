#pragma once
#include "MyVariable.h"
#include "qwidget.h"
#include "qgraphicsscene.h"
#include "qgraphicsview.h"
#include "QGameMode.h"

class QMyObject;

class QGameModeLoader:public QObject
{
	Q_OBJECT
private:
	QGameMainMode	*MainMode;		//��Ϸ����Ҫģʽ
	QGameMode		*CurrentMode;	//��Ϸ�ĵ�ǰģʽ
	QGraphicsView	*LoaderView;	//�����ߵ��ӽ�,���������ϵͳ������Ż���
public:
	QGameModeLoader(QObject* parent = 0);
	~QGameModeLoader();

signals:
	//������Ϣ��Displayer�л���ĳ������
	void exchangetoScene(QGraphicsScene*);
	//������Ϣ��Displayer�����Ʒ
	void addItem(objectNames, QPointF);
	//��Ʒ��ӳɹ�
	void Itemadded(QMyObject*);

public slots:
	//������Ϸģʽ
	void Load(int);
	//�˳���ǰģʽ
	void QuitMode();
	//�����ӽǣ����������ϵͳ������Ż���
	void setView(QGraphicsView*);

public:
	//�õ���Ҫ��Ϸģʽָ��
	QGameMainMode* getMainMode();
	//�õ���ǰ��Ϸģʽָ��
	QGameMode* getCurrentMode();
};