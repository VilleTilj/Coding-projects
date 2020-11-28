#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QImage>
#include "QTimer"

const int PADDING = 10;


namespace StudentSide {

Mainwindow::Mainwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    myDialog(new DialogGameSettings)
{
    ui->setupUi(this);

    connectSignals();
    setUiWidgets();

    ui->gameView->setFixedSize(WIDTH_MAIN, HEIGHT_MAIN);
    ui->centralwidget->setFixedSize(WIDTH_MAIN + ui->startButton->width() + PADDING*2, HEIGHT_MAIN + PADDING);
    ui->startButton->move(WIDTH_MAIN + PADDING, PADDING);

    // create scene
    map = new QGraphicsScene(this);
    ui->gameView->setScene(map);
    map->setSceneRect(0,0,WIDTH_MAIN,HEIGHT_MAIN);
    resize(minimumSizeHint());

    createActions();
    createMenus();

    // Create timer to move actors
    timer = new QTimer;
    timer->start(1500);
    myDialog->exec();
}


Mainwindow::~Mainwindow()
{
    delete ui;
}


void Mainwindow::setBackground(QPixmap &image)
{
    QPixmap myImage = image;
    //QTransform myTransform;
    //myTransform.rotate(180);
    //myImage = myImage.transformed(myTransform);
   map->addPixmap(image);
}


void Mainwindow::addActor(std::shared_ptr<Interface::IActor> actor)
{
    Interface::Location location = actor->giveLocation();
    if(std::shared_ptr<Interface::IVehicle> nActor = std::dynamic_pointer_cast<Interface::IVehicle>(actor)) {
        type = NYSSE;

    }

    else if(std::shared_ptr<Interface::IPassenger> nActor = std::dynamic_pointer_cast<Interface::IPassenger>(actor)) {
        type = PASSENGER;
    }

    StudentSide::ActorItem* graphicActor = new StudentSide::ActorItem(location.giveX(), location.giveY(), type);
    actors_[actor] = graphicActor;
    map->addItem(graphicActor);
    last_ = graphicActor;
}


void Mainwindow::addStop(std::shared_ptr<Interface::IStop> stop)
{
    Interface::Location location = stop->getLocation();
    StudentSide::ActorItem* graphicActor = new StudentSide::ActorItem(location.giveX(),location.giveY(), BUSS_STOP);
    stops_[stop] = graphicActor;
    map->addItem(graphicActor);
    last_ = graphicActor;
}


void Mainwindow::moveActor(std::shared_ptr<Interface::IActor> actor, int x, int y)
{
    //find corresponding gpraphic actor.
    std::map<std::shared_ptr<Interface::IActor>,  StudentSide::ActorItem*>::iterator it;

    for (it = actors_.begin(); it != actors_.end(); ++it){
        if(it->first == actor){
            it->second->setCoord(x, y);
        }
    }
}


void Mainwindow::removeActor(std::shared_ptr<Interface::IActor> actor)
{
    std::map<std::shared_ptr<Interface::IActor>,  StudentSide::ActorItem*>::iterator it;
    for (it = actors_.begin(); it != actors_.end(); ++it){
        if(it->first == actor){
            addPoints();
            map->removeItem(it->second);
            delete it->second;
            actors_.erase(actor);
        }
    }
}


void Mainwindow::addPlayer(std::shared_ptr<Actor> player)
{
    player_ = player;
    Interface::Location location = player_->giveLocation();
    graphicPlayer_ = new StudentSide::playerActor(location);
    map->addItem(graphicPlayer_);
}


Interface::Location Mainwindow::GivePlayerLocation()
{
    return graphicPlayer_->giveLocation();
}


playerActor *Mainwindow::returnPlayer()
{
    return graphicPlayer_;
}

void Mainwindow::addPoints()
{
    points_ = points_ + POINTS;
    ui->points_lcd->display(points_);
}

QPushButton *Mainwindow::getStartButton()
{
    return ui->startButton;
}

QAction *Mainwindow::getStartAction()
{
    return startAct;
}


void Mainwindow::normalGameSettings(QString name, int gameTime)
{
    if(!name.isEmpty()) {
        playerName_ = name;
    }
    ui->nameLabel->setText(playerName_);
    timelimit = gameTime;
    seconds = timelimit;
    points_ = 0;
    ui->points_lcd->display(points_);
    update_time_lcd();
    isInfiniteTime = false;
}


void Mainwindow::infiniteGameSettings(QString name)
{
    playerName_ = name;
    ui->nameLabel->setText(playerName_);
    seconds = 0;
    points_ = 0;
    ui->points_lcd->display(points_);
    update_time_lcd();
    isInfiniteTime = true;
}


void Mainwindow::updateTimelimit()
{
    if(!isInfiniteTime){
        if(secondsRunning && seconds > 0){
            seconds--;
            update_time_lcd();
        } else {
            timer_.stop();
            ui->startButton->setEnabled(true);
            startAct->setEnabled(true);
            secondsRunning = false;
        }
    } else {
        seconds++;
        update_time_lcd();
    }
}


void Mainwindow::startGame()
{
    seconds = timelimit;
    timer_.start(SECOND);
    secondsRunning = true;
    ui->startButton->setEnabled(false);
    startAct->setEnabled(false);
    points_ = 0;
}

void Mainwindow::restartGame()
{

}

void Mainwindow::changeSettings()
{
    // TODO stop the game logic
    myDialog->exec();
}

void Mainwindow::showTopScores()
{

}

void Mainwindow::showRules()
{
    QString title = "Game Rules";
    readFileToMessage(RULES, title);
}

void Mainwindow::showAboutInfo()
{
    QString title = "About...";
    readFileToMessage(ABOUT, title);
}

void Mainwindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.addAction(startAct);
    menu.addAction(restartAct);
    menu.exec(event->globalPos());
}

void Mainwindow::update_time_lcd()
{
    ui->time_lcd_min->display(seconds / 60);
    ui->time_lcd_sec->display(seconds % 60);
}

void Mainwindow::connectSignals()
{
    connect(myDialog, &DialogGameSettings::normalSettings, this, &Mainwindow::normalGameSettings);
    connect(myDialog, &DialogGameSettings::infiniteSettings, this, &Mainwindow::infiniteGameSettings);
    connect(ui->startButton, &QPushButton::clicked, this, &Mainwindow::startGame);
    connect(&timer_, &QTimer::timeout, this, &Mainwindow::updateTimelimit);
    //connect(timer, &QTimer::timeout, map, &QGraphicsScene::advance);
}

void Mainwindow::setUiWidgets()
{
    ui->gameView->setFixedSize(WIDTH_MAIN, HEIGHT_MAIN);
    ui->centralwidget->setFixedSize(WIDTH_MAIN + ui->startButton->width() + PADDING, HEIGHT_MAIN + PADDING);
    ui->startButton->move(WIDTH_MAIN + PADDING, PADDING);
    ui->playernameLabel->move(WIDTH_MAIN + PADDING, PADDING + (2*30));
    ui->nameLabel->move(WIDTH_MAIN + PADDING, PADDING + (3*30));
    ui->timeLabel->move(WIDTH_MAIN + PADDING/2, PADDING + (5*30));
    ui->time_lcd_min->move(WIDTH_MAIN, PADDING + (6*30));
    ui->time_lcd_sec->move(WIDTH_MAIN + PADDING * 5, PADDING + (6*30));
    ui->pointsLabel->move(WIDTH_MAIN + PADDING, PADDING + (8*30));
    ui->points_lcd->move(WIDTH_MAIN + PADDING, PADDING + (9*30));

}

void Mainwindow::createActions()
{
    startAct = new QAction(tr("&Start"),this);
    startAct->setShortcut(tr("Ctrl+S"));
    startAct->setStatusTip(tr("Starts game!"));
    connect(startAct, &QAction::triggered, this, &Mainwindow::startGame);

    restartAct = new QAction(tr("&Restart"),this);
    restartAct->setShortcut(tr("Ctrl+R"));
    restartAct->setStatusTip(tr("Restarts game"));
    connect(restartAct, &QAction::triggered, this, &Mainwindow::restartGame);

    changeSettingsAct = new QAction(tr("&Change settings"));
    changeSettingsAct->setStatusTip(tr("Launches dialog for settings"));
    connect(changeSettingsAct, &QAction::triggered, this, &Mainwindow::changeSettings);

    showScores = new QAction(tr("&Top scores"));
    showScores->setStatusTip(tr("Show top scores"));
    connect(showScores, &QAction::triggered, this, &Mainwindow::showTopScores);

    quitAct = new QAction(tr("&Quit"));
    quitAct->setShortcut(tr("Esc"));
    quitAct->setStatusTip(tr("Quit game"));
    connect(quitAct, &QAction::triggered, this, &Mainwindow::close);

    rulesAct = new QAction(tr("&Read me!"));
    rulesAct->setStatusTip(tr("Popup window containing rules"));
    connect(rulesAct, &QAction::triggered, this, &Mainwindow::showRules);

    aboutUsAct = new QAction(tr("&About us"));
    aboutUsAct->setStatusTip(tr("Popup window containing information about us"));
    connect(aboutUsAct, &QAction::triggered, this, &Mainwindow::showAboutInfo);
}

void Mainwindow::createMenus()
{
    gameMenu = menuBar()->addMenu(tr("&Game"));
    gameMenu->addAction(startAct);
    gameMenu->addAction(restartAct);
    gameMenu->addAction(changeSettingsAct);
    gameMenu->addSeparator();
    gameMenu->addAction(showScores);
    gameMenu->addAction(quitAct);

    aboutMenu = menuBar()->addMenu(tr("&About"));
    aboutMenu->addAction(rulesAct);
    aboutMenu->addAction(aboutUsAct);
}

void Mainwindow::readFileToMessage(QString fileName, QString title)
{
    QString text = "";
    QFile inputFile(fileName);
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          QString line = in.readLine();
          text.append(line + "\n");
       }
       inputFile.close();
    }
    QMessageBox msgBox;
    msgBox.setText(text);
    msgBox.setWindowTitle(title);
    msgBox.exec();
}

} //namespace
