#ifndef DIALOGGAMESETTINGS_HH
#define DIALOGGAMESETTINGS_HH

#include <QDialog>
//#include "mainwindow.hh"

const int ONE_MINUTE = 60;
const int TWO_MINUTE = 120;

namespace Ui {
class DialogGameSettings;
}

namespace StudentSide {

/*!
 * \brief The DialogGaneSettings class sets up dialog window to get pre settings for the main game
 */

class DialogGameSettings : public QDialog
{
    Q_OBJECT

public:

    /*!
     * \brief DialogGameSettings constructor for the dialog window
     * \param parent
     */

    explicit DialogGameSettings(QWidget *parent = nullptr);

    /*!
     * \brief Destructor
     */

    ~DialogGameSettings();

public slots:

    /*!
     * \brief normal game
     */
    void normal();

    /*!
     * \brief infinite time game
     */
    void infinite();

    /*!
     * \brief setState1min changes state of checkbox1min
     */
    void setState1min();

    /*!
     * \brief setState2minc hanges state of checkbox2min
     */
    void setState2min();

signals:

    /*!
     * \brief normalSettings
     */
    void normalSettings(QString name, int timelimit);

    /*!
     * \brief infiniteSettings
     */
    void infiniteSettings();

private:
    Ui::DialogGameSettings *ui;
    int timelimit = 0;

    void setTimelimit();
};
} //namespace
#endif // DIALOGGAMESETTINGS_HH
