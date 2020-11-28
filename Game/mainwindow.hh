#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include "dialoggamesettings.hh"
#include <QMainWindow>
#include <QGraphicsScene>
#include "interfaces/iactor.hh"
#include <QTimer>
#include <iostream>
#include <memory>
#include <QVector>
#include <QPixmap>
#include <QMap>
#include "actoritem.hh"
#include "actor.hh"
#include "interfaces/ipassenger.hh"
#include "interfaces/ivehicle.hh"
#include "interfaces/istop.hh"
#include "playeractor.hh"
#include <QMenu>

const int PLAYER = 3;
const int SECOND = 1000;
const int WIDTH_MAIN = 1095;
const int HEIGHT_MAIN = 592;
const int POINTS = 100;


namespace Ui {
class MainWindow;
}

namespace StudentSide {

/*!
 * \brief The mainwindow class
 */
class Mainwindow : public QMainWindow
{
    Q_OBJECT

public:

    /*!
     * \brief mainwindow constructor to create mainwindow userinterface.
     * \param parent
     */
    explicit Mainwindow(QWidget *parent = nullptr);

    /*!
     * \brief Destructor
     */
    ~Mainwindow();

    /*!
     * \brief setBackground sets the game map to gamewindow
     * \param image Map image
     */
    void setBackground(QPixmap &image);

    /*!
     * \brief addActor adds actor to mainwindow
     * \param actor wanted actor to be added
     */
    void addActor(std::shared_ptr<Interface::IActor> actor);

    /*!
     * \brief addStop adds bus stop to mainwindow
     * \param stop Buss stop to be added
     */
    void addStop(std::shared_ptr<Interface::IStop> stop);

    /*!
     * \brief moveActor moves wanted actor in mainwindow
     * \param actor Actor to be moved
     * \param x x-coordinate
     * \param y y-coordinate
     */
    void moveActor(std::shared_ptr<Interface::IActor> actor, int x, int y);

    /*!
     * \brief removeActor removes wanted actor from mainwindow
     * \param actor Actor to be removed
     */
    void removeActor(std::shared_ptr<Interface::IActor> actor);

    /*!
     * \brief addPlayer adds player to mainwindow
     * \param player_ Player that user can move and play with
     */
    void addPlayer(std::shared_ptr<StudentSide::Actor> player_);

    /*!
     * \brief GivePlayerLocation gives player coordinates
     * \return location of player
     */
    Interface::Location GivePlayerLocation();

    /*!
     * \brief returnPlayer returns player graphics
     * \return graphics of player
     */
    StudentSide::playerActor *returnPlayer();

    /*!
     * \brief addPoints adds points to points_lcd
     */
    void addPoints();

    /*!
     * \brief getStartButton gives startButton
     * \return starButton of userinterface
     */
    QPushButton* getStartButton();

private slots:

    /*!
     * \brief normalGameSettings adjust normal gamesettings
     * \param name Players name
     * \param gameTime wanted timelimit by user
     */
    void normalGameSettings(QString name, int gameTime);

    /*!
     * \brief infiniteGameSettings adjusts game to be infinite time
     */
    void infiniteGameSettings();

    /*!
     * \brief updateTimelimit updates time to lcds in mainwindow and stops timer when needed
     */
    void updateTimelimit();

    /*!
     * \brief startGame starts game when pressing start button
     */
    void startGame();


protected:
#ifndef QT_NO_CONTEXTMENU
    void contextMenuEvent(QContextMenuEvent *event) override;
#endif // QT_NO_CONTEXTMENU

private:
    Ui::MainWindow *ui;    //!< Mainwindows userinterface
    DialogGameSettings *myDialog;
    QGraphicsScene *map;   //!< Scene of the map of game
    QString playerName_ = "Timo";   //!< Player name
    StudentSide::ActorItem* last_;  //!< last actoritem
    std::map<std::shared_ptr<Interface::IActor>, StudentSide::ActorItem *> actors_;     //!< Map containing information about actors
    QMap<std::shared_ptr<Interface::IStop>, StudentSide::ActorItem *>stops_;    //!< map containing bus stops
    std::shared_ptr<Actor> player_;     //!< Pointer to player
    StudentSide::playerActor* graphicPlayer_; //!< Graphics for player
    QTimer* timer = nullptr;    //!< timer for advance actors
    int type = 0;               //!< type of actor
    QTimer timer_;              //!< timer for countdown timelimit
    int timelimit = 0;          //!< timelimit for game
    int seconds = 0;            //!< seconds to count and show in lcds
    bool isInfiniteTime = true; //!< boolean value to check gametype
    bool secondsRunning = false;//!< Check if seconds are runnign in lcds
    int points_ = 0;            //!< Game points
    QMenu *gameMenu;
    QAction *startAct;

    /*!
     * \brief update_time_lcd updates time to min and sec lcd
     */
    void update_time_lcd();

    /*!
     * \brief connectSignals connects all signals and slots
     */
    void connectSignals();

    /*!
     * \brief setUiWidgets sets ui component to mainwindow
     */
    void setUiWidgets();

    void createActions();

    void createMenus();



};
} //namespace
#endif // MAINWINDOW_HH
