#ifndef INITGAMEENGINE_HH
#define INITGAMEENGINE_HH

#include "dialoggamesettings.hh"
#include "graphics/simplemainwindow.hh"

namespace StudentSide {

class InitGameEngine
{
public:
    InitGameEngine();

    void gameSetting();
    void gameWindow();

private:

    QMainWindow* ui_;
};


} //namespace
#endif // INITGAMEENGINE_HH
