#include "SavingsAccount.h"

int SavingsAccount::nextAccount = 1;
SavingsAccount::SavingsAccount(string accountName, float balance, float interestRate) : interestRate(interestRate){
    setAccountNo(accountPrefix, nextAccount);
    setName(accountName);
    setBalance(balance);
    nextAccount++;
}
float SavingsAccount::getInterestRate() const{
    return interestRate;
}
void SavingsAccount::displayInfo() const{
    cout<<"Savings Account\n";
    cout<<"Account No  "<<getAccountNo()<<'\n';
    cout<<"Holder Name "<<getName()<<'\n';
    cout<<"Balance "<<getBalance()<<'\n';
    cout<<"Interest Rate "<<getInterestRate()<<'\n';
}