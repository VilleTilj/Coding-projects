#ifndef DIALOGGAMESETTINGS_HH
#define DIALOGGAMESETTINGS_HH

#include <QDialog>

const int ONE_MINUTE = 6;
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
     * \brief normalSettings to set normal game settings
     * \param name Name of the player
     * \param timelimit Sets the timelimit for game
     */
    void normalSettings(QString name, int timelimit);

    /*!
     * \brief infiniteSettings to set infinite time game.
     */
    void infiniteSettings(QString name);

private:
    Ui::DialogGameSettings *ui; //!< Userinterface for dialog.
    int timelimit = 0;          //!< timelimit for the game.

    /*!
     * \brief setTimelimit sets game timelimit depending on user choise.
     */
    void setTimelimit();

    /*!
     * \brief changeButtonsStates change buttons state enabled or disabled
     * depending on checkbox states.
     */
    void changeButtonsStates();
};

} //namespace
#endif // DIALOGGAMESETTINGS_HH
