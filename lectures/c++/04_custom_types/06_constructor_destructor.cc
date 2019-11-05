#include <iostream>
#include <string>

struct Foo {
  int _i;
  double _d;
  std::string _s;

  // constructor: function without return type
  Foo(const int i, const double d,
      const std::string& s);  // custom constructor

  Foo();  // default constructor

  // "~" + no return type & no arguments
  ~Foo();  // destructor
};

Foo::Foo(const int i, const double d, const std::string& s)
    : _i{i},
      _d{d},
      _s{s}
      // if you need, build/initialize member variables here
      // NOT in the body

      // no "=" here

      // _i, _d, _s must be initialized in the same order they have
      // been declared

{
  std::cout << "custom ctor\n";
  // if you want/need you can use _i, _d, _s and change their value
  // with the usual notation +,-,=,*, call a function..
  // don't use {} because this notation is reserved for the
  // construction of the variables and at this point they have already
  // been constructed

  // _i{i}; // compile error
  // _i = i;  // two operations: construct the object & copy the data
}

Foo::Foo() {
  std::cout << "default ctor\n";  // what happens to our member variables?
}

Foo::~Foo() {
  std::cout << "dtor " << _i << "\n";
}


// overload the operator "<<"
// must be defined outside the class
std::ostream& operator<<(std::ostream& os, const Foo& f) {
  os << "🦄 " << f._i << " " << f._d << " " << f._s << std::endl;
  return os;
}

int main() {
  Foo f0;    // call default ctor
  Foo f1{};  // call default ctor
  // Foo f2(); // compiler error

  Foo f2{3, 3.3, "picio"};
  std::cout <<
    "f0: " << f0 <<
    "f1: " << f1 <<
    "f2: " << f2 <<
    std::endl;

  // f0.~Foo();
  // the destructor is called when the variable goes out of scope
  return 0;
}
