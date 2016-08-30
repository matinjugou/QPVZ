#pragma once
#include "QMyObject.h"

class QFightMethods :public QMyObject
{
public:
	QFightMethods(QWidget* parent = 0);
	~QFightMethods();
public:
	virtual void hurt(QMyObject *enemy);
};