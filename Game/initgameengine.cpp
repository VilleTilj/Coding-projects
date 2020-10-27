#include "initgameengine.hh"

InitGameEngine::InitGameEngine()
{
    DialogGameSettings *myDialog = new DialogGameSettings();
    myDialog->exec();
}
