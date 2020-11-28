#ifndef STATISTICS_HH
#define STATISTICS_HH

#include "interfaces/istatistics.hh"

namespace StudentSide {

class Statistics : public Interface::IStatistics
{
public:

    Statistics();

    ~Statistics();

    void morePassengers(int num);

    void nysseRemoved();

    void newNysse();

    void nysseLeft();
};

} //namespace
#endif // STATISTICS_HH
