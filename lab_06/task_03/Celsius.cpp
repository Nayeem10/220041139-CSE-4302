#include "Celsius.h"

const double zero = -273.15;

double convertFromFahrenheitToCelsius(double temp){
    return (temp - 32) * 5 / 9;
}

double convertFromKelvinToCelsius(double temp){
    return temp - 273.15;
}

Celsius::Celsius() : temp(0){}
Celsius::Celsius(double temp): temp(max(zero, temp)) {}
Celsius::Celsius(Kelvin other) {
    *this = other; 
}
Celsius::Celsius(Fahrenheit other){
    *this = other; 
}
double Celsius::getTemp(){
    return temp;
}

void Celsius::assign(double temp){
    if(temp < zero){
        cout << "Error: Temperature is below absolute zero temperature\n";
        return;
    }
    this->temp = temp;
}

void Celsius::display() const{
    cout <<"The temperature is " << temp << " Celsius.\n";
}

Celsius Celsius::operator=(Kelvin other){
    this->temp = convertFromKelvinToCelsius(other.getTemp());
    return *this;
}

Celsius Celsius::operator=(Fahrenheit other){
    this->temp = convertFromFahrenheitToCelsius(other.getTemp());
    return *this;
}