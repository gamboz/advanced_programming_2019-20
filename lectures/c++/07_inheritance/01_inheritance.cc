#include "ap_error.h"
#include <iostream>

struct Animal {
  unsigned int age;
  double weight;

  Animal(const unsigned int a, const double w) : age{a}, weight{w} {
    AP_ERROR(weight >= 0) << "invalid weight: " << weight << std::endl;
  }

  Animal() noexcept : Animal{0, 0} {}  // delegating constructor

  void speak() const noexcept { std::cout << "Unknown\n"; }
  void info() const noexcept {
    std::cout << "age:\t" << age << '\n' << "weight:\t" << weight << '\n';
  }
};

// inheritance (public inheritance) →   xxx : public yyy
// xxx IS A yyy (different from object composition with maps the "HAS A" verb)
// yyy is the parent or base class or the super class
// xxx is the child or the derived class

// only public and protected members are accessible by the children

// private and protected inheritance is possible, but
// xxx : private yyy
// means that all members of yyy became private
// they are used for implementation details
// (std::Vector private-inherits from an allocator)

// IS A → : public
// HAS A → object composition
// USE A → : protected  /  : private


struct Dog : public Animal {
  void speak() const noexcept { std::cout << "Bau\n"; }
  Dog() noexcept = default;
  Dog(const unsigned int a, const double d) : Animal{a, d} {}
};

struct Snake : public Animal {
  bool dangerous;


  // Constructors are called from the parent down
  // (i.e. first the parent - delegated constructor)

  Snake(const unsigned int a, const double w, const bool b)
      : Animal{a, w}, dangerous{b} {}
  explicit Snake(const bool b) noexcept : Animal{}, dangerous{b} {}

  // re-implementing the info function
  // calling the parent's info also
  void info() const noexcept {
    Animal::info();
    std::cout << "dangerous:\t" << (dangerous ? "true" : "false") << std::endl;
  }
  void speak() const noexcept { std::cout << "ssss\n"; }
};

// run-time (dynamic) polymorphism
// can passo children to a function that expects parents
// (works only with references and pointers)
void print_animal(const Animal& a) noexcept {
  std::cout << "through ref\n";
  a.info();
  a.speak();
}

// compile-time (static) polymorphism
template <class T>
void print_animal_template(const T& a) noexcept {
  std::cout << "through template\n";
  a.info();
  a.speak();
}

int main() {
  try {
    Dog d;
    d.info();
    d.speak();

    std::cout << std::endl;

    Dog d1{0, 0.6};
    d1.info();
    d1.speak();

    std::cout << std::endl;

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

    std::cout << std::endl;

    print_animal_template(s);

    return 0;
  } catch (std::runtime_error& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
}
