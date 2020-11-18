#ifndef ACTORITEM_HH
#define ACTORITEM_HH

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>


const QString nysseStop = ":/../pics/pics/NysseStop.png";
const QString bussi = "://../pics/pics/bussi.png";

namespace StudentSide {

class ActorItem : public QGraphicsItem
{

public:
    ActorItem();

    ActorItem(int x, int y, int type = 0);
    ~ActorItem();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setCoord(int x, int y);

private:
    int x_;
    int y_;
    int type_;

    const int BussStop = 0;
    const int Nysse = 1;
    const int passenger = 2;

    const int WIDTH = 5;
    const int HEIGHT = 5;

};
}
#endif // ACTORITEM_HH
