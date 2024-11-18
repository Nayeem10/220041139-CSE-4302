#ifndef FIVEYEARMDS_H
#define FIVEYEARMDS_H

#include <iostream>
#include <string>
#include "MonthlyDepositScheme.h"
using namespace std;

class FiveYearMDS : public MonthlyDepositScheme{
    float maximumInterest;
public:
    FiveYearMDS(string, float, float, float);
    float getMaximumInterest() const;
    void displayInfo() const;
};

#endif