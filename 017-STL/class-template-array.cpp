#include <iostream>
#include <string>

template <typename T, int N>
class Array
{
private:
  int size{N};
  T data[N];

  friend std::ostream &operator<<(std::ostream &os, const Array<T, N> &arr)
  {
    std::cout << "[ ";
    for (const auto &elem : arr.data)
    {
      std::cout << elem << " ";
    }
    std::cout << "]";
    return os;
  }

public:
  Array() = default;
  Array(T value)
  {
    fill(value);
  }
  int get_size()
  {
    return size;
  }

  void fill(T value)
  {
    for (auto &elem : data)
    {
      elem = value;
    }
  }

  T &operator[](int index)
  {
    return this->data[index];
  }
};

int main()
{

  Array<int, 5> nums;
  std::cout << "The size of nums is: " << nums.get_size() << std::endl;
  std::cout << nums << std::endl;

  nums.fill(0);
  std::cout << "The size of nums is: " << nums.get_size() << std::endl;
  std::cout << nums << std::endl;

  nums.fill(10);
  std::cout << nums << std::endl;

  nums[0] = 1000;
  nums[3] = 2000;
  std::cout << nums << std::endl;

  Array<int, 100> nums2{1};
  std::cout << "The size of nums2 is: " << nums2.get_size() << std::endl;
  std::cout << nums2 << std::endl;

  Array<std::string, 10> strings(std::string{"Frank"});
  std::cout << "The size of strings is: " << strings.get_size() << std::endl;
  std::cout << strings << std::endl;

  strings[0] = std::string{"Larry"};
  std::cout << strings << std::endl;

  strings.fill(std::string{"X"});
  std::cout << strings << std::endl;

  return 0;
}
