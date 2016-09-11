#include "QGameMode.h"
#include "QGameModeLoader.h"
#include "QCardSelector.h"
#include "QMyMap.h"
#include "QMySunShine.h"
#include "QCardBanks.h"
#include "QMyShovel.h"
#include "QMyProcessor.h"
#include "QZombies.h"
#include "QPlants.h"

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
	currentTime = 0;

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

	zombieHand = new QMyObject(this);
	zombieHand->setOneGif("Resources/pvz-material/images/interface/SelectorZombieHand.gif");
	Scene->addItem(zombieHand);
	zombieHand->setPos(270, 270);
	
	Mapper = new QSignalMapper(this);
	connect(StartGame_Adventure, SIGNAL(clicked()), Mapper, SLOT(map()));
	connect(StartGame_NetFight, SIGNAL(clicked()), Mapper, SLOT(map()));

	Mapper->setMapping(StartGame_Adventure, 1);
	Mapper->setMapping(StartGame_NetFight, 2);

	eveilLaugh = new QMediaPlayer(zombieHand);
	eveilLaugh->setMedia(QUrl::fromLocalFile("Resources/pvz-material/audio/evillaugh.mp3"));
	eveilLaugh->setVolume(50);

	gameStartSound = new QMediaPlayer(zombieHand);
	gameStartSound->setMedia(QUrl::fromLocalFile("Resources/pvz-material/audio/losemusic.mp3"));
	gameStartSound->setVolume(50);

	backgroundMusic = new QMediaPlayer(this);
	backgroundMusic->setMedia(QUrl::fromLocalFile("Resources/pvz-material/audio/Faster.mp3"));
	backgroundMusic->setVolume(50);
	backgroundMusic->play();
	connect(backgroundMusic, SIGNAL(stateChanged(QMediaPlayer::State)), this, SLOT(replayBGM(QMediaPlayer::State)));

	connect(Mapper, SIGNAL(mapped(int)), this, SLOT(beforeNewGameStart(int)));

	connect(Options, SIGNAL(clicked()), this, SIGNAL(Setting_Options()));
	connect(Help, SIGNAL(clicked()), this, SIGNAL(Help_Start()));
	connect(Quit, SIGNAL(clicked()), qApp, SLOT(quit()));

	emit exchangetoScene(Scene);
}

QGameMainMode::~QGameMainMode()
{

}

void QGameMode::replayBGM(QMediaPlayer::State statechanged)
{
	if (statechanged == QMediaPlayer::StoppedState)
		backgroundMusic->play();
}

void QGameMainMode::beforeNewGameStart(int gameModeType)
{
	ModetoStart = gameModeType;
	TimerID = startTimer(20);
}

//public
void QGameMainMode::timerEvent(QTimerEvent *event)
{
	if (currentTime == 0)
	{
		ModeButtonStatus = 1;
		zombieHand->getMyGif()->jumpToFrame(1);
		disconnect(Mapper, SIGNAL(mapped(int)), this, SLOT(beforeNewGameStart(int)));
		zombieHand->getMyGif()->start();
		backgroundMusic->pause();
		eveilLaugh->play();
		gameStartSound->play();
	}
	if (currentTime % 5 == 0)
	{
		switch (ModetoStart)
		{
		case 1:
		{
			if (ModeButtonStatus == 1)
			{
				StartGame_Adventure->changetoHoverImg();
				ModeButtonStatus = 2;
			}
			else
			{
				StartGame_Adventure->changetoPlainImg();
				ModeButtonStatus = 1;
			}
		}
		break;
		case 2:
		{
			if (ModeButtonStatus == 1)
			{
				StartGame_NetFight->changetoHoverImg();
				ModeButtonStatus = 2;
			}
			else
			{
				StartGame_NetFight->changetoPlainImg();
				ModeButtonStatus = 1;
			}
		}
		break;
		default:
			break;
		}
	}
	currentTime++;
	if (currentTime == 125)
	{
		killTimer(TimerID);
		currentTime = 0;
		emit NewGameStart(ModetoStart);
		connect(Mapper, SIGNAL(mapped(int)), this, SLOT(beforeNewGameStart(int)));
		zombieHand->getMyGif()->jumpToFrame(0);
	}
}


QGameAdventureMode::QGameAdventureMode(QGameModeLoader *parent)
	:QGameMode(parent)
{
	Scene->setSceneRect(0, 0, 1400, 600);

	SettingsFile.setFileName("Resources/files/SettingsFiles.txt");
	if (!SettingsFile.open(QIODevice::ReadOnly))
	{
		qDebug() << "Failed";
	}
	QTextStream inStream(&SettingsFile);
	inStream >> Level;
	inStream >> totZombies;
	for (int i = 0; i < totZombies; i++)
	{
		Node tempNode;
		int tempzombieType;
		int tempzombieShowTime;
		inStream >> tempzombieType >> tempzombieShowTime;
		tempNode.Zombie_Type = zombieTypeInttoEnum(tempzombieType);
		tempNode.timetoshow = tempzombieShowTime;
		ZombiesList.push_back(tempNode);
	}
	inStream >> totCards;
	for (int i = 0; i < totCards; i++)
	{
		int tempplantType;
		inStream >> tempplantType;
		CardList.push_back(plantTypeInttoEnum(tempplantType));
	}
	int tempHighPoint;
	QVector<int> tempHighPos;
	inStream >> tempHighPoint;
	for (int i = 0; i < tempHighPoint; i++)
	{
		int singletempHighPos;
		inStream >> singletempHighPos;
		tempHighPos.push_back(singletempHighPos);
	}
	SettingsFile.close();

	Selector = new QCardSelector(totCards, CardList, this);
	Bank = new QCardBank(this);
	MappingSystem = new QMyMap(this);
	Shovel = new QMyShovel(this);
	Shovel_Bank = new QMyObject(this);
	MyProcessorBar = new QMyProcessor(100, 0, tempHighPos, this);
	MyProcessorBar->setZValue(100);
	QuitGame = new QMyButton("Resources/pvz-material/images/Buttons/QuitGamePlain.png", "Resources/pvz-material/images/Buttons/QuitGameHover.png", this);
	GameOverPix = new QMyObject(this);
	readyToPlantText = new QMyObject(this);

	GameOverPix->pushbackPixmap(QPixmap("Resources/pvz-material/images/interface/ZombiesWon.png"));
	GameOverPix->setMyPixmap(0);

	Shovel_Bank->setPixmap(QPixmap("Resources/pvz-material/images/interface/ShovelBank.png"));

	Background->pushbackPixmap(QPixmap("Resources/pvz-material/images/interface/background1.jpg"));
	Background->setMyPixmap(0);
	Background->setPos(0, 0);
	
	readyToPlantText->pushbackPixmap(QPixmap("Resources/pvz-material/images/interface/PrepareGrowPlants1.png"));
	readyToPlantText->pushbackPixmap(QPixmap("Resources/pvz-material/images/interface/PrepareGrowPlants2.png"));
	readyToPlantText->pushbackPixmap(QPixmap("Resources/pvz-material/images/interface/PrepareGrowPlants3.png"));

	readyToPlantText->setPos(520, 230);
	Selector->setPos(500, 687);
	Bank->setPos(500, -120);
	Shovel_Bank->setPos(666, 0);
	GameOverPix->setPos(401, 80);
	GameOverPix->setOpacity(0);

	Shovel->setPos(666, 0);
	Shovel->setOriginPos(Shovel->pos());
	Shovel->setOpacity(0);
	Shovel_Bank->setOpacity(0);
	MyProcessorBar->setPos(900, 550);
	MyProcessorBar->setOpacity(0);
	QuitGame->setPos(787, 0);

	Scene->addItem(Bank);
	Scene->addItem(Selector);
	Scene->addItem(MappingSystem);
	Scene->addItem(Shovel_Bank);
	Scene->addItem(Shovel);
	Scene->addItem(MyProcessorBar);
	Scene->addItem(GameOverPix);
	Scene->addItem(readyToPlantText);
	Scene->addItem(QuitGame);

	backgroundMusic = new QMediaPlayer(this);
	backgroundMusic->setMedia(QUrl::fromLocalFile("Resources/pvz-material/audio/Look up at the Sky.mp3"));
	backgroundMusic->setVolume(50);
	backgroundMusic->play();

	readyToPlantBGM = new QMediaPlayer(this);
	readyToPlantBGM->setMedia(QUrl::fromLocalFile("Resources/pvz-material/audio/readysetplant.mp3"));
	readyToPlantBGM->setVolume(50);

	connect(Selector, SIGNAL(moveRequest(QMyCard*)), Bank, SLOT(moveRequested(QMyCard*)));
	connect(Selector, SIGNAL(removeInform(QMyCard*)), Bank, SLOT(removeConfirm(QMyCard*)));
	connect(Bank, SIGNAL(moveAccepted(QPointF, QMyCard*)), Selector, SLOT(moveAccepted(QPointF, QMyCard*)));

	connect(Bank, SIGNAL(ReadytoPlant(objectNames, QPointF)), MappingSystem, SLOT(Plantrequest_Ready(objectNames, QPointF)));
	connect(MappingSystem, SIGNAL(RequestDone()), Bank, SLOT(plantRequestDone()));
	connect(MappingSystem, SIGNAL(RequestCancelled()), Bank, SLOT(plantRequestCancelled()));
	connect(MappingSystem, SIGNAL(addItem(objectNames, QPointF)), this, SIGNAL(addItem(objectNames, QPointF)));
	
	connect(QuitGame, SIGNAL(clicked()), this, SIGNAL(exit()));

	connect(this, SIGNAL(Itemadded(QMyObject*)), MappingSystem, SLOT(Itemadded(QMyObject*)));
	connect(Selector, SIGNAL(startGameNow()), this, SLOT(GameStart()));
	connect(Selector, SIGNAL(startGameNow()), Bank, SLOT(Initconnection()));

	connect(Shovel, SIGNAL(leftButtonClicked(QPointF)), MappingSystem, SLOT(ShovelMessage(QPointF)));

	connect(MappingSystem, SIGNAL(SunShineAdded()), Bank, SLOT(SunShineAdded()));

	connect(MappingSystem, SIGNAL(GameOver()), this, SLOT(GameOver()));

	connect(MappingSystem, SIGNAL(AllZombiesAreDone(bool)), this, SLOT(GameConditionChanged(bool)));
	
	currentTime = 0;
	stage = 0;
	barMoveed = 0;
	firstZombieShowed = false;
	GameOverTiemerID = -1;
	GameOverTiemerCount = 0;
	isGameOvered = false;
	Gamewin1 = false;
	Gamewin2 = false;

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

void QGameAdventureMode::GameOver()
{
	if (!isGameOvered)
	{
		isGameOvered = true;
		QPropertyAnimation *GameOverAnimation = new QPropertyAnimation(GameOverPix, "opacity", GameOverPix);
		GameOverAnimation->setDuration(100);
		GameOverAnimation->setStartValue(0);
		GameOverAnimation->setEndValue(1);
		GameOverAnimation->setEasingCurve(QEasingCurve::Linear);
		GameOverAnimation->start();
		GameOverTiemerID = startTimer(1000);
	}
}

//public
void QGameAdventureMode::timerEvent(QTimerEvent *event)
{
	if (Gamewin1 && Gamewin2)
	{
		emit exit();
	}
	if (event->timerId() == GameOverTiemerID)
	{
		GameOverTiemerCount++;
		if (GameOverTiemerCount == 5)
		{
			emit exit();
		}
	}
	else
	{
		currentTime++;
		if (stage == 1)
		{
			if ((currentTime >= 50) && (currentTime < 75))
			{
				if (barMoveed == 0)
				{
					moveScrollBar(0, 500, 700);
					QPropertyAnimation *ButtonAnimation = new QPropertyAnimation(QuitGame, "pos", QuitGame);
					ButtonAnimation->setStartValue(QuitGame->pos());
					ButtonAnimation->setEndValue(QPointF(1400 - QuitGame->boundingRect().width(), 0));
					ButtonAnimation->setDuration(700);
					ButtonAnimation->setEasingCurve(QEasingCurve::InOutCubic);
					ButtonAnimation->start();
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
					QPropertyAnimation *ButtonAnimation = new QPropertyAnimation(QuitGame, "pos", QuitGame);
					ButtonAnimation->setStartValue(QuitGame->pos());
					ButtonAnimation->setEndValue(QPointF(987, 0));
					ButtonAnimation->setDuration(500);
					ButtonAnimation->setEasingCurve(QEasingCurve::InOutCubic);
					ButtonAnimation->start();
					Bank->moveTo(220, 0, 500);
					barMoveed = 2;
				}
			}
			else if (currentTime > 30)
			{
				QPropertyAnimation *ShovelAnimation = new QPropertyAnimation(Shovel, "opacity", Shovel);
				QPropertyAnimation *ShovelBankAnimation = new QPropertyAnimation(Shovel_Bank, "opacity", Shovel_Bank);
				ShovelAnimation->setDuration(100);
				ShovelAnimation->setStartValue(0);
				ShovelAnimation->setEndValue(1);
				ShovelAnimation->setEasingCurve(QEasingCurve::Linear);
				ShovelBankAnimation->setDuration(100);
				ShovelBankAnimation->setStartValue(0);
				ShovelBankAnimation->setEndValue(1);
				ShovelBankAnimation->setEasingCurve(QEasingCurve::Linear);
				ShovelAnimation->start();
				ShovelBankAnimation->start();
				currentTime = 0;
				stage++;
				barMoveed = 0;
			}
		}
		else if (stage == 3)
		{
			if (currentTime == 1)
			{
				backgroundMusic->stop();
				backgroundMusic->setMedia(QUrl::fromLocalFile("Resources/pvz-material/audio/UraniwaNi.mp3"));
				readyToPlantBGM->play();
				readyToPlantCount = 0;
				readyToPlantText->setMyPixmap(readyToPlantCount);
			}
			if ((currentTime % 20 == 0) && (currentTime < 59))
			{
				readyToPlantCount++;
				readyToPlantText->setMyPixmap(readyToPlantCount);
			}
			if (currentTime == 55)
			{
				readyToPlantText->hide();
				currentTime = 0;
				stage++;
				backgroundMusic->play();
				connect(backgroundMusic, SIGNAL(stateChanged(QMediaPlayer::State)), this, SLOT(replayBGM(QMediaPlayer::State)));
			}
		}
		else if (stage == 4)
		{
			currentTime++;
			for (int i = 0; i < totZombies; i++)
			{
				if ((ZombiesList[i].timetoshow * 50) == currentTime)
				{
					QPoint tempPoint;
					int y = rand() % 5;
					tempPoint.setX(13);
					tempPoint.setY(y);
					addItem(ZombiesList[i].Zombie_Type, MappingSystem->PointtoPos(tempPoint));
					MyProcessorBar->addtocurrentProcess(1.0 / (double)totZombies);
					if (!firstZombieShowed)
					{
						firstZombieShowed = true;
						MyProcessorBar->Init();
						QPropertyAnimation *ProcessorAnimation = new QPropertyAnimation(MyProcessorBar, "opacity", MyProcessorBar);
						ProcessorAnimation->setDuration(100);
						ProcessorAnimation->setStartValue(0);
						ProcessorAnimation->setEndValue(1);
						ProcessorAnimation->setEasingCurve(QEasingCurve::Linear);
						ProcessorAnimation->start();
					}
					if (i == (totZombies - 1))
					{
						Gamewin2 = true;
					}
				}
			}
			if (currentTime % 500 == 0)
			{
				newSunShine = new QMySunShine(Scene);
				QPointF tempPos;
				tempPos.setX(MappingSystem->getRect().width() / 14 * (rand() % 9) + MappingSystem->getRect().x() + 2);
				tempPos.setY(-60);
				newSunShine->setPos(tempPos);
				Scene->addItem(newSunShine);
				tempPos.setY(MappingSystem->getRect().height() / 5 * (rand() % 4) + MappingSystem->getRect().y());
				newSunShine->moveTo(tempPos, 3000, QEasingCurve::Linear);
				newSunShine->setZValue(100);
				connect(newSunShine, SIGNAL(BeTaken()), Bank, SLOT(SunShineAdded()));
			}
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

void QGameAdventureMode::GameConditionChanged(bool value)
{
	Gamewin1 = value;
}

objectNames QGameAdventureMode::zombieTypeInttoEnum(int zombieTypeint)
{
	switch (zombieTypeint)
	{
	case 1:
	{
		return CommonZombie;
	}
	break;
	case 2:
	{
		return BucketHeadZombie;
	}
	break; 
	case 3:
	{
		return PoleVaultingZombie;
	}
	break;
	default:
		break;
	}
	return Nosuchobject;
}

objectNames QGameAdventureMode::plantTypeInttoEnum(int plantTypeint)
{
	switch (plantTypeint)
	{
	case 1:
	{
		return PeaShooter;
	}
	break;
	case 2:
	{
		return SunFlower;
	}
	break;
	case 3:
	{
		return WallNut;
	}
	break;
	case 4:
	{
		return CherryBomb;
	}
	default:
		break;
	}
	return Nosuchobject;
}



QGameNetFightMode::QGameNetFightMode(QGameModeLoader* parent)
	:QGameMode(parent)
{
	Scene->setSceneRect(0, 0, 1400, 600);

	MappingSystem = new QMyMap(this);
	Bank = new QCardBank(this);
	QuitGame = new QMyButton("Resources/pvz-material/images/Buttons/QuitGamePlain.png", "Resources/pvz-material/images/Buttons/QuitGameHover.png", this);
	ZombieLine = new QMyObject(this);
	readyToPlantText = new QMyObject(this);

	Background->pushbackPixmap(QPixmap("Resources/pvz-material/images/interface/background1.jpg"));
	Background->setMyPixmap(0);
	Background->setPos(0, 0);
	Bank->setPos(500, -120);
	Bank->setSunShine(200);

	ZombieLine->pushbackPixmap(QPixmap("Resources/pvz-material/images/interface/Stripe.png"));
	ZombieLine->setMyPixmap(0);
	ZombieLine->setPos(807, 70);

	readyToPlantText->pushbackPixmap(QPixmap("Resources/pvz-material/images/interface/PrepareGrowPlants1.png"));
	readyToPlantText->pushbackPixmap(QPixmap("Resources/pvz-material/images/interface/PrepareGrowPlants2.png"));
	readyToPlantText->pushbackPixmap(QPixmap("Resources/pvz-material/images/interface/PrepareGrowPlants3.png"));

	readyToPlantText->setPos(520, 230);

	QuitGame->setPos(787, 0);

	Scene->addItem(ZombieLine);
	Scene->addItem(Bank);
	Scene->addItem(MappingSystem);
	Scene->addItem(QuitGame);
	Scene->addItem(readyToPlantText);

	backgroundMusic = new QMediaPlayer(this);
	backgroundMusic->setMedia(QUrl::fromLocalFile("Resources/pvz-material/audio/Look up at the Sky.mp3"));
	backgroundMusic->setVolume(50);
	backgroundMusic->play();

	readyToPlantBGM = new QMediaPlayer(this);
	readyToPlantBGM->setMedia(QUrl::fromLocalFile("Resources/pvz-material/audio/readysetplant.mp3"));
	readyToPlantBGM->setVolume(50);

	connect(Bank, SIGNAL(ReadytoPlant(objectNames, QPointF)), MappingSystem, SLOT(Plantrequest_Ready(objectNames, QPointF)));
	connect(MappingSystem, SIGNAL(RequestDone()), Bank, SLOT(plantRequestDone()));
	connect(MappingSystem, SIGNAL(RequestCancelled()), Bank, SLOT(plantRequestCancelled()));
	connect(MappingSystem, SIGNAL(addItem(objectNames, QPointF)), this, SIGNAL(addItem(objectNames, QPointF)));

	connect(QuitGame, SIGNAL(clicked()), this, SIGNAL(exit()));

	connect(this, SIGNAL(Itemadded(QMyObject*)), MappingSystem, SLOT(Itemadded(QMyObject*)));


	connect(MappingSystem, SIGNAL(SunShineAdded()), Bank, SLOT(SunShineAdded()));

	currentTime = 0;
	stage = 0;
	barMoveed = 0;
	timeCouner = 0;

	animation = new QPropertyAnimation(this);
}

QGameNetFightMode::~QGameNetFightMode()
{

}


//public slot
void QGameNetFightMode::GameStart()
{
	if (stage < 2)
	{
		if (stage == 0)
			emit exchangetoScene(Scene);
		stage++;
		TimerID = startTimer(20);
		if (stage == 2)
		{
			MappingSystem->startTimer(20);
		}
	}
}

bool QGameNetFightMode::InitTcpConnection()
{
	myDialog = new QMyDialog;
	if (myDialog->exec() == QDialog::Accepted)
	{
		if (myDialog->ui.radioButton_Server->isChecked())
		{
			asServer = true;
		}
		else
		{
			asServer = false;
			ipStr = myDialog->ui.IPLineEdit->text();
		}
		if (asServer)
		{
			Server = new QTcpServer(this);
			Server->listen(QHostAddress::Any, 1270);
			if (Server->waitForNewConnection(60000))
			{
				Socket = new QTcpSocket(this);
				Socket = Server->nextPendingConnection();
			}
			else
			{
				delete myDialog;
				return false;
			}
		}
		else
		{
			Socket = new QTcpSocket(this);
			Socket->connectToHost(ipStr, 1270);
		}
		delete myDialog;
		return true;
	}
	else
	{
		delete myDialog;
		return false;
	}
}

void QGameNetFightMode::LoadMyCard()
{
	if (asServer)
	{
		SettingsFile.setFileName("Resources/files/SettingsFiles_NetFight_Plants.txt");
		if (!SettingsFile.open(QIODevice::ReadOnly))
		{
			qDebug() << "Failed";
		}

		QTextStream inStream(&SettingsFile);
		inStream >> totCards;
		for (int i = 0; i < totCards; i++)
		{
			int tempplantType;
			inStream >> tempplantType;
			CardList.push_back(plantTypeInttoEnum(tempplantType));
		}

	}
	else
	{
		SettingsFile.setFileName("Resources/files/SettingsFiles_NetFight_Zombies.txt");
		if (!SettingsFile.open(QIODevice::ReadOnly))
		{
			qDebug() << "Failed";
		}

		QTextStream inStream(&SettingsFile);
		inStream >> totCards;
		for (int i = 0; i < totCards; i++)
		{
			int tempzombieType;
			inStream >> tempzombieType;
			CardList.push_back(zombieTypeInttoEnum(tempzombieType));
		}
	}

	SettingsFile.close();


	Selector = new QCardSelector(totCards, CardList, this);
	Scene->addItem(Selector);
	Selector->setPos(500, 687);

	connect(Selector, SIGNAL(moveRequest(QMyCard*)), Bank, SLOT(moveRequested(QMyCard*)));
	connect(Selector, SIGNAL(removeInform(QMyCard*)), Bank, SLOT(removeConfirm(QMyCard*)));
	connect(Bank, SIGNAL(moveAccepted(QPointF, QMyCard*)), Selector, SLOT(moveAccepted(QPointF, QMyCard*)));

	connect(Selector, SIGNAL(startGameNow()), this, SLOT(GameStart()));
	connect(Selector, SIGNAL(startGameNow()), Bank, SLOT(Initconnection()));

}

void QGameNetFightMode::InitAddItemConnection()
{
	connect(Socket, SIGNAL(readyRead()), this, SLOT(getMessage()));
	connect(MappingSystem, SIGNAL(addItem(objectNames, QPointF)), this, SLOT(sendMessage(objectNames, QPointF)));
}

void QGameNetFightMode::sendMessage(objectNames itemobejectnames, QPointF tempPos)
{
	QString tempString;
	tempString = itemObjectnamestoString(itemobejectnames) 
		+ "$" + QString::number(tempPos.x()) + "$" + QString::number(tempPos.y());
	Socket->write(tempString.toLatin1());
}

void QGameNetFightMode::getMessage()
{
	QString buffer;
	buffer = QString(Socket->readAll());
	QStringList List = buffer.split('$');
	QPointF tempPos;
	objectNames tempobjectName = itemStringtoObjectnames(List[0]);
	tempPos.setX(List[1].toDouble());
	tempPos.setY(List[2].toDouble());
	addItem(tempobjectName, tempPos);
}

void QGameNetFightMode::timerEvent(QTimerEvent *event)
{
	currentTime++;
	timeCouner++;
	if (timeCouner == 15000)
	{
		killTimer(TimerID);
		emit exit();
	}
	if (stage == 1)
	{
		if ((currentTime >= 50) && (currentTime < 75))
		{
			if (barMoveed == 0)
			{
				moveScrollBar(0, 500, 700);
				QPropertyAnimation *ButtonAnimation = new QPropertyAnimation(QuitGame, "pos", QuitGame);
				ButtonAnimation->setStartValue(QuitGame->pos());
				ButtonAnimation->setEndValue(QPointF(1400 - QuitGame->boundingRect().width(), 0));
				ButtonAnimation->setDuration(700);
				ButtonAnimation->setEasingCurve(QEasingCurve::InOutCubic);
				ButtonAnimation->start();
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
				QPropertyAnimation *ButtonAnimation = new QPropertyAnimation(QuitGame, "pos", QuitGame);
				ButtonAnimation->setStartValue(QuitGame->pos());
				ButtonAnimation->setEndValue(QPointF(987, 0));
				ButtonAnimation->setDuration(500);
				ButtonAnimation->setEasingCurve(QEasingCurve::InOutCubic);
				ButtonAnimation->start();
				Bank->moveTo(220, 0, 500);
				barMoveed = 2;
			}
		}
		else if (currentTime > 30)
		{
			currentTime = 0;
			stage++;
			barMoveed = 0;
		}
	}
	else if (stage == 3)
	{
		if (currentTime == 1)
		{
			backgroundMusic->stop();
			backgroundMusic->setMedia(QUrl::fromLocalFile("Resources/pvz-material/audio/UraniwaNi.mp3"));
			readyToPlantBGM->play();
			readyToPlantCount = 0;
			readyToPlantText->setMyPixmap(readyToPlantCount);
		}
		if ((currentTime % 20 == 0) && (currentTime < 59))
		{
			readyToPlantCount++;
			readyToPlantText->setMyPixmap(readyToPlantCount);
		}
		if (currentTime == 55)
		{
			readyToPlantText->hide();
			currentTime = 0;
			stage++;
			backgroundMusic->play();
			connect(backgroundMusic, SIGNAL(stateChanged(QMediaPlayer::State)), this, SLOT(replayBGM(QMediaPlayer::State)));
		}
	}
	else if (stage == 4)
	{
		currentTime++;
		if ((currentTime % 500 == 0) && (asServer))
		{
			newSunShine = new QMySunShine(Scene);
			QPointF tempPos;
			tempPos.setX(MappingSystem->getRect().width() / 14 * (rand() % 9) + MappingSystem->getRect().x());
			tempPos.setY(-60);
			newSunShine->setPos(tempPos);
			Scene->addItem(newSunShine);
			tempPos.setY(MappingSystem->getRect().height() / 5 * (rand() % 4) + MappingSystem->getRect().y());
			newSunShine->moveTo(tempPos, 3000, QEasingCurve::Linear);
			newSunShine->setZValue(100);
			connect(newSunShine, SIGNAL(BeTaken()), Bank, SLOT(SunShineAdded()));
		}
	}
}

void QGameNetFightMode::moveScrollBar(int fromvalue, int arrivevalue, int duration)
{
	animation->setTargetObject(View->horizontalScrollBar());
	animation->setPropertyName("value");
	animation->setDuration(duration);
	animation->setStartValue(fromvalue);
	animation->setEndValue(arrivevalue);
	animation->setEasingCurve(QEasingCurve::InOutCubic);
	animation->start();
}

objectNames QGameNetFightMode::zombieTypeInttoEnum(int zombieTypeint)
{
	switch (zombieTypeint)
	{
	case 1:
	{
		return CommonZombie;
	}
	break;
	case 2:
	{
		return BucketHeadZombie;
	}
	break;
	case 3:
	{
		return PoleVaultingZombie;
	}
	break;
	default:
		break;
	}
	return Nosuchobject;
}

objectNames QGameNetFightMode::plantTypeInttoEnum(int plantTypeint)
{
	switch (plantTypeint)
	{
	case 1:
	{
		return PeaShooter;
	}
	break;
	case 2:
	{
		return SunFlower;
	}
	break;
	case 3:
	{
		return WallNut;
	}
	break;
	case 4:
	{
		return CherryBomb;
	}
	default:
		break;
	}
	return Nosuchobject;
}

objectNames QGameNetFightMode::itemStringtoObjectnames(QString itemnamestring)
{
	if (itemnamestring == "PeaShooter")
	{
		return PeaShooter;
	}
	else if (itemnamestring == "CommonZombie")
	{
		return CommonZombie;
	}
	else if (itemnamestring == "SunFlower")
	{
		return SunFlower;
	}
	else if (itemnamestring == "WallNut")
	{
		return WallNut;
	}
	else if (itemnamestring == "BucketHeadZombie")
	{
		return BucketHeadZombie;
	}
	else if (itemnamestring == "PoleVaultingZombie")
	{
		return PoleVaultingZombie;
	}
	else if (itemnamestring == "CherryBomb")
	{
		return CherryBomb;
	}
	return Nosuchobject;
}

QString QGameNetFightMode::itemObjectnamestoString(objectNames itemobjectname)
{
	switch (itemobjectname)
	{
	case PeaShooter:
	{
		return "PeaShooter";
	}
		break;
	case CommonZombie:
	{
		return "CommonZombie";
	}
		break;
	case SunFlower: 
	{
		return "SunFlower";
	}
		break;
	case WallNut: 
	{
		return "WallNut";
	}
		break;
	case BucketHeadZombie:
	{
		return "BucketHeadZombie";
	}
		break;
	case PoleVaultingZombie:
	{
		return "PoleVaultingZombie";
	}
		break;
	case CherryBomb:
	{
		return "CherryBomb";
	}
	break;
	default:
		break;
	}
	return Nosuchobject;
}