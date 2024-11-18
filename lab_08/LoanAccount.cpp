#include "LoanAccount.h"

int LoanAccount::nextAccount = 1;
LoanAccount::LoanAccount(string accountName, float balance, float interestRate) : interestRate(interestRate){
    setAccountNo(accountPrefix, nextAccount);
    setName(accountName);
    setBalance(balance);
    nextAccount++;
}
float LoanAccount::getInterestRate() const{
    return interestRate;
}
void LoanAccount::displayInfo() const{
    cout<<"Loan Account\n";
    cout<<"Account No  "<<getAccountNo()<<'\n';
    cout<<"Holder Name "<<getName()<<'\n';
    cout<<"Balance "<<getBalance()<<'\n';
    cout<<"Interest Rate "<<getInterestRate()<<'\n';
}