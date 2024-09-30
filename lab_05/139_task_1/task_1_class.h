#ifndef CLASS_H
#define CLASS_H

#include<algorithm>
#include<string>
#include<vector>
using namespace std;

class SavingsAccount{
    string name, address;
    double interestRate, currentBalance, minimumBalance;

public:
    SavingsAccount();
    void setMembers(string name, string address, double interestRate, double currentBalance){
        this->name = name;
        this->address = address;
        this->interestRate = interestRate;
        this->currentBalance = currentBalance;
        minimumBalance = currentBalance;
    }
    void deposit(int);
    void withdraw(int);
    string getName();
    double getBalance();
    double getInterestRate();
    double calculateInterest(int) const;
    void disburseInterest(int);
};

#endif