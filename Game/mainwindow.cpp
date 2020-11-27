#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QImage>
#include "QTimer"

const int PADDING = 10;


namespace StudentSide {

mainwindow::mainwindow(QWidget *parent) :
    QMainWindow(parent),
    ui_(new Ui::MainWindow)
{
    ui_->setupUi(this);
    DialogGameSettings *myDialog = new DialogGameSettings;

    //signals
    connect(myDialog, &DialogGameSettings::normalSettings, this, &mainwindow::adjustGameSettings);
    connect(myDialog, &DialogGameSettings::infiniteSettings, this, &mainwindow::defaultSettings);
    connect(ui_->quitButton, &QPushButton::clicked, this, &mainwindow::close);
    connect(ui_->startButton, &QPushButton::clicked, this, &mainwindow::start_game);
    connect(&timer_, &QTimer::timeout, this, &mainwindow::update_timelimit);
    ui_->gameView->setFixedSize(width_, height_);
    ui_->centralwidget->setFixedSize(width_ + ui_->startButton->width() + PADDING, height_ + PADDING);
    ui_->startButton->move(width_ + PADDING, PADDING);
    ui_->scoresButton->move(width_ + PADDING, PADDING + 30);
    ui_->quitButton->move(width_ + PADDING, PADDING + (2 * 30));
    ui_->playernameLabel->move(width_ + PADDING, PADDING + (5*30));
    ui_->nameLabel->move(width_ + PADDING, PADDING + (6*30));
    ui_->timeLabel->move(width_ + PADDING, PADDING + (3*30));
    ui_->time_lcd_min->move(width_- PADDING, PADDING + (4*30));
    ui_->time_lcd_sec->move(width_+ PADDING*4, PADDING + (4*30));



    map = new QGraphicsScene(this);
    ui_->gameView->setScene(map);
    map->setSceneRect(0,0,width_,height_);
    resize(minimumSizeHint());
    myDialog->exec();
    timer = new QTimer;
    connect(timer, &QTimer::timeout, map, &QGraphicsScene::advance);
    timer->start(1500);
}


mainwindow::~mainwindow()
{
    delete ui_;
}


void mainwindow::setBackground(QPixmap &image)
{
    QPixmap myImage = image;
    //QTransform myTransform;
    //myTransform.rotate(180);
    //myImage = myImage.transformed(myTransform);
   map->addPixmap(image);
}


void mainwindow::adjustGameSettings(QString name, int game_time)
{
    if(!name.isEmpty()) {
        playerName_ = name;
    }
    ui_->nameLabel->setText(playerName_);
    timelimit = game_time;
    seconds = timelimit;
    update_time_lcd();
    isInfiniteTime = false;
}


void mainwindow::addActor(std::shared_ptr<Interface::IActor> actor)
{

    Interface::Location location = actor->giveLocation();
    if(std::shared_ptr<Interface::IVehicle> nActor = std::dynamic_pointer_cast<Interface::IVehicle>(actor)) {
        type = Nysse;

    }

    else if(std::shared_ptr<Interface::IPassenger> nActor = std::dynamic_pointer_cast<Interface::IPassenger>(actor)) {
        type = passenger;
    }

    StudentSide::ActorItem* graphicActor = new StudentSide::ActorItem(location.giveX(), location.giveY(), type);
    actors_[actor] = graphicActor;
    map->addItem(graphicActor);
    last_ = graphicActor;
}


void mainwindow::addStop(std::shared_ptr<Interface::IStop> stop)
{
    Interface::Location location = stop->getLocation();
    StudentSide::ActorItem* graphicActor = new StudentSide::ActorItem(location.giveX(),location.giveY(), BussStop);
    stops_[stop] = graphicActor;
    map->addItem(graphicActor);
    last_ = graphicActor;
}


void mainwindow::moveActor(std::shared_ptr<Interface::IActor> actor, int x, int y)
{

    //find corresponding gpraphic actor.

    std::map<std::shared_ptr<Interface::IActor>,  StudentSide::ActorItem*>::iterator it;

    for (it = actors_.begin(); it != actors_.end(); ++it)
        if(it->first == actor){
            it->second->setCoord(x, y);
        }
}


void mainwindow::removeActor(std::shared_ptr<Interface::IActor> actor)
{
    std::map<std::shared_ptr<Interface::IActor>,  StudentSide::ActorItem*>::iterator it;
    for (it = actors_.begin(); it != actors_.end(); ++it)
        if(it->first == actor){
            map->removeItem(it->second);
            //qDebug() << "ryyyyyyys";
            delete it->second;
            actors_.erase(actor);
        }


}


void mainwindow::addPlayer(std::shared_ptr<Actor> player)
{
    player_ = player;
    Interface::Location location = player_->giveLocation();
    graphicPlayer_ = new StudentSide::playerActor(location);
    map->addItem(graphicPlayer_);
}


Interface::Location mainwindow::GivePlayerLocation()
{
    return graphicPlayer_->giveLocation();
}

void mainwindow::update_timelimit()
{
    if(!isInfiniteTime){
        if(timelimit_running && seconds > 0){
            seconds--;
            update_time_lcd();
        } else {
            timer_.stop();
            ui_->startButton->setEnabled(true);
            timelimit_running = false;
        }
    } else {
        seconds++;
        update_time_lcd();
    }
}

void mainwindow::start_game()
{
    seconds = timelimit;
    timer_.start(SECOND);
    timelimit_running = true;
    ui_->startButton->setEnabled(false);

    emit initialize_logic();
}

void mainwindow::update_time_lcd()
{
    ui_->time_lcd_min->display(seconds / 60);
    ui_->time_lcd_sec->display(seconds % 60);
}

playerActor *mainwindow::returnPlayer()
{
    return graphicPlayer_;
}

void mainwindow::defaultSettings()
{
    ui_->nameLabel->setText(playerName_);
    update_time_lcd();
    isInfiniteTime = true;
}

} //namespace
