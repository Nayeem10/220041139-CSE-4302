#include "Account.h"

float Account::getBalance() const{
    return balance;
}
string Account::getName() const{
    return accountName;
}
string Account::getAccountNo() const{
    return accountNo;
}
void Account::setBalance(float balance){
    this->balance = balance;
}
void Account::setName(string accountName){
    this->accountName = accountName;
}
void Account::setAccountNo(int pre, int next){
    accountNo = to_string(pre) + "-" + to_string(next);
}

