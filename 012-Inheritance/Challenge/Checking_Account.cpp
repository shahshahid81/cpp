#include <iostream>
#include "Checking_Account.h"

std::ostream &operator<<(std::ostream &os, const Checking_Account &account)
{
  os << "[Checking_Account: " << account.name << ": " << account.balance << "]";
  return os;
}

Checking_Account::Checking_Account(const char *name, const double balance)
    : Account(name, balance)
{
}

bool Checking_Account::withdraw(double amount)
{
  return Account::withdraw(amount + withdrawal_fee);
}
