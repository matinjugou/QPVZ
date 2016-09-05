#include "QMyProcessor.h"
#include "QGameMode.h"

QMyProcessor::QMyProcessor(QGameAdventureMode *parent)
	:QObject(parent)
{
	totProcess = 0;
	currentProcess = 0;
	Init();
}

QMyProcessor::QMyProcessor(qreal totprocess, qreal currentprocess, const QVector<int> &breakpoints,
	QGameAdventureMode *parent)
	:QObject(parent)
{
	totProcess = totprocess;
	currentProcess = currentprocess;
	breakPoints = breakpoints;
	Init();
}


QMyProcessor::~QMyProcessor()
{

}

void QMyProcessor::Init()
{
	boardUpperPix.load("Resources/pvz-material/images/interface/FlagMeterEmpty.png");
	boardBelow.setPixmap(QPixmap("Resources/pvz-material/images/interface/FlagMeterFull.png"));
	boardUpper.setPixmap(boardUpperPix);
	ZombieHead.setPixmap(QPixmap("Resources/pvz-material/images/interface/FlagMeterParts1.png"));
	FlagPix.load("Resources/pvz-material/images/interface/FlagMeterParts2.png");
	boardBelow.setParentItem(this);
	boardUpper.setParentItem(this);
	boardBelow.setPos(0, 0);
	boardUpper.setPos(0, 0);
	ZombieHead.setPos(152 - ZombieHead.boundingRect().width(), 0);
	for (const auto &i : breakPoints)
	{
		Flag = new QGraphicsPixmapItem(FlagPix, this);
		Flag->setPos(157.0 - 155.0 * (double)i / totProcess, 0);
		Flag->setParentItem(this);
	}
	ZombieHead.setParentItem(this);
	TimerID = startTimer(20);
}

void QMyProcessor::settotProcess(qreal totprocess)
{
	totProcess = totprocess;
}

void QMyProcessor::setcurrentProcess(qreal currentprocess)
{
	currentProcess = currentprocess;
}


void QMyProcessor::addtocurrentProcess(qreal percent)
{
	currentProcess += percent * totProcess;
}

void QMyProcessor::setbreakPoints(const QVector<int> &breakpoints)
{
	breakPoints = breakpoints;
}

void QMyProcessor::timerEvent(QTimerEvent *event)
{
	boardUpper.setPixmap(boardUpperPix.copy(0, 0, 157 - 150.0 * currentProcess / totProcess, boardUpper.boundingRect().height()));
	ZombieHead.setPos(157 - 155.0 * currentProcess / totProcess - ZombieHead.boundingRect().width(), 0);
	if (currentProcess > totProcess)
	{
		killTimer(TimerID);
	}
}