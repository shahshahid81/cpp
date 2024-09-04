#include "Trust_Account.h"

std::ostream &operator<<(std::ostream &os, const Trust_Account &account)
{
  os << "[Trust_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%]";
  return os;
}

Trust_Account::Trust_Account(const char *name, const double balance, const double interest_rate)
    : Savings_Account(name, balance, interest_rate)
{
}

bool Trust_Account::deposit(double amount)
{
  if (amount >= 5000)
  {
    amount += 50;
  }

  return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount)
{
  if (number_of_withdrawals >= 3)
  {
    std::cout << "More than 3 withdrawals are not allowed!!" << std::endl;
    return false;
  }
  bool status = Savings_Account::withdraw(amount);
  if (status)
  {
    number_of_withdrawals++;
  }
  return status;
}
