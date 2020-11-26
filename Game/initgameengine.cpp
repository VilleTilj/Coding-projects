#include "initgameengine.hh"
#include <memory>
#include <QImage>
#include <QDebug>
#include <QObject>


namespace StudentSide {

InitGameEngine::InitGameEngine() :
    ui_(new StudentSide::mainwindow),
    logic_(new CourseSide::Logic),
    iCityPtr(nullptr)
    //cityPtr_(nullptr)


{
    gameWindow();
    timer = new QTimer;
    connect(timer, &QTimer::timeout, this, &InitGameEngine::advance);

    //timer->start(1500);
}


void InitGameEngine::gameWindow()
{
    //draw ui for user
    ui_->show();
    std::shared_ptr<Interface::ICity> iCityPtr = Interface::createGame();
    //get graphics for the map and the to city
    QImage big;
    big.load(bigMap);
    QImage small;
    small.load(smallMap);
    cityPtr_ = std::dynamic_pointer_cast<StudentSide::City>(iCityPtr);
    cityPtr_->setBackground(small, big);

    QPixmap map;
    map.load(smallMap);
    ui_->setBackground(map);
    //start game logic
    initLogic();

}

void InitGameEngine::initLogic()
{
    cityPtr_->addUi(ui_);
    logic_->takeCity(cityPtr_);
    logic_->fileConfig();
    logic_->setTime(17, 00);
    cityPtr_->makePlayer();
    graphicPlayer_ = ui_->returnPlayer();
    logic_->finalizeGameStart();

}

void InitGameEngine::advance()
{
    std::vector<std::shared_ptr<Interface::IActor>> actors = cityPtr_->giveMovedActors();
    if(actors.size() != 0){
        for(unsigned long int i = 0; i < actors.size(); i++ ) {
            ui_->moveActor(actors.at(i), actors.at(i)->giveLocation().giveX(), actors.at(i)->giveLocation().giveY());
        }
    }
}

} //namespace
