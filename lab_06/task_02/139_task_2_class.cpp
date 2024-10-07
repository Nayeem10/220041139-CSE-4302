#include "139_task_2_class.h"

float dis(float x, float y){
    return hypot(x, y);
}

float dis(float x1, float y1, float x2, float y2){
    return hypot(x1 - x2, y1 - y2);
}

Coordinate::Coordinate(): x(0), y(0){}
Coordinate::Coordinate(float x, float y): x(x), y(y) {}

float Coordinate::getDistance(){
    return dis(x, y);
}

void Coordinate::move_x(float increment){
    x += increment;
}

void Coordinate::move_y(float increment){
    y += increment;
}

void Coordinate::move(float incX, float incY){
    x += incX, y += incY;
}

float Coordinate::getX(){
    return x;
}

float Coordinate::getY(){
    return y;
}

Coordinate::~Coordinate(){

}

float Coordinate::operator-(Coordinate other){
    return dis(x, y, other.x, other.y);
}

bool operator>(Coordinate &a, Coordinate &b){
    return a.getDistance() > b.getDistance();
}

bool operator<(Coordinate &a, Coordinate &b){
    return a.getDistance() < b.getDistance();
}

bool operator>=(Coordinate &a, Coordinate &b){
    return a.getDistance() >= b.getDistance();
}

bool operator<=(Coordinate &a, Coordinate &b){
    return a.getDistance() <= b.getDistance();
}

bool operator==(Coordinate &a, Coordinate &b){
    return a.getDistance() == b.getDistance();
}

bool operator!=(Coordinate &a, Coordinate &b){
    return a.getDistance() != b.getDistance();
}

