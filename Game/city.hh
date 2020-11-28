#ifndef CITY_HH
#define CITY_HH

#include "interfaces/icity.hh"
#include <QTime>
#include <algorithm>
#include "mainwindow.hh"
#include "actor.hh"
#include "vehicle.hh"
#include "actor.hh"

/*!
 * \file city.hh
 * \brief Defines city operations for game that has been inherited from iCity
 */


namespace StudentSide
{

/*!
 * \brief The City class that defines city operations
 */
class City : public Interface::ICity
{
public:

    /*!
     * \brief City constructor
     */
    City();

    /*!
     * \brief Destructor
     */
    ~City();

    /*!
     * \brief setBackground sets the map picture to game board.
     * \param basicbackground Normal sised map.
     * \param bigbackground Big sized map. Used if doing scrolling map-expansion.
     */
    void setBackground(QImage& basicbackground, QImage& bigbackground);

    /*!
     * \brief setClock sets the time of a game clock.
     * \param clock Game clock time at the function call.
     */
    void setClock(QTime clock);


    /*!
     * \brief addStop adds a stop to the city.
     * \param stop pointer to a stop object.
     */
    void addStop(std::shared_ptr<Interface::IStop> stop);

    /*!
     * \brief startGame changes game state to gamestate from initstate.
     */
    void startGame();

    /*!
     * \brief addActor adds a new actor to the city.
     * \param newactor actor to be added to the city.
     */
    void addActor(std::shared_ptr<Interface::IActor> newactor);

    /*!
     * \brief removeActor removes the actor from the city.
     * \param actor Actor to be removed.
     */
    void removeActor(std::shared_ptr<Interface::IActor> actor);

    /*!
     * \brief actorRemoved tells the city that actor is removed.
     * \param actor Actor that is set removed ingame.
     */
    void actorRemoved(std::shared_ptr<Interface::IActor> actor);

    /*!
     * \brief findActor try to find if actor can be found in the city.
     * \param actor Actor that is looked from city.
     * \return Boolean value that tells if actor can be found.
     */
    bool findActor(std::shared_ptr<Interface::IActor> actor) const;

    /*!
     * \brief getNearbyActors returns vector containing actors that are close to given position.
     * \param loc Location for getting the actors close to it.
     * \return Vector of actors.
     */
    std::vector<std::shared_ptr<Interface::IActor> > getNearbyActors(Interface::Location loc) const;

    /*!
     * \brief actorMoved tells if actor is being moved
     * \param actor Actor that has moved.
     */
    void actorMoved(std::shared_ptr<Interface::IActor> actor);

    /*!
     * \brief isGameOver tells if game ends.
     * \return  Boolean value if game is over.
     */
    bool isGameOver() const;

    /*!
     * \brief getImage returns the image depending on wanted size.
     * \param image_size Size of the wanted image used.
     * \return returns wanted image of map.
     */
    QImage getImage(std::string image_size);

    /*!
     * \brief addUi adds mainwindows userinterface to city.
     * \param ui Userinterface.
     */
    void addUi(std::shared_ptr<StudentSide::Mainwindow> ui);

    /*!
     * \brief makePlayer creates player and adds it to userinterface.
     */
    void makePlayer();

    /*!
     * \brief giveMovedActors returns vector containing moved actors.
     * \return vector containing pointer to actors.
     */
    std::vector<std::shared_ptr<Interface::IActor>> giveMovedActors();
private:
    QImage small_;  //!< Small map image
    QImage big_;    //!<  Big map image
    std::vector<std::shared_ptr<Interface::IActor>> actors_;     //!< Vector containing actors in game
    std::vector<std::shared_ptr<Interface::IActor>> moved_actor; //!< Vector containing moved actors
    std::vector<std::shared_ptr<Interface::IStop>> stops_;       //!< Vector containing acotrs
    std::shared_ptr<StudentSide::Mainwindow> ui_;   //!< Pointer to userinterface
    QTime time_;         //!< Time for game and actors
    std::shared_ptr<StudentSide::Actor> player_ ;   //!< Pointer to player.
};
} //namespace


#endif // CITY_HH
