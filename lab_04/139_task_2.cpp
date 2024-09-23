#include <iostream>
using namespace std;

class Flight{
private:
    int flightNum;
    string destination;
    double distance, maxFuelCapacity;

    double callFuel(){
        if(distance <= 1000) return 500;
        if(distance <= 2000) return 1100;
        return 2200;
    }

public:
    Flight() : flightNum(-1), destination("untitled"), distance(0), maxFuelCapacity(0) {};
    Flight(const int FlightNum, const string Destination, const float Distance, const double MaxFuelCapacity) : flightNum(FlightNum), destination(Destination), distance(Distance), maxFuelCapacity(MaxFuelCapacity) {};

    void feedInfo(){
        cout << "Flight Number: ";      cin >> flightNum;
        cout << "Destination: ";        cin >> destination;
        cout << "Distance: ";           cin >> distance;
        cout << "Max Fuel Capacity: ";  cin >> maxFuelCapacity;
    }

    void showInfo(){
        cout << "Flight Number: " << flightNum << '\n'
             << "Destination: " << destination << '\n'
             << "Distance: " << distance << '\n'
             << "Max Fuel Capacity: " << maxFuelCapacity << '\n'
             << (callFuel() <= maxFuelCapacity ? "Fuel capacity is fit for this flight distance." : "Not sufficient fuel capacity for this flight.") << '\n';
    }

    ~Flight() {}
};

int main(){
    Flight toDhaka(101, "Dhaka", 1000, 100000);
    toDhaka.showInfo();

}