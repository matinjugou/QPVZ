#include "QCardBanks.h"
#include "QGameMode.h"
QCardBank::QCardBank(QGameMode *parent)
	:QObject(parent)
{
	setHandlesChildEvents(false);
	totCard = 0;
	sunshineNum = 50;
	sunshineText = new QGraphicsTextItem;
	sunshineText->setPlainText(QString::number(sunshineNum, 10));
	sunshineText->setFont(QFont("Verdana"));
	sunshineText->setPos(30, 60);
	Board = new QGraphicsPixmapItem(QPixmap("Resources/pvz-material/images/interface/sunbank.png"));
	addToGroup(Board);
	addToGroup(sunshineText);
	animation = new QPropertyAnimation(this, "pos");

	for (int i = 0; i < 8; i++)
		cardList[i] = NULL;
	cardReadytoPlant = NULL;
}

QCardBank::~QCardBank()
{
}


//public slots
void QCardBank::moveRequested(QMyCard* card)
{
	if (totCard < 8)
	{
		QPointF tmpPos;
		tmpPos.setX(totCard * 51 + 79);
		tmpPos.setY(9);
		addToGroup(card);
		emit moveAccepted(tmpPos, card);
		cardList[totCard] = card;
		totCard++;
	}
}

void QCardBank::removeConfirm(QMyCard* cardtoremove)
{
	int tempMark;
	for (int i = 0; i < totCard; i++)
	{
		if (cardList[i] == cardtoremove)
		{
			tempMark = i;
			break;
		}
	}
	for (int i = tempMark; i < totCard - 1; i++)
	{
		cardList[i] = cardList[i + 1];
		cardList[i]->moveTo(i * 51 + 79, 9, 200);
	}
	cardList[totCard] = NULL;
	totCard--;
}

void QCardBank::Initconnection()
{
	for (int i = 0; i < totCard; i++)
	{
		cardList[i]->setChosenType(inGame);
		connect(cardList[i], SIGNAL(ReadytoPlant(objectNames, QPointF, QMyCard*)), this, SLOT(ReadytoPlantFromCard(objectNames, QPointF, QMyCard*)));
	}
	startTimer(20);
}

void QCardBank::ReadytoPlantFromCard(objectNames itemName, QPointF itemPos, QMyCard* cardtoplant)
{
	cardReadytoPlant = cardtoplant;
	cardReadytoPlant->setOpacity(0.5);
	itemPos.setX(itemPos.x() + pos().x());
	itemPos.setY(itemPos.y() + pos().y());
	emit ReadytoPlant(itemName, itemPos);
}

void QCardBank::plantRequestDone()
{
	cardReadytoPlant->setOpacity(1);
	cardReadytoPlant->CDStart();
	sunshineNum -= cardReadytoPlant->getSunPrice();
	cardReadytoPlant = NULL;
}

void QCardBank::plantRequestCancelled()
{
	cardReadytoPlant->setOpacity(1);
	cardReadytoPlant = NULL;
}

void QCardBank::SunShineAdded()
{
	sunshineNum += 25;
}

void QCardBank::setSunShine(int sunshinetoset)
{
	sunshineNum = sunshinetoset;
}

//public foo
void QCardBank::moveTo(int x, int y, int duration)
{
	animation->setDuration(duration);
	animation->setStartValue(pos());
	animation->setEndValue(QPointF(x, y));
	animation->setEasingCurve(QEasingCurve::InOutCubic);
	animation->start();
}

void QCardBank::moveTo(QPointF targetPos, int duration)
{
	qreal x = targetPos.x();
	qreal y = targetPos.y();
	animation->setDuration(duration);
	animation->setStartValue(pos());
	animation->setEndValue(QPoint(x, y));
	animation->setEasingCurve(QEasingCurve::InOutCubic);
	animation->start();
}

void QCardBank::timerEvent(QTimerEvent *event)
{
	sunshineText->setPlainText(QString::number(sunshineNum, 10));
	for (int i = 0; i < totCard; i++)
	{
		if (cardList[i]->getSunPrice() > sunshineNum)
		{
			cardList[i]->setAcceptedMouseButtons(Qt::NoButton);
			cardList[i]->setOpacity(0.7);
		}
		else
		{
			if (!cardList[i]->getInCD())
			{
				cardList[i]->setAcceptedMouseButtons(Qt::AllButtons);
				cardList[i]->setOpacity(1);
			}
			else
			{
				cardList[i]->setAcceptedMouseButtons(Qt::NoButton);
				cardList[i]->setOpacity(0.7);
			}
		}
	}
}