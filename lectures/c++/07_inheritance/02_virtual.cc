#include <ap_error.h>
#include <iostream>

struct Animal {
  unsigned int age;
  double weight;

  Animal(const unsigned int a, const double w) : age{a}, weight{w} {
    AP_ERROR(!(weight < 0)) << "invalid weight!\n";
  }

  Animal() : Animal{0, 0} {}  // delegating constructor

  // if you have pure virtual functions (virtual functions not implemented)
  // you have an abstract class
  // and you cannot instantiate a virtual class
  // (you cannot meet "the" animal)
  // compile-time error
  virtual void speak() const = 0;  // pure virtual function ==> abstract class
  virtual void info() const noexcept {
    std::cout << "age:\t" << age << '\n' << "weight:\t" << weight << '\n';
  }

  virtual ~Animal() {}  // why? see file 03_virtual_destructor.cc
};

// Fixing (fermare) the interface is one of the main reasons for inheritance.


struct Dog : public Animal {
  void speak() const noexcept override { std::cout << "Bau\n"; }
  //                          ^^^^^^^^ implements (maybe again) the virtual function

  // before c++11, one could sign the function f that implements the virtual function f of the parent as "virtual", but in the case of misspelled signature the compiler would define a new virtual function
  Dog() = default;
  Dog(const unsigned int a, const double d) : Animal{a, d} {}
};

struct Snake : public Animal {
  bool dangerous;
  Snake(const unsigned int a, const double w, const bool b)
      : Animal{a, w}, dangerous{b} {}
  explicit Snake(const bool b) : Animal{}, dangerous{b} {}
  void info() const noexcept override {
    Animal::info();
    std::cout << "dangerous:\t" << (dangerous ? "true" : "false") << std::endl;
  }
  void speak() const noexcept override { std::cout << "ssss\n"; }
};

// polimorphism + dynamic binding
// now we can do dynamic binding because the function has been declared virtual
void print_animal(const Animal& a) noexcept {
  std::cout << "throught ref\n";
  a.info();
  a.speak();
}

int main() {
  try {
    Snake s{true};
    s.info();
    s.speak();

    std::cout << std::endl;

    Animal* p = new Snake{1, 2.3, false};

    std::cout << "through pointer\n";
    p->info();
    p->speak();

    delete p;

    std::cout << std::endl;

    print_animal(s);

    return 0;
  } catch (std::runtime_error& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
}












struct x {
  void foo { std::cout <<  "in foo\n"; }
};

struct y : public x {
};

sizeof(x) --> 1
sizeof(y) --> 1

struct x-prime {
  virtual void foo { std::cout <<  "in foo\n"; }
  // virtual add a pointer to a table
  // the table keeps track of parents & children functions definition
  // so, to run a virtual function
  // you must follow the pointer to the table
  // then from the table row to the actual function
  // (and back)
  // also, the compiler cannot inline virtual function
  // because it does not know which to choose
  
  // This is very bad for high-performance

  // Jumps are bad
  // Dealing with memory is slow
  
};

struct y : public x {
};
