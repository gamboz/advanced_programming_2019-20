#include <iostream>

// export symbols with the rules of "C"
// this also means that one cannot have function overloading
// of these functions
extern "C"{
  void hello(){
    std::cout << "Hello, World" << std::endl;
  }
}

int main(){
  hello();
}
