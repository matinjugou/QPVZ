#include "QGameMode.h"
#include "QGameModeLoader.h"
#include "QCardSelector.h"

QGameMode::QGameMode(QGameModeLoader* parent)
	:QObject(parent)
{
	Scene = new QGraphicsScene(this);
	Scene->setItemIndexMethod(QGraphicsScene::NoIndex);
	
	Background = new QMyObject(this);
	Scene->addItem(Background);
	Background->setPos(0, 0);
	
}

QGameMode::~QGameMode()
{

}

//public
QGraphicsScene* QGameMode::getScene()
{
	return Scene;
}

void QGameMode::setView(QGraphicsView *loaderView)
{
	View = loaderView;
}


QGameMainMode::QGameMainMode(QGameModeLoader* parent)
	:QGameMode(parent)
{
	Scene->setSceneRect(0, 0, 900, 600);

	Background->pushbackPixmap(QPixmap("Resources/pvz-material/images/interface/Surface.png"));
	Background->setMyPixmap(0);

	StartGame_Adventure = new QMyButton("Resources/pvz-material/images/Buttons/startGame_Adventure.png", "Resources/pvz-material/images/Buttons/startGame_Adventure_pressed.png", this);
	StartGame_Adventure->setPos(507, 68);
	Scene->addItem(StartGame_Adventure);

	StartGame_NetFight = new QMyButton("Resources/pvz-material/images/Buttons/startGame_NetFight.png", "Resources/pvz-material/images/Buttons/startGame_NetFight_pressed.png", this);
	StartGame_NetFight->setPos(507, 172);
	Scene->addItem(StartGame_NetFight);
	
	Options = new QMyButton("Resources/pvz-material/images/Buttons/SelectorScreen_Options1.png", "Resources/pvz-material/images/Buttons/SelectorScreen_Options2.png", this);
	Options->setPos(734, 520);
	Scene->addItem(Options);
	
	Help = new QMyButton("Resources/pvz-material/images/Buttons/SelectorScreen_Help1.png", "Resources/pvz-material/images/Buttons/SelectorScreen_Help2.png", this);
	Help->setPos(657, 487);
	Scene->addItem(Help);

	Quit = new QMyButton("Resources/pvz-material/images/Buttons/SelectorScreen_Quit1.png", "Resources/pvz-material/images/Buttons/SelectorScreen_Quit2.png", this);
	Quit->setPos(805, 505);
	Quit->setScale(0.8);
	Scene->addItem(Quit); 
	
	QSignalMapper *Mapper = new QSignalMapper(this);
	connect(StartGame_Adventure, SIGNAL(clicked()), Mapper, SLOT(map()));
	connect(StartGame_NetFight, SIGNAL(clicked()), Mapper, SLOT(map()));

	Mapper->setMapping(StartGame_Adventure, 1);
	Mapper->setMapping(StartGame_NetFight, 2);

	connect(Mapper, SIGNAL(mapped(int)), this, SIGNAL(NewGameStart(int)));

//	connect(StartGame_Adventure, SIGNAL(clicked()), this, SIGNAL(AdventureMode_Start()));

	connect(Options, SIGNAL(clicked()), this, SIGNAL(Setting_Options()));
	connect(Help, SIGNAL(clicked()), this, SIGNAL(Help_Start()));
	connect(Quit, SIGNAL(clicked()), this, SIGNAL(Quit_Game()));

	emit exchangetoScene(Scene);
//	startTimer(20);
}

QGameMainMode::~QGameMainMode()
{

}

//public
void QGameMainMode::timerEvent(QTimerEvent *event)
{
	
}


QGameAdventureMode::QGameAdventureMode(QGameModeLoader *parent)
	:QGameMode(parent)
{
	Scene->setSceneRect(0, 0, 1400, 600);

	Selector = new QCardSelector(2, CardList, this);
	Bank = new QCardBank(this);
	MappingSystem = new QMyMap(this);
	
	Background->pushbackPixmap(QPixmap("Resources/pvz-material/images/interface/background1.jpg"));
	Background->setMyPixmap(0);
	Background->setPos(0, 0);
	
	Selector->setPos(500, 687);
	Bank->setPos(500, -120);
	
	Scene->addItem(Bank);
	Scene->addItem(Selector);
	Scene->addItem(MappingSystem);
	MappingSystem->setScene(Scene);	//引入对象树系统后可以优化掉

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
	barMoveed = 0;
	animation = new QPropertyAnimation(this);
}

QGameAdventureMode::~QGameAdventureMode()
{

}

//public slot
void QGameAdventureMode::GameStart()
{
	if (stage < 2)
	{
		stage++;
		TimerID = startTimer(20);
		if (stage == 2)
		{
			MappingSystem->startTimer(20);
		}
	}
}

//public
void QGameAdventureMode::timerEvent(QTimerEvent *event)
{
	currentTime++;
	if (stage == 1)
	{
		if ((currentTime >= 50) && (currentTime < 75))
		{
			if (barMoveed == 0)
			{
				moveScrollBar(0, 500, 700);
				barMoveed = 1;
			}
		}
		else if ((currentTime > 75) && (currentTime <= 85))
		{
			if (barMoveed == 1)
			{
				Selector->moveTo(500, 87, 200);
				Bank->moveTo(500, 0, 200);
				barMoveed = 2;
			}
		}
		else if (currentTime >= 85)
		{
			currentTime = 0;
			killTimer(TimerID);
			barMoveed = 0;
		}
	}
	else if (stage == 2)
	{
		if (currentTime <= 5)
		{
			if (barMoveed == 0)
			{
				Selector->moveTo(500, 600, 100);
				barMoveed = 1;
			}
		}
		else if ((currentTime > 5) && (currentTime <= 30))
		{
			if (barMoveed == 1)
			{
				moveScrollBar(500, 200, 500);
				Bank->moveTo(220, 0, 500);
				barMoveed = 2;
			}
		}
		else if (currentTime > 20)
		{
			currentTime = 0;
			stage++;
			barMoveed = 0;
		}
	}
	else if (stage == 3)
	{
		currentTime++;
		for (int i = 0; i < totZombies; i++)
		{
			if ((ZombiesList[i].timetoshow * 50) == currentTime)
			{
				QPoint tempPoint;
				int y = rand() % 4;
				tempPoint.setX(10);
				tempPoint.setY(y);
				addItem(CommonZombie, MappingSystem->PointtoPos(tempPoint));
			}
		}
		if (currentTime % 500 == 0)
		{
			newSunShine = new QMySunShine(Scene);
			QPointF tempPos;
			tempPos.setX(MappingSystem->getRect().width() / 12 * (rand() % 9) + MappingSystem->getRect().x());
			tempPos.setY(-60);
			newSunShine->setPos(tempPos);
			Scene->addItem(newSunShine);
			tempPos.setY(MappingSystem->getRect().height() / 5 * (rand() % 4) + MappingSystem->getRect().y());
			newSunShine->moveTo(tempPos, 3000, QEasingCurve::Linear);
			connect(newSunShine, SIGNAL(BeTaken()), Bank, SLOT(SunShineAdded()));
		}
	}
}

void QGameAdventureMode::moveScrollBar(int fromvalue, int arrivevalue, int duration)
{
	animation->setTargetObject(View->horizontalScrollBar());
	animation->setPropertyName("value");
	animation->setDuration(duration);
	animation->setStartValue(fromvalue);
	animation->setEndValue(arrivevalue);
	animation->setEasingCurve(QEasingCurve::InOutCubic);
	animation->start();
}