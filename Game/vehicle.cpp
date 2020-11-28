
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
    std::string name = "Vehicle";
    return name;
}


std::vector<std::shared_ptr<Interface::IPassenger> > Vehicle::getPassengers() const
{
    std::vector<std::shared_ptr<Interface::IPassenger>> Vehicle;
    return  Vehicle;
}


void Vehicle::addPassenger(std::shared_ptr<Interface::IPassenger> passenger)
{
    qDebug() << passenger->isInVehicle();
    return;
}


void Vehicle::removePassenger(std::shared_ptr<Interface::IPassenger> passenger)
{
    qDebug() << passenger->isRemoved();
    return;
}

} // namespace
