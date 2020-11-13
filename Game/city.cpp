#include "city.hh"
#include <QDebug>
#include <vector>

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
    time_ = clock;
}

void City::addStop(std::shared_ptr<Interface::IStop> stop)
{

    if(std::find(stops_.begin(), stops_.end(), stop) == stops_.end()){
        stops_.push_back(stop);
        Interface::Location location = stop->getLocation();
        location.printBoth();
        ui_->addActor(location.giveX(), location.giveY(), 0);
    }
}

void City::startGame()
{
    return;
}

void City::addActor(std::shared_ptr<Interface::IActor> newactor)
{
    if(std::find(actors_.begin(), actors_.end(), newactor) == actors_.end()){
        actors_.push_back(newactor);
        Interface::Location location = newactor->giveLocation();
        location.printBoth();
        ui_->addActor(location.giveX(), location.giveY(), 0);
    }
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

void City::addUi(std::shared_ptr<mainwindow> ui)
{
    ui_ = ui;
}


}
