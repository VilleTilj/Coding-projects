#include "gameengine.hh"
#include "ui_mainwindow.h"
#include <memory>
#include <QImage>
#include <QDebug>
#include <QObject>
#include <QPushButton>


namespace StudentSide {

GameEngine::GameEngine() :
    ui(new StudentSide::Mainwindow),
    logic_(new CourseSide::Logic),
    iCityPtr(nullptr),
    stats (new StudentSide::Statistics)
{
    gameWindow();
    connect(&timer, &QTimer::timeout, this, &GameEngine::advance);
    connect(ui->getStartButton(), &QPushButton::clicked, this, &GameEngine::initLogic);
    connect(ui->getStartAction(), &QAction::triggered, this, &GameEngine::initLogic);
}

void GameEngine::advance()
{
    if(ui->gameEnded()){
        timer.stop();
        ui->destroyPlayer();
        cityPtr_->GameOver();
    }

    else if (ui->isNuked() == true) {
        ui->stopGameTimer();
        ui->getPeopleLabel()->setText("People killed:");
        cityPtr_->nukeCity();
        cityPtr_->GameOver();
        QPixmap image;
        assert(image.load(FALLOUT));
        image = image.scaled(SCREEN_WIDTH , SCREEN_HEIGHT);
        ui->setBackground(image);
        timer.stop();
        ui->destroyPlayer();

    }


    if (stats->giveCurrentPoints() > THRESHOLD_FOR_NUKE && nukeAdded == false) {
        cityPtr_->addNuke();
        nukeAdded = true;
    }

    graphicPlayer_->setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    graphicPlayer_->setFocus();
    updateScreen();
    graphicPlayer_->giveLocation();
    std::vector<std::shared_ptr<Interface::IActor>> actor = cityPtr_->getNearbyActors(graphicPlayer_->giveLocation());
    for(unsigned long int i = 0; i < actor.size(); i++){
        cityPtr_->removeActorsNearby(actor.at(i));
    }
}

void GameEngine::updateScreen()
{
    std::vector<std::shared_ptr<Interface::IActor>> actors = cityPtr_->giveMovedActors();
    std::vector<std::shared_ptr<Interface::IActor>> passengers = cityPtr_->giveNewPassengers();
    for(unsigned long int i = 0; i < actors.size(); i++) {
        Interface::Location location = actors.at(i)->giveLocation();
        ui->moveActor(actors.at(i), location.giveX(), location.giveY());
    }

    for(unsigned long int i = 0; i < passengers.size(); i++) {
        ui->addActor(passengers.at(i));
    }

    if(passengers.size() > EMPTY_VECTOR) {
    stats->morePassengers(passengers.size());
        stats->morePassengers(passengers.size());
    }
}


void GameEngine::initLogic()
{
    cityPtr_->addUi(ui);
    cityPtr_->takeStats(stats);
    ui->takeStats(stats);
    cityPtr_->startGame();
    logic_->takeCity(cityPtr_);
    logic_->fileConfig();
    cityPtr_->makePlayer();
    graphicPlayer_ = ui->returnPlayer();
    logic_->finalizeGameStart();
    timer.start(TICK);
}


void GameEngine::gameWindow()
{
    //draw ui for user
    ui->show();

    std::shared_ptr<Interface::ICity> iCityPtr = Interface::createGame();
    //get graphics for the map and the to city
    QImage big;
    QImage small;
    QPixmap map;
    if(!big.load(bigMap) or !small.load(smallMap) or !map.load(bigMap)){
        throw Interface::InitError("Setting the picture was unsuccesful or the picture was invalid.");
    }
    big.load(bigMap);
    small.load(smallMap);
    map.load(bigMap);
    cityPtr_ = std::dynamic_pointer_cast<StudentSide::City>(iCityPtr);
    //this part is just for removing error messages
    cityPtr_->setBackground(small, big);
    //set ui background as pixmap
    ui->setBackground(map);
}

} //namespace
