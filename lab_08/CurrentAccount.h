#ifndef CURRENTACCOUNT_H
#define CURRENTACCOUNT_H

#include "Account.h"
#include <iostream>
#include <string>
using namespace std;

class CurrentAccount : public Account{
    const static int serviceCharge = 100;
    const static int accountPrefix = 100;
    static int nextAccount;
public:
    CurrentAccount(string, float);
    void displayInfo() const;
};

#endif