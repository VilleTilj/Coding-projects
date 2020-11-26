#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QImage>


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

    ui_->gameView->setFixedSize(width_, height_);
    ui_->centralwidget->setFixedSize(width_ + ui_->startButton->width() + PADDING, height_ + PADDING);
    ui_->startButton->move(width_ + PADDING, PADDING);
    ui_->nameLabel->move(width_ + PADDING + ui_->nameLabel->width(), PADDING);



    map = new QGraphicsScene(this);
    ui_->gameView->setScene(map);
    map->setSceneRect(0,0,width_,height_);
    resize(minimumSizeHint());

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


void mainwindow::defaultSettings()
{
    ui_->nameLabel->setText(playerName_);
}

} //namespace
