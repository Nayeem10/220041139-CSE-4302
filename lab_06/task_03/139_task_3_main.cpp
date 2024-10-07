#include <iostream>
#include "Celsius.h"
#include "Fahrenheit.h"
#include "Kelvin.h"

using namespace std;

int main(){
    Celsius c(23);
    Kelvin k = c;
    k.display();
    Fahrenheit f(199);
    c = f;
    c.display();

}