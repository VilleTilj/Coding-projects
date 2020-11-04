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


/*!
 * \brief The InitGameEngine class is for setting the game up. It launches
 * dialog window for settings and initializes gamewindow.
 */

class InitGameEngine
{
public:

    /*!
     * \brief Constructor that initializes game settings and runs mainwindow.
     */

    InitGameEngine();

    /*!
     * \brief
     */
    void gameSetting();

    /*!
     * \brief
     */
    void gameWindow();

private:
    std::shared_ptr<StudentSide::mainwindow> ui_;
    std::shared_ptr<CourseSide::Logic> logic_;
    std::shared_ptr<Interface::ICity> iCityPtr;
};


} //namespace
#endif // INITGAMEENGINE_HH
