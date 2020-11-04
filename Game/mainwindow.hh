#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include "dialoggamesettings.hh"

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <iostream>
#include <memory>
#include <QVector>
#include <map>

namespace Ui {
class MainWindow;
}

namespace StudentSide {

/*!
 * \brief The mainwindow class
 */
class mainwindow : public QMainWindow
{
    Q_OBJECT

public:

    /*!
     * \brief mainwindow
     * \param parent
     */
    explicit mainwindow(QWidget *parent = nullptr);
    ~mainwindow();

public slots:

    /*!
     * \brief adjustGameSettings
     */
    void adjustGameSettings(std::string name);

    void defaultSettings();

private:
    Ui::MainWindow *ui_;
    QGraphicsScene *map;
    std::string playerName = "Timo";

    const int width_ = 500;
    const int height_ = 500;

};
} //namespace
#endif // MAINWINDOW_HH
