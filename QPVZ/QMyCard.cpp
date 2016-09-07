#include "QMyCard.h"

QMyCard::QMyCard(QCardSelector *parent)
	:QMyObject(parent)
{
	chosenType = unchosen;

	QBrush mybrush;
	mybrush.setColor(Qt::black);
	mybrush.setStyle(Qt::Dense4Pattern);
	
	CardCover.setParentItem(this);
	CardCover.setBrush(mybrush);
	CardCover.setRect(0, 0, 50, 0);
	CardCover.setOpacity(0.7);

	currentTime = 0;
	inCD = false;
}

QMyCard::~QMyCard()
{
}

//public slots
void QMyCard::moveAccepted(QPointF PostoLoad)
{
//	moveTo(PostoLoad.x(), PostoLoad.y(), 5);
	moveTo(PostoLoad, 300);
	chosenType = chosen;
}

//public
int QMyCard::getSunPrice()
{
	return Sunprice;
}

bool QMyCard::getInCD()
{
	return inCD;
}

void QMyCard::CDStart()
{
	TimerID = startTimer(20);
	inCD = true;
}

void QMyCard::timerEvent(QTimerEvent *event)
{
	currentTime++;
	CardCover.setRect(0, 0, 50, 70 - ((double)currentTime / (double)CD) * 70);
	if (currentTime == CD)
	{
		killTimer(TimerID);
		currentTime = 0;
		inCD = false;
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
		moveTo(cardPosinSelector, 300);
	}
	else
	{
		emit ReadytoPlant(objectTypeName, pos(), this);
	}
	
}

void QMyCard::setChosenType(cardType cardTypeName)
{
	chosenType = cardTypeName;
}

void QMyCard::setCardOriginPos(QPointF originPos)
{
	cardPosinSelector = originPos;
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

//public
PeaShooterCard::PeaShooterCard(QCardSelector *parent)
	:QMyCard(parent)
{
	objectTypeName = PeaShooter;
	Pictures.push_back(QPixmap("Resources/pvz-material/images/Cards/Plants/Peashooter.png"));
	setPixmap(Pictures[0]);
	Sunprice = 100;
	nameText = QString::number(Sunprice, 10);
	CD = 375;
}

PeaShooterCard::~PeaShooterCard()
{

}

SunFlowerCard::SunFlowerCard(QCardSelector *parent)
	:QMyCard(parent)
{
	objectTypeName = SunFlower;
	Pictures.push_back(QPixmap("Resources/pvz-material/images/Cards/Plants/SunFlower.png"));
	setPixmap(Pictures[0]);
	Sunprice = 50;
	nameText = QString::number(Sunprice, 10);
	CD = 375;
}

SunFlowerCard::~SunFlowerCard()
{

}

WallNutCard::WallNutCard(QCardSelector *parent)
	:QMyCard(parent)
{
	objectTypeName = WallNut;
	Pictures.push_back(QPixmap("Resources/pvz-material/images/Cards/Plants/WallNut.png"));
	setPixmap(Pictures[0]);
	Sunprice = 50;
	nameText = QString::number(Sunprice, 10);
	CD = 1500;
}

WallNutCard::~WallNutCard()
{

}

CommonZombieCard::CommonZombieCard(QCardSelector *parent)
	:QMyCard(parent)
{
	objectTypeName = CommonZombie;
	Pictures.push_back(QPixmap("Resources/pvz-material/images/Cards/Zombies/CommonZombie.png"));
	setPixmap(Pictures[0]);
	Sunprice = 50;
	nameText = QString::number(Sunprice, 10);
	CD = 375;
}

CommonZombieCard::~CommonZombieCard()
{

}

BucketHeadZombieCard::BucketHeadZombieCard(QCardSelector *parent)
	:QMyCard(parent)
{
	objectTypeName = BucketHeadZombie;
	Pictures.push_back(QPixmap("Resources/pvz-material/images/Cards/Zombies/BucketheadZombie.png"));
	setPixmap(Pictures[0]);
	Sunprice = 100;
	nameText = QString::number(Sunprice, 10);
	CD = 750;
}

BucketHeadZombieCard::~BucketHeadZombieCard()
{

}

PoleVaultingZombieCard::PoleVaultingZombieCard(QCardSelector *parent)
	:QMyCard(parent)
{
	objectTypeName = PoleVaultingZombie;
	Pictures.push_back(QPixmap("Resources/pvz-material/images/Cards/Zombies/PoleVaultingZombie.png"));
	setPixmap(Pictures[0]);
	Sunprice = 100;
	nameText = QString::number(Sunprice, 10);
	CD = 750;
}

PoleVaultingZombieCard::~PoleVaultingZombieCard()
{

}