#include <iostream>

template <typename T>
class Vector {
  T* elem;
  std::size_t _size;

 public:
  explicit Vector(const std::size_t length)
      : elem{new T[length]{}}, _size{length} {}

  // explicit ≝ do not create the implicit conversion rule
  // from std::size_t to Vector

  // sort-of copy
  // Vector(const Vector<T> &v)
  //   :
  //   elem{new T},
  //   _size{v._size}
  // {
  //   for(auto i=v.elem; i!=v.last(); ++elem){
  //     *elem[i] = *v.elem[i];
  //   }
  // }
  
    

  // RAII
  // release acquired resources
  ~Vector() { delete[] elem; }

  const T& operator[](const std::size_t& i) const { return elem[i]; }
  T& operator[](const std::size_t& i) { return elem[i]; }

  std::size_t size() const { return _size; }

  
  // range-for:   for(element : container)    (need pointers or iterators)

  // iterators overload !=, ++ and *
  // to provide walking through a data structure

  const T* begin() const { return elem; }
  T* begin() { return elem; }

  // one-past the last element (sentinel)
  const T* end() const { return elem + size(); }
  T* end() { return elem + size(); }
};


void print(const Vector<int>& v){
  for (auto x: v)
    std::cout << x << std::endl;
}

int main() {
  Vector<int> v1{3};
  v1[0] = 1;
  v1[1] = 2;
  v1[2] = 3;

  // print(1) works only if the constructor is not "explicit"
  // print(1);
  
  // range-for loop definition:
  
  // auto it = v1.begin();
  // auto stop = v1.end();
  // for (; it != stop; ++it){
  //   const auto x = *it;
  //   // BODY
  // }

 

  std::cout << "v1: ";
  for (const auto x : v1)
    std::cout << x << " ";
  std::cout << std::endl;

  Vector<int> v2{v1};  // default copy constructor

  std::cout << "v2 after default copy ctor: ";
  for (const auto x : v2)
    std::cout << x << " ";
  std::cout << std::endl;

  v1[0] = 99;

  std::cout << "v2 after v1 has been changed: ";
  for (const auto x : v2)
    std::cout << x << " ";
  std::cout << std::endl;

  v2[1] = -999;

  std::cout << "v1 after v2 has been changed: ";
  for (const auto x : v1)
    std::cout << x << " ";
  std::cout << std::endl;

  return 0;
}
