#include "dialoggamesettings.hh"
#include "ui_dialoggamesettings.h"

namespace StudentSide {

DialogGameSettings::DialogGameSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogGameSettings)
{
    ui->setupUi(this);
    connect(ui->normalGameButton, &QPushButton::clicked, this, &DialogGameSettings::normal);
    connect(ui->normalGameButton, &QPushButton::clicked, this, &DialogGameSettings::accept);

    connect(ui->infiniteGameButton, &QPushButton::clicked, this, &DialogGameSettings::infinite);
    connect(ui->infiniteGameButton, &QPushButton::clicked, this, &DialogGameSettings::reject);

    connect(ui->checkBox1min, &QCheckBox::stateChanged, this, &DialogGameSettings::setState2min);
    connect(ui->checkBox2min, &QCheckBox::stateChanged, this, &DialogGameSettings::setState1min);

    changeButtonsStates();
}

DialogGameSettings::~DialogGameSettings()
{
    delete ui;
}

void DialogGameSettings::normal()
{
    setTimelimit();
    emit normalSettings(ui->lineEdit->text(), timelimit);
}

void DialogGameSettings::infinite()
{
    emit infiniteSettings(ui->lineEdit->text());
}

void DialogGameSettings::setState1min()
{
    if(ui->checkBox2min->isChecked()) {
        ui->checkBox1min->setEnabled(false);
    } else {
        ui->checkBox1min->setEnabled(true);
    }
    changeButtonsStates();
}

void DialogGameSettings::setState2min()
{
    if(ui->checkBox1min->isChecked()) {
        ui->checkBox2min->setEnabled(false);
    } else {
        ui->checkBox2min->setEnabled(true);
    } 
    changeButtonsStates();
}

void DialogGameSettings::setTimelimit()
{
    if(ui->checkBox1min->isChecked()){
        timelimit = ONE_MINUTE;
    } else {
        timelimit = TWO_MINUTE;
    }
}

void DialogGameSettings::changeButtonsStates()
{
    if((ui->checkBox1min->isChecked() || ui->checkBox2min->isChecked()) && !ui->lineEdit->text().isEmpty()) {
        ui->normalGameButton->setEnabled(true);
        ui->infiniteGameButton->setEnabled(true);
    } else {
        ui->normalGameButton->setEnabled(false);
        ui->infiniteGameButton->setEnabled(false);

    }
}
} //namespace
