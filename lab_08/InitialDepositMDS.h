#ifndef INITIALDEPOSITMDS_H
#define INITIALDEPOSITMDS_H

#include <iostream>
#include <string>
#include "MonthlyDepositScheme.h"
using namespace std;

class InitialDepositMDS : public MonthlyDepositScheme{
    float maximumInterest;
    float initialDepositAmount;
public:
    InitialDepositMDS(string, float, float, float);
    float getMaximumInterest() const;
    float getInitialDepositAmount() const;
    void displayInfo() const;
};

#endif