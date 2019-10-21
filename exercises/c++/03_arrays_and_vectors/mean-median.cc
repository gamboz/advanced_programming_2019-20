// ## Mean and Median

// Store the numbers contained in file `temperatures.txt` into a
// `std::vector<double>` and compute:
//   - the mean
//   - the median

// *Hints*:

// - use `push_back()`
// - you can increment a variable using `+=` operator
// - you can **sort** the elements of a vector `v` as follows
// ```c++
// #include <algorithm>

// std::vector<double> v;
// ...
// std::sort( v.begin(), v.end() );
// ```

#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main(int argc, char** argv) {
  double temp {};
  // std::ifstream infile("temperatures.txt");
  string filename = "temperatures.txt";
  if (argc == 2) {
    istringstream is{argv[1]};
    is >> filename;
  }

  ifstream infile = ifstream(filename);

  vector<double> temperatures {};
  // Q: is it more expensive to find the initial number of tokens and size the vector thus
  //    or just add pieces and let the vector to increase by itself?

  double max{0}, min{0}, mean{0}, median{0}, sum{0};

  while (infile >> temp) {
    // cout << setprecision(7) << temp << endl;
    sum += temp;

    temperatures.push_back(temp);

  }

  cout << "Read " << temperatures.size() << " values." << endl;

  sort(temperatures.begin(), temperatures.end());

  min = temperatures.at(0);
  max = temperatures.at(temperatures.size()-1);
  cout << setw(9) << "min: " << setprecision(7) << min << endl;
  cout << setw(9) << "max: " << setprecision(7) << max << endl;
  // TODO: use macros for output

  mean = sum / temperatures.size();
  cout << setw(9) << "mean: " << setprecision(7) << mean << endl;

  if (temperatures.size() % 2 == 1) {
    median = temperatures.at(temperatures.size()/2);
  } else {
    // according to wikipedia, median of odd-size groups is between
    // the the midpoint floor and ceil
    int midpoint_ceiling = temperatures.size() / 2; // Q: cannot use {} initializer; why?
    int midpoint_floor = midpoint_ceiling - 1;

    median = (temperatures.at(midpoint_floor) + temperatures.at(midpoint_ceiling)) / 2;
  }

  cout << setw(9) << "median: " << setprecision(7) << median << endl;
}
