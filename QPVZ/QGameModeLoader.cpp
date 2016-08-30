#include "QGameModeLoader.h"

QGameModeLoader::QGameModeLoader(QWidget *parent)
	:QObject(parent)
{
	MainMode = new QGameMainMode;
	connect(CurrentMode, SIGNAL(exchangetoScene(QGraphicsScene*)), this, SIGNAL(exchangetoScene(QGraphicsScene*)));
	connect(MainMode, SIGNAL(exchangetoScene(QGraphicsScene*)), this, SIGNAL(exchangetoScene(QGraphicsScene*)));
	connect(CurrentMode, SIGNAL(exit()), this, SLOT(QuitMode()));
}

QGameModeLoader::~QGameModeLoader()
{

}

QGameMode* QGameModeLoader::Load(GameModeNames name)
{
	switch (name)
	{
	case Adventure: 
	{
	}
		break;
	default:
		break;
	}
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