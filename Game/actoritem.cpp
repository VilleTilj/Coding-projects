#include "actoritem.hh"
#include <QDebug>
#include <QImage>
#include <QPixmap>
#include <QDebug>
#include <assert.h>

namespace StudentSide {

ActorItem::ActorItem(int x, int y, int type):x_(x), y_(y), type_(type)
{
    setPos(mapToParent(x_, y_ ));

    if (type_ == BUSS_STOP) {
        image.load(NYSSE_STOP);
        image = image.scaled(10, 10);
        setPixmap(image);
    }



    else if (type_ == NYSSE) {

        image.load(BUSSI);
        image = image.scaled(15, 15);
        setPixmap(image);

    }

    else if (type_ == PASSENGER){

        image.load(HUMAN);
        image = image.scaled(30, 30);
        setPixmap(image);
    }
    
}

ActorItem::~ActorItem()
{

}



void ActorItem::setCoord(int x, int y)
{
    setX( x );
    setY( y );
}

} //namespace
