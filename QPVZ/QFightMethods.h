#pragma once
#include "QMyObject.h"
#include "QPlants.h"
#include "MyVariable.h"

class QFightMethods :public QMyObject
{
public:
	QFightMethods(QPlants* parent = 0); //TODO ��ֲ��Ķ���ָ����Ϊ�������룬����ʹ��deleteɾ���������ڴ�й©
	~QFightMethods();
public:
	virtual void hurt(QMyObject *enemy){}
};