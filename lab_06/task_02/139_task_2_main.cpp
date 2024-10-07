#include<iostream>
#include<vector>
#include<algorithm>
#include<time.h>
#include "139_task_2_class.h"

using namespace std;

void randomAssignment(vector<Coordinate> &c){
    for(auto &coordinate: c){
        coordinate = Coordinate(rand() % 5000 - rand() % 5000, rand() %5000 - rand() % 5000);
    }
}

void heightest(vector<Coordinate> &c){
    float mx = 0;
    Coordinate a, b;
    for(int i = 0; i < c.size(); i++){
        for(int j = i + 1; j < c.size(); j++){
            float dis = c[i] - c[j];
            if(dis > mx){
                mx = dis;
                a = c[i], b = c[j];
            }
        }
    }
    cout << "Heightest distance " << mx << " between " << a.getX() << " "<<a.getY() << " and " << b.getX() << ' ' << b.getY() << '\n';
}

void lowest(vector<Coordinate> &c){
    float mn = 1e9;
    Coordinate a, b;
    for(int i = 0; i < c.size(); i++){
        for(int j = i + 1; j < c.size(); j++){
            float dis = c[i] - c[j];
            if(dis < mn){
                mn = dis;
                a = c[i], b = c[j];
            }
        }
    }
    cout << "Lowest distance " << mn << " between " << a.getX() << " "<<a.getY() << " and " << b.getX() << ' ' << b.getY() << '\n';
}

int main(){
    vector<Coordinate> coordinates(10);
    randomAssignment(coordinates);
    heightest(coordinates);
    lowest(coordinates);

    sort(coordinates.begin(), coordinates.end());
    cout << "Sorted order\n";
    for(int i = 0; i < coordinates.size(); i++){
        cout<<coordinates[i].getX() << " " << coordinates[i].getY() << " " << coordinates[i].getDistance() << '\n';
    }

}