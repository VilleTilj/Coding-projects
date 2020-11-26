#include "playeractor.hh"
#include <QDebug>
#include <QImage>
#include <QPixmap>
#include <assert.h>


namespace StudentSide {

playerActor::playerActor(Interface::Location location):x_(location.giveX()), y_(location.giveY()), location_(location)
{
    setPos(mapToParent(x_, y_ ));

    image.load(TIMO);
    image = image.scaled(70, 50);
    setPixmap(image);
}

void playerActor::changePosition(int x, int y)
{
    setX( x );
    setY( y );
    location_.setXY(x,y);
}

void playerActor::keyPressEvent(QKeyEvent *event)
{

    if( event->key() == Qt::Key_W && y_ > UP_BORDER)
    {
        y_ = y_ - MOVE_UP;
        changePosition(x_, y_ );
    }

    else if( event->key() == Qt::Key_A && x_ > LEFT_BORDER)
    {

        x_ = x_ - MOVE_LEFT;
        changePosition(x_, y_ );
    }

    else if( event->key() == Qt::Key_S && y_ < DOWN_BORDER)
    {

        y_ = y_ + MOVE_DOWN;
        changePosition(x_, y_ );
    }

    else if( event->key() == Qt::Key_D && x_ < RIGHT_BORDER)
    {

        x_ = x_ + MOVE_UP;
        changePosition(x_, y_ );
    }

}

Interface::Location playerActor::giveLocation()
{
    return location_;
}

}
