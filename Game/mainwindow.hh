#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include "dialoggamesettings.hh"

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <iostream>
#include <memory>
#include <QVector>
#include <map>
#include "graphics/simpleactoritem.hh"


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
    void setBackground(QImage &image);
    void addActor(int locX, int locY, int type);

public slots:

    /*!
     * \brief adjustGameSettings
     */
    void adjustGameSettings(std::string name);

    void defaultSettings();

private:
    Ui::MainWindow *ui_;
    QGraphicsScene *map;
    std::string playerName = "Timo";

    const int width_ = 1095;
    const int height_ = 592;
    QVector<QGraphicsItem*> actors_;
    CourseSide::SimpleActorItem* last_;


};
} //namespace
#endif // MAINWINDOW_HH
