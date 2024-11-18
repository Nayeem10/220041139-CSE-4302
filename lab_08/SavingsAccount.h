#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include <iostream>
#include <string>
#include "Account.h"
using namespace std;

class SavingsAccount : public Account{
    float interestRate;
    const static int accountPrefix = 200;
    static int nextAccount;
public:
    SavingsAccount(string, float, float);
    float getInterestRate() const;
    void displayInfo() const;
};

#endif