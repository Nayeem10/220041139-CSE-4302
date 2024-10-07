#include<iostream>
#include<string>
#include "task_2_class.h"

using namespace std;

int main(){
    Employee a, b;
    a.setInfo();
    b.setInfo();
    Employee c = a.compare(b);
    c.getInfo();
}