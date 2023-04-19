#include <QWidget>
#include <QGroupBox>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QComboBox>
#include <QLineEdit>
#include <QLabel>
#include <string>
#include "GPIO.h"

class WindowMorse : public QWidget
{
    Q_OBJECT

public:
    WindowMorse(QWidget* parent = 0) : QWidget(parent) {
        
        // constructs the whole window for morsecode mode
        QGroupBox* morseWinGroupbox = new QGroupBox(tr("morse code mode:"));
        QLabel* morseWinLabel = new QLabel(tr("Select GPIO pin:"));
        QComboBox* morseWinComboBox = new QComboBox;

        // adding all the GPIOs to the combobox
        morseWinComboBox->addItem(tr("gpio4")); //this is default
        morseWinComboBox->addItem(tr("gpio2"));
        morseWinComboBox->addItem(tr("gpio3"));
        morseWinComboBox->addItem(tr("gpio14"));
        morseWinComboBox->addItem(tr("gpio15"));
        morseWinComboBox->addItem(tr("gpio18"));
        morseWinComboBox->addItem(tr("gpio17"));
        morseWinComboBox->addItem(tr("gpio27"));
        morseWinComboBox->addItem(tr("gpio23"));
        morseWinComboBox->addItem(tr("gpio22"));
        morseWinComboBox->addItem(tr("gpio24"));
        morseWinComboBox->addItem(tr("gpio10"));
        morseWinComboBox->addItem(tr("gpio25"));
        morseWinComboBox->addItem(tr("gpio9"));
        morseWinComboBox->addItem(tr("gpio8"));
        morseWinComboBox->addItem(tr("gpio11"));
        morseWinComboBox->addItem(tr("gpio7"));
        morseWinComboBox->addItem(tr("gpio5"));
        morseWinComboBox->addItem(tr("gpio12"));
        morseWinComboBox->addItem(tr("gpio6"));
        morseWinComboBox->addItem(tr("gpio13"));
        morseWinComboBox->addItem(tr("gpio16"));
        morseWinComboBox->addItem(tr("gpio19"));
        morseWinComboBox->addItem(tr("gpio20"));
        morseWinComboBox->addItem(tr("gpio26"));
        morseWinComboBox->addItem(tr("gpio21"));

        // creating the lineedit widget
        morseWinLineEdit = new QLineEdit;
        morseWinLineEdit->setPlaceholderText("Write the text and hit enter:");
        morseWinLineEdit->setInputMask(">" + QString(50, 'a')); //    TODO set as per say 50 chars

        // arrange widgets into QGridLayout and set it as layout for QGroupBox
        QGridLayout* morseWinGridLayout = new QGridLayout;
        morseWinGridLayout->addWidget(morseWinLabel, 0,0);
        morseWinGridLayout->addWidget(morseWinComboBox, 0,1);
        morseWinGridLayout->addWidget(morseWinLineEdit, 1,0,1, 2);
        morseWinGroupbox->setLayout(morseWinGridLayout);

        // connect the change in QComboBox to approp slots
        connect(morseWinComboBox, QOverload<int>::of(&QComboBox::activated), this, &WindowMorse::GPIOchanged);

        // connect the returnpressed signal from lineedit to to slot in this window
        connect (morseWinLineEdit, &QLineEdit::returnPressed, this, &WindowMorse::readTextEntered);

        // setting the layout
        QVBoxLayout* layout = new QVBoxLayout;
        layout->addWidget(morseWinGroupbox);
        setLayout(layout);
    }

private:
    QString using_gpio = QString("gpio4"); //sets the default
    QLineEdit* morseWinLineEdit;

public slots:
    void GPIOchanged(int index) {
        switch (index)
        {
        case 0:
            using_gpio = QString("gpio4");
            break;
        case 1:
            using_gpio = QString("gpio2");
            break;
        case 2:
            using_gpio = QString("gpio3");
            break;
        case 3: 
            using_gpio = QString("gpio14");
            break;
        case 4:
            using_gpio = QString("gpio15");
            break;
        case 5:
            using_gpio = QString("gpio18");
            break;
        case 6:
            using_gpio = QString("gpio17");
            break;
        case 7:
            using_gpio = QString("gpio27");
            break;
        case 8:
            using_gpio = QString("gpio23");
            break;
        case 9:
            using_gpio = QString("gpio22");
            break;
        case 10:
            using_gpio = QString("gpio24");
            break;
        case 11:
            using_gpio = QString("gpio10");
            break;
        case 12:
            using_gpio = QString("gpio25");
            break;
        case 13:
            using_gpio = QString("gpio9");
            break;
        case 14:
            using_gpio = QString("gpio8");
            break;
        case 15:
            using_gpio = QString("gpio11");
            break;
        case 16:
            using_gpio = QString("gpio7");
            break;
        case 17:
            using_gpio = QString("gpio5");
            break;
        case 18:
            using_gpio = QString("gpio12");
            break;
        case 19:
            using_gpio = QString("gpio6");
            break;
        case 20:
            using_gpio = QString("gpio13");
            break;
        case 21:
            using_gpio = QString("gpio16");
            break;
        case 22:
            using_gpio = QString("gpio19");
            break;
        case 23:
            using_gpio = QString("gpio20");
            break;
        case 24:
            using_gpio = QString("gpio26");
            break;
        case 25:
            using_gpio = QString("gpio21");
            break;
        default:
            break;
        }
    }
    void readTextEntered() {  
        // creating a universal GPIOClass object
        QString setgpio = using_gpio.mid(4, 2);
        GPIOClass gpio_x = GPIOClass(setgpio);
        gpio_x.export_gpio();

        gpio_x.setdir_gpio("out");
        for (int  i = 0; i < morseWinLineEdit->text().size(); i++) {
            gpio_x.morsechar(morseWinLineEdit->text().at(i));
        }
        gpio_x.unexport_gpio();
    }
};