#pragma once
#include "QMyObject.h"
#include "MyVariable.h"

class QZombies;

class QEquipments :public QMyObject
{
protected:
	int HP;
public:
	QEquipments(QZombies *parent = 0);//TODO ����ʬ�����ָ�봫�룬Ȼ��ʹ��delete�ķ�ʽ����equipment�������ڴ�й©
	~QEquipments();
public:
	virtual void exec();//TODO д��װ������ôǿ����ʬ��
};