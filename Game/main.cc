#include "gameengine.hh"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Q_INIT_RESOURCE(offlinedata);
    Q_INIT_RESOURCE(Graphics);
    StudentSide::GameEngine w;
    return a.exec();
}
