#include "QCardBanks.h"

QCardBank::QCardBank(QWidget *parent)
//	:QGraphicsItemGroup(parent)
{
	setHandlesChildEvents(false);
	totCard = 0;
	statusType = 0;
	sunshineNum = 50;
	sunshineText = new QGraphicsTextItem;
	sunshineText->setPlainText(QString::number(sunshineNum, 10));
	sunshineText->setFont(QFont("Verdana"));
	sunshineText->setPos(30, 60);
	Board = new QGraphicsPixmapItem(QPixmap("Resources/pvz-material/images/interface/sunbank.png"));
	addToGroup(Board);
	addToGroup(sunshineText);
}

QCardBank::~QCardBank()
{
	delete Board;
	delete sunshineText;
}

void QCardBank::moveRequested(QMyCard* card)
{
	if (totCard < 8)
	{
		QPointF tmpPos;
		tmpPos.setX(totCard * 51 + 79);
		tmpPos.setY(9);
//		tmpPos.setX(0);
//		tmpPos.setY(0);
//		card->setParent(this);
//		card->setParentItem(this);
		addToGroup(card);
		emit moveAccepted(tmpPos, card);
		cardList[totCard] = card;
		totCard++;
	}
}

void QCardBank::removeConfirm(QMyCard* cardtoremove)
{
//	removeFromGroup(cardtoremove);
	totCard--;
}

void QCardBank::Initconnection()
{
	for (int i = 0; i < totCard; i++)
	{
		cardList[i]->setChosenType(inGame);
		connect(cardList[i], SIGNAL(ReadytoPlant(objectNames, QPointF, QMyCard*)), this, SLOT(ReadytoPlantFromCard(objectNames, QPointF, QMyCard*)));
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