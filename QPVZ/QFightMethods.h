#pragma once
#include "QMyObject.h"

class QFightMethods :public QMyObject
{
public:
	QFightMethods(QWidget* parent = 0); //TODO 将植物的对象指针作为参数传入，并且使用delete删除，处理内存泄漏
	~QFightMethods();
public:
	virtual void hurt(QMyObject *enemy){}
};