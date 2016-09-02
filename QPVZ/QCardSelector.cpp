#include "QCardSelector.h"

QCardSelector::QCardSelector(QWidget *parent)
//	:QGraphicsItemGroup(parent)
{
	setHandlesChildEvents(false);
	Board = new QGraphicsPixmapItem(QPixmap("Resources/pvz-material/images/interface/SeedChooser_Background.png"));
	Board->setPos(0, 0);
	Board->setScale(0.9);
	addToGroup(Board);
	currentPos.setX(1);
	currentPos.setY(1);
	maxX = 8;
	maxY = 6;
	startGame = new QMyButton("Resources/pvz-material/images/Buttons/SeedChooser_Button_Disabled.png", "Resources/pvz-material/images/Buttons/SeedChooser_Button.png");
	startGame->setPos(137, 420);
	addToGroup(startGame);
	connect(startGame, SIGNAL(clicked()), this, SIGNAL(startGameNow()));
}

QCardSelector::QCardSelector(int totcard, const objectNames cardlist[], QWidget *parent)
//	:QGraphicsItemGroup(parent)
{
	setHandlesChildEvents(false);
	Board = new QGraphicsPixmapItem(QPixmap("Resources/pvz-material/images/interface/SeedChooser_Background.png"));
	Board->setPos(0, 0);
	Board->setScale(0.9);
	addToGroup(Board);
	currentPos.setX(1);
	currentPos.setY(1);

	maxX = 8;
	maxY = 6;
	for (int i = 0; i < totcard; i++)
	{
		addNewCard(cardlist[i]); //Ö®ºóÒª²¹³ä
	}
	startGame = new QMyButton("Resources/pvz-material/images/Buttons/SeedChooser_Button_Disabled.png", "Resources/pvz-material/images/Buttons/SeedChooser_Button.png");
	startGame->setPos(137, 420);
	addToGroup(startGame);
	connect(startGame, SIGNAL(clicked()), this, SIGNAL(startGameNow()));
}

QCardSelector::~QCardSelector()
{


}

void QCardSelector::moveAccepted(QPointF itemPos, QMyCard* cardtomove)
{
	cardtomove->moveAccepted(itemPos);
}

void QCardSelector::resetIn(QMyCard* cardtoset)
{
	addToGroup(cardtoset);
	emit removeInform(cardtoset);
}

void QCardSelector::addNewCard(objectNames name)
{
	switch (name)
	{
	case PeaShooter:
	{
		newCard = new PeaShooterCard;
		newCardBoard = new PeaShooterCard;
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
}

