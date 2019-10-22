// ## Matrix transpose

// Write a function that computes the transpose of a matrix. The
// matrix is represented by a simple `std::array<double,N>` where N is
// the total size of the matrix (i.e., number of rows times number of
// columns). The original array must be modified inside the function
// `transpose`.

// *Hints*:

// - In C/C++, the matrices are accessed row-wise
// - Don't try to use that for very big matrices, otherwise you go in stack overflow.
// - You are not required to do the transpose *in place*
// - Test with both square and rectangular matrices.
// - Use `std::swap` defined in header `<utility>`

// ## Convert `argv` to types

// Modify the above program such that the number of rows and columns
// are read from command line arguments.

// *Hints*:
//  - Use `std::istringstream` defined in the header `<sstream>`

//  ```c++
// #include <sstream>

// std::size_t rows;
// {
//   std::istringstream is{argv[1]};
//   is >> rows;
// }
//  ```

#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <utility>
// #include <assert.h>

using namespace std;

// transpose a matrix
void transpose(vector<int>&, int rows, int cols);

// cout a matrix
void print_matrix(vector<int>&, int rows, int cols);

// build a matrix
void fill_array_sequece(vector<int>&, size_t);


int main(int argc, char** argv){
  // read the matrix size from cli positional parameters
  // build the matrix with numbers starting from 0
  // and transpose it

  if (argc != 3){
    cout << "Usage: " << argv[0] << " ROWS COLS" << endl;
    return 1;
  }

  std::size_t rows;
  std::size_t cols;
  {
    std::istringstream is{argv[1]};
    is >> rows;
  }
  {
    std::istringstream is{argv[2]};
    is >> cols;
  }
  cout << "ROWS: " << rows << "; COLS: " << cols << endl;

  vector<int> ma {};
  cout << "filling vector with sequence" << endl;
  fill_array_sequece(ma, rows*cols);

  cout << "original matrix" << endl;
  print_matrix(ma, rows, cols);

  transpose(ma, rows, cols);

  cout << "matrix now transposed:" << endl;
  print_matrix(ma, cols, rows);

  return 0;
}


void print_matrix(vector<int>& ma, int rows, int cols) {
  for (int r{0}; r < rows; r++) {
    for (int c{0}; c < cols; c++) {
      cout << setw(4) << ma[cols * r + c] << setw(4);
    }
    if (r == rows-1) {
      cout << " □" << endl;  // stop-sign is too prominent: 🛑
    } else {
      cout << " ⤶" << endl;
    }
  }
}

void fill_array_sequece(vector<int>& ma, const size_t size) {
  ma.erase(ma.begin(), ma.end());
  for (size_t i{0}; i < size; i++)
    ma.push_back(i);

  // TODO: use itertor
  // vector<int>::iterator serial;
  // int serial = ma.end() + 1;

}

void transpose(vector<int>& ma, int rows, int cols){
  auto transposed{ma};

  // transpose
  for (int i{0}; i < rows; i++){
    for (int j{0} ; j < cols ; j++){
      transposed[j * rows + i] = ma[i * cols + j];
    }
  }

  swap(ma, transposed);
}
