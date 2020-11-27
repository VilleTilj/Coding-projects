#include "creategame.hh"
#include "city.hh"
#include "QImage"
#include <memory>


std::shared_ptr<Interface::ICity> Interface::createGame()
{
    std::shared_ptr<StudentSide::City> city = std::make_shared<StudentSide::City>(StudentSide::City());
    return city;
}
