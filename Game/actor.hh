#ifndef ACTOR_HH
#define ACTOR_HH
#include "interfaces/iactor.hh"
#include "core/location.hh"

namespace StudentSide {

/*!
 * \file actor.hh
 * \brief The Actor class
 */

class Actor : public Interface::IActor
{
public:

    /*!
     * \brief Constructor for Actors
     */
    Actor();

    /*!
    * \brief Destructor
    * \pre -
    **/
    ~Actor();

    /*!
     * \brief giveLocation method gives location from Interface
     * \return location of actor
     */
    Interface::Location giveLocation() const override;

    /*!
     * \brief move the actor
     * \param loc, location of the actor
     * \pre loc >= 0
     */
    void move(Interface::Location loc) override;

    /*!
     * \brief isRemoved checks if actor has been removed
     * \return boolean value of if actor is removed
     */
    bool isRemoved() const override;

    /*!
     * \brief remove actor
     */
    void remove() override;

    /*!
     * \brief addLocation to actor
     * \param location of a actor
     */
    void addLocation(Interface::Location location);

private:
    Interface::Location location_; //!< location of actor
    bool removed = false; //!< boolean value of if actor exists.
};

} //namespace


#endif // ACTOR_HH
