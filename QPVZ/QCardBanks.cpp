#include "QCardBanks.h"

QCardBank::QCardBank(QWidget *parent)
//	:QGraphicsItemGroup(parent)
{
	totCard = 0;
	statusType = 0;
	Board = new QGraphicsPixmapItem(QPixmap("Resources/pvz-material/images/interface/sunbank.png"));
}

QCardBank::~QCardBank()
{

}

void QCardBank::moveRequested(QMyCard* card)
{
	if (totCard < 8)
	{
		Position tmpPos;
		tmpPos.x = totCard * 102 + 50;
		tmpPos.y = 20;
		emit moveAccepted(tmpPos, card);
		addToGroup(card);
		cardList[totCard] = card;
		totCard++;
	}
}

void QCardBank::removeConfirm(QMyCard* cardtoremove)
{
	removeFromGroup(cardtoremove);
	totCard--;
}

void QCardBank::Initconnection()
{
	for (int i = 0; i < 8; i++)
	{
		cardList[i]->setChosenType(inGame);
		connect(cardList[i], SIGNAL(ReadytoPlant(objectNames, QPointF)), this, SIGNAL(ReadytoPlant(objectNames, QPointF)));
	}
}