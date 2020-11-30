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



namespace StudentSide {

class Statistics : public Interface::IStatistics
{
public:

    Statistics();

    ~Statistics();


    /*!
     * \brief Notifies for the player if new passengers have been added to the game
     */

    void morePassengers(int num) override;

    /*!
     * \brief Notifies for the player if nysse has been removed
     */

    void nysseRemoved() override;

    /*!
     * \brief Notifies for the player if new nysse is added to the game
     */

    void newNysse() override;

    /*!
     * \brief Notifies for the player if nysse has left the game area
     */

    void nysseLeft() override;

    /*!
     * \brief adds points according to which actor has been removed
     * \pre actor is not nullptr
     */

    void Addpoints(std::shared_ptr<Interface::IActor> actor);

    /*!
     * \brief gives the current points to the mainwindow
     * \return amount of points saved in variable points
     */

    int giveCurrentPoints();

    /*!
     * \brief gives the amount of passengers removed by the player
     * \return the amount of passengers saved in passengers
     */

    int givePassengers();

    /*!
     * \brief gives the amount of nysses removed by the player
     * \return the amount of passengers saved in nysses
     */

    int giveNysses();


private:

    int points = 0; //!< the amount of points acquired
    int passengers = 0; //!< the amount of passengers destroied
    int nysses = 0; //!< the amount of nysses destroied
};

} //namespace
#endif // STATISTICS_HH
