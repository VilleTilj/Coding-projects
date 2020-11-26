#ifndef ACTORITEM_HH
#define ACTORITEM_HH

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPainter>


const QString nysseStop = ":/../pics/pics/NysseStop.png";
const QString bussi = "://../pics/pics/bussi.png";
const QString human = "://../pics/pics/huma.png";



namespace StudentSide {

class ActorItem : public QGraphicsPixmapItem
{

public:
    ActorItem();

    ActorItem(int x, int y, int type = 0);
    ~ActorItem();

    void setCoord(int x, int y);

private:
    int x_;
    int y_;
    int type_;

    const int BussStop = 0;
    const int Nysse = 1;
    const int passenger = 2;

    const int WIDTH = 9;
    const int HEIGHT = 9;
    QPixmap image;
};
}
#endif // ACTORITEM_HH
