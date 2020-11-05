#ifndef INITGAMEENGINE_HH
#define INITGAMEENGINE_HH

#include "dialoggamesettings.hh"
#include "graphics/simplemainwindow.hh"
#include "creategame.hh"
#include "city.hh"
#include "../Course/CourseLib/core/logic.hh"
#include <QImage>

const QString bigMap = ":/offlinedata/offlinedata/kartta_iso_1095x592.png";
const QString smallMap = ":/offlinedata/offlinedata/kartta_pieni_500x500.png";

namespace StudentSide {

class InitGameEngine
{
public:
    InitGameEngine();

    void gameSetting();
    void gameWindow();


private:
    std::shared_ptr<StudentSide::mainwindow> ui_;
    std::shared_ptr<CourseSide::Logic> logic_;
    std::shared_ptr<Interface::ICity> iCityPtr;
    //std::shared_ptr<StudentSide::City> cityPtr_;
};


} //namespace
#endif // INITGAMEENGINE_HH
