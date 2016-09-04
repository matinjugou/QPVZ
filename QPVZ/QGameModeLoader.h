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
	void exchangetoScene(QGraphicsScene*);
	//������Ϣ��Displayer�л���ĳ������
	void addItem(objectNames, QPointF);
	//������Ϣ��Displayer�����Ʒ
	void Itemadded(QMyObject*);
	//��Ʒ��ӳɹ�

public slots:
	void Load(int);
	//������Ϸģʽ
	void LoadAdventure();
	//����ð��ħ��������map֮������Ż���
	void QuitMode();
	//�˳���ǰģʽ
	void setView(QGraphicsView*);
	//�����ӽǣ����������ϵͳ������Ż���

public:
	QGameMainMode* getMainMode();
	//�õ���Ҫ��Ϸģʽָ��
	QGameMode* getCurrentMode();
	//�õ���ǰ��Ϸģʽָ��
};