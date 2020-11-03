#include "initgameengine.hh"



namespace StudentSide {

InitGameEngine::InitGameEngine() :
    ui_(new StudentSide::mainwindow),
    logic_(new CourseSide::Logic),
    iCityPtr(nullptr)
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
    //logic_->takeCity(iCityPtr);
    //logic_->fileConfig();
    ui_->show();
    

}



} //namespace
