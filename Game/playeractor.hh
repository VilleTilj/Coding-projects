#ifndef PLAYERACTOR_HH
#define PLAYERACTOR_HH
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "core/location.hh"


const QString TIMO = "://../pics/pics/timoTaxi.png";
const int TIMO_WIDTH = 70;
const int TIMO_HEIGHT = 50;

const int MOVE_RIGHT = 10;
const int MOVE_LEFT = 10;
const int MOVE_UP = 10;
const int MOVE_DOWN = 10;

const int UP_BORDER = 0;
const int DOWN_BORDER = 590;
const int LEFT_BORDER = 0;
const int RIGHT_BORDER = 1000;

const int X_COMPP = 355;
const int Y_COMPP = 547;

namespace StudentSide {

/*!
 * \file playeractor.hh
 * \brief The playerActor class
 */

class playerActor : public QGraphicsPixmapItem
{
public:

    /*!
     * \brief playerActor constructor to set player to map
     * \param location Location to set player
     */
    playerActor(Interface::Location location);

    /*!
     * \brief changePosition changes players position
     * \param x x-coordinate
     * \param y y-coordinate
     */
    void changePosition(int x, int y);

    /*!
     * \brief keyPressEvent reads keyinputs
     * \param event from key presses
     */
    void keyPressEvent(QKeyEvent* event) override;

    /*!
     * \brief giveLocation returns location of player
     * \return location of player
     */
    Interface::Location giveLocation();



private:
    int x_;     //!< x-coordinate of player
    int y_;     //!< y-coordinate of player

    QPixmap image;  //!< Image of player

    Interface::Location location_; //!< Location of player

};

} // namespace
#endif // PLAYERACTOR_HH
