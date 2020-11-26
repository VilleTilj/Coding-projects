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
    connect(myDialog, &DialogGameSettings::customSettings, this, &mainwindow::adjustGameSettings);
    connect(myDialog, &DialogGameSettings::defaultSettings, this, &mainwindow::defaultSettings);
    connect(ui_->quitButton, &QPushButton::clicked, this, &mainwindow::close);
    ui_->gameView->setFixedSize(width_, height_);
    ui_->centralwidget->setFixedSize(width_ + ui_->startButton->width() + PADDING, height_ + PADDING);
    ui_->startButton->move(width_ + PADDING, PADDING);
    ui_->scoresButton->move(width_ + PADDING, PADDING + 30);
    ui_->quitButton->move(width_ + PADDING, PADDING + (2 * 30));
    ui_->playernameLabel->move(width_ + PADDING, PADDING + (5*30));
    ui_->nameLabel->move(width_ + PADDING, PADDING + (6*30));
    ui_->timeLabel->move(width_ + PADDING, PADDING + (3*30));
    ui_->time_lcd->move(width_+ PADDING, PADDING + (4*30));


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


void mainwindow::adjustGameSettings(QString name)
{
    if(!name.isEmpty()) {
        playerName_ = name;
    }
    ui_->nameLabel->setText(playerName_);
}


void mainwindow::addActor(std::shared_ptr<Interface::IActor> actor)
{

    Interface::Location location = actor->giveLocation();
    if(std::shared_ptr<Interface::IPassenger> nActor = std::dynamic_pointer_cast<Interface::IPassenger>(actor)) {
        type = passenger;

    }

    else if(std::shared_ptr<Interface::IVehicle> nActor = std::dynamic_pointer_cast<Interface::IVehicle>(actor)) {
        type = Nysse;
    }

    StudentSide::ActorItem* graphicActor = new StudentSide::ActorItem(location.giveX(), 500 -  location.giveY(), type);
    actors_[actor] = graphicActor;
    map->addItem(graphicActor);
    last_ = graphicActor;
}


void mainwindow::addStop(std::shared_ptr<Interface::IStop> stop)
{
    Interface::Location location = stop->getLocation();
    StudentSide::ActorItem* graphicActor = new StudentSide::ActorItem(location.giveX(),500 - location.giveY(), BussStop);
    stops_[stop] = graphicActor;
    map->addItem(graphicActor);
    last_ = graphicActor;
}


void mainwindow::moveActor(std::shared_ptr<Interface::IActor> actor, int x, int y)
{

    //find corresponding gpraphic actor.

    QMap<std::shared_ptr<Interface::IActor>,  StudentSide::ActorItem*>::iterator it;

    for (it = actors_.begin(); it != actors_.end(); ++it)
        if(it.key() == actor){
            it.value()->setCoord(x, 500 - y);
        }
}


void mainwindow::removeActor(std::shared_ptr<Interface::IActor> actor)
{
    QMap<std::shared_ptr<Interface::IActor>,  StudentSide::ActorItem*>::iterator it;

    for (it = actors_.begin(); it != actors_.end(); ++it)
        if(it.key() == actor){
            map->removeItem(it.value());
            delete it.value();
        }
    actors_.erase(it);
}


void mainwindow::addPlayer(std::shared_ptr<Actor> player)
{
    player_ = player;
    Interface::Location location = player_->giveLocation();
    graphicPlayer_ = new StudentSide::playerActor(location);
    map->addItem(graphicPlayer_);
    graphicPlayer_->setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    graphicPlayer_->setFocus();
}


Interface::Location mainwindow::GivePlayerLocation()
{
    return graphicPlayer_->giveLocation();
}

playerActor *mainwindow::returnPlayer()
{
    return graphicPlayer_;
}

void mainwindow::defaultSettings()
{
    ui_->nameLabel->setText(playerName_);
}

} //namespace
