#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include "dialoggamesettings.hh"
#include "interfaces/ipassenger.hh"
#include "interfaces/ivehicle.hh"
#include "interfaces/istop.hh"
#include "playeractor.hh"
#include "interfaces/iactor.hh"
#include "actoritem.hh"
#include "actor.hh"
#include "statistics.hh"
#include "actors/nysse.hh"

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <iostream>
#include <memory>
#include <QVector>
#include <QPixmap>
#include <QMap>
#include <QMessageBox>
#include <QMenu>

const QString RULES = "://../datafiles/datafiles/rules.txt";
const QString ABOUT = "://../datafiles/datafiles/about.txt";
const QString SCORES = "://../scores.csv";

const int PLAYER = 3;
const int SECOND = 1000;
const int WIDTH_MAIN = 1095;
const int HEIGHT_MAIN = 592;
const int POINTS = 10;
const int X_COMP = 355;
const int Y_COMP = 547;


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
     * \brief takeStats
     * \param stats
     */
    void takeStats(std::shared_ptr<StudentSide::Statistics> stats);

    /*!
     * \brief getStartButton gives startButton
     * \return starButton of userinterface
     */
    QPushButton *getStartButton();

    /*!
     * \brief getStartAction return startaction to start the game from menubar
     * \return starAction
     */
    QAction *getStartAction();

    /*!
     * \brief gameEnded return boolean if game is ended or not
     * \return true when gane has ended, false otherwise
     */
    bool gameEnded();

    /*!
     * \brief destroyPlayer destroys the player
     */
    void destroyPlayer();

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
    void infiniteGameSettings(QString name);

    /*!
     * \brief updateTimelimit updates time to lcds in mainwindow and stops timer when needed
     */
    void updateTimelimit();

    /*!
     * \brief startGame starts game when pressing start button
     */
    void startGame();

    /*!
     * \brief restartGame restarts game with chosen settings
     */
    void restartGame();

    /*!
     * \brief changeSettings launches dialoggamesettings dialog to change settings
     */
    void changeSettings();

    /*!
     * \brief showTopScores shows top ten scores of 1min and 2 min games
     */
    void showTopScores();

    /*!
     * \brief showRules shows the game rules in popup
     */
    void showRules();

    /*!
     * \brief showAboutInfo show the aboutUs information in popup
     */
    void showAboutInfo();



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
    std::shared_ptr<StudentSide::Statistics> stats_; //:< stats class
    int type = 0;               //!< type of actor
    QTimer timer_;              //!< timer for countdown timelimit
    int timelimit = 0;          //!< timelimit for game
    int seconds = 0;            //!< seconds to count and show in lcds
    bool isInfiniteTime = true; //!< boolean value to check gametype
    bool secondsRunning = false;//!< Check if seconds are runnign in lcds
    int points_ = 0;            //!< Game points
    QString gamemode = "";

    QMenu *gameMenu;
    QMenu *aboutMenu;
    QAction *startAct;
    QAction *restartAct;
    QAction *changeSettingsAct;
    QAction *showScores;
    QAction *quitAct;
    QAction *rulesAct;
    QAction *aboutUsAct;

    /*!
     * \brief gameEnding stops game when timelimit is reached and save highscores
     *
     */
    void gameEnding();

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

    /*!
     * \brief createActions creates menu actions
     */
    void createActions();

    /*!
     * \brief createMenus creates menus to mainwindow
     */
    void createMenus();

    void readFileToMessage(QString fileName, QString title);

};
} //namespace
#endif // MAINWINDOW_HH
