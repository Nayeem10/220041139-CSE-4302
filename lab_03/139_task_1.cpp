#include<iostream>
using namespace std;

class Counter{
private:
    int count, incrementSteps = 0;

public:
    void setIncrementStep(int val){ 
        incrementSteps = val;
    }
    void resetCount(){
        count = 0;
    }
    void increment(){
        count += incrementSteps;
    }
    int getCount(){
        return count;
    }
};


int main(){ 
    Counter a; 
    a.setIncrementStep(10); 
    a.increment();
    cout << a.getCount() << '\n';

    return 0;
}