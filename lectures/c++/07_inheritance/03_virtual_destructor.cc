#include <iostream>

struct Base {
  Base() { std::cout << "Base\n"; }
  ~Base() { std::cout << "~Base\n"; }
};

struct Derived : public Base {
  Derived() { std::cout << "Derived\n"; }
  ~Derived() { std::cout << "~Derived\n"; }
};

int main() {
  { Derived d; }

  std::cout << "\n\npointers\n";
  Base* p = new Derived;
  delete p;  // <-- calling the destructor of base, but not from derived
             //     one should define the destructor of the base class "virtual"

  return 0;
}
