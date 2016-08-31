#include "QMyButton.h"

QMyButton::QMyButton(QGraphicsItem *parent) :
	QGraphicsPixmapItem(parent)
{
	setAcceptHoverEvents(true);
}

QMyButton::QMyButton(const QString &filename, const QString &filenameHover, QGraphicsItem *parent) :
	QGraphicsPixmapItem(parent)
{
	setAcceptHoverEvents(true);
	Button_Plain.load(filename);
	Button_Hover.load(filenameHover);
	setPixmap(Button_Plain);
}

void QMyButton::setPlainImg(const QString &filename)
{
	QPixmap pixmap;
	pixmap.load(filename);
	pixmap = pixmap.scaled(100, 100, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
	setPixmap(pixmap);
}

void QMyButton::setHoverImg(const QString &filename)
{
	QPixmap pixmap;
	pixmap.load(filename);
	pixmap = pixmap.scaled(100, 100, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
	setPixmap(pixmap);
}

QMyButton::~QMyButton()
{

}

void QMyButton::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
	setPixmap(Button_Hover);
}
void QMyButton::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
	setPixmap(Button_Plain);
}

void QMyButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	PosX = pos().x();
	PosY = pos().y();
	setPos(pos().x() + 2, pos().y() + 2);
}

void QMyButton::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	emit clicked();
	setPos(PosX, PosY);
}

void QMyButton::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	if (!isUnderMouse())
	{
		ungrabMouse();
		setPixmap(Button_Plain);
		setPos(PosX, PosY);
	}
}
