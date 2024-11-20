#include <iostream>
#include <vector>

using namespace std;

class Vehicle{
    string license, manufacturer;
    float carriage;

public:
    Vehicle(string license, string manufacturer, float carriage) : license(license), manufacturer(manufacturer), carriage(carriage) {}
    virtual void maintenence() = 0;
};

class GasolineVehicle : virtual public Vehicle{
    float fuelCapacity;
    string fuelType;
public:
    GasolineVehicle(string license, string manufacturer, float carriage, float fuetCapacity, string fuelType) : Vehicle(license, manufacturer, carriage), fuelCapacity(fuelCapacity), fuelType(fuelType) {}
};

class ElectricVehicle : virtual public Vehicle{
    float batteryCapacity, chargingTime;
public:
    ElectricVehicle(string license, string manufacturer, float carriage, float batteryCapacity, float chargingTime) : Vehicle(license, manufacturer, carriage), batteryCapacity(batteryCapacity), chargingTime(chargingTime) {}
    void maintenence(){
        cout<<"Electric Vehicle - Maintenence"<<endl;
    }
};

class Motorcycle : public GasolineVehicle{
public:
    Motorcycle(string license, string manufacturer, float carriage, float fuetCapacity, string fuelType) : Vehicle(license, manufacturer, carriage), GasolineVehicle(license, manufacturer, carriage, fuetCapacity, fuelType) {}
    void maintenence(){
        cout<<"Motorcycle - Maintenence"<<endl;
    }
};

class Car : public GasolineVehicle{
    int passenger;
public:
    Car(string license, string manufacturer, float carriage, float fuetCapacity, string fuelType, int passenger) : Vehicle(license, manufacturer, carriage), GasolineVehicle(license, manufacturer, carriage, fuetCapacity, fuelType), passenger(passenger) {}
    void maintenence(){
        cout<<"Car - Maintenence"<<endl;
    }
};

class Truck : public GasolineVehicle{
float cargoCapacity;
public:
    Truck(string license, string manufacturer, float carriage, float fuetCapacity, string fuelType, float cargoCapacity) : Vehicle(license, manufacturer, carriage), GasolineVehicle(license, manufacturer, carriage, fuetCapacity, fuelType), cargoCapacity(cargoCapacity) {}
    void maintenence(){
        cout<<"Truck - Maintenence"<<endl;
    }
};

class HybridVehicle : public GasolineVehicle, public ElectricVehicle{
    float energyEfficiency;
public:
    HybridVehicle(string license, string manufacturer, float carriage, float fuetCapacity, string fuelType, float batteryCapacity, float chargingTime, float energyEfficiency) : Vehicle(license, manufacturer, carriage), GasolineVehicle(license, manufacturer, carriage, fuetCapacity, fuelType), ElectricVehicle(license, manufacturer, carriage, batteryCapacity, chargingTime), energyEfficiency(energyEfficiency) {}
    void maintenence(){
        cout<<"Hybrid Vehicle - Maintenence"<<endl;
    }
};



class Employee{
protected:
    string name;
    int ID;
public:
    Employee(string name, int ID) : name(name), ID(ID) {}
    virtual void introduce() = 0;
};

class Manager : public Employee{
public:
    Manager(string name, int ID) : Employee(name, ID) {}
    void introduce(){
        cout<<"Manager: Mr. "<<name<<endl;
    }
};

class Driver : public Employee{
public:
    Driver(string name, int ID) : Employee(name, ID) {}
    void introduce(){
        cout<<"Driver: "<<name<<endl;
    }

};

class Branch{
    vector<Vehicle*> vehicle;
    vector<Employee*> employee;
public:
    Branch() {}
    void addVehicle(Vehicle *v){
        vehicle.push_back(v);
    }
    void addEmployee(Employee *e){
        employee.push_back(e);
    }
    void introduceEmployee(){
        for(auto e: employee){
            e->introduce();
        }
        cout<<endl;
    }
    void maintenenceAllVehicle(){
        for(auto v: vehicle){
            v->maintenence();
        }
        cout<<endl;
    }
};

int main(){
    Branch gazipur;
    gazipur.addVehicle(new Car("GAZ123", "Toyota", 1500, 50, "Petrol", 5));
    gazipur.addVehicle(new Motorcycle("GAZ456", "Yamaha", 300, 15, "Petrol"));
    gazipur.addVehicle(new Truck("GAZ789", "Volvo", 5000, 200, "Diesel", 10000));
    gazipur.addVehicle(new ElectricVehicle("GAZ101", "Tesla", 2000, 85, 2.5));
    gazipur.addVehicle(new HybridVehicle("GAZ202", "Honda", 1800, 40, "Petrol", 50, 1.5, 0.8));

    gazipur.addEmployee(new Manager("Mahin", 220041238));
    gazipur.addEmployee(new Driver("Nakib", 220041220));
    
    gazipur.introduceEmployee();
    gazipur.maintenenceAllVehicle();
    return 0;
}