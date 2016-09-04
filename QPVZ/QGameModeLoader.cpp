#include "QGameModeLoader.h"
#include "QGameMode.h"
QGameModeLoader::QGameModeLoader(QObject *parent)
	:QObject(parent)
{
	MainMode = new QGameMainMode(this);
	CurrentMode = MainMode;
	connect(CurrentMode, SIGNAL(exit()), this, SLOT(QuitMode()));
	connect(MainMode, SIGNAL(NewGameStart(int)), this, SLOT(Load(int)));
	connect(MainMode, SIGNAL(AdventureMode_Start()), this, SLOT(LoadAdventure()));
}

QGameModeLoader::~QGameModeLoader()
{

}

//public slots
void QGameModeLoader::Load(int name)
{
	//TODO 加载模式
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
		AdventureMode->GameStart();
	}
		break;
	default:
		break;
	}
}

void QGameModeLoader::LoadAdventure()
{
	//TODO 加载模式
		QGameAdventureMode *AdventureMode = new QGameAdventureMode(this);
		CurrentMode = AdventureMode;
		emit exchangetoScene(AdventureMode->getScene());
		connect(CurrentMode, SIGNAL(addItem(objectNames, QPointF)), this, SIGNAL(addItem(objectNames, QPointF)));
		connect(this, SIGNAL(Itemadded(QMyObject*)), CurrentMode, SIGNAL(Itemadded(QMyObject*)));
		AdventureMode->setView(LoaderView);
		AdventureMode->GameStart();
}

void QGameModeLoader::QuitMode()
{
	exchangetoScene(MainMode->getScene());
	delete CurrentMode;
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