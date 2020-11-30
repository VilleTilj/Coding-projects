#include "statistics.hh"
#include <QDebug>
#include <iostream>
#include <string>

namespace StudentSide {



Statistics::Statistics()
{

}

Statistics::~Statistics()
{

}

void Statistics::morePassengers(int num)
{
    Q_ASSERT(num > 0);
    qDebug() << num << " passengers";

}

void Statistics::nysseRemoved()
{
    qDebug() << "Nysse has been removed";
}

void Statistics::newNysse()
{
    qDebug() << "Added new nysse to the game";
}

void Statistics::nysseLeft()
{
    qDebug() << "Nysse has left the game";
}

void Statistics::Addpoints(std::shared_ptr<Interface::IActor> actor)
{
    Q_ASSERT(actor != nullptr);
     if(std::shared_ptr<Interface::IPassenger> passenger = std::dynamic_pointer_cast<Interface::IPassenger>(actor)) {
         points += POINTS_FROM_PASSENGER;
         passengers += 1;
     }
     else if (std::shared_ptr<Interface::IVehicle> nysse = std::dynamic_pointer_cast<Interface::IVehicle>(actor)) {
         points += POINTS_FROM_NYSSE;
         nysses += 1;
     }
}

int Statistics::giveCurrentPoints()
{
    return points;
}

int Statistics::givePassengers()
{
    return passengers;
}

int Statistics::giveNysses()
{
    return nysses;
}

} // namespace
