#include "CurrentAccount.h"

int CurrentAccount::nextAccount = 1;
CurrentAccount::CurrentAccount(string accountName = "Untitled", float balance = 0) {
    setAccountNo(accountPrefix, nextAccount);
    setName(accountName);
    setBalance(balance);
    nextAccount++;
}
void CurrentAccount::displayInfo() const{
    cout<<"Current Account\n";
    cout<<"Account No  "<<getAccountNo()<<'\n';
    cout<<"Holder Name "<<getName()<<'\n';
    cout<<"Balance "<<getBalance()<<'\n';
}