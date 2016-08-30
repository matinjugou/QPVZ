#pragma once
#include "QMyObject.h"

class QEquipments :public QMyObject
{
protected:
	int HP;
public:
	QEquipments(QWidget *parent = 0);//TODO 将僵尸对象的指针传入，然后使用delete的方式管理equipment，处理内存泄漏
	~QEquipments();
public:
	virtual void exec();//TODO 写下装备是怎么强化僵尸的
};