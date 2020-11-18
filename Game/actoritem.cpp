#include "actoritem.hh"
#include <QDebug>
#include <QImage>
#include <QPixmap>

namespace StudentSide {

ActorItem::ActorItem(int x, int y, int type):x_(x), y_(y), type_(type)
{
    setPos(mapToParent(x_, y_ ));
}

ActorItem::~ActorItem()
{

}

QRectF ActorItem::boundingRect() const
{
    return QRectF(0, 0, WIDTH, HEIGHT);
}

void ActorItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF bounds;
    QImage image;

    if (type_ == BussStop) {

        image.load(nysseStop);
        bounds = QRectF(0, 0, 15, 15);
    }



    else if (type_ == Nysse) {

        image.load(bussi);
        bounds = QRectF(0, 0, 10, 13);


        //QRectF bounds = boundingRect();
        //QColor color(type_%256, type_%256, type_%256);
        //QBrush brush(color);
        //painter->setBrush(brush);
        //painter->drawEllipse(bounds);
    }

    QBrush brush(image);
    painter->drawImage(bounds,image);

}

void ActorItem::setCoord(int x, int y)
{
    setX( x );
    setY( y );
}

} //namespace
