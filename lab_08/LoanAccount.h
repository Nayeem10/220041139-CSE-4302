#ifndef LOANACCOUNT_H
#define LOANACCOUNT_H

#include <iostream>
#include <string>
#include "Account.h"
using namespace std;

class LoanAccount : public Account{
    float interestRate;
    const static int accountPrefix = 900;
    static int nextAccount;
public:
    LoanAccount(string, float, float);
    float getInterestRate() const;
    void displayInfo() const;
};

#endif