#include "TwoYearMDS.h"

TwoYearMDS::TwoYearMDS(string accountName, float balance, float interestRate, float maximumInterest){
    setAccountInfo(accountName, balance, interestRate);
    this->maximumInterest = maximumInterest;
}
float TwoYearMDS::getMaximumInterest() const{
    return maximumInterest;
}
void TwoYearMDS::displayInfo() const{
    cout<<"Two Year MDS Plan\n";
    cout<<"Account No  "<<getAccountNo()<<'\n';
    cout<<"Holder Name "<<getName()<<'\n';
    cout<<"Balance "<<getBalance()<<'\n';
    cout<<"Interest Rate "<<getInterestRate()<<'\n';
}