#ifndef ACTORITEM_HH
#define ACTORITEM_HH

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPainter>


const QString NYSSE_STOP = ":/../pics/pics/NysseStop.png";
const QString BUSSI = "://../pics/pics/bussi.png";
const QString HUMAN = "://../pics/pics/huma.png";
const int BUSS_STOP = 0;
const int NYSSE = 1;
const int PASSENGER = 2;
const int WIDTH = 9;
const int HEIGHT = 9;


namespace StudentSide {

/*!
 * \file actoritem.hh
 * \brief The ActorItem class
 */

class ActorItem : public QGraphicsPixmapItem
{
public:

    /*!
     * \brief ActorItem constructor that sets the pictures for actors
     * \param x x-coordinate
     * \param y y-coordinate
     * \param type actor type
     */
    ActorItem(int x, int y, int type = 0);

    /*!
     * \brief Destructor
     */
    ~ActorItem();

    /*!
     * \brief setCoord sets the actorItems position to the gameboard
     * \param x x-coordination
     * \param y y-coordination
     */
    void setCoord(int x, int y);

private:
    int x_;         //!< x-coordinate for the actor
    int y_;         //!< y-coordinate for the actor
    int type_;      //!< type for the actor
    QPixmap image;  //!< image for actor
};
}
#endif // ACTORITEM_HH
