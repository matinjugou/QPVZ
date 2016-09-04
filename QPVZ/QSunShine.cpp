#include "QMySunShine.h"

QMySunShine::QMySunShine(QGameMode *parent)
	:QMyObject(parent)
{
	myGif.setFileName("Resources/pvz-material/images/interface/Sun.gif");
	myGif.jumpToFrame(0);
	connect(&myGif, SIGNAL(frameChanged(int)), this, SLOT(setnewPixmap()));
	myGif.start();

	beTaken = false;
	currentTime = 0;
	TimerID = startTimer(20);
	Scaleanimation = new QPropertyAnimation(this, "scale");
	setOpacity(0.9);
}

QMySunShine::~QMySunShine()
{

}

//public slot
void QMySunShine::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	beTaken = true;
	killTimer(TimerID);
	TimerID = startTimer(20);
	currentTime = 0;
	moveTo(240, 15, 700);
	SetScaleAnimation(1, 0.5, 700);
}

void QMySunShine::timerEvent(QTimerEvent *event)
{
	currentTime++;
	if (!beTaken)
	{
		if (currentTime == 700)
		{
			killTimer(TimerID);
			delete this;
		}
	}
	else
	{
		if (currentTime == 35)
		{
			emit BeTaken();
		}
		if (currentTime == 45)
		{
			killTimer(TimerID);
			delete this;
		}
	}
}

void QMySunShine::SetScaleAnimation(qreal fromScale, qreal toScale, int duration)
{
	Scaleanimation->setDuration(duration);
	Scaleanimation->setStartValue(fromScale);
	Scaleanimation->setEndValue(toScale);
	Scaleanimation->setEasingCurve(QEasingCurve::InOutCubic);
	Scaleanimation->start();
}