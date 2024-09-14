#include "IllegalBalanceException.h"

const char *IllegalBalanceException::what() const noexcept
{
  return "Balance should be greater than or equal to 0.";
}
