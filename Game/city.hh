#ifndef CITY_HH
#define CITY_HH


#include "interfaces/icity.hh"
#include <QTime>

namespace StudentSide
{

class City : public Interface::ICity
{
public:
    City();
    ~City();
    void setBackground(QImage& basicbackground, QImage& bigbackground);

    void setClock(QTime clock);

    void addStop(std::shared_ptr<Interface::IStop> stop);

    void startGame();

    void addActor(std::shared_ptr<Interface::IActor> newactor);

    void removeActor(std::shared_ptr<Interface::IActor> actor);

    void actorRemoved(std::shared_ptr<Interface::IActor> actor);

    bool findActor(std::shared_ptr<Interface::IActor> actor) const;

    std::vector<std::shared_ptr<Interface::IActor> > getNearbyActors(Interface::Location loc) const;

    void actorMoved(std::shared_ptr<Interface::IActor> actor);

    bool isGameOver() const;

private:


};

} //namespace


#endif // CITY_HH
