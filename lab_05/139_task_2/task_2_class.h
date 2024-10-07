#ifndef CLASS_H
#define CLASS_H

#include<iostream>
#include<string>
using namespace std;

struct DOB{
    int month, day, year;
};

class Employee{
    string name;
    DOB dateOfBirth;
    int salary;

public:
    Employee();
    void setName(string);
    void setDateofBirth(DOB);
    void setSalary(int);
    const string getName() const;
    const DOB getDateofBirth() const;
    const int getSalary() const;
    void setInfo();
    void getInfo();
    Employee compare(Employee);
};

#endif