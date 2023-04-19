#include <QWidget>
#include <QGroupBox>
#include <QGridLayout>
#include <QVBoxLayout>
#include "GPIO.h"
#include "ToggleButton.h"

class WindowGpioControl : public QWidget
{
    Q_OBJECT

public:
    WindowGpioControl(QWidget* parent = nullptr) : QWidget(parent) {
        
        // creating groupbox that will contain all the togglebuttons
        QGroupBox* gpiocWinGroupBox = new QGroupBox(tr("GPIO control mode:"));
        QGridLayout* glayout = new QGridLayout(gpiocWinGroupBox);

        // creating toggle buttons one for each gpio pin TODO!!! the rest, this is BETA
        ToggleButton* b1 = new ToggleButton("5V"); b1->setStyleSheet("background-color: red; color: black;");
        ToggleButton* b2 = new ToggleButton("3V3"); b2->setStyleSheet("background-color: orange; color: black;");
        ToggleButton* b3 = new ToggleButton("5V"); b3->setStyleSheet("background-color: red; color: black;");
        ToggleButton* b4 = new ToggleButton("gpio2");
        ToggleButton* b5 = new ToggleButton("GND"); b5->setStyleSheet("background-color: black; color: white;");
        ToggleButton* b6 = new ToggleButton("gpio3");
        ToggleButton* b7 = new ToggleButton("gpio14");
        ToggleButton* b8 = new ToggleButton("gpio4");
        ToggleButton* b9 = new ToggleButton("gpio15");
        ToggleButton* b10 = new ToggleButton("GND"); b10->setStyleSheet("background-color: black; color: white;");
        ToggleButton* b11 = new ToggleButton("gpio18");
        ToggleButton* b12 = new ToggleButton("gpio17");
        ToggleButton* b13 = new ToggleButton("GND"); b13->setStyleSheet("background-color: black; color: white;");
        ToggleButton* b14 = new ToggleButton("gpio27");
        ToggleButton* b15 = new ToggleButton("gpio23");
        ToggleButton* b16 = new ToggleButton("gpio22");
        ToggleButton* b17 = new ToggleButton("gpio24");
        ToggleButton* b18 = new ToggleButton("3V3"); b18->setStyleSheet("background-color: orange; color: black;");
        ToggleButton* b19 = new ToggleButton("GND"); b19->setStyleSheet("background-color: black; color: white;");
        ToggleButton* b20 = new ToggleButton("gpio10");
        ToggleButton* b21 = new ToggleButton("gpio25");
        ToggleButton* b22 = new ToggleButton("gpio9");
        ToggleButton* b23 = new ToggleButton("gpio8");
        ToggleButton* b24 = new ToggleButton("gpio11");
        ToggleButton* b25 = new ToggleButton("gpio7");
        ToggleButton* b26 = new ToggleButton("GND"); b26->setStyleSheet("background-color: black; color: white;");
        // PINS ph. 27 & 28 arse reserved for advanced use only and will be skipped comletely
        ToggleButton* b29 = new ToggleButton("GND"); b29->setStyleSheet("background-color: black; color: white;");
        ToggleButton* b30 = new ToggleButton("gpio5");
        ToggleButton* b31 = new ToggleButton("gpio12");
        ToggleButton* b32 = new ToggleButton("gpio6");
        ToggleButton* b33 = new ToggleButton("GND"); b33->setStyleSheet("background-color: black; color: white;");
        ToggleButton* b34 = new ToggleButton("gpio13");
        ToggleButton* b35 = new ToggleButton("gpio16");
        ToggleButton* b36 = new ToggleButton("gpio19");
        ToggleButton* b37 = new ToggleButton("gpio20");
        ToggleButton* b38 = new ToggleButton("gpio26");
        ToggleButton* b39 = new ToggleButton("gpio21");
        ToggleButton* b40 = new ToggleButton("GND"); b40->setStyleSheet("background-color: black; color: white;");


        // arranging the buttons into a desired layout
        glayout->addWidget(b1, 0,0);
        glayout->addWidget(b2, 1,0);
        glayout->addWidget(b3, 0,1);
        glayout->addWidget(b4, 1,1);
        glayout->addWidget(b5, 0,2);
        glayout->addWidget(b6, 1,2);
        glayout->addWidget(b7, 0,3);
        glayout->addWidget(b8, 1,3);
        glayout->addWidget(b9, 0,4);
        glayout->addWidget(b10, 1,4);
        glayout->addWidget(b11, 0,5);
        glayout->addWidget(b12, 1,5);
        glayout->addWidget(b13, 0,6);
        glayout->addWidget(b14, 1,6);
        glayout->addWidget(b15, 0,7);
        glayout->addWidget(b16, 1,7);
        glayout->addWidget(b17, 0,8);
        glayout->addWidget(b18, 1,8);
        glayout->addWidget(b19, 0,9);
        glayout->addWidget(b20, 1,9);
        glayout->addWidget(b21, 0,10);
        glayout->addWidget(b22, 1,10);
        glayout->addWidget(b23, 0,11);
        glayout->addWidget(b24, 1,11);
        glayout->addWidget(b25, 0,12);
        glayout->addWidget(b26, 1,12);
        glayout->addWidget(b29, 0,13);
        glayout->addWidget(b30, 1,13);
        glayout->addWidget(b31, 0,14);
        glayout->addWidget(b32, 1,14);
        glayout->addWidget(b33, 0,15);
        glayout->addWidget(b34, 1,15);
        glayout->addWidget(b35, 0,16);
        glayout->addWidget(b36, 1,16);
        glayout->addWidget(b37, 0,17);
        glayout->addWidget(b38, 1,17);
        glayout->addWidget(b39, 0,18);
        glayout->addWidget(b40, 1,18);

        // connecting the toggled signal from the buttons to appropriate slot
        QObject::connect(b4, &QAbstractButton::toggled, b4, &ToggleButton::did_toggle);
        QObject::connect(b6, &QAbstractButton::toggled, b6, &ToggleButton::did_toggle);
        QObject::connect(b7, &QAbstractButton::toggled, b7, &ToggleButton::did_toggle);
        QObject::connect(b8, &QAbstractButton::toggled, b8, &ToggleButton::did_toggle);
        QObject::connect(b9, &QAbstractButton::toggled, b9, &ToggleButton::did_toggle);
        QObject::connect(b11, &QAbstractButton::toggled, b11, &ToggleButton::did_toggle);
        QObject::connect(b12, &QAbstractButton::toggled, b12, &ToggleButton::did_toggle);
        QObject::connect(b14, &QAbstractButton::toggled, b14, &ToggleButton::did_toggle);
        QObject::connect(b15, &QAbstractButton::toggled, b15, &ToggleButton::did_toggle);
        QObject::connect(b16, &QAbstractButton::toggled, b16, &ToggleButton::did_toggle);
        QObject::connect(b17, &QAbstractButton::toggled, b17, &ToggleButton::did_toggle);
        QObject::connect(b20, &QAbstractButton::toggled, b20, &ToggleButton::did_toggle);
        QObject::connect(b21, &QAbstractButton::toggled, b21, &ToggleButton::did_toggle);
        QObject::connect(b22, &QAbstractButton::toggled, b22, &ToggleButton::did_toggle);
        QObject::connect(b23, &QAbstractButton::toggled, b23, &ToggleButton::did_toggle);
        QObject::connect(b24, &QAbstractButton::toggled, b24, &ToggleButton::did_toggle);
        QObject::connect(b25, &QAbstractButton::toggled, b25, &ToggleButton::did_toggle);
        QObject::connect(b30, &QAbstractButton::toggled, b30, &ToggleButton::did_toggle);
        QObject::connect(b31, &QAbstractButton::toggled, b31, &ToggleButton::did_toggle);
        QObject::connect(b32, &QAbstractButton::toggled, b32, &ToggleButton::did_toggle);
        QObject::connect(b34, &QAbstractButton::toggled, b34, &ToggleButton::did_toggle);
        QObject::connect(b35, &QAbstractButton::toggled, b35, &ToggleButton::did_toggle);
        QObject::connect(b36, &QAbstractButton::toggled, b36, &ToggleButton::did_toggle);
        QObject::connect(b37, &QAbstractButton::toggled, b37, &ToggleButton::did_toggle);
        QObject::connect(b38, &QAbstractButton::toggled, b38, &ToggleButton::did_toggle);
        QObject::connect(b39, &QAbstractButton::toggled, b39, &ToggleButton::did_toggle);

        // setting up the layout
        QVBoxLayout* layout = new QVBoxLayout;
        layout->addWidget(gpiocWinGroupBox);
        setLayout(layout);
    }
};