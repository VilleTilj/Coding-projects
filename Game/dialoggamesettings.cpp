#include "dialoggamesettings.hh"
#include "ui_dialoggamesettings.h"

DialogGameSettings::DialogGameSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogGameSettings)
{
    ui->setupUi(this);
}

DialogGameSettings::~DialogGameSettings()
{
    delete ui;
}
