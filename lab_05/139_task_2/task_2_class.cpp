#ifndef CLASS_H
#define CLASS_H

#include "class.h"

int convert(DOB d){
    return d.year * 365 + d.month * 30 + d.day;
}

Employee::Employee() : name("John Doe"), dateOfBirth({1, 1, 2002}),salary(10000) {}

void Employee::setName(string name){
    if(name.size() <= 2) return;
    this->name = name;
}
void Employee::setDateofBirth(DOB dateOfBirth){
    if(convert(dateOfBirth) > convert({9, 30, 2006})) return;
    this->dateOfBirth = dateOfBirth;
}

void Employee::setSalary(int salary){
    if(salary < 10000 || salary > 100000) return;
    this->salary = salary;
}

const string Employee::getName() const{
    return name;
}

const DOB Employee::getDateofBirth() const{
    return dateOfBirth;
}
const int Employee::getSalary() const{
    return salary;
}

void Employee::setInfo(){
    string name;
    DOB dateOfBirth;
    int salary;
    cout << "Name: "; cin >> name;
    setName(name);
    cout << "Date of Birth(MM / DD / YY): "; 
    cin >> dateOfBirth.month >> dateOfBirth.day >> dateOfBirth.year;
    setDateofBirth(dateOfBirth);
    cout << "Salary: "; cin >> salary;
    setSalary(salary);
}

void Employee::getInfo(){
    cout << "Name: "; cout << getName() << '\n';
    cout << "Date of Birth: ";
    DOB tmp = getDateofBirth();
    cout << tmp.month << " / " << tmp.day << " / " << tmp.year << '\n';
    cout << "Salary: " << getSalary() << '\n';
}

Employee Employee::compare(Employee other){
    if(convert(this->dateOfBirth) > convert(other.getDateofBirth())) return other;
    return *this;
}

#endif