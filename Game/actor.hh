#ifndef ACTOR_HH
#define ACTOR_HH
#include "interfaces/iactor.hh"
#include "core/location.hh"

namespace StudentSide {

class Actor : public Interface::IActor
{
public:
    Actor();

    ~Actor();

    Interface::Location giveLocation() const;

    void move(Interface::Location loc);

    bool isRemoved() const;

    void remove();

    void addLocation(Interface::Location location);

private:
    Interface::Location location_;
};



} //namespace


#endif // ACTOR_HH
