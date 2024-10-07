#include "task_1_class.h"
#include <iostream>
using namespace std;

SavingsAccount::SavingsAccount(){
    name = "untiled";
    address = "";
    interestRate = 0;
    currentBalance = 0;
    minimumBalance = 0;
}

void SavingsAccount::deposit(int amount){
    if(amount <= 0) return;
    currentBalance += amount;
}

void SavingsAccount::withdraw(int amount){
    if(amount < currentBalance || amount <= 0){
        cout << "Not enough balance\n";
        return;
    }
    currentBalance -= amount;
    minimumBalance = min(minimumBalance, currentBalance);
}

string SavingsAccount::getName(){
    return name;
}

double SavingsAccount::getBalance(){
    return currentBalance;
}

double SavingsAccount::getInterestRate(){
    return interestRate;
}

double SavingsAccount::calculateInterest(int periodInMonths) const{
    return minimumBalance * interestRate * periodInMonths / 1200.00;
}

void SavingsAccount::disburseInterest(int periodInMonths){
    double interest = calculateInterest(periodInMonths);
    currentBalance += interest;
    minimumBalance = currentBalance;
}

