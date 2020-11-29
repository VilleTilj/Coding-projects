#ifndef NUKEACTOR_HH
#define NUKEACTOR_HH
#include <QGraphicsPixmapItem>
#include "core/location.hh"

const QString NUKE = "://../pics/pics/nuke.png";
const int NUKE_WIDTH = 50;
const int NUKE_HEIGHT = 40;

namespace StudentSide {

class NukeActor : public QGraphicsPixmapItem
{
public:
    NukeActor(Interface::Location location);
    ~NukeActor();



private:
    int x_;     //!< x-coordinate of player
    int y_;     //!< y-coordinate of player

    QPixmap image;  //!< Image of player

    Interface::Location location_; //!< Location of player
};
}

#endif // NUKEACTOR_HH
