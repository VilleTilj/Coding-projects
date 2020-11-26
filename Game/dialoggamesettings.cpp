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

    //connect(ui->checkBox1min, &QCheckBox::stateChanged, this, &DialogGameSettings::setState2min);
    //connect(ui->checkBox2min, &QCheckBox::stateChanged, this, &DialogGameSettings::setState1min);
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

void DialogGameSettings::setState1min()
{
    /*
    if(ui->checkBox2min->isChecked()) {
        ui->checkBox1min->setEnabled(false);
    } else {
        ui->checkBox1min->setEnabled(true);
    }
    */
}

void DialogGameSettings::setState2min()
{
    /*
    if(ui->checkBox1min->isChecked()) {
        ui->checkBox2min->setEnabled(false);
    } else {
        ui->checkBox2min->setEnabled(true);
    }
    */
}
} //namespace
