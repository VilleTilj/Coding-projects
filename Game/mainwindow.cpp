#include "mainwindow.hh"
#include "ui_mainwindow.h"

namespace StudentSide {



mainwindow::mainwindow(QWidget *parent) :
    QMainWindow(parent),
    ui_(new Ui::MainWindow)
{
    ui_->setupUi(this);

}
}
