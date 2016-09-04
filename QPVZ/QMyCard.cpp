#include "QMyCard.h"

QMyCard::QMyCard(QWidget *parent)
	:QMyObject(parent)
{

}

QMyCard::~QMyCard()
{
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
		moveTo(cardPosinSelector, 300);
	}
	else
	{
		qDebug() << pos().x() << " " << pos().y() << "\n";
		emit ReadytoPlant(objectTypeName, pos(), this);
	}
	
}

void QMyCard::moveAccepted(QPointF PostoLoad)
{
//	moveTo(PostoLoad.x(), PostoLoad.y(), 5);
	moveTo(PostoLoad, 300);
	chosenType = chosen;
}

void QMyCard::setChosenType(cardType cardTypeName)
{
	chosenType = cardTypeName;
}

void QMyCard::setCardOriginPos(QPointF originPos)
{
	cardPosinSelector = originPos;
}

void QMyCard::CDStart()
{
	TimerID = startTimer(20);
	inCD = true;
}

void QMyCard::timerEvent(QTimerEvent *event)
{
	currentTime++;
	CardCover.setRect(0, 0, 50, 70 - ((double)currentTime / (double)(CD * 50)) * 70);
	if (currentTime == (CD * 50))
	{
		killTimer(TimerID);
		currentTime = 0;
		inCD = false;
	}
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
	painter->drawText(QRectF(0, rect.height() - 17, rect.width() - 7, 15), Qt::AlignCenter, nameText);

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

PeaShooterCard::PeaShooterCard(QWidget *parent)
{
	objectTypeName = PeaShooter;
	chosenType = unchosen;
	Pictures.push_back(QPixmap("Resources/pvz-material/images/Cards/Plants/Peashooter.png"));
	setPixmap(Pictures[0]);
	Sunprice = 100;
	nameText = QString::number(Sunprice, 10);
	CardCover.setParentItem(this);
	QBrush mybrush;
	mybrush.setColor(Qt::black);
	mybrush.setStyle(Qt::Dense4Pattern);
	
	CardCover.setBrush(mybrush);
	CardCover.setRect(0, 0, 50, 0);
	CardCover.setOpacity(0.7);
	CD = 7;
	currentTime = 0;
	inCD = false;
}

PeaShooterCard::~PeaShooterCard()
{

}
