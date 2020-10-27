#ifndef DIALOGGAMESETTINGS_HH
#define DIALOGGAMESETTINGS_HH

#include <QDialog>

namespace Ui {
class DialogGameSettings;
}

namespace StudentSide {

class DialogGameSettings : public QDialog
{
    Q_OBJECT

public:
    explicit DialogGameSettings(QWidget *parent = nullptr);
    ~DialogGameSettings();

public slots:
    void showMainwindow();

signals:
    void sendUserInputs(); // TODO implement user input fields

private:
    Ui::DialogGameSettings *ui;
};
} //namespace
#endif // DIALOGGAMESETTINGS_HH
