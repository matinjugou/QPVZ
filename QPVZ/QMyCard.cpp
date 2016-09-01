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
	//����Ƭ�����ʱ���¼�
	//�������ѡ��Ƭ�׶Σ�����signal[movetoselector]����[movetobank]
	//�ȵ�����ƶ���ɵ�ʱ��ʼ�ƶ������ұ�������group�Ĺ���
	//����Ѿ���ʼ��Ϸ�����ʹ�����Ʒ����Ϣ
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