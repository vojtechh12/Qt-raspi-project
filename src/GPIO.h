#ifndef GPIO_CLASS_H
#define GPIO_CLASS_H
#include <string>
#include <QChar>

using namespace std;

/* GPIO Class

* Purpose: Each object instantiated from this class will control a GPIO pin

* The GPIO pin number must be passed to the overloaded class constructor

*/
class GPIOClass
{
public:
    GPIOClass();  
    // create a GPIO object that controls GPIO4 (defaul)

    GPIOClass(string x); 
    // create a GPIO object that controls GPIOx, where x is passed to this constructor

    GPIOClass(QString x);
    // the same as above, but uses QString, is convenient in qt code

    int export_gpio(); 
    // exports GPIO

    int unexport_gpio(); 
    // unexport GPIO

    int setdir_gpio(string dir); 
    // Set GPIO Direction

    int setval_gpio(string val); 
    // Set GPIO Value (putput pins)

    int getval_gpio(string& val); 
    // Get GPIO Value (input/ output pins)

    string get_gpionum(); 
    // return the GPIO number associated with the instance of an object

    void morseShort();

    void morseLong();

    void morseSeparator();

    void morsechar(QChar c);

private:
    string gpionum; 
    // GPIO number associated with the instance of an object
    
};
#endif