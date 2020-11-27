#include "gameengine.hh"
#include <memory>
#include <QImage>
#include <QDebug>
#include <QObject>


namespace StudentSide {

GameEngine::GameEngine() :
    ui(new StudentSide::Mainwindow),
    logic_(new CourseSide::Logic),
    iCityPtr(nullptr)
{
    gameWindow();
    connect(&timer, &QTimer::timeout, this, &GameEngine::advance);
}


void GameEngine::advance()
{
    graphicPlayer_->setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    graphicPlayer_->setFocus();
    graphicPlayer_->giveLocation();
    std::vector<std::shared_ptr<Interface::IActor>> actor = cityPtr_->getNearbyActors(graphicPlayer_->giveLocation());
    //qDebug() << actor.size();
    for(unsigned long int i = 0; i < actor.size(); i++){
        cityPtr_->removeActor(actor.at(i));
    }
}


void GameEngine::initLogic()
{
    cityPtr_->addUi(ui);
    logic_->takeCity(cityPtr_);
    logic_->fileConfig();
    logic_->setTime(8, 00);
    cityPtr_->makePlayer();
    graphicPlayer_ = ui->returnPlayer();
    logic_->finalizeGameStart();
    timer.start(150);
}


void GameEngine::gameWindow()
{
    //draw ui for user
    ui->show();
    std::shared_ptr<Interface::ICity> iCityPtr = Interface::createGame();
    //get graphics for the map and the to city
    QImage big;
    big.load(bigMap);
    QImage small;
    small.load(smallMap);
    cityPtr_ = std::dynamic_pointer_cast<StudentSide::City>(iCityPtr);
    cityPtr_->setBackground(small, big);

    QPixmap map;
    map.load(bigMap);
    ui->setBackground(map);
    //start game logic
    initLogic();

}

} //namespace
