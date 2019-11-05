#include <cmath>
#include <iostream>
#include <iterator>

#if __cplusplus > 201103L

template <class T>
auto init(const std::size_t l) {
  return new T[l]{};
}

#else

template <class T>
T* init(const std::size_t l) {
  // return new array of type T
  // with all slots initialized to 0 by {}
  return new T[l]{};
}

#endif

template <typename T> void debug(T);

int main() {
  auto b = true;          // a bool
  auto ch = 'x';          // a char
  auto i = 123;           // an int
  auto d = 1.2;           // a double
  auto z = std::sqrt(d);  // z has the type of whatever sqrt(d) returns
  auto ui = 0u;           // unsigned int
  auto llui = 0llu;       // long long unsigned int

  for (auto i = 0; i < 7; ++i)
    std::cout << i << std::endl;

  auto pb = &b;  // guess what.. How can I know?
  //  debug(pb);
  std::cout << pb<<std::endl;

  auto pch = &ch;
  std::cout << pch <<std::endl;

  auto pi = &i;
  std::cout << pi <<std::endl;

  auto ps = init<double>(11);
  delete[] ps;
  return 0;
}
