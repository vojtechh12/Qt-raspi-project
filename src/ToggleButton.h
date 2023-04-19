#include <QPushButton>
#include <QAbstractButton>
#include "GPIO.h"


class ToggleButton : public QPushButton
{
    Q_OBJECT


public:
    ToggleButton(QWidget * parent = 0) : QPushButton (parent)
    {
        setStyleSheet("background-color: grey;");
    }
    ToggleButton(const QString &text, QWidget *parent = 0) : QPushButton(text, parent) 
    { 
        this->setCheckable(true);
        setStyleSheet("background-color: grey;");
        this->setMinimumSize(40,5);
        setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    }

public slots: 
    void did_toggle(bool checked) {
        // creating a universal GPIOClass object
        QString setgpio = this->text().mid(4, 2);
        GPIOClass gpio_x = GPIOClass(setgpio);

        if (checked) { 
            this->setStyleSheet("background-color: green;");
            gpio_x.export_gpio();
            gpio_x.setdir_gpio("out");
            gpio_x.setval_gpio("1");

        }
        else { 
            this->setStyleSheet("background-color: grey;");
            gpio_x.unexport_gpio();
        }
    }

};