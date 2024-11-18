#ifndef TWOYEARMDS_H
#define TWOYEARMDS_H

#include <iostream>
#include <string>
#include "MonthlyDepositScheme.h"
using namespace std;

class TwoYearMDS : public MonthlyDepositScheme{
    float maximumInterest;
public:
    TwoYearMDS(string, float, float, float);
    float getMaximumInterest() const;
    void displayInfo() const;
};

#endif