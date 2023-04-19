
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <chrono>
#include <thread>
#include "GPIO.h"
#include <QChar>
#include <QString>

using namespace std;

GPIOClass::GPIOClass() {
    this->gpionum = "4"; 
    //GPIO4 is default
}

GPIOClass::GPIOClass(string gnum) {
    this->gpionum = gnum;
    //Instatiate GPIOClass object for GPIO pin number "gnum"
}

GPIOClass::GPIOClass(QString gnum) {
    this->gpionum = gnum.toStdString();
}

int GPIOClass::export_gpio() {
    string export_str = "/sys/class/gpio/export";
    
    ofstream exportgpio;
    exportgpio.open(export_str.c_str()); 
    // Open "export" file. Convert C++ string to C string. Required for all Linux pathnames
    
    if (!exportgpio.is_open()) {
        cout << " OPERATION FAILED: Unable to export GPIO" << this->gpionum << "." << endl;
        return -1;
    }

    exportgpio << this->gpionum; 
    //write GPIO number to export
    
    exportgpio.close(); 
    //close export file
    
    return 0;
}

int GPIOClass::unexport_gpio() {
    string unexport_str = "/sys/class/gpio/unexport";

    ofstream unexportgpio(unexport_str.c_str()); 
    //Open unexport file
    
    if (!unexportgpio.is_open()) {
        cout << " OPERATION FAILED: Unable to unexport GPIO" << this->gpionum << "." << endl;
        return -1;
    }

    unexportgpio << this->gpionum; 
    //write GPIO number to unexport

    unexportgpio.close(); 
    //close unexport file

    return 0;
}

int GPIOClass::setdir_gpio(string dir){

    if (dir != "in" && dir != "out") return -2; //wrong input
    string setdir_str = "/sys/class/gpio/gpio" + this->gpionum + "/direction";

    ofstream setdirgpio(setdir_str.c_str()); 
    // open direction file for gpio

    if (!setdirgpio.is_open()){
        cout << " OPERATION FAILED: Unable to set direction of GPIO" << this->gpionum << " ." << endl;
        return -1;
    }

    setdirgpio << dir; 
    //write direction to direction file

    setdirgpio.close(); 
    // close direction file
        
    return 0;
}

int GPIOClass::setval_gpio(string val) {

    string setval_str =  "/sys/class/gpio/gpio" + this->gpionum + "/value";

    ofstream setvalgpio(setval_str.c_str()); 
    // open value file for gpio
        
    if (!setvalgpio.is_open()){
        cout <<  " OPERATION FAILED: Unable to set the value of GPIO" << this->gpionum << "." << endl;
        return -1;
    }

    setvalgpio << val ;
    //write value to value file

    setvalgpio.close();
    // close value file 

    return 0;
}

int GPIOClass::getval_gpio(string& val) {

    string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "/value";

    ifstream getvalgpio(getval_str.c_str());
    // open value file for gpio
    
    if (!getvalgpio.is_open()){ 
        cout << " OPERATION FAILED: Unable to get value of GPIO" << this->gpionum << "." << endl;
        return -1;
    }
    
    getvalgpio >> val ;  
    //read gpio value
    
    if (val != "0")
        val = "1";
    else
        val = "0";
    
    getvalgpio.close(); 
    //close the value file
    
    return 0;
}

// before using morseShort or morseLong user must have already exported given gpio pin and set it up as output
void GPIOClass::morseShort() {
    this->setval_gpio("1");
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    this->setval_gpio("0");
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void GPIOClass::morseLong() {
    this->setval_gpio("1");
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    this->setval_gpio("0");
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void GPIOClass::morseSeparator() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void GPIOClass::morsechar(QChar c) {
    // does different combination of morseshort and morselong signals depending on which letter it encodes
    // before calling this function, given gpio must be exported and set as output
    switch (c.unicode())
    {
    case ('A'):
        morseShort(); morseLong();
        morseSeparator();
        break;
    case ('B'):
        morseLong(); morseShort(); morseShort(); morseShort();
        morseSeparator();
        break;
    case ('C'):
        morseLong(); morseShort(); morseLong(); morseShort();
        morseSeparator();
        break;
    case ('D'):
        morseLong(); morseShort(); morseShort();
        morseSeparator();
        break;
    case ('E'):
        morseShort();
        morseSeparator();
        break;
    case ('F'):
        morseShort(); morseShort(); morseLong(); morseShort();
        morseSeparator();
        break;
    case ('G'):
        morseLong(); morseLong(); morseShort();
        morseSeparator();
        break;
    case ('H'):
        morseShort(); morseShort(); morseShort(); morseShort();
        morseSeparator();
        break;
    case ('I'):
        morseShort(); morseShort();
        morseSeparator();
        break;
    case ('J'):
        morseShort(); morseLong(); morseLong(); morseLong();
        morseSeparator();
        break;
    case ('K'):
        morseLong(); morseShort(); morseLong();
        morseSeparator();
        break;
    case ('L'):
        morseShort(); morseLong(); morseShort(); morseShort();
        morseSeparator();
        break;
    case ('M'):
        morseLong(); morseLong();
        morseSeparator();
        break;
    case ('N'):
        morseLong(); morseShort();
        morseSeparator();
        break;
    case('O'):
        morseLong(); morseLong(); morseLong();
        morseSeparator();
        break;
    case ('P'):
        morseShort(); morseLong(); morseLong(); morseShort();
        morseSeparator();
        break;
    case('Q'):
        morseLong(); morseLong(); morseShort(); morseLong();
        morseSeparator();
        break;
    case('R'):
        morseShort(); morseLong(); morseShort();
        morseSeparator();
        break;
    case('S'):
        morseShort(); morseShort(); morseShort();
        morseSeparator();
        break;
    case('T'):
        morseLong();
        morseSeparator();
        break;
    case ('U'):
        morseShort(); morseShort(); morseLong();
        morseSeparator();
        break;
    case ('V'):
        morseShort(); morseShort(); morseShort(); morseLong();
        morseSeparator();
        break;
    case ('W'):
        morseShort(); morseLong(); morseLong();
        morseSeparator();
        break;
    case ('X'):
        morseLong(); morseShort(); morseShort(); morseLong();
        morseSeparator();
        break;
    case ('Y'):
        morseLong(); morseShort(); morseLong(); morseLong();
        morseSeparator();
        break;
    case ('Z'):
        morseLong(); morseLong(); morseShort(); morseShort();
        morseSeparator();
        break;

    default:
        std::cerr << "Invalid input to fct GPIOClass::morsechar(char c)" << std::endl;
        break;
    }
}

string GPIOClass::get_gpionum(){
    return this->gpionum;
}