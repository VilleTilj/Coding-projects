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
    return removed;
}

void Actor::remove()
{
    removed = true;
}

void Actor::addLocation(Interface::Location location)
{
    location_ = location;
}

}
