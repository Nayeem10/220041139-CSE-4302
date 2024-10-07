#include "Kelvin.h"

const double zero = 0;

double convertFromCelsiusToKelvin(double temp){
    return temp + 273.15;
}

double convertFromFahreneitToKelvin(double temp){
    return (temp - 32) * 5 / 9 + 273.15;
}

Kelvin::Kelvin() : temp(0){}
Kelvin::Kelvin(double temp): temp(max(zero, temp)) {}
Kelvin::Kelvin(Celsius other){
    *this = other; 
}
Kelvin::Kelvin(Fahrenheit other){
    *this = other; 
}

double Kelvin::getTemp(){
    return temp;
}

void Kelvin::assign(double temp){
    if(temp < zero){
        cout << "Error: Temperature is below absolute zero temperature\n";
        return;
    }
    this->temp = temp;
}

void Kelvin::display() const{
    cout <<"The temperature is " << temp << " Kelvin.\n";
}

Kelvin Kelvin::operator=(Fahrenheit other){
    this->temp = convertFromFahreneitToKelvin(other.getTemp());
    return *this;
}

Kelvin Kelvin::operator=(Celsius other){
    this->temp = convertFromCelsiusToKelvin(other.getTemp());
    return *this;
}