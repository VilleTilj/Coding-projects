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
#include "nukeactor.hh"

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
const QString SCORES = "://../datafiles/datafiles/scores.csv";

const int PLAYER = 3;
const int SECOND = 1000;
const int WIDTH_MAIN = 1095;
const int HEIGHT_MAIN = 592;
const int POINTS = 10;
const int X_COMP = 355;
const int Y_COMP = 547;

/*!
 * \brief Ui namespace for mainwindow class
 */
namespace Ui {
class MainWindow;
}

/*!
 * \brief namespace StudenSide, Students own imlplementations to project
 */
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
     * \pre -
     * \post Exception guaranteed: nothrow
     */
    explicit Mainwindow(QWidget *parent = nullptr);

    /*!
     * \brief Destructor
     */
    ~Mainwindow();

    /*!
     * \brief setBackground sets the game map to gamewindow
     * \param image Map image
     * \pre -
     * \post Exception guaranteed: nothrow
     */
    void setBackground(QPixmap &image);

    /*!
     * \brief addActor adds actor to mainwindow
     * \param actor wanted actor to be added
     * \pre actor cant be null when addingt it
     * \post Exception guaranteed: nothrow
     */
    void addActor(std::shared_ptr<Interface::IActor> actor);

    /*!
     * \brief addStop adds bus stop to mainwindow
     * \param stop Buss stop to be added
     * \pre stop must be found
     * \post Exception guaranteed: nothrow
     */
    void addStop(std::shared_ptr<Interface::IStop> stop);

    /*!
     * \brief moveActor moves wanted actor in mainwindow
     * \param actor Actor to be moved
     * \param x x-coordinate
     * \param y y-coordinate
     * \pre actor must be found and x and y coordinates do not pass map borders
     * \post Exception guaranteed: minimum
     */
    void moveActor(std::shared_ptr<Interface::IActor> actor, int x, int y);

    /*!
     * \brief removeActor removes wanted actor from mainwindow
     * \param actor Actor to be removed
     * \pre actor must be found
     * \post Exception guaranteed: nothrow
     */
    void removeActor(std::shared_ptr<Interface::IActor> actor, bool points);

    /*!
     * \brief addPlayer adds player to mainwindow
     * \param player_ Player that user can move and play with
     * \pre player cant be null
     * \post Exception guaranteed: minimum
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
     * \pre -
     * \post Exception guaranteed: minimum
     */
    StudentSide::playerActor *returnPlayer();

    /*!
     * \brief addPoints adds points to points_lcd
     * \pre -
     * \post Exception guaranteed: nothrow
     */
    void addPoints();

    /*!
     * \brief takeStats
     * \param stats
     * \pre stats must be found
     * \post Exception guaranteed: nothrow
     */
    void takeStats(std::shared_ptr<StudentSide::Statistics> stats);

    /*!
     * \brief getStartButton gives startButton
     * \return starButton of userinterface
     * \pre -
     * \post Exception guaranteed: nothrow
     */
    QPushButton *getStartButton();

    /*!
     * \brief getStartAction return startaction to start the game from menubar
     * \return starAction
     * \pre -
     * \post Exception guaranteed: nothrow
     */
    QAction *getStartAction();

    /*!
     * \brief stopGameTimer stops game timer in lcd
     * \pre -
     * \post Exception guaranteed: nothrow
     */
    void stopGameTimer();

    /*!
     * \brief getPeopleLabel returns label containing people info
     * \return QLabel
     * \pre -
     * \post Exception guaranteed: nothrow
     */
    QLabel *getPeopleLabel();

    /*!
     * \brief gameEnded return boolean if game is ended or not
     * \return true when gane has ended, false otherwise
     * \pre -
     * \post Exception guaranteed: nothrow
     */
    bool gameEnded();

    /*!
     * \brief destroyPlayer destroys the player
     * \pre -
     * \post Exception guaranteed: nothrow
     */
    void destroyPlayer();

    /*!
     * \brief add nuke to game
     * \param actor for nuke
     * \pre nuke must be found :D
     * \post Exception guaranteed: nothrow
     */
     void addNuke(std::shared_ptr<StudentSide::Actor> nuke);

     /*!
      * \brief get information if nuke has been launched by the player
      * \pre -
      * \post Exception guaranteed: minimum
      */
     bool isNuked();


private slots:

    /*!
     * \brief normalGameSettings adjust normal gamesettings
     * \param name Players name
     * \param gameTime wanted timelimit by user
     * \pre -
     * \post Exception guaranteed: nothrow
     */
    void normalGameSettings(QString name, int gameTime);

    /*!
     * \brief infiniteGameSettings adjusts game to be infinite time
     * \param name Players name
     * \pre -
     * \post Exception guaranteed: nothrow
     */
    void infiniteGameSettings(QString name);

    /*!
     * \brief updateTimelimit updates time to lcds in mainwindow and stops timer when needed
     * \pre -
     * \post Exception guaranteed: nothrow
     */
    void updateTimelimit();

    /*!
     * \brief startGame starts game when pressing start button
     * \pre -
     * \post Exception guaranteed: minimum
     */
    void startGame();

    /*!
     * \brief restartGame restarts game with chosen settings
     * \pre -
     * \post Exception guaranteed: nothrow
     */
    void restartGame();

    /*!
     * \brief changeSettings launches dialoggamesettings dialog to change settings
     */
    void changeSettings();

    /*!
     * \brief showTopScores shows top ten scores of 1min and 2 min games
     * \pre -
     * \post Exception guaranteed: strong
     */
    void showTopScores();

    /*!
     * \brief showRules shows the game rules in popup
     * \pre -
     * \post Exception guaranteed: nothrow
     */
    void showRules();

    /*!
     * \brief showAboutInfo show the aboutUs information in popup
     * \pre -
     * \post Exception guaranteed: nothrow
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
    std::shared_ptr<Actor> nuke_;     //!< Pointer to nuke
    StudentSide::playerActor* graphicPlayer_; //!< Graphics for player
    StudentSide::NukeActor* graphicNuke_; //!< Graphics for nuke
    std::shared_ptr<StudentSide::Statistics> stats_; //:< stats class
    int type = 0;               //!< type of actor
    QTimer timer_;              //!< timer for countdown timelimit
    int timelimit = 0;          //!< timelimit for game
    int seconds = 0;            //!< seconds to count and show in lcds
    bool isInfiniteTime = true; //!< boolean value to check gametype
    bool secondsRunning = false;//!< Check if seconds are runnign in lcds
    int points_ = 0;            //!< Game points
    QString gamemode = "";      //!< tells selected gamemode

    // Menus and actions to them
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
     * \pre -
     * \post Exception guaranteed: nothrow
     */
    void gameEnding();

    /*!
     * \brief update_time_lcd updates time to min and sec lcd
     * \pre -
     * \post Exception guaranteed: nothrow
     */
    void update_time_lcd();

    /*!
     * \brief connectSignals connects all signals and slots
     * \pre -
     * \post Exception guaranteed: nothrow
     */
    void connectSignals();

    /*!
     * \brief setUiWidgets sets ui component to mainwindow
     * \pre -
     * \post Exception guaranteed: nothrow
     */
    void setUiWidgets();

    /*!
     * \brief createActions creates menu actions
     * \pre -
     * \post Exception guaranteed: nothrow
     */
    void createActions();

    /*!
     * \brief createMenus creates menus to mainwindow
     * \pre -
     * \post Exception guaranteed: nothrow
     */
    void createMenus();

    /*!
     * \brief readFileToMessage read file and shows the insides in messagebox
     * \param fileName direction to fiel
     * \param title Title for the messagebox
     * \pre -
     * \post Exception guaranteed: nothrow
     */
    void readFileToMessage(QString fileName, QString title);

};

} //namespace
#endif // MAINWINDOW_HH
