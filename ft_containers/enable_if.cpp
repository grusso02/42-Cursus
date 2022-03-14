#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <type_traits>

// template<class T> struct enable_if<true, T> { typedef T type; };
// 1. the return type (bool) is only valid if T is an integral type:
template < class T >
typename std::enable_if<std::is_integral<T>::value, bool>::type is_odd(T i)
{
  return bool(i % 2);
}

// template <bool Cond, class T = void> struct enable_if {};
// 2. the second template argument is only valid if T is an integral type:
template < class T, class = typename std::enable_if<std::is_integral<T>::value>::type>
bool is_even(T i)
{
  return !bool(i % 2);
}

//Used in ft_containers
template <typename T>
std::string odd_or_even(T i, typename std::enable_if<std::is_integral<T>::value, T>::type* = 0)
{
    if (bool(i % 2))
      return ("odd");
    return ("even");
}

template < class T >
typename std::enable_if<std::is_integral<T>::value, void>::type odd_or_even2(T i)
{
 /*    if (bool(i % 2))
      return ("odd");
    return ("even"); */

    std::cout << "Eccomi" << std::endl;
}

class A
{
  public:
    A() : i(2) {};
  int i;
};

int main()
{
  int i = 1;    // code does not compile if type of i is not integral
  A num;

  std::cout << std::boolalpha;
  std::cout << "i is odd: " << is_odd(i) << std::endl;
  std::cout << "i is even: " << is_even(i) << std::endl;
  std::cout << "i is " << odd_or_even(i) << std::endl;
  odd_or_even2(i);

  return 0;
}