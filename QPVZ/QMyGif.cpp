#include "QMyGif.h"

QMyGif::QMyGif(QWidget* parent)
	:QObject(parent)
{
	
}

QMyGif::QMyGif(const QString &filename, QWidget* parent)
	: QObject(parent)
{
	Pic.setFileName(filename);
	Label.setMovie(&Pic);
	Pic.start();
}

QMyGif::~QMyGif()
{

}

void QMyGif::setGif(const QString &filename)
{
	Pic.setFileName(filename);
	Label.setMovie(&Pic);
	Pic.start();
}