#include "initgameengine.hh"
#include "creategame.hh"


namespace StudentSide {

InitGameEngine::InitGameEngine() :
    ui_(new CourseSide::SimpleMainWindow)
{

    gameSetting();
    gameWindow();

}

void InitGameEngine::gameSetting()
{
    DialogGameSettings *myDialog = new DialogGameSettings();
    myDialog->exec();
    //std::shared_ptr<Interface::ICity> city = Interface::createGame();
}

void InitGameEngine::gameWindow()
{
    ui_->show();

}



} //namespace
