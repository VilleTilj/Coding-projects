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
    ui->centralwidget->setFixedSize(WIDTH_MAIN + ui->startButton->width() + PADDING, HEIGHT_MAIN + PADDING);
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

QPushButton* Mainwindow::getStartButton()
{
    return ui->startButton;
}


void Mainwindow::normalGameSettings(QString name, int gameTime)
{
    if(!name.isEmpty()) {
        playerName_ = name;
    }
    ui->nameLabel->setText(playerName_);
    timelimit = gameTime;
    seconds = timelimit;
    update_time_lcd();
    isInfiniteTime = false;
}


void Mainwindow::infiniteGameSettings()
{
    ui->nameLabel->setText(playerName_);
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
}

void Mainwindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
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
    connect(ui->quitButton, &QPushButton::clicked, this, &Mainwindow::close);
    connect(ui->startButton, &QPushButton::clicked, this, &Mainwindow::startGame);
    connect(&timer_, &QTimer::timeout, this, &Mainwindow::updateTimelimit);
    //connect(timer, &QTimer::timeout, map, &QGraphicsScene::advance);
}

void Mainwindow::setUiWidgets()
{
    ui->gameView->setFixedSize(WIDTH_MAIN, HEIGHT_MAIN);
    ui->centralwidget->setFixedSize(WIDTH_MAIN + ui->startButton->width() + PADDING, HEIGHT_MAIN + PADDING);
    ui->startButton->move(WIDTH_MAIN + PADDING, PADDING);
    ui->scoresButton->move(WIDTH_MAIN + PADDING, PADDING + 30);
    ui->quitButton->move(WIDTH_MAIN + PADDING, PADDING + (2 * 30));
    ui->playernameLabel->move(WIDTH_MAIN + PADDING, PADDING + (5*30));
    ui->nameLabel->move(WIDTH_MAIN + PADDING, PADDING + (6*30));
    ui->timeLabel->move(WIDTH_MAIN + PADDING, PADDING + (3*30));
    ui->time_lcd_min->move(WIDTH_MAIN- PADDING, PADDING + (4*30));
    ui->time_lcd_sec->move(WIDTH_MAIN+ PADDING*4, PADDING + (4*30));
    ui->points_lcd->move(WIDTH_MAIN + PADDING, PADDING + (7*30));

}

void Mainwindow::createActions()
{
    startAct = new QAction(tr("&New"),this);
    startAct->setShortcut(tr("Ctrl+S"));
    startAct->setStatusTip(tr("Start game!"));
    connect(startAct, &QAction::triggered, this, &Mainwindow::startGame);

}

void Mainwindow::createMenus()
{
    gameMenu = menuBar()->addMenu(tr("&Game"));
    gameMenu->addAction(startAct);
}

} //namespace
