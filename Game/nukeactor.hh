#ifndef NUKEACTOR_HH
#define NUKEACTOR_HH
#include <QGraphicsPixmapItem>
#include "core/location.hh"

const QString NUKE = "://../pics/pics/nuke.png";
const int NUKE_WIDTH = 30;
const int NUKE_HEIGHT = 20;

/*!
 * \brief namespace StudenSide, Students own imlplementations to project
 */
namespace StudentSide {


/*!
 * \brief The NukeActor class
 */
class NukeActor : public QGraphicsPixmapItem
{
public:
    /*!
     * \brief NukeActor gets nukeactor to the map
     * \param location Location to draw the nuke actor
     * \pre Location must be inside map coordinates
     * \post Exception guaranteed: nothrow
     */
    NukeActor(Interface::Location location);

    /*!
     * \brief Destructor
     */
    ~NukeActor();



private:
    int x_;     //!< x-coordinate of player
    int y_;     //!< y-coordinate of player

    QPixmap image;  //!< Image of player

    Interface::Location location_; //!< Location of player
};
}

#endif // NUKEACTOR_HH
