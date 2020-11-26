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

    if (type_ == BussStop) {
        image.load(nysseStop);
        image = image.scaled(10, 10);
        setPixmap(image);
    }



    else if (type_ == Nysse) {

        image.load(bussi);
        image = image.scaled(15, 15);
        setPixmap(image);

    }

    else if (type_ == passenger){

        image.load(human);
        image = image.scaled(30, 30);
        setPixmap(image);
    }
    
    else {
        image = image.scaled(70, 50);
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
