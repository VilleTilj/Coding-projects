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
    if(loc.giveX() > 0 && loc.giveX() < 1100 && loc.giveY() > 0 && loc.giveY() < 590) {
        throw Interface::GameError("Location is not possible.");
        //err->giveMessage();
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
