#include "actor.hh"

namespace StudentSide
{


Actor::Actor()
{

}

StudentSide::Actor::~Actor()
{

}

Interface::Location Actor::giveLocation() const
{

    return location_;
}

void Actor::move(Interface::Location loc)
{
    location_ = loc;
}

bool Actor::isRemoved() const
{
    return false;
}

void Actor::remove()
{
    return;
}

void Actor::addLocation(Interface::Location location)
{
    location_ = location;
}

}
