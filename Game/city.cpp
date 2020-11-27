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
        ui_->addStop(stop);
    }
}

void City::startGame()
{
    return;
}

void City::addActor(std::shared_ptr<Interface::IActor> newactor)
{
    if(std::find(actors_.begin(), actors_.end(), newactor) == actors_.end()){
        Interface::Location location = newactor->giveLocation();
        if(location.giveX() > 0 && location.giveX() < 1200 && location.giveY() > 0 && location.giveY() < 600) {
        actors_.push_back(newactor);
        ui_->addActor(newactor);
        }
    }
}


void City::removeActor(std::shared_ptr<Interface::IActor> actor)
{
    if(std::find(actors_.begin(), actors_.end(), actor) != actors_.end()) {
        actor->remove();
        actors_.erase(std::remove(actors_.begin(), actors_.end(), actor), actors_.end());
        ui_->removeActor(actor);
    }

}

void City::actorRemoved(std::shared_ptr<Interface::IActor> actor)
{
    return;
}

bool City::findActor(std::shared_ptr<Interface::IActor> actor) const
{

    if(std::find(actors_.begin(), actors_.end(), actor) != actors_.end()){
        return true;
    }
    return false;
}

std::vector<std::shared_ptr<Interface::IActor> > City::getNearbyActors(Interface::Location loc) const
{
    std::vector<std::shared_ptr<Interface::IActor>> actorsToBedeleted;
    for(unsigned long int i = 0; i < actors_.size(); i++) {
        Interface::Location location = actors_.at(i)->giveLocation();
        //qDebug() << location.giveX(), location.giveY();
        //qDebug() << loc.giveX();
        //qDebug() << loc.giveY();
        if(location.isClose(loc, 30) == true){
            actorsToBedeleted.push_back(actors_[i]);

        }
    }
    return actorsToBedeleted;
}

void City::actorMoved(std::shared_ptr<Interface::IActor> actor)
{
    //moved_actor.push_back(actor);
    Interface::Location location = actor->giveLocation();
    ui_->moveActor(actor, location.giveX(), location.giveY());

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

void City::addUi(std::shared_ptr<StudentSide::mainwindow> ui)
{
    ui_ = ui;
}

void City::makePlayer()
{
    Interface::Location location;
    player_ = std::make_shared<StudentSide::Actor>(StudentSide::Actor());
    player_->addLocation(location);
    ui_->addPlayer(player_);


}

std::vector<std::shared_ptr<Interface::IActor> > City::giveMovedActors()
{
    std::vector<std::shared_ptr<Interface::IActor>> actors = moved_actor;
    moved_actor.clear();
    return actors;
}
}
