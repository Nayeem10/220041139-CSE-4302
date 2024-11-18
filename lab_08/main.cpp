#include <iostream>
#include "CurrentAccount.h"
#include "SavingsAccount.h"
#include "LoanAccount.h"
#include "TwoYearMDS.h"
#include "FiveYearMDS.h"
#include "InitialDepositMDS.h"


int main(){
    InitialDepositMDS a("nayeem", 1000, 19, 1000);
    a.displayInfo();
    LoanAccount loan("hossain", 1000, 19);
    loan.displayInfo();
    CurrentAccount current("Ahad", 10000);
    CurrentAccount current2("Ahad", 989);
    current.displayInfo();
    current2.displayInfo();
}

