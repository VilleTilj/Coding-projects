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
    Interface::Location location;
    return location;
}

void Actor::move(Interface::Location loc)
{
    return;
}

bool Actor::isRemoved() const
{
    return false;
}

void Actor::remove()
{
    return;
}
}
