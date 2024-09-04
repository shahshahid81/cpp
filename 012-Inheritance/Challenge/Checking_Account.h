#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_

#include <iostream>
#include "Account.h"

class Checking_Account : public Account
{
  friend std::ostream &operator<<(std::ostream &os, const Checking_Account &account);

private:
  static constexpr const char *default_name = "Unnamed";
  static constexpr const double default_balance = 0;
  static constexpr const double withdrawal_fee = 1.5;

public:
  Checking_Account(const char *name = default_name, const double balance = default_balance);
  bool withdraw(double amount);
};

#endif