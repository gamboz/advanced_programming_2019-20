#include "find_if_hardcoded.hpp"

#include <ratio>
#include <vector>
#include <numeric>
#include <iostream>

#include <chrono>





template <typename T>
class predicate_template {
  T value;

public:

  predicate_template(const T& x) : value{x} {};

  bool operator()(const T& x) const noexcept {
    return x == value;
  }
};




template <typename T>
class Equality : public PredicateBase<T>  {
  T target;
public:

  Equality(const T& x) : target{x} {};

  bool operator()(const T& value) const noexcept {
    return target == value;
  }
};




int main(){
  // int[] values {1, 2, 3};
  // std::cout << "is 3 in " << values << "?\n";
  // std::cout << find_if_hardcoded(values, values[3], 3) << std::endl;


  constexpr std::size_t N = 1024*1024*100;
  constexpr int target = 99'000'000;  // since c++11
  std::vector<int> v(N);
  std::iota(v.begin(), v.end(), 0);


  // HARDCODED

  auto t0 = std::chrono::high_resolution_clock::now();
  auto it = find_if_hardcoded(v.begin(), v.end(), target);
  auto t1 = std::chrono::high_resolution_clock::now();

  if (it != v.end()) std::cout << "FOUND " << target
                               << " at " << std::distance(v.begin(), it)
                               << std:: endl;

  std::cout << "find_if_hardcoded took " <<
    std::chrono::duration_cast<std::chrono::milliseconds>(t1-t0).count()
            << " milliseconds\n";







  // TEMPLATE
  // NB predicate is any object that has the operator()
  //    overloaded

  t0 = std::chrono::high_resolution_clock::now();
  it = find_if_with_template(v.begin(), v.end(),
                              predicate_template<int>(target));
  t1 = std::chrono::high_resolution_clock::now();

  if (it != v.end()) std::cout << "FOUND " << target
                               << " at " << std::distance(v.begin(), it)
                               << std:: endl;

  std::cout << "find_if_with_template took " <<
    std::chrono::duration_cast<std::chrono::milliseconds>(t1-t0).count()
            << " milliseconds\n";



  // TEMPLATE + LAMBDA

  // Lambda functions syntax:
  // [ collect variable that will be available in the body ]
  // ( arguments )
  // { body ; }
  t0 = std::chrono::high_resolution_clock::now();
  it = find_if_with_template(v.begin(), v.end(),
                             [target](auto x){ return x == target; }
                             );
  t1 = std::chrono::high_resolution_clock::now();

  if (it != v.end()) std::cout << "FOUND " << target
                               << " at " << std::distance(v.begin(), it)
                               << std:: endl;

  std::cout << "find_if_with_template + lambda took " <<
    std::chrono::duration_cast<std::chrono::milliseconds>(t1-t0).count()
            << " milliseconds\n";





  // DYNAMIC POLIMORPHISM
  // NB:

  auto predicate = new Equality<int>(target);
  t0 = std::chrono::high_resolution_clock::now();
  it = find_if_with_virtual(v.begin(), v.end(),
                            *predicate
                            );
  t1 = std::chrono::high_resolution_clock::now();

  if (it != v.end()) std::cout << "FOUND " << target
                               << " at " << std::distance(v.begin(), it)
                               << std:: endl;

  std::cout << "find_if_with_virtual took " <<
    std::chrono::duration_cast<std::chrono::milliseconds>(t1-t0).count()
            << " milliseconds\n";







}


/** results


|            | |        portatilino          | |                 PC i5-8500                    |
|------------+-+-------------+---------------+-+-------------+-----------------+---------------|
| f          | |    g++9.2.0 | clang++ 9.0.0 | | g++9.2.1-20 | clang++ 9.0.0-4 | clang++ 7.0.1 |
|------------+-+-------------+---------------+-+-------------+-----------------+---------------|
| hardcoded  | |          70 |            44 | |          37 |              30 |            30 |
| template   | |          72 |            48 | |          38 |              31 |            31 |
| t + lambda | |          72 |            47 | |          40 |              34 |            34 |
| virtual    | |         102 |           192 | |          58 |             124 |           124 |
|            | |             |               | |             |                 |               |


 */
