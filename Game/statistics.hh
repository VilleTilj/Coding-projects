#ifndef STATISTICS_HH
#define STATISTICS_HH

#include "interfaces/istatistics.hh"
#include "interfaces/iactor.hh"
#include "interfaces/ipassenger.hh"

#include <memory>
#include <QMetaType>

const int POINTS_FROM_PASSENGER = 10;

namespace StudentSide {

class Statistics : public Interface::IStatistics
{
public:

    Statistics();

    ~Statistics();

    void morePassengers(int num) override;

    void nysseRemoved() override;

    void newNysse() override;

    void nysseLeft() override;

    void Addpoints(std::shared_ptr<Interface::IActor> actor);

    int giveCurrentPoints();


private:

    int points = 0;
};

} //namespace
#endif // STATISTICS_HH
