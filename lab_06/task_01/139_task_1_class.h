#ifndef CLASS_H
#define CLASS_H

#include <iostream>
using namespace std;

class Counter{
    int count, steps;

public:

    Counter();
    Counter(int, int);
    void setIncrementSteps(int);

    int getCount();
    int getSteps();
    void increment();

    void resetCount(int);

    Counter operator+(Counter);
    Counter operator++();
    Counter operator++(int);
    Counter operator+=(Counter);
    friend bool operator>(Counter&, Counter&);
    friend bool operator<(Counter&, Counter&);
    friend bool operator>=(Counter&, Counter&);
    friend bool operator<=(Counter&, Counter&);
    friend bool operator==(Counter&, Counter&);
    friend bool operator!=(Counter&, Counter&);
    
};

#endif