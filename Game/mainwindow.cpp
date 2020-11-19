#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QDebug>

const int PADDING = 10;

namespace StudentSide {

mainwindow::mainwindow(QWidget *parent) :
    QMainWindow(parent),
    ui_(new Ui::MainWindow)
{
    ui_->setupUi(this);
    DialogGameSettings *myDialog = new DialogGameSettings;
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

    myDialog->exec();
}

mainwindow::~mainwindow()
{
    delete ui_;
}


void mainwindow::setBackground(QImage &image)
{
    //QImage myImage = image;
    //QTransform myTransform;
    //myTransform.rotate(180);
    //myImage = myImage.transformed(myTransform);
    map->setBackgroundBrush(image);
}


void mainwindow::adjustGameSettings(QString name)
{
    if(!name.isEmpty()) {
        playerName_ = name;
    }
    ui_->nameLabel->setText(playerName_);
}

void mainwindow::addActor(int locX, int locY, int type)
{

    CourseSide::SimpleActorItem* nActor = new CourseSide::SimpleActorItem(locX, locY);
    actors_.push_back(nActor);
    map->addItem(nActor);
    last_ = nActor;
}


void mainwindow::defaultSettings()
{
    ui_->nameLabel->setText(playerName_);
}

} //namespace
