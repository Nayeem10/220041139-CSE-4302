#ifndef CLASS_H
#define CLASS_H

#include<iostream>
#include<math.h>
using namespace std;

class Coordinate{
    float x, y;
public:
    Coordinate();
    Coordinate(float, float);
    float getDistance();
    void move_x(float);
    void move_y(float);
    void move(float, float);
    float getX();
    float getY();
    ~Coordinate();

    float operator-(Coordinate);

    friend bool operator>(Coordinate&, Coordinate&);
    friend bool operator<(Coordinate&, Coordinate&);
    friend bool operator>=(Coordinate&, Coordinate&);
    friend bool operator<=(Coordinate&, Coordinate&);
    friend bool operator==(Coordinate&, Coordinate&);
    friend bool operator!=(Coordinate&, Coordinate&);
};

#endif