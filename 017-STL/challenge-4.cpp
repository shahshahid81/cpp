#include <cctype>
#include <stack>
#include <queue>
#include <iostream>
#include <string>
#include <iomanip>

bool is_palindrome(const std::string &s)
{
  // Use a stack and a queue to solve the problem.
  std::stack<char> stk;
  std::queue<char> q;

  for (const char &ch : s)
  {
    if (isalpha(ch))
    {
      stk.push(std::toupper(ch));
      q.push(std::toupper(ch));
    }
  }

  while (!stk.empty() && !q.empty())
  {
    if (stk.top() != q.front())
    {
      return false;
    }
    stk.pop();
    q.pop();
  }

  return stk.empty() && q.empty();
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