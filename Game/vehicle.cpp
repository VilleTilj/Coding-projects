#include "vehicle.hh"

namespace StudentSide {


Vehicle::Vehicle()
{

}

StudentSide::Vehicle::~Vehicle()
{

}

std::string Vehicle::getName() const
{
    std::string ryys = "ryys";
    return ryys;
}

std::vector<std::shared_ptr<Interface::IPassenger> > Vehicle::getPassengers() const
{
    std::vector<std::shared_ptr<Interface::IPassenger>> Vehicle;
    return  Vehicle;
    ;}

void Vehicle::addPassenger(std::shared_ptr<Interface::IPassenger> passenger)
{
    return;
}

void Vehicle::removePassenger(std::shared_ptr<Interface::IPassenger> passenger)
{
    return;
}

}
