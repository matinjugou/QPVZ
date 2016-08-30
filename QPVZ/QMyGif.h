#pragma once
#include "QtWidgets"

class QMyGif :public QObject
{
private:
	QLabel Label;
	QMovie Pic;
public:
	QMyGif(QWidget* parent = 0);
	QMyGif(const QString &filename, QWidget* parent = 0);
	~QMyGif();
public:
	void setGif(const QString &filename);
};