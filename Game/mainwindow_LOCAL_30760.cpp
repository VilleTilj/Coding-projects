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

    StudentSide::ActorItem* nActor = new StudentSide::ActorItem(locX, locY, type);
    actors_.push_back(nActor);
    map->addItem(nActor);
    last_ = nActor;
}


void mainwindow::defaultSettings()
{
    ui_->nameLabel->setText(playerName_);
}

} //namespace
