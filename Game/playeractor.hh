#ifndef PLAYERACTOR_HH
#define PLAYERACTOR_HH
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "core/location.hh"


const QString TIMO = "://../pics/pics/timoTaxi.png";

namespace StudentSide {



class playerActor : public QGraphicsPixmapItem
{
public:
    playerActor();

    playerActor(Interface::Location location);

    void changePosition(int x, int y);

    void keyPressEvent(QKeyEvent* event) override;

    Interface::Location giveLocation();


private:
    int x_;
    int y_;

    QPixmap image;

    const int MOVE_RIGHT = 10;
    const int MOVE_LEFT = 10;
    const int MOVE_UP = 10;
    const int MOVE_DOWN = 10;

    const int UP_BORDER = -10;
    const int DOWN_BORDER = 520;
    const int LEFT_BORDER = -10;
    const int RIGHT_BORDER = 1020;
    Interface::Location location_;

};
}
#endif // PLAYERACTOR_HH
