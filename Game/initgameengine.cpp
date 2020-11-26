#include "initgameengine.hh"
#include <memory>
#include <QImage>
#include <QDebug>

namespace StudentSide {

InitGameEngine::InitGameEngine() :
    ui_(new StudentSide::mainwindow),
    logic_(new CourseSide::Logic),
    iCityPtr(nullptr)
    //cityPtr_(nullptr)
    

{
    gameWindow();
        
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
    map.load(bigMap);
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
    logic_->finalizeGameStart();
    cityPtr_->makePlayer();
}

} //namespace
