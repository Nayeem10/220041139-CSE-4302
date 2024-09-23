#include <iostream>
using namespace std;

enum bankAccountType{savings, deposit};

class BankAccount{
private:
    static double sourceTax;
    static int currentBankAccountCount;
    static int totalBankAccountCount;

    int accountNumber;
    string holderName;
    bankAccountType accountType;
    double currentBalance;
    const double minimumBalance;
    double interesrRate = .03, sourceTaxRate = .1;

public:
    BankAccount() : accountNumber(-1), holderName("untitled"), accountType(savings), currentBalance(0), minimumBalance(10) {
        totalBankAccountCount++;
        currentBankAccountCount++;
    }

    BankAccount(const int AccountNumber, const string HolderName, bankAccountType AcountType, const double CurrentBalance, const double MinimumBalance) : accountNumber(AccountNumber), holderName(HolderName), accountType(AcountType), currentBalance(CurrentBalance), minimumBalance(MinimumBalance) {
        totalBankAccountCount++;
        currentBankAccountCount++;
    }

    void reset(const int AccountNumber, const string HolderName, bankAccountType AcountType, const double CurrentBalance){
        accountNumber = AccountNumber;
        holderName = HolderName;
        accountType = AcountType;
        currentBalance = CurrentBalance;
    }

    void updateInterestRate(double newRate){
        interesrRate = newRate;
    }

    void showInfo() const {
        cout << "Account Number: " << accountNumber << '\n'
             << "Account Holder Name: " << holderName << '\n'
             << "Account Type: " << (accountType == 0 ? "Savings" : "Deposit") << '\n'
             << "Current Balance: " << currentBalance << '\n'
             << "Minimum Balance: " << minimumBalance <<'\n';
    }

    void showBalance() const {
        cout << "Current Balance: " << currentBalance << '\n';
    }

    int getBalance(){
        return currentBalance;
    }

    static int getTotalAccountCount(){
        return totalBankAccountCount;
    }

    static int getCurrentAccountCount(){
        return currentBankAccountCount;
    }

    static double getSourceTax(){
        return sourceTax;
    }

    void deposit(double amount){
        if(amount < 0){
            cout << "Only non negative amount allowed.\n";
            return;
        }
        currentBalance += amount;
    }

    void withdrawal(double amount){
        if(amount < 0){
            cout << "Only non negative amount allowed.\n";
            return;
        }
        if(currentBalance - amount < minimumBalance){
            cout << "Balance is too low.\n";
            return;
        }
        currentBalance -= amount;
    }

    void giveInterest(){
        double interest = currentBalance * interesrRate;
        sourceTax += interest * sourceTaxRate;
        interest *= (1 - sourceTaxRate);
        currentBalance += interest;
    }

    ~BankAccount(){
        cout << "Account of " << holderName << " with account no " << accountNumber << " is destroyed with a balance BDT " << currentBalance << '\n';
        currentBankAccountCount--;
    }
};

double BankAccount::sourceTax = 0;
int BankAccount::currentBankAccountCount = 0;
int BankAccount::totalBankAccountCount = 0;

void displayStat(){
    cout << "Total bank account created: " << BankAccount::getTotalAccountCount() << '\n'
         << "Currently bank account present: " << BankAccount::getCurrentAccountCount() << '\n'
         << "Total source tax collected: " << BankAccount::getSourceTax() << '\n';
}

BankAccount Larger(BankAccount a, BankAccount b){
    if(a.getBalance() > b.getBalance()) 
        return a;
    return b;
}

void dummy(){
    BankAccount x, y, z;
    displayStat();
}

int main(){
    BankAccount nayeem(101, "nayeem", savings, 1000, 10), b, c, d;
    BankAccount iut(101010, "IUT", deposit, 1000000, 100);
    nayeem.giveInterest();
    iut.giveInterest();
    iut.showInfo();
    dummy();
    displayStat();
}