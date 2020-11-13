#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

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

class mainwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);
    ~mainwindow();
    void setBackground(QImage &image);
    void addActor(int locX, int locY, int type);

signals:


private:
    Ui::MainWindow *ui_;
    QGraphicsScene *map;

    const int width_ = 1095;
    const int height_ = 592;
    QVector<QGraphicsItem*> actors_;
    CourseSide::SimpleActorItem* last_;


};
} //namespace
#endif // MAINWINDOW_HH
