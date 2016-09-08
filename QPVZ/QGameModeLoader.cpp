#include "QGameModeLoader.h"
#include "QGameMode.h"
#include "qdebug.h"
QGameModeLoader::QGameModeLoader(QObject *parent)
	:QObject(parent)
{
	MainMode = new QGameMainMode(this);
	CurrentMode = MainMode;
	connect(CurrentMode, SIGNAL(exit()), this, SLOT(QuitMode()));
	connect(MainMode, SIGNAL(NewGameStart(int)), this, SLOT(Load(int)));
}

QGameModeLoader::~QGameModeLoader()
{

}

//public slots
void QGameModeLoader::Load(int name)
{
	//TODO ¼ÓÔØÄ£Ê½
	switch (name)
	{
	case 1:
	{
		QGameAdventureMode *AdventureMode = new QGameAdventureMode(this);
		CurrentMode = AdventureMode;
		emit exchangetoScene(AdventureMode->getScene());
		AdventureMode->setView(LoaderView);
		connect(CurrentMode, SIGNAL(addItem(objectNames, QPointF)), this, SIGNAL(addItem(objectNames, QPointF)));
		connect(this, SIGNAL(Itemadded(QMyObject*)), CurrentMode, SIGNAL(Itemadded(QMyObject*)));
		connect(AdventureMode, SIGNAL(exit()), this, SLOT(QuitMode()));
		AdventureMode->GameStart();
	}
	break;
	case 2:
	{
		QGameNetFightMode *NetFightMode = new QGameNetFightMode(this);
		CurrentMode = NetFightMode;
		NetFightMode->setView(LoaderView);
		connect(NetFightMode, SIGNAL(exchangetoScene(QGraphicsScene*)), this, SIGNAL(exchangetoScene(QGraphicsScene*)));
		connect(CurrentMode, SIGNAL(addItem(objectNames, QPointF)), this, SIGNAL(addItem(objectNames, QPointF)));
		connect(this, SIGNAL(Itemadded(QMyObject*)), CurrentMode, SIGNAL(Itemadded(QMyObject*)));
		connect(NetFightMode, SIGNAL(exit()), this, SLOT(QuitMode()));
		if (!NetFightMode->InitTcpConnection())
			return;
		NetFightMode->LoadMyCard();
		NetFightMode->InitAddItemConnection();
		NetFightMode->GameStart();
	}
	default:
	break;
	}
}

void QGameModeLoader::QuitMode()
{
	if (CurrentMode != MainMode)
		CurrentMode->deleteLater();
	CurrentMode = MainMode;
	exchangetoScene(MainMode->getScene());
	MainMode->replayBGM(QMediaPlayer::StoppedState);
}

void QGameModeLoader::setView(QGraphicsView* view)
{
	LoaderView = view;
}

//public
QGameMainMode* QGameModeLoader::getMainMode()
{
	return MainMode;
}

QGameMode* QGameModeLoader::getCurrentMode()
{
	return CurrentMode;
}