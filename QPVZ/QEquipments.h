#pragma once
#include "QMyObject.h"

class QEquipments :public QMyObject
{
protected:
	int HP;
public:
	QEquipments(QWidget *parent = 0);
	~QEquipments();
public:
	virtual void exec();//TODO д��װ������ôǿ����ʬ��
};