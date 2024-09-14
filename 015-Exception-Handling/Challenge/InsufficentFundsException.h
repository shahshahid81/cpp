#ifndef __INSUFFICENT_FUNDS_EXCEPTION_H__
#define __INSUFFICENT_FUNDS_EXCEPTION_H__

#include <exception>

class InsufficentFundsException : public std::exception
{
public:
  InsufficentFundsException() = default;
  ~InsufficentFundsException() = default;
  virtual const char *what() const noexcept override;
};

#endif