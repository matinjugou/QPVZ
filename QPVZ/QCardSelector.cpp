#include "QCardSelector.h"
#include "QGameMode.h"

QCardSelector::QCardSelector(QGameMode *parent)
	:QObject(parent)
{
	setHandlesChildEvents(false);
	Board = new QGraphicsPixmapItem(QPixmap("Resources/pvz-material/images/interface/SeedChooser_Background.png"), this);
	Board->setPos(0, 0);
	Board->setScale(0.9);
	addToGroup(Board);
	currentPos.setX(1);
	currentPos.setY(1);
	maxX = 8;
	maxY = 6;
	startGame = new QMyButton("Resources/pvz-material/images/Buttons/SeedChooser_Button_Disabled.png", "Resources/pvz-material/images/Buttons/SeedChooser_Button.png", this);
	startGame->setPos(137, 420);
	addToGroup(startGame);
	connect(startGame, SIGNAL(clicked()), this, SIGNAL(startGameNow()));
	animation = new QPropertyAnimation(this, "pos", this);
}

QCardSelector::QCardSelector(QGameAdventureMode *parent)
	:QObject(parent)
{
	setHandlesChildEvents(false);
	Board = new QGraphicsPixmapItem(QPixmap("Resources/pvz-material/images/interface/SeedChooser_Background.png"), this);
	Board->setPos(0, 0);
	Board->setScale(0.9);
	addToGroup(Board);
	currentPos.setX(1);
	currentPos.setY(1);
	maxX = 8;
	maxY = 6;
	startGame = new QMyButton("Resources/pvz-material/images/Buttons/SeedChooser_Button_Disabled.png", "Resources/pvz-material/images/Buttons/SeedChooser_Button.png", this);
	startGame->setPos(137, 420);
	addToGroup(startGame);
	connect(startGame, SIGNAL(clicked()), this, SIGNAL(startGameNow()));
	animation = new QPropertyAnimation(this, "pos", this);
}

QCardSelector::QCardSelector(int totcard, const QVector<objectNames> &cardlist, QGameMode *parent)
	:QObject(parent)
{
	setHandlesChildEvents(false);
	Board = new QGraphicsPixmapItem(QPixmap("Resources/pvz-material/images/interface/SeedChooser_Background.png"), this);
	Board->setPos(0, 0);
	Board->setScale(0.9);
	addToGroup(Board);
	currentPos.setX(1);
	currentPos.setY(1);

	maxX = 8;
	maxY = 6;
	for (int i = 0; i < totcard; i++)
	{
		addNewCard(cardlist[i]); //之后要补充
	}
	startGame = new QMyButton("Resources/pvz-material/images/Buttons/SeedChooser_Button_Disabled.png", "Resources/pvz-material/images/Buttons/SeedChooser_Button.png", this);
	startGame->setPos(137, 420);
	addToGroup(startGame);
	connect(startGame, SIGNAL(clicked()), this, SIGNAL(startGameNow()));
	animation = new QPropertyAnimation(this, "pos", this);
}

QCardSelector::QCardSelector(int totcard, const QVector<objectNames> &cardlist, QGameAdventureMode *parent)
	:QObject(parent)
{
	setHandlesChildEvents(false);
	Board = new QGraphicsPixmapItem(QPixmap("Resources/pvz-material/images/interface/SeedChooser_Background.png"), this);
	Board->setPos(0, 0);
	Board->setScale(0.9);
	addToGroup(Board);
	currentPos.setX(1);
	currentPos.setY(1);

	maxX = 8;
	maxY = 6;
	for (int i = 0; i < totcard; i++)
	{
		addNewCard(cardlist[i]); //之后要补充
	}
	startGame = new QMyButton("Resources/pvz-material/images/Buttons/SeedChooser_Button_Disabled.png", "Resources/pvz-material/images/Buttons/SeedChooser_Button.png", this);
	startGame->setPos(137, 420);
	addToGroup(startGame);
	connect(startGame, SIGNAL(clicked()), this, SIGNAL(startGameNow()));
	animation = new QPropertyAnimation(this, "pos", this);
}

QCardSelector::~QCardSelector()
{


}

//public slots
void QCardSelector::moveAccepted(QPointF itemPos, QMyCard* cardtomove)
{
	cardtomove->moveAccepted(itemPos);
}

void QCardSelector::resetIn(QMyCard* cardtoset)
{
	addToGroup(cardtoset);
	emit removeInform(cardtoset);
}

//public
void QCardSelector::moveTo(int x, int y, int duration)
{
	animation->setDuration(duration);
	animation->setStartValue(pos());
	animation->setEndValue(QPoint(x, y));
	animation->setEasingCurve(QEasingCurve::InOutCubic);
	animation->start();
}

void QCardSelector::moveTo(QPointF targetPos, int duration)
{
	qreal x = targetPos.x();
	qreal y = targetPos.y();
	animation->setDuration(duration);
	animation->setStartValue(pos());
	animation->setEndValue(QPoint(x, y));
	animation->setEasingCurve(QEasingCurve::InOutCubic);
	animation->start();
}

void QCardSelector::addNewCard(objectNames name)
{
	switch (name)
	{
	case PeaShooter:
	{
		newCard = new PeaShooterCard(this);
		newCardBoard = new PeaShooterCard(this);
		connect(newCard, SIGNAL(moveToBank(QMyCard*)), this, SIGNAL(moveRequest(QMyCard*)));
		connect(newCard, SIGNAL(moveToSelector(QMyCard*)), this, SLOT(resetIn(QMyCard*)));
	}
		break;
	case SunFlower:
	{
		newCard = new SunFlowerCard(this);
		newCardBoard = new SunFlowerCard(this);
		connect(newCard, SIGNAL(moveToBank(QMyCard*)), this, SIGNAL(moveRequest(QMyCard*)));
		connect(newCard, SIGNAL(moveToSelector(QMyCard*)), this, SLOT(resetIn(QMyCard*)));
	}
	break;
	case WallNut:
	{
		newCard = new WallNutCard(this);
		newCardBoard = new WallNutCard(this);
		connect(newCard, SIGNAL(moveToBank(QMyCard*)), this, SIGNAL(moveRequest(QMyCard*)));
		connect(newCard, SIGNAL(moveToSelector(QMyCard*)), this, SLOT(resetIn(QMyCard*)));
	}
	break;
	case CherryBomb:
	{
		newCard = new CherryBombCard(this);
		newCardBoard = new CherryBombCard(this);
		connect(newCard, SIGNAL(moveToBank(QMyCard*)), this, SIGNAL(moveRequest(QMyCard*)));
		connect(newCard, SIGNAL(moveToSelector(QMyCard*)), this, SLOT(resetIn(QMyCard*)));
	}
	break;
	case CommonZombie:
	{
		newCard = new CommonZombieCard(this);
		newCardBoard = new CommonZombieCard(this);
		connect(newCard, SIGNAL(moveToBank(QMyCard*)), this, SIGNAL(moveRequest(QMyCard*)));
		connect(newCard, SIGNAL(moveToSelector(QMyCard*)), this, SLOT(resetIn(QMyCard*)));
	}
	break;
	case BucketHeadZombie:
	{
		newCard = new BucketHeadZombieCard(this);
		newCardBoard = new BucketHeadZombieCard(this);
		connect(newCard, SIGNAL(moveToBank(QMyCard*)), this, SIGNAL(moveRequest(QMyCard*)));
		connect(newCard, SIGNAL(moveToSelector(QMyCard*)), this, SLOT(resetIn(QMyCard*)));
	}
	break;
	case PoleVaultingZombie:
	{
		newCard = new PoleVaultingZombieCard(this);
		newCardBoard = new PoleVaultingZombieCard(this);
		connect(newCard, SIGNAL(moveToBank(QMyCard*)), this, SIGNAL(moveRequest(QMyCard*)));
		connect(newCard, SIGNAL(moveToSelector(QMyCard*)), this, SLOT(resetIn(QMyCard*)));
	}
	break;
	default:
		break;
	}
	addToGroup(newCardBoard);
	addToGroup(newCard);
	newCardBoard->setPos((currentPos.x() - 1) * 51 + 17, ((currentPos.y() - 1) * 70) + 35);
	newCardBoard->setOpacity(0.5);
	newCard->setPos((currentPos.x() - 1) * 51 + 17, ((currentPos.y() - 1) * 70) + 35);
	newCard->setCardOriginPos(newCard->pos());
	currentPos.setX(currentPos.x() + 1);
	if (currentPos.x() > maxX)
	{
		currentPos.setX(1);
		currentPos.setY(currentPos.y() + 1);
	}
	newCard = NULL;
	newCardBoard = NULL;
}

