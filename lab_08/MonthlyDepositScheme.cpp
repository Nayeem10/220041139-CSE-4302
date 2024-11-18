#include "MonthlyDepositScheme.h"

int MonthlyDepositScheme::nextAccount = 1;
void MonthlyDepositScheme::setAccountInfo(string accountName, float balance, float interestRate){
    setAccountNo(accountPrefix, nextAccount);
    setName(accountName);
    setBalance(balance);
    this->interestRate = interestRate;
    nextAccount++;
}

int MonthlyDepositScheme::getNextAccountNo(){
    return nextAccount++;
}
float MonthlyDepositScheme::getInterestRate() const{
    return interestRate;
}