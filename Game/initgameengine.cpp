#include "initgameengine.hh"

namespace StudentSide {

InitGameEngine::InitGameEngine()
{
    DialogGameSettings *myDialog = new DialogGameSettings();
    myDialog->exec();
}
} //namespace
