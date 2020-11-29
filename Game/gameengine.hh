#ifndef INITGAMEENGINE_HH
#define INITGAMEENGINE_HH

#include "dialoggamesettings.hh"
#include "creategame.hh"
#include "city.hh"
#include "../Course/CourseLib/core/logic.hh"
#include <QImage>
#include "playeractor.hh"
#include "QTime"
#include "core/location.hh"
#include "statistics.hh"
#include "errors/initerror.hh"

const QString bigMap = ":/offlinedata/offlinedata/kartta_iso_1095x592.png";
const QString smallMap = ":/offlinedata/offlinedata/kartta_pieni_500x500.png";
const QString FALLOUT = "://../pics/pics/fallout.png";

namespace StudentSide {

/*!
 * \brief The InitGameEngine class is for setting the game up. It launches
 * dialog window for settings and initializes gamewindow.
 */
class GameEngine : public QObject
{
    Q_OBJECT
public:

    /*!
     * \brief Constructor that initializes game settings and runs mainwindow.
     */
    GameEngine();

private slots:

    /*!
     * \brief advance moves player and removes passengers who carry buss that are close to player.
     */
    void advance();

    void updateScreen();

    /*!
     * \brief initLogic initializes game logic and finalizes game starting state.
     */
    void initLogic();


private:
    std::shared_ptr<StudentSide::Mainwindow> ui;    //!< Mainwindows userinterface
    std::shared_ptr<CourseSide::Logic> logic_;      //!< Pointer to game logic
    std::shared_ptr<StudentSide::Statistics> stats; //!< pointer to statistics
    std::shared_ptr<Interface::ICity> iCityPtr;     //!< Pointer to city interface
    std::shared_ptr<StudentSide::City> cityPtr_;    //!< Pointer to city
    StudentSide::playerActor* graphicPlayer_;       //!< Player
    QTimer timer;   //!< Timer


    /*!
     * \brief gameWindow draws game window and sets map to it.
     */
    void gameWindow();
};


} //namespace
#endif // INITGAMEENGINE_HH
