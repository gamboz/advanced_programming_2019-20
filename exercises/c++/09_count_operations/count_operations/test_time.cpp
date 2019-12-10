#include "timer.hpp"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

timer<> t;

template <typename I>
void set_timed(const std::size_t n, I first, I last) {
  t.start();
  using value_type = typename std::iterator_traits<I>::value_type;
  // std::iterator_traits<>  is a specialize machinery to get the value_type of things such as raw pointers
  // use "typename" on this, otherwise compiler thinks the resutl is a static variable
  std::set<value_type> set{first, last};
  t.stop();
}

template <typename I>
void vector_timed(const std::size_t n, I first, I last) {
  t.start();
  using value_type = typename std::iterator_traits<I>::value_type;
  // std::vector<value_type> v{first, last};
  // std::sort(v.begin(), v.end());
  // auto it = std::unique(v.begin(), v.end());
  // t.stop();

  std::sort(first, last);
  auto it = std::unique(first, last);
  t.stop();
  (void)std::distance(first, it);
}

using namespace std::chrono;
int main() {
  using value_type = int;
  for (std::size_t n = 16; n < (1 << 25); n <<= 1) {
    //                                    left bit-shift (equivalent to n*2)
    //                stop when n == n**25 (25 left shifts)
    std::vector<value_type> v(n);  // attenzione che v{4} crea un vector lungo 1 con "4" come elemento
    std::iota(v.begin(), v.end(), value_type(-1024));  // iota creates a sequence
    //                            costruttore di value_type che prende un int
    //                            (se non esiste, compilation-error)
    std::random_shuffle(v.begin(), v.end());
    for (std::size_t i = 0; i < n; ++i) {
      v[i] = int{v[i]} & 1023;  // introduces repetitions
    }
    std::cout << std::setw(15) << n << "\t";
    //set_timed(n,v.begin(),v.end());
    vector_timed(n, v.begin(), v.end());
  }
}
