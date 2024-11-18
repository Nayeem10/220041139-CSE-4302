#ifndef MONTHLYDEPOSITSCHEMEACCOUNT_H
#define MONTHLYDEPOSITSCHEMEACCOUNT_H

#include <iostream>
#include <string>
#include "Account.h"
using namespace std;

class MonthlyDepositScheme : public Account{
    float interestRate;
    const static int accountPrefix = 300;
    static int nextAccount;
public:
    void setAccountInfo(string, float, float);
    int getNextAccountNo();
    float getInterestRate() const; 
};

#endif