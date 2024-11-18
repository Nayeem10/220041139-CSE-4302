#include "InitialDepositMDS.h"

InitialDepositMDS::InitialDepositMDS(string accountName, float balance, float interestRate, float maximumInterest){
    setAccountInfo(accountName, balance, interestRate);
    this->maximumInterest = maximumInterest;
    this->initialDepositAmount = balance;
}
float InitialDepositMDS::getMaximumInterest() const{
    return maximumInterest;
}
float InitialDepositMDS::getInitialDepositAmount() const{
    return initialDepositAmount;
}
void InitialDepositMDS::displayInfo() const{
    cout<<"Initial Deposit MDS Plan\n";
    cout<<"Account No  "<<getAccountNo()<<'\n';
    cout<<"Holder Name "<<getName()<<'\n';
    cout<<"Balance "<<getBalance()<<'\n';
    cout<<"Interest Rate "<<getInterestRate()<<'\n';
    cout<<"Maximum Interest "<<getMaximumInterest()<<'\n';
}