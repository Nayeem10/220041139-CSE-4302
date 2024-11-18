#include "FiveYearMDS.h"

FiveYearMDS::FiveYearMDS(string accountName, float balance, float interestRate, float maximumInterest){
    setAccountInfo(accountName, balance, interestRate);
    this->maximumInterest = maximumInterest;
}
float FiveYearMDS::getMaximumInterest() const{
    return maximumInterest;
}
void FiveYearMDS::displayInfo() const{
    cout<<"Five Year MDS Plan\n";
    cout<<"Account No  "<<getAccountNo()<<'\n';
    cout<<"Holder Name "<<getName()<<'\n';
    cout<<"Balance "<<getBalance()<<'\n';
    cout<<"Interest Rate "<<getInterestRate()<<'\n';
}