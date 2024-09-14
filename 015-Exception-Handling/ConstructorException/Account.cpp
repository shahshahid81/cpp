#include "Account.h"

Account::Account(std::string name, double balance) 
    : name{name}, balance{balance} {
        // Here, we are throwing exception in constructor if the values provided are not valid.
        // However, the destructor for this won't be called so we need to properly clean up any resources if we had before throwing exception.
        if (balance < 0.0)
            throw IllegalBalanceException{};
}

bool Account::deposit(double amount) {
    if (amount < 0) 
        return false;
    else {
        balance += amount;
        return true;
    }
}

bool Account::withdraw(double amount) {
    if (balance-amount >=0) {
        balance-=amount;
        return true;
    } else
        return false;
}

 void Account::print(std::ostream &os) const {
    os.precision(2);
    os << std::fixed;
    os << "[Account: " << name << ": " << balance << "]";
}
