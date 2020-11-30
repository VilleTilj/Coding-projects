#ifndef ACTORITEM_HH
#define ACTORITEM_HH


#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPainter>


const QString NYSSE_STOP = ":/../pics/pics/NysseStop.png"; //!< Pic of stopsign
const QString BUSSI = "://../pics/pics/bussi.png"; //!< pic of buss
const QString HUMAN = "://../pics/pics/huma.png"; //!< pic of passenger
const int DIM_STOP = 10;
const int DIM_BUSS = 15;
const int DIM_PASSENGER = 30;
const int BUSS_STOP = 0;
const int NYSSE = 1;
const int PASSENGER = 2;
const int WIDTH = 9;
const int HEIGHT = 9;
const int WIDTHMAP = 1100;
const int HEIGHTMAP = 590;

/*!
 * \brief namespace StudenSide, Students own imlplementations to project
 */
namespace StudentSide {

/*!
 * \file actoritem.hh
 * \brief The ActorItem class sets actor images for buss, stop and passenger
 */
class ActorItem : public QGraphicsPixmapItem
{
public:

    /*!
     * \brief ActorItem constructor that sets the pictures for actors
     * \param x x-coordinate
     * \param y y-coordinate
     * \param type actor type
     * \pre coordinates must be in range of map coordinates.
     * \post Exception guaranteed: nothrow
     */
    ActorItem(int x, int y, int type = 0);

    /*!
     * \brief Destructor
     * \post Exception guaranteed: nothrow
     */
    ~ActorItem();

    /*!
     * \brief setCoord sets the actorItems position to the gameboard
     * \param x x-coordination
     * \param y y-coordination
     * \pre -
     * \post Exception guaranteed: minimum
     */
    void setCoord(int x, int y);

private:
    int x_;     //!< x-coordinate for the actor
    int y_;     //!< y-coordinate for the actor
    int type_;  //!< type for the actor
    QPixmap image;          //!< image for actor
};

} // namespace
#endif // ACTORITEM_HH
