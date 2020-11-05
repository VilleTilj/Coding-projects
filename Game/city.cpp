#include "city.hh"
#include <QDebug>

namespace StudentSide
{
//moist
City::City()
{

}

City::~City()
{

}

void City::setBackground(QImage &basicbackground, QImage &bigbackground) {
    small_ = basicbackground;
    big_ = bigbackground;

}

void City::setClock(QTime clock)
{
    return;
}

void City::addStop(std::shared_ptr<Interface::IStop> stop)
{
    return;
}

void City::startGame()
{
    return;
}

void City::addActor(std::shared_ptr<Interface::IActor> newactor)
{
    return;
}

void City::removeActor(std::shared_ptr<Interface::IActor> actor)
{
    return;
}

void City::actorRemoved(std::shared_ptr<Interface::IActor> actor)
{
    return;
}

bool City::findActor(std::shared_ptr<Interface::IActor> actor) const
{
    return false;
}

std::vector<std::shared_ptr<Interface::IActor> > City::getNearbyActors(Interface::Location loc) const
{
    std::vector<std::shared_ptr<Interface::IActor>> ryys;
    return ryys;
}

void City::actorMoved(std::shared_ptr<Interface::IActor> actor)
{
    return;
}

bool City::isGameOver() const
{
    return false;
}

QImage City::getImage(std::string image_size)
{
    if(image_size == "small") {
        return small_;
    }
    else {
        return big_;
    }
}


}
