#ifndef CITY_HH
#define CITY_HH

#include "interfaces/icity.hh"
#include "mainwindow.hh"
#include "actor.hh"
#include "vehicle.hh"
#include "actor.hh"
#include "statistics.hh"
#include "errors/gameerror.hh"
#include "errors/initerror.hh"
#include <QTime>
#include <QPixmap>
#include <algorithm>


/*!
 * \brief namespace StudenSide, Students own imlplementations to project
 */



const int RENDER_DISTANCE = 2000;
const int PASSENGER_RENDER_MIN = -500;
const int PASSENGER_RENDER_MAX = 1050;
const int DISTANCE_TO_INTERACT = 25;

namespace StudentSide
{

/*!
 * \file city.hh
 * \brief The City class that defines city operations
 */
class City : public Interface::ICity
{
public:

    /*!
     * \brief City constructor
     * \pre -
     * \post Exception guaranteed: nothrow
     */
    City();

    /*!
     * \brief Destructor
     * \pre -
     * \post Exception guaranteed: nothrow
     */
    ~City();

    /*!
     * \brief setBackground sets the map picture to game board.
     * \param basicbackground Normal sised map.
     * \param bigbackground Big sized map. Used if doing scrolling map-expansion.
     * \pre -
     * \post Exception guaranteed: minimum
     */
    void setBackground(QImage& basicbackground, QImage& bigbackground) override;

    /*!
     * \brief setClock sets the time of a game clock.
     * \param clock Game clock time at the function call.
     * \pre -
     * \post Exception guaranteed: nothrow
     */
    void setClock(QTime clock) override;


    /*!
     * \brief addStop adds a stop to the city.
     * \param stop pointer to a stop object.
     * \pre stop cannot be null
     * \post Exception guarannteed: Strong
     */
    void addStop(std::shared_ptr<Interface::IStop> stop) override;

    /*!
     * \brief startGame changes game state to gamestate from initstate.
     * \pre -
     * \post Exception guaranteed: nothrow
     */
    void startGame() override;

    /*!
     * \brief addActor adds a new actor to the city.
     * \param newactor actor to be added to the city.
     * \pre  newactor cannot be null
     * \post Exception guaranteed: Strong
     */
    void addActor(std::shared_ptr<Interface::IActor> newactor) override;

    /*!
     * \brief removeActor removes the actor from the city.
     * \param actor Actor to be removed.
     * \pre  actor to be removed needs to be found
     * \post Exception guaranteed: Strong
     */
    void removeActor(std::shared_ptr<Interface::IActor> actor) override;

    /*!
     * \brief actorRemoved tells the city that actor is removed.
     * \param actor Actor that is set removed ingame.
     * \pre  actor cant be null
     * \post Exception guaranteed: nothrow
     */
    void actorRemoved(std::shared_ptr<Interface::IActor> actor) override;

    /*!
     * \brief findActor try to find if actor can be found in the city.
     * \param actor Actor that is looked from city.
     * \return Boolean value that tells if actor can be found.
     * \pre  -
     * \post Exception guaranteed: nothrow
     */
    bool findActor(std::shared_ptr<Interface::IActor> actor) const override;

    /*!
     * \brief getNearbyActors returns vector containing actors that are close to given position.
     * \param loc Location for getting the actors close to it.
     * \return Vector of actors.
     * \pre  -
     * \post Exception guaranteed: nothrow
     */
    std::vector<std::shared_ptr<Interface::IActor> > getNearbyActors(Interface::Location loc) const override;

    /*!
     * \brief actorMoved tells if actor is being moved
     * \param actor Actor that has moved.
     * \pre  actor cannot be null
     * \post Exception guaranteed: nothrow
     */
    void actorMoved(std::shared_ptr<Interface::IActor> actor) override;

    /*!
     * \brief isGameOver tells if game ends.
     * \return  Boolean value if game is over.
     * \pre -
     * \post Exception guaranteed: nothrow
     */
    bool isGameOver() const override;

    /*!
     * \brief getImage returns the image depending on wanted size.
     * \param image_size Size of the wanted image used.
     * \return returns wanted image of map.
     * \pre -
     * \post Exception guaranteed: nothrow
     */
    QImage getImage(std::string image_size);

    /*!
     * \brief addUi adds mainwindows userinterface to city.
     * \param ui Userinterface.
     * \pre ui must be found
     * \post Exception guaranteed: nothrow
     */
    void addUi(std::shared_ptr<StudentSide::Mainwindow> ui);

    /*!
     * \brief makePlayer creates player and adds it to userinterface.
     * \pre -
     * \post Exception guaranteed: nothrow
     */
    void makePlayer();

    /*!
     * \brief removeActorsNearby removes passenger near player
     * \param actor pointer to interface IActor
     * \pre actor cannot be null
     * \post Exception guaranteed: nothrow
     */
    void removeActorsNearby(std::shared_ptr<Interface::IActor> actor);

    /*!
     * \brief giveMovedActors returns vector containing moved actors.
     * \return vector containing pointer to actors.
     * \pre -
     * \post Exception guaranteed: nothrow
     */
    std::vector<std::shared_ptr<Interface::IActor>> giveMovedActors();

    /*!
     * \brief giveNewPassengers
     * \return vector containing newpassenger that point to IActor
     * \pre -
     * \post Exception guaranteed: nothrow
     */
    std::vector<std::shared_ptr<Interface::IActor>> giveNewPassengers();

    /*!
     * \brief takeStats returns statistics class
     * \param stats statistics to get info
     * \pre -
     * \post Exception guaranteed: nothrow
     */
    void takeStats(std::shared_ptr<StudentSide::Statistics> stats);

    /*!
     * \brief addNuke adds nuke actor to map
     * \pre -
     * \post Exception guaranteed: nothrow
     */
    void addNuke();

    /*!
     * \brief nukeCity KABOOM
     * \pre -
     * \post Exception guaranteed: nothrow
     */
    void nukeCity();

    /*!
     * \brief GameOver gives game state gameover
     * \pre -
     * \post Exception guaranteed: nothrow
     */
    void GameOver();


private:
    QImage small_;  //!< Small map image
    QImage big_;    //!<  Big map image
    std::vector<std::shared_ptr<Interface::IActor>> actors_;     //!< Vector containing actors in game
    std::vector<std::shared_ptr<Interface::IActor>> moved_actor; //!< Vector containing moved actors
    std::vector<std::shared_ptr<Interface::IActor>> new_passengers;  //!< Vector containing busses to be added in game
    std::vector<std::shared_ptr<Interface::IStop>> stops_;       //!< Vector containing stops in game
    std::shared_ptr<StudentSide::Mainwindow> ui_;   //!< Pointer to userinterface
    QTime time_;         //!< Time for game and actors
    std::shared_ptr<StudentSide::Actor> player_ ;   //!< Pointer to player.
    std::shared_ptr<StudentSide::Actor> nuke_ ; //!< pointer to nuke
    std::shared_ptr<StudentSide::Statistics> stats_; //!< pointer to statistics class

    bool gamestarted = false;
    bool gameOver = false;
};

} //namespace

#endif // CITY_HH
