#include "QGameModeLoader.h"

QGameModeLoader::QGameModeLoader(QWidget *parent)
//	:QObject(parent)
{
	MainMode = new QGameMainMode;
	CurrentMode = MainMode;
	connect(CurrentMode, SIGNAL(exit()), this, SLOT(QuitMode()));
	connect(MainMode, SIGNAL(NewGameStart(GameModeNames)), this, SLOT(Load(GameModeNames)));
	connect(MainMode, SIGNAL(AdventureMode_Start()), this, SLOT(LoadAdventure()));
}

QGameModeLoader::~QGameModeLoader()
{

}

void QGameModeLoader::setView(QGraphicsView* view)
{
	LoaderView = view;
}

QGameMode* QGameModeLoader::Load(GameModeNames name)
{
	//TODO 加载模式
	switch (name)
	{
	case Adventure:
	{
		QGameAdventureMode *AdventureMode = new QGameAdventureMode;
		CurrentMode = AdventureMode;
		emit exchangetoScene(AdventureMode->getScene());
		AdventureMode->setView(LoaderView);
		connect(CurrentMode, SIGNAL(addItem(objectNames, QPointF)), this, SIGNAL(addItem(objectNames, QPointF)));
		connect(this, SIGNAL(Itemadded(QMyObject*)), CurrentMode, SIGNAL(Itemadded(QMyObject*)));
		AdventureMode->GameStart();
		return AdventureMode;
	}
		break;
	default:
		break;
	}
	return NULL;
}

void QGameModeLoader::LoadAdventure()
{
	//TODO 加载模式
		QGameAdventureMode *AdventureMode = new QGameAdventureMode;
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

QGameMainMode* QGameModeLoader::getMainMode()
{
	return MainMode;
}

QGameMode* QGameModeLoader::getCurrentMode()
{
	return CurrentMode;
}