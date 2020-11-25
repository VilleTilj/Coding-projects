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

    //return locations_;
}

void Actor::move(Interface::Location loc)
{
    locations_ = loc;
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
