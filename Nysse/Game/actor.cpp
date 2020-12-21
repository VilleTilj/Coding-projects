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
    if(location_ == nullptr) {
        throw Interface::GameError("actor wasn't given a location");
    }
    else {
        return *location_;
    }
    return *location_;
}

void Actor::move(Interface::Location loc)
{
    if(loc.giveX() > POLE && loc.giveX() < MAX_X && loc.giveY() > POLE && loc.giveY() < MAX_Y) {
        throw Interface::GameError("Location is not possible.");
    }
    location_->setXY(loc.giveX(), loc.giveY());
}

bool Actor::isRemoved() const
{
    return removed;
}

void Actor::remove()
{
    removed = true;
}

void Actor::addLocation(Interface::Location *location)
{
    location_ = location;
}

} // namespace
