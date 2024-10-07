#ifndef KELVIN_H
#define KELVIN_H

#include <iostream>
#include "Celsius.h"
#include "Fahrenheit.h"

using namespace std;

class Celsius;
class Fahrenheit;

class Kelvin{
    double temp;
public:
    Kelvin();
    Kelvin(double);
    Kelvin(Fahrenheit);
    Kelvin(Celsius);

    double getTemp();
    void assign(double);
    void display() const;

    Kelvin operator=(Fahrenheit);
    Kelvin operator=(Celsius);
    
};

#endif