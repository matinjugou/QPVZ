#include "QGameMode.h"

QGameMode::QGameMode(QWidget* parent)
//	:QObject(parent)
{
	Scene = new QGraphicsScene;
	Scene->setSceneRect(0, 0, 900, 600);
	Scene->setItemIndexMethod(QGraphicsScene::NoIndex);
}

QGameMode::~QGameMode()
{

}

QGameMainMode::QGameMainMode(QWidget* parent)
//	:QGameMode(parent)
{
	QPixmap tempPic;

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
	
	connect(StartGame_Adventure, SIGNAL(clicked()), this, SIGNAL(AdventureMode_Start()));
	connect(StartGame_NetFight, SIGNAL(clicked()), this, SIGNAL(NetFightMode_Start()));
	connect(Options, SIGNAL(clicked()), this, SIGNAL(Setting_Options()));
	connect(Help, SIGNAL(clicked()), this, SIGNAL(Help_Start()));
	connect(Quit, SIGNAL(clicked()), this, SIGNAL(Quit_Game()));

	emit exchangetoScene(Scene);
	startTimer(20);
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