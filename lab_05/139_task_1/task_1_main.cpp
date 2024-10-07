#include <iostream>
#include <random>
#include "task_1_class.h"

using namespace std;

void editInformationByKeyboard(SavingsAccount &account){
    string name, address;
    double interestRate, currentBalance;
    string tmp;
    cout << "Name: "; 
    for(int i = 0; i < 2; i++){
        string tmp; 
        cin >> tmp;
        name += " " + tmp;
    }
    cout << "Address: ";
    for(int i = 0; i < 4; i++){
        string tmp; 
        cin >> tmp;
        address += " " + tmp;
    }
    cout << "Interest Rate: ";  cin >> interestRate;
    cout << "Current Balance: "; cin >> currentBalance;
    account.setMembers(name, address, interestRate, currentBalance);
}

string randomString(){
    int sz = rand() % 7 + 4;
    string ret = "";
    for(int i = 0; i < sz; i++){
        ret += ('a' + rand() % 26);
    }
    return ret;
}

void generateInformaiotnRandom(SavingsAccount &account){
    string name = "", address = "";
    double interestRate, currentBalance;
    name = randomString() + " " + randomString();
    for(int i = 0; i < 4; i++){
        address += " " + randomString();
    }
    interestRate = (20.0 + rand() % 20 + 1) / 10;
    currentBalance = 1000 + rand() % 49001;
    account.setMembers(name, address, interestRate, currentBalance);
}

void ShowAllAlphabetically(vector<SavingsAccount> ar){
    sort(ar.begin(), ar.end(), [](SavingsAccount &a, SavingsAccount & b){
        return a.getName() > b.getName();
    });
    for(auto account: ar){
        cout << "Name: " << account.getName() << ' '
             << "Balance: " << account.getBalance() << '\n';
    }
}

void getDisbursedamount(vector<SavingsAccount> &ar){
    int n = ar.size();
    double totalAmount = 0;
    for(int i = 0; i < 100; i++){
        double  amount = ar[i].calculateInterest(3);
        cout << "Name: " << ar[i].getName() << ' '
             << "Current Balance: " << ar[i].getBalance() << ' '
             << "Interest Rate: " << ar[i].getInterestRate() << ' '
             << "Interest Amount: " << amount << '\n';
        totalAmount += amount;
    }
    cout << "Total disbursed amount: " << totalAmount << '\n';
    cout << "Afirm Confirmation (y / n)" << '\n';
    char confirm;
    cin >> confirm;
    if(confirm == 'y'){
        for(int i = 0; i < n; i++){
            ar[i].disburseInterest(3);
        }
    }
}

int main(){
    srand(time(0));
    vector<SavingsAccount> accounts(100);
    for(int i = 0; i < 0; i++){
        editInformationByKeyboard(accounts[i]);
    }
    for(int i = 0; i < 100; i++){
        generateInformaiotnRandom(accounts[i]);
    }
    getDisbursedamount(accounts);
    ShowAllAlphabetically(accounts);
}