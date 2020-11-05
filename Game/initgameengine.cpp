#include "initgameengine.hh"
#include <memory>
#include <QImage>


namespace StudentSide {

InitGameEngine::InitGameEngine() :
    ui_(new StudentSide::mainwindow),
    logic_(new CourseSide::Logic),
    iCityPtr(nullptr)
    //cityPtr_(nullptr)
{
    gameSetting();
    gameWindow();
}

void InitGameEngine::gameSetting()
{
    std::shared_ptr<Interface::ICity> city = Interface::createGame();
}

void InitGameEngine::gameWindow()
{
    logic_->takeCity(iCityPtr);
    logic_->fileConfig();
    ui_->show();
    std::shared_ptr<Interface::ICity> iCityPtr = Interface::createGame();
    QImage big;
    big.load(bigMap);
    QImage small;
    small.load(smallMap);

    std::shared_ptr<StudentSide::City> cityPtr_ = std::dynamic_pointer_cast<StudentSide::City>(iCityPtr);
    cityPtr_->setBackground(small, big);
    QImage ryys = cityPtr_->getImage("big");
    ui_->setBackground(ryys);



}




} //namespace
