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
		QPointF tmpPos;
		tmpPos.setX(totCard * 102 + 50);
		tmpPos.setY(20);
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
		connect(cardList[i], SIGNAL(ReadytoPlant(objectNames, QPointF, QMyCard*)), this, SIGNAL(ReadytoPlant(objectNames, QPointF, QMyCard*)));
	}
}


void QCardBank::ReadytoPlantFromCard(objectNames itemName, QPointF itemPos, QMyCard* cardtoplant)
{
	cardReadytoPlant = cardtoplant;
	emit ReadytoPlant(itemName, itemPos);
}

void QCardBank::plantRequestDone()
{
//	cardReadytoPlant->setPixmap(); »»»ØÕý³£Í¼Æ¬
}