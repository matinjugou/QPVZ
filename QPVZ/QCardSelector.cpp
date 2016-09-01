#include "QCardSelector.h"

QCardSelector::QCardSelector(QWidget *parent)
//	:QGraphicsItemGroup(parent)
{
	Board = new QGraphicsPixmapItem(QPixmap("Resources/pvz-material/images/interface/SeedChooser_Background.png"));
	Board->setPos(0, 600);
	addToGroup(Board);
	currentPos.x = 1;
	currentPos.y = 1;
}

QCardSelector::QCardSelector(int totcard, const objectNames cardlist[], QWidget *parent)
//	:QGraphicsItemGroup(parent)
{
	Board = new QGraphicsPixmapItem(QPixmap("Resources/pvz-material/images/interface/SeedChooser_Background.png"));
	Board->setPos(0, 600);
	currentPos.x = 1;
	currentPos.y = 1;
	for (int i = 0; i < totcard; i++)
	{
		addNewCard(cardlist[i]);
	}
}

QCardSelector::~QCardSelector()
{


}

void QCardSelector::moveAccepted(QPointF itemPos, QMyCard* cardtomove)
{
	cardtomove->moveAccepted(itemPos);
	removeFromGroup(cardtomove);
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
		//TODO写卡片子类构造以及绘画位置，并创建一个具有一定透明度的卡片垫在下层
		//newCard = new Q...Card(Pos);
		//newCardBoard = new ...
		//connect(newCard, SIGANL(moveToBank(this)), this, SIGNAL(moveRequest(QMyCard*)));
		//connect(newCard, SIGANL(moveToSelector(this)), this, SLOT(resetIn(QMyCard*)));
	}
		break;
	default:
		break;
	}
	addToGroup(newCard);
	currentPos.x++;
	if (currentPos.x > maxX)
	{
		currentPos.x = 1;
		currentPos.y++;
	}
}

