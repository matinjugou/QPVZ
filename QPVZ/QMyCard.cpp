#include "QMyCard.h"

QMyCard::QMyCard(QWidget *parent)
	:QMyObject(parent)
{

}

QMyCard::~QMyCard()
{
}

void QMyCard::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	QPixmap pixmap = this->pixmap();
	QRect rect = pixmap.rect();

	painter->drawPixmap(rect, pixmap);


	//print name,calculate the text's heigh & width for center layout  
	QPen pen(Qt::black);
	painter->setPen(pen);
	painter->setRenderHint(QPainter::Antialiasing);
	QFont font("Verdana", 8, QFont::Normal);
	painter->setFont(font);
	painter->drawText(QRectF(0, rect.height(), rect.width(), 15), Qt::AlignCenter, nameText);

	if (option->state & QStyle::State_Sunken)
	{
		QRectF rect1 = boundingRect();
		//QPen pen(Qt::darkGreen);
		painter->setPen(QPen(Qt::darkGreen));
	}
	else
	{

	}
}

void QMyCard::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	//TODO
	//处理卡片被点击时的事件
	//如果还在选择卡片阶段，则发送signal[movetoselector]或者[movetobank]
	//等到获得移动许可的时候开始移动，并且被动更改group的归属
	//如果已经开始游戏，则发送创建物品的消息
	if (chosenType == unchosen)
	{
		emit moveToBank(this);
	}
	else if (chosenType == chosen)
	{
		emit moveToSelector(this);
		chosenType = unchosen;
		moveTo(cardPosinSelector.x(), cardPosinSelector.y(), 5);
	}
	else
	{
		emit ReadytoPlant(objectTypeName, pos(), this);
	}
	
}

void QMyCard::moveAccepted(QPointF PostoLoad)
{
	moveTo(PostoLoad.x(), PostoLoad.y(), 5);
	chosenType = chosen;
}

void QMyCard::setChosenType(cardType cardTypeName)
{
	chosenType = cardTypeName;
}