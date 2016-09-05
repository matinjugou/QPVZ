#include "QMyProcessor.h"
#include "QGameMode.h"

QMyProcessor::QMyProcessor(QGameAdventureMode *parent)
	:QObject(parent)
{
	totProcess = 0;
	currentProcess = 0;
}

QMyProcessor::QMyProcessor(qreal totprocess, qreal currentprocess, const QVector<int> &breakpoints,
	QGameAdventureMode *parent = 0)
	:QObject(parent)
{
	totProcess = totprocess;
	currentProcess = currentprocess;
	breakPoints = breakpoints;
	Init();
}

void QMyProcessor::Init()
{
	boardBelow.setPixmap(QPixmap("Resources/pvz-material/images/interface/FlagMeterFull.png"));
	boardUpper.setPixmap(QPixmap("Resources/pvz-material/images/interface/FlagMeterEmpty.png"));
	ZombieHead.setPixmap(QPixmap("Resources/pvz-material/images/interface/FlagMeterParts1.png"));
	FlagPix.load("Resources/pvz-material/images/interface/FlagMeterParts2.png");
	boardBelow.setParentItem(this);
	boardUpper.setParentItem(this);
	ZombieHead.setParentItem(this);

}