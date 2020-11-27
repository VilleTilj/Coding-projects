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
        image = image.scaled(DIM_STOP, DIM_STOP);
        setPixmap(image);
    }



    else if (type_ == NYSSE) {

        image.load(BUSSI);
        image = image.scaled(DIM_BUSS, DIM_BUSS);
        setPixmap(image);

    }

    else if (type_ == PASSENGER){

        image.load(HUMAN);
        image = image.scaled(DIM_PASSENGER, DIM_PASSENGER);
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
