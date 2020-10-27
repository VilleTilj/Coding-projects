#ifndef DIALOGGAMESETTINGS_HH
#define DIALOGGAMESETTINGS_HH

#include <QDialog>

namespace Ui {
class DialogGameSettings;
}

class DialogGameSettings : public QDialog
{
    Q_OBJECT

public:
    explicit DialogGameSettings(QWidget *parent = nullptr);
    ~DialogGameSettings();

private:
    Ui::DialogGameSettings *ui;
};

#endif // DIALOGGAMESETTINGS_HH
