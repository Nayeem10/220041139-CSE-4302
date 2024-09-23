#include <iostream>
using namespace std;

class Calculator{
private:
    int status;
    
public:
    Calculator() : status(0) {}
    Calculator(int value) : status(value) {}

    int getStatus(){
        return status;
    }

    void setStatus(int status){
        this->status = status;
    }

    void add(const int value){
        status += value;
    }

    void substract(const int value){
        status -= value;
    }

    void multiply(const int value){
        status *= value;
    };

    int divideBy(const int value){
        if(value == 0){
            cout << "Invalid Arithmatic Operation!\n";
            return 0;
        }
        int rem = status % value;
        status /= value;
        return rem;
    }

    void display() const{
        cout << "Calculator display : " << status << '\n';
    }

    void clear(){
        status = 0;
    }

    ~Calculator(){
        cout << "Destructor of Calculator class is called\n";
    }
};

int main(){
    Calculator dummy;
    dummy.add(10);
    dummy.display();
    dummy.divideBy(0);
}