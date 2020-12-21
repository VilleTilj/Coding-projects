
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
    return name;
}


std::vector<std::shared_ptr<Interface::IPassenger> > Vehicle::getPassengers() const
{
    return passengers;
}


void Vehicle::addPassenger(std::shared_ptr<Interface::IPassenger> passenger)
{
    Q_ASSERT(passenger != nullptr);
    passengers.push_back(passenger);
}


void Vehicle::removePassenger(std::shared_ptr<Interface::IPassenger> passenger)
{
    Q_ASSERT(passenger != nullptr);
    if(std::find(passengers.begin(), passengers.end(), passenger) != passengers.end()) {
        throw Interface::GameError("Passenger is not in the vehicle.");
    }
    else {
        passengers.erase(std::remove(passengers.begin(), passengers.end(), passenger), passengers.end());
    }
}

} // namespace
