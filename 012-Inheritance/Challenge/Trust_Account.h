#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_

#include "Savings_Account.h"

class Trust_Account : public Savings_Account
{
  friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);

private:
  static constexpr const char *default_name = "Unnamed";
  static constexpr const double default_balance = 0;
  static constexpr const double default_interest_rate = 0.0;
  static constexpr const double max_withdrawal_percentage = 0.2;
  static constexpr const unsigned short bonus_threshold = 5000;
  static constexpr const unsigned short bonus_amount = 50;
  static constexpr const unsigned max_withdrawal = 3;

protected:
  unsigned short number_of_withdrawals = 0;

public:
  Trust_Account(const char *name = default_name, const double balance = default_balance, const double interest_rate = default_interest_rate);

  bool deposit(double balance);
  bool withdraw(double balance);
};

#endif