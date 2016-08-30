#include "QGameModeLoader.h"

QGameModeLoader::QGameModeLoader(QWidget *parent)
//	:QObject(parent)
{
	MainMode = new QGameMainMode;
	CurrentMode = MainMode;
	connect(CurrentMode, SIGNAL(exchangetoScene(QGraphicsScene*)), this, SIGNAL(exchangetoScene(QGraphicsScene*)));
	connect(MainMode, SIGNAL(exchangetoScene(QGraphicsScene*)), this, SIGNAL(exchangetoScene(QGraphicsScene*)));
	connect(CurrentMode, SIGNAL(exit()), this, SLOT(QuitMode()));
}

QGameModeLoader::~QGameModeLoader()
{

}

QGameMode* QGameModeLoader::Load(GameModeNames name)
{
	//TODO ¼ÓÔØÄ£Ê½
	switch (name)
	{
	default:
		break;
	}
	return NULL;
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