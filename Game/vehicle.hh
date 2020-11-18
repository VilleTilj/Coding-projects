#ifndef VEHICLE_HH
#define VEHICLE_HH
#include "interfaces/ivehicle.hh"
#include "interfaces/ipassenger.hh"

namespace StudentSide {


class Vehicle : public Interface::IVehicle
{
public:
    Vehicle();

    ~Vehicle();

    std::string getName() const;

    std::vector<std::shared_ptr<Interface::IPassenger> > getPassengers() const;

    void addPassenger(std::shared_ptr<Interface::IPassenger> passenger);

    void removePassenger(std::shared_ptr<Interface::IPassenger> passenger);
};

} //namespace


#endif // VEHICLE_HH
