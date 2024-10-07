#include<iostream>
#include "139_task_1_class.h"

using namespace std;

int main(){
    Counter a, b;
    a.setIncrementSteps(5);
    a.increment();
    b.setIncrementSteps(5);
    b.increment();
    b.increment();
    Counter c = a + b;
    ++c; c++;
    c.setIncrementSteps(b.getSteps());
    cout<<b.getCount()<<'\n';
    c += (b++);
    cout << c.getCount()<<'\n';
    if(b > a) cout<<"Yes\n";
}