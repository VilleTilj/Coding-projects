#include "dialoggamesettings.hh"
#include "ui_dialoggamesettings.h"

namespace StudentSide {

DialogGameSettings::DialogGameSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogGameSettings)
{
    ui->setupUi(this);
    //connect(ui->startButton, &QPushButton::clicked, this, &DialogGameSettings::showMainwindow);
    connect(ui->startButton, &QPushButton::clicked, this, &DialogGameSettings::accept);
    connect(ui->quitButton, &QPushButton::clicked, this, &DialogGameSettings::reject);
}

DialogGameSettings::~DialogGameSettings()
{
    delete ui;
}

void DialogGameSettings::showMainwindow()
{
    emit sendUserInputs();
}
} //namespace
