#include "Fahrenheit.h"

const double zero = -459.67;

double convertFromCelsiusToFahrenheit(double temp){
    return temp * 9 / 5 + 32;
}

double convertFromKelvinToFahrenheit(double temp){
    return temp - 273.15 * 9 / 5 + 32;
}

Fahrenheit::Fahrenheit() : temp(0){}
Fahrenheit::Fahrenheit(double temp): temp(max(zero, temp)) {}
Fahrenheit::Fahrenheit(Celsius other){
    *this = other; 
}
Fahrenheit::Fahrenheit(Kelvin other){
    *this = other; 
}

double Fahrenheit::getTemp(){
    return temp;
}

void Fahrenheit::assign(double temp){
    if(temp < zero){
        cout << "Error: Temperature is below absolute zero temperature\n";
        return;
    }
    this->temp = temp;
}

void Fahrenheit::display() const{
    cout <<"The temperature is " << temp << " Fahrenheit.\n";
}

Fahrenheit Fahrenheit::operator=(Kelvin other){
    this->temp = convertFromKelvinToFahrenheit(other.getTemp());
    return *this;
}

Fahrenheit Fahrenheit::operator=(Celsius other){
    this->temp = convertFromCelsiusToFahrenheit(other.getTemp());
    return *this;
}