#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include "dialoggamesettings.hh"

#include <QMainWindow>
#include <QGraphicsScene>
#include "interfaces/iactor.hh"
#include <QTimer>
#include <iostream>
#include <memory>
#include <QVector>
#include <QPixmap>
#include <QMap>
#include "actoritem.hh"
#include "actor.hh"
#include "interfaces/ipassenger.hh"
#include "interfaces/ivehicle.hh"
#include "interfaces/istop.hh"

namespace Ui {
class MainWindow;
}

namespace StudentSide {

/*!
 * \brief The mainwindow class
 */
class mainwindow : public QMainWindow
{
    Q_OBJECT

public:

    /*!
     * \brief mainwindow
     * \param parent
     */
    explicit mainwindow(QWidget *parent = nullptr);
    ~mainwindow();
    void setBackground(QPixmap &image);
    void addActor(std::shared_ptr<Interface::IActor> actor);

    void addStop(std::shared_ptr<Interface::IStop> stop);

    void moveActor(std::shared_ptr<Interface::IActor> actor, int x, int y);


public slots:

    /*!
     * \brief adjustGameSettings
     */
    void adjustGameSettings(QString name);

    void defaultSettings();

private:
    Ui::MainWindow *ui_;
    QGraphicsScene *map;
    QString playerName_ = "Timo";

    const int width_ = 500;
    const int height_ = 500;
    StudentSide::ActorItem* last_;

    QMap<std::shared_ptr<Interface::IActor>, StudentSide::ActorItem *> actors_;
    QMap<std::shared_ptr<Interface::IStop>, StudentSide::ActorItem *>stops_;


    int type = 0;
    const int BussStop = 0;
    const int Nysse = 1;
    const int passenger = 2;
};
} //namespace
#endif // MAINWINDOW_HH
