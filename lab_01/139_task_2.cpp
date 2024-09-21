#include<iostream>
using namespace std;

class Temperature{
private:
    double value;
    string unit;

    bool isValid(double value, const string &unit){
        return (unit == "Celsius" && value >= -273.15) ||
               (unit == "Fahrenheit" && value >= -459.67) ||
               (unit == "Kelvin" && value >= 0);
    }

public:
    void assign(double value, const string unit){
        if(unit == "Celsius" || unit == "Fahrenheit" || unit == "Kelvin"){
            if(isValid(value, unit)){
                this->value = value;
                this->unit = unit;
            }else{
                cerr << "Error: Temperature value is below absolute temperature!\n";
            }
        }else{
            cerr << "Error: Invalid temperature unit!\n";
        }
    }

    double convert(const string &targetUnit) const{
        if(targetUnit == unit){
            return value;
        }

        double convertedValue;
        if(unit == "Celsius"){
            if(targetUnit == "Fahrenheit"){
                convertedValue = value * 9.0 / 5.0 + 32;
            }else if(targetUnit == "Kelvin"){
                convertedValue = value + 273.15;
            }
        }else if(unit == "Fahrenheit"){
            if(targetUnit == "Celsius"){
                convertedValue = (value - 32) * 5.0 / 9.0;
            }else if(targetUnit == "Kelvin") {
                convertedValue = (value - 32) * 5.0 / 9.0 + 273.15;
            }
        }else if(unit == "Kelvin"){
            if (targetUnit == "Celsius"){
                convertedValue = value - 273.15;
            }else if(targetUnit == "Fahrenheit"){
                convertedValue = (value - 273.15) * 9.0 / 5.0 + 32;
            }
        }

        return convertedValue;
    }

    void print() const{
        if(unit.empty()){
            cerr << "Error: Temperature is not assigned!\n";
            return;
        }
        cout << "The temperature is " << value << " " << unit << ".\n";
    }
};


int main(){ 
    Temperature T1;
    T1.assign(100, "Celsius");
    T1.print();
    cout << T1.convert("Kelvin") << '\n';

    return 0;
}
