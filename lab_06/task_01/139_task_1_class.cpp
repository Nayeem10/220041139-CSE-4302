#include "139_task_1_class.h"

Counter::Counter(): count(0), steps(1){}
Counter::Counter(int count, int steps): count(count), steps(steps){
    if(this->steps < 0) this->steps = 1;
}

void Counter::setIncrementSteps(int steps){
    if(steps < 0){
        cout << "Error: Increment steps cannot be is negative\n";
        return;
    }
    this->steps = steps;
}

int Counter::getCount(){
    return count;
}

int Counter::getSteps(){
    return steps;
}

void Counter::increment(){
    count += steps;
}

void Counter::resetCount(int steps = 1){
    count = 0;
    if(steps >= 0) this->steps = steps;
}

Counter Counter::operator+(Counter other){
    if(other.steps != this->steps){
        cout<<"Increment step is not same\n";
        return Counter();
    }
    return Counter(this->count + other.count, this->steps + other.steps);
}

Counter Counter::operator++(){
    count++;
    return *this;
}

Counter Counter::operator++(int other){
    this->count++;
    return *this;
}

Counter Counter::operator+=(Counter other){
    return *this = *this + other;
}

bool operator>(Counter &a, Counter &b){
    return a.getCount() > b.getCount();
}

bool operator<(Counter &a, Counter &b){
    return a.getCount() < b.getCount();
}

bool operator>=(Counter &a, Counter &b){
    return a.getCount() >= b.getCount();
}

bool operator<=(Counter &a, Counter &b){
    return a.getCount() <= b.getCount();
}
bool operator==(Counter &a, Counter &b){
    return a.getCount() == b.getCount();
}

bool operator!=(Counter &a, Counter &b){
    return a.getCount() != b.getCount();
}
