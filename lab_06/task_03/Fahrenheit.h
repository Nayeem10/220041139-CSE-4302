#ifndef FAHRENHEIT_H
#define FAHRENHEIT_H

#include <iostream>
#include "Celsius.h"
#include "Kelvin.h"

using namespace std;

class Celsius;
class Kelvin;

class Fahrenheit{
    double temp;
public:
    Fahrenheit();
    Fahrenheit(double);
    Fahrenheit(Kelvin);
    Fahrenheit(Celsius);

    double getTemp();
    void assign(double);
    void display() const;

    Fahrenheit operator=(Kelvin);
    Fahrenheit operator=(Celsius);
    
};

#endif