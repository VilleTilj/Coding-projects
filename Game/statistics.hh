#ifndef STATISTICS_HH
#define STATISTICS_HH

#include "interfaces/istatistics.hh"
#include "interfaces/iactor.hh"
#include "interfaces/ipassenger.hh"
#include "interfaces/ivehicle.hh"

#include <memory>
#include <QMetaType>

const int POINTS_FROM_PASSENGER = 10;
const int POINTS_FROM_NYSSE = 20;


/*!
 * \brief namespace StudenSide, Students own imlplementations to project
 */
namespace StudentSide {

/*!
 * \file statistics.hh
 * \brief The Statistics class
 */
class Statistics : public Interface::IStatistics
{
public:

    /*!
     * \brief Statistics contructor
     */
    Statistics();

    /*!
     * \brief Destructor
     */
    ~Statistics();

    /*!
     * \brief Notifies for the player if new passengers have been added to the game
     * \param num Number of passengers in the map
     * \pre num must be positive value above zero
     * \post Exception guaranteed: nothrow
     */
    void morePassengers(int num) override;

    /*!
     * \brief Notifies for the player if nysse has been removed
     * \pre -
     * \post Exception guaranteed: nothrow
     */
    void nysseRemoved() override;

    /*!
     * \brief Notifies for the player if new nysse is added to the game
     * \pre -
     * \post Exception guaranteed: nothrow
     */
    void newNysse() override;

    /*!
     * \brief Notifies for the player if nysse has left the game area
     * \pre -
     * \post Exception guaranteed: nothrow
     */
    void nysseLeft() override;

    /*!
     * \brief adds points according to which actor has been removed
     * \param actor Sharedpointer to Interface of Actor
     * \pre actor is not nullptr
     * \post Exception guaranteed: nothrow
     */
    void Addpoints(std::shared_ptr<Interface::IActor> actor);

    /*!
     * \brief gives the current points to the mainwindow
     * \return amount of points saved in variable points
     * \pre -
     * \post Exception guaranteed: basic
     */
    int giveCurrentPoints();

    /*!
     * \brief gives the amount of passengers removed by the player
     * \return the amount of passengers saved in passengers
     * \pre -
     * \post Exception guaranteed: basic
     */
    int givePassengers();

    /*!
     * \brief gives the amount of nysses removed by the player
     * \return the amount of passengers saved in nysses
     * \pre -
     * \post Exception guaranteed: basic
     */
    int giveNysses();


private:

    int points = 0; //!< the amount of points acquired
    int passengers = 0; //!< the amount of passengers destroied
    int nysses = 0; //!< the amount of nysses destroied
};

} //namespace
#endif // STATISTICS_HH
