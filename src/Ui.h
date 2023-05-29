#include <QWidget>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QStackedWidget>
#include <libssh/libssh.h>
#include "WindowGpioControl.h"
#include "WindowMorse.h"

class Ui : public QMainWindow
{
    Q_OBJECT
public:
    Ui(QMainWindow* parent = nullptr) : QMainWindow(parent) {
    
    // creating menu()
    QMenuBar* bar = this->menuBar();
    QMenu* menu = bar->addMenu("&mode");
    
    // adding actions to the menu(mode) in menubar
    QAction* gpiocAction = new QAction("gpio-control");
    QAction* morsecAction = new QAction("morsecode");
    menu->addAction(gpiocAction);
    menu->addSeparator();
    menu->addAction(morsecAction);

    // creting a centralwidget that will later contain all the other widgets within itself
    // also creating gpiocontrol and morsecode custom widgets
    QWidget* centralw = new QWidget;
    WindowGpioControl* gpiocontrol = new WindowGpioControl();
    WindowMorse* morsecode = new WindowMorse();

    // adding both custom WindowWidgets gpiocontrol and morsecode into stackedwidget
    QStackedWidget* stackedw = new QStackedWidget;
    stackedw->addWidget(gpiocontrol);
    stackedw->addWidget(morsecode);

    // setting the stackedwidget up as the layout for centralwidget
    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(stackedw);
    centralw->setLayout(layout);

    //finally setting the centralwidget that now contains all the others as the CentralWidget of this custom Mainwindow
    this->setCentralWidget(centralw);

    // connecting menu actions with changing of the current visible widget
    connect(morsecAction, &QAction::triggered, [=] () {
        stackedw->setCurrentWidget(morsecode);
    });
    connect(gpiocAction, &QAction::triggered, [=] () {
        stackedw->setCurrentWidget(gpiocontrol);
    });
    }
};