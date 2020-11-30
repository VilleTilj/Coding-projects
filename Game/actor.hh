#ifndef ACTOR_HH
#define ACTOR_HH
#include "interfaces/iactor.hh"
#include "core/location.hh"
#include "errors/gameerror.hh"
#include <memory>


/*!
 * \brief namespace StudenSide, Students own imlplementations to project
 */

const int MAX_X = 1100;
const int MAX_Y = 590;
const int POLE = 0;


namespace StudentSide {

/*!
 * @file actor.hh
 * @brief The Actor class to give actors properties
 */

class Actor : public Interface::IActor
{
public:

    /*!
     * \brief Constructor for Actors
     * \pre -
     */
    Actor();

    /*!
    * \brief Destructor
    * \pre -
    **/
    ~Actor();

    /*!
     * \brief giveLocation method gives location from Interface
     * \pre -
     * \post Exception guarantee: Strong
     * \return location of actor
     */
    Interface::Location giveLocation() const override;

    /*!
     * \brief move the actor to wanted location
     * \param loc, location of the actor
     * \pre loc.x > 0, loc.y > 0, loc.x < 1100, loc.y < 590
     * \post Exception guarantee: Strong
     */
    void move(Interface::Location loc) override;

    /*!
     * \brief isRemoved checks if actor has been removed
     * \return boolean value of if actor is removed
     * \pre -
     * \post Exception guarantee: Basic
     */
    bool isRemoved() const override;

    /*!
     * \brief remove actor
     * \pre -
     * \post Exception guarantee: nothrow
     */
    void remove() override;

    /*!
     * \brief addLocation to actor
     * \param location of a actor
     * \pre -
     * \post Exception guarantee: Minimum
     */
    void addLocation(Interface::Location* location);

private:
    Interface::Location *location_ = nullptr; //!< location of actor
    bool removed = false; //!< boolean value of if actor exists.

};

} //namespace


#endif // ACTOR_HH
