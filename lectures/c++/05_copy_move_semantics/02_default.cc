#include <iostream>
#include <string>

struct S {
  int a;
  double b;
  std::string s;  // default ctor of string set s to empty string
};

std::ostream& operator<<(std::ostream& o, S& s){
  o << s.a << "--" << s.b << "--" << s.s << "\n";
  return o;
}


int main() {
  S s1;  // calls default constructor

  //                           // directly initialize the members. Note
  //                           // that I need access (i.e. they must be
  //                           // public)
  // // it is called aggregate initialization (see
  // // https://en.cppreference.com/w/cpp/language/aggregate_initialization)

  S s3{};  // calls {} on each member: S s3 { {}, {}, {} };
  // S s2{1, 2.3, "alberto"};  // if there are no custom ctors I can

  std::cout << s1.a << "--" << s1.b << "--" << s1.s << "!\n";
  // std::cout << s2.a << "--" << s2.b << "--" << s2.s << "!\n";
  // std::cout << s3.a << "--" << s3.b << "--" << s3.s << "!\n";

  
  // S s4(4, 4.4, "quattro");  // -std=c++2a
  S s4{4, 4.4, "quattro"};
  // std::cout << s1 << s2 << s3 << s4 << std::endl;

  
  return 0;
}
