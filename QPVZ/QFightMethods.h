#pragma once
#include "QMyObject.h"

class QFightMethods :public QMyObject
{
public:
	QFightMethods(QWidget* parent = 0); //TODO ��ֲ��Ķ���ָ����Ϊ�������룬����ʹ��deleteɾ���������ڴ�й©
	~QFightMethods();
public:
	virtual void hurt(QMyObject *enemy){}
};