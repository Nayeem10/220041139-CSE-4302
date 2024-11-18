#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
using namespace std;

class Account{
    string accountNo;
    string accountName;
    float balance;
    static int next;
public:

    float getBalance() const;
    string getName() const;
    string getAccountNo() const;
    void setAccountNo(int, int);
    void setBalance(float);
    void setName(string);
};

#endif