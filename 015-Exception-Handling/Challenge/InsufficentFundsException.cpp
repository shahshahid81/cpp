#include "InsufficentFundsException.h"

const char *InsufficentFundsException::what() const noexcept
{
  return "No Sufficient Funds to withdraw the money.";
}
