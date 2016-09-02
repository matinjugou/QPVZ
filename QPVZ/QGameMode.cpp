#include "QGameMode.h"

QGameMode::QGameMode(QWidget* parent)
//	:QObject(parent)
{
}

QGameMode::~QGameMode()
{

}

QGameMainMode::QGameMainMode(QWidget* parent)
//	:QGameMode(parent)
{
	QPixmap tempPic;
	Scene = new QGraphicsScene;
	Scene->setSceneRect(0, 0, 900, 600);
	Scene->setItemIndexMethod(QGraphicsScene::NoIndex);
	Background = new QMyObject;
	tempPic.load("Resources/pvz-material/images/interface/Surface.png");
	Background->setPos(0, 0);
	Background->pushbackPixmap(tempPic);
	Background->setMyPixmap(0);
	Scene->addItem(Background);

	StartGame_Adventure = new QMyButton("Resources/pvz-material/images/Buttons/startGame_Adventure.png", "Resources/pvz-material/images/Buttons/startGame_Adventure_pressed.png");
	StartGame_Adventure->setPos(507, 68);
	Scene->addItem(StartGame_Adventure);

	StartGame_NetFight = new QMyButton("Resources/pvz-material/images/Buttons/startGame_NetFight.png", "Resources/pvz-material/images/Buttons/startGame_NetFight_pressed.png");
	StartGame_NetFight->setPos(507, 172);
	Scene->addItem(StartGame_NetFight);
	
	Options = new QMyButton("Resources/pvz-material/images/Buttons/SelectorScreen_Options1.png", "Resources/pvz-material/images/Buttons/SelectorScreen_Options2.png");
	Options->setPos(734, 520);
	Scene->addItem(Options);
	
	Help = new QMyButton("Resources/pvz-material/images/Buttons/SelectorScreen_Help1.png", "Resources/pvz-material/images/Buttons/SelectorScreen_Help2.png");
	Help->setPos(657, 487);
	Scene->addItem(Help);

	Quit = new QMyButton("Resources/pvz-material/images/Buttons/SelectorScreen_Quit1.png", "Resources/pvz-material/images/Buttons/SelectorScreen_Quit2.png");
	Quit->setPos(805, 505);
	Quit->setScale(0.8);
	Scene->addItem(Quit); 
	
	QSignalMapper *Mapper = new QSignalMapper;
	connect(StartGame_Adventure, SIGNAL(clicked()), Mapper, SLOT(map()));
	connect(StartGame_NetFight, SIGNAL(clicked()), Mapper, SLOT(map()));

	Mapper->setMapping(StartGame_Adventure, Adventure);
	Mapper->setMapping(StartGame_NetFight, NetFight);

//	connect(Mapper, SIGNAL(mapped(GameModeNames)), this, SIGNAL(NewGameStart(GameModeNames)));

	connect(StartGame_Adventure, SIGNAL(clicked()), this, SIGNAL(AdventureMode_Start()));

	connect(Options, SIGNAL(clicked()), this, SIGNAL(Setting_Options()));
	connect(Help, SIGNAL(clicked()), this, SIGNAL(Help_Start()));
	connect(Quit, SIGNAL(clicked()), this, SIGNAL(Quit_Game()));

	emit exchangetoScene(Scene);
//	startTimer(20);
}

QGameMainMode::~QGameMainMode()
{
	delete StartGame_Adventure;
	delete StartGame_NetFight;
	delete Options;
	delete Help;
	delete Quit;
}

void QGameMainMode::timerEvent(QTimerEvent *event)
{
	
}

QGraphicsScene* QGameMode::getScene()
{
	return Scene;
}

QGameAdventureMode::QGameAdventureMode(QWidget *parent)
{
	Scene = new QGraphicsScene;
	Scene->setSceneRect(0, 0, 1400, 600);
	Scene->setItemIndexMethod(QGraphicsScene::NoIndex);
	Selector = new QCardSelector(2, CardList);
	Bank = new QCardBank;
	MappingSystem = new QMyMap;
	Background = new QMyObject;
	QPixmap tempPix;
	tempPix.load("Resources/pvz-material/images/interface/background1.jpg");
	Background->pushbackPixmap(tempPix);
	Background->setMyPixmap(0);
	Background->setPos(0, 0);
	Selector->setPos(500, 687);
	Bank->setPos(500, -120);
	Scene->addItem(Background);
	Scene->addItem(Bank);
	Scene->addItem(Selector);
	Scene->addItem(MappingSystem);

	connect(Selector, SIGNAL(moveRequest(QMyCard*)), Bank, SLOT(moveRequested(QMyCard*)));
	connect(Selector, SIGNAL(removeInform(QMyCard*)), Bank, SLOT(removeConfirm(QMyCard*)));
	connect(Bank, SIGNAL(moveAccepted(QPointF, QMyCard*)), Selector, SLOT(moveAccepted(QPointF, QMyCard*)));

	connect(Bank, SIGNAL(ReadytoPlant(objectNames, QPointF)), MappingSystem, SLOT(Plantrequest_Ready(objectNames, QPointF)));
	connect(MappingSystem, SIGNAL(RequestDone()), Bank, SLOT(plantRequestDone()));
	connect(MappingSystem, SIGNAL(addItem(objectNames, QPointF)), this, SIGNAL(addItem(objectNames, QPointF)));

	connect(this, SIGNAL(Itemadded(QMyObject*)), MappingSystem, SLOT(Itemadded(QMyObject*)));
	connect(Selector, SIGNAL(startGameNow()), this, SLOT(GameStart()));
	connect(Selector, SIGNAL(startGameNow()), Bank, SLOT(Initconnection()));
	currentTime = 0;
	stage = 0;
	horizontalScollBarValue = 0;
//	emit exchangetoScene(Scene);
}

void QGameAdventureMode::GameStart()
{
	if (stage < 2)
	{
		stage++;
		TimerID = startTimer(20);
	}
}

void QGameAdventureMode::timerEvent(QTimerEvent *event)
{
	currentTime++;
	if (stage == 1)
	{
		if ((currentTime >= 50) && (currentTime < 75))
		{
			horizontalScollBarValue += 20;
			View->horizontalScrollBar()->setValue(horizontalScollBarValue);
		}
		else if ((currentTime > 100) && (currentTime <= 150))
		{
			if (Selector->pos().y() > 87)
			{
				Selector->setPos(Selector->pos().x(), Selector->pos().y() - 100);
			}
			if (Bank->pos().y() < 0)
			{
				Bank->setPos(Bank->pos().x(), Bank->pos().y() + 20);
			}

		}
		else if (currentTime >= 150)
		{
			currentTime = 0;
			killTimer(TimerID);
		}
	}
	else if (stage == 2)
	{
		if (currentTime <= 5)
		{
			Selector->setPos(Selector->pos().x(), Selector->pos().y() + 200);
		}
		else if ((currentTime > 5) && (currentTime <= 20))
		{
			horizontalScollBarValue -= 20;
			View->horizontalScrollBar()->setValue(horizontalScollBarValue);
			if (Bank->pos().x() > 20)
			{
				Bank->setPos(Bank->pos().x() - 18, Bank->pos().y());
			}
		}
		else if (currentTime > 20)
		{
			currentTime = 0;
			killTimer(TimerID);
		}
	}
}

void QGameMode::setView(QGraphicsView *loaderView)
{
	View = loaderView;
}

QGameAdventureMode::~QGameAdventureMode()
{
	delete Selector;
	delete Bank;
	delete MappingSystem;
}