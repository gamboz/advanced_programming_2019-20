martedi stanza 005

#include <iostream> // std::ostream
#include <memory>  // std::unique_ptr
#include <utility> // std::move 

// class members that represent the state of the object, keep these private
//                              the invariance (?)  


// general rule: start from the bottom
//               be lazy (delay coding)


// template "code" will be transformed into actual code ad compilation time
// X will be any type
template <class X>
class Vector {

  std::size_t _size{};

  // elem is and array of pointer to values of type X
  // elem[X0][X1]...
  std::unique_ptr<X[]> elem{};

  std::size_t _capacity{};

  public:
  void push_back(const X& x) {

    check_and_increase_capacity();
    
    elem[_size] = x;
    ++ _size;
  }

  // variadic template:
  template <typename... Types>
  void emplace_back(Types&&... args) { // parameter pack
    //push_back(  X{args} )
    check_and_increase_capacity();
    
    elem[_size] = T{std::forward(Types... args)};    // <---
    ++ _size;
    
  }

  // move semantics
  void push_back(const X&& x) {    // <---

    check_and_increase_capacity();
    
    elem[_size] = std::move(x);    // <---
    ++ _size;
  }




  // // copy & move with std::forward
  // template <class PIPPO>              // <---
  // void push_back(PIPPO&& x){          // <---
  //   check_and_increase_capacity();
    
  //   elem[_size] = std::forward(x);    // <---
  //   ++ _size;

  // }


  Vector() = default;
  
  explicit Vector(const std::size_t& length)
    :
    // here, variables are not yet initialiatize
    // and here they re initialized with the right value
    // in one step
    _size{length}, //     _size(length),     () OR {}          QUESTION
    elem{new X[length]{} },
    _capacity{length}
  { // in the body, the variables have already been initialize
    // so we do an assignment (two steps)
  }
  
private:
  void check_and_increase_capacity() {
    // if (_size < _capacity){
    //   return;
    // } else {
    //   reserve(2*_size);
    //   return;
    // }
    if (_capacity == 0) {
      reserve(8);
    }

    if (_capacity == _size) {
      reserve( 2 * _size);
    }

    // if (_capacity == _size) {
    //   reserve( 2 * _size + 1);
    // }

  }

public:  // useful for the OP also
  void reserve(const std::size_t new_size){
    if (_capacity < new_size) {

      // std::unique_ptr<T[]> elem_bis = new X[new_size]{} ;
      T* elem_bis = new T[new_size];

      for (std::size_t i = 0; i < _size; ++i) {
        
        elem_bis[i] = std::move(elem[i]);

      }
    
      elem.reset(elem_bis);
      
      _capacity = new_size;
    }
  }



  // std::size_t size() {
  //   return _size;
  // }

  // std::size_t capacity() {
  //   return _capacity;
  // }

  auto size() const noexcept { return _size; }
  auto capacity() const noexcept { return _capacity; }
  //               ^ callint this function I will not modify my object
  //                 also, I cannot modiy the object via the return object


  //overload []
  T& operator[](const std::size_t i) noexcept {
    // preconditions:
    //   elem != nullptr
    //   i < _size
    return elem[i];
  }

  // return something that cannot modify my vector object
  const T& operator[](const std::size_t i) const noexcept { return elem[i]; }

  template <typename Y>
  std::ostream& operator<<(const std::ostream& os, const Vector<Y>& v) {
    os << "size " << x.size() << "\n" << "capacity" << x.capacity() << "\n";
    for(std::size_t i=0; i<x.size(); ++i){
      os << x[i] << " ";
    }
    os<< std::endl;
    return os;
  }
};


int main() {

  Vector<int> v{};
  int x{11};
  v.push_back(x);

  std::cout << v << std::endl;
}
