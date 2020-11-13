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
    DialogGameSettings *myDialog = new DialogGameSettings();
    myDialog->exec();
}

void InitGameEngine::gameWindow()
{

    ui_->show();
    std::shared_ptr<Interface::ICity> iCityPtr = Interface::createGame();
    QImage big;
    big.load(bigMap);
    QImage small;
    small.load(smallMap);
    cityPtr_ = std::dynamic_pointer_cast<StudentSide::City>(iCityPtr);
    cityPtr_->setBackground(small, big);
    QImage BigImage = cityPtr_->getImage("big");
    ui_->setBackground(BigImage);
    initLogic();


}

void InitGameEngine::initLogic()
{
    cityPtr_->addUi(ui_);
    logic_->takeCity(cityPtr_);
    logic_->fileConfig();
    logic_->finalizeGameStart();
}






} //namespace
