#include "dialoggamesettings.hh"
#include "ui_dialoggamesettings.h"

namespace StudentSide {

DialogGameSettings::DialogGameSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogGameSettings)
{
    ui->setupUi(this);
    connect(ui->customSettings, &QPushButton::clicked, this, &DialogGameSettings::custom);
    connect(ui->customSettings, &QPushButton::clicked, this, &DialogGameSettings::accept);

    connect(ui->defaultButton, &QPushButton::clicked, this, &DialogGameSettings::defaults);
    connect(ui->defaultButton, &QPushButton::clicked, this, &DialogGameSettings::reject);
}

DialogGameSettings::~DialogGameSettings()
{
    delete ui;
}

void DialogGameSettings::custom()
{
    emit customSettings(ui->lineEdit->text());
}

void DialogGameSettings::defaults()
{
    emit defaultSettings();
}
} //namespace
