#include <cctype>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

bool is_palindrome(const std::string &s)
{
  std::deque<char> dq;

  for (const char &ch : s)
  {
    if (std::isalpha(ch))
    {
      dq.push_back(std::toupper(ch));
    }
  }

  while (dq.size() > 1 && dq.front() == dq.back())
  {
    dq.pop_front();
    dq.pop_back();
  }

  return dq.size() == 0;
}

int main()
{
  std::vector<std::string> test_strings{"a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
                                        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
                                        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome"};

  std::cout << std::boolalpha;
  std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
  for (const auto &s : test_strings)
  {
    std::cout << std::setw(8) << std::left << is_palindrome(s) << s << std::endl;
  }
  std::cout << std::endl;
  return 0;
}