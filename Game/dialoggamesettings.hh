#ifndef DIALOGGAMESETTINGS_HH
#define DIALOGGAMESETTINGS_HH

#include <QDialog>
//#include "mainwindow.hh"

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
     * \brief custom
     */
    void custom();

    /*!
     * \brief defaults
     */
    void defaults();
signals:

    /*!
     * \brief customSettings
     */
    void customSettings(std::string name); // TODO implement user input fields

    /*!
     * \brief defaultSettings
     */
    void defaultSettings();

private:
    Ui::DialogGameSettings *ui;
};
} //namespace
#endif // DIALOGGAMESETTINGS_HH
