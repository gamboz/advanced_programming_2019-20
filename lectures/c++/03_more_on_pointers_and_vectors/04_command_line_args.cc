#include <iostream>

// int main(int argc, char* argv[]) {
int main(int argc, char** argv) {
  for (auto i = 0; i < argc; ++i)
    std::cout << "argv[" << i << "] = " << argv[i] << std::endl;
  return 0;
}
