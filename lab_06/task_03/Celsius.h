#ifndef CELSIUS_H
#define CELSIUS_H

#include <iostream>
#include "Fahrenheit.h"
#include "Kelvin.h"

class Fahrenheit;
class Kelvin;

using namespace std;

class Celsius{
    double temp;
public:
    Celsius();
    Celsius(double);
    Celsius(Fahrenheit);
    Celsius(Kelvin);

    double getTemp();
    void assign(double);
    void display() const;

    Celsius operator=(Kelvin);
    Celsius operator=(Fahrenheit);

};

#endif