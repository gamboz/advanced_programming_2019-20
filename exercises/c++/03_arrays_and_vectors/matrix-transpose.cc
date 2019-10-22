// ## Matrix transpose

// Write a function that computes the transpose of a matrix. The
// matrix is represented by a simple `std::array<double,N>` where N
// is the total size of the matrix (i.e., number of rows times
// number of columns). The original array must be modified inside
// the function `transpose`.

// *Hints*:

// - In C/C++, the matrices are accessed row-wise
// - Don't try to use that for very big matrices, otherwise you go in stack overflow.
// - You are not required to do the transpose *in place*
// - Test with both square and rectangular matrices.
// - Use `std::swap` defined in header `<utility>`

#include <iostream>
#include <array>
#include <utility>

using namespace std;

// transpose a matrix
void transpose(array<double, 10>&, int rows, int cols);

// cout a matrix
void print_matrix(array<double, 10>&, int rows, int cols);


int main () {
  array<double,10> ma{1, 2, 3, 4, 5,
                      6, 7, 8, 9, 0};

  transpose(ma, 2, 5);
}


void transpose(array<double, 10>& ma, int rows, int cols){

  // transposed = 1, 6
  //              2, 7
  //              3, 8
  //              4, 9
  //              5, 0

  // 0,0 (1)   →   0,0
  // 0,1 (2)   →   1,0
  // 0,2 (3)   →   2,0
  // 0,3 (4)   →   3,0
  // 0,4 (5)   →   4,0
  // 1,0 (6)   →   0,1
  // 1,1 (7)   →   1,1
  // 1,2 (8)   →   2,1
  // 1,3 (9)   →   3,1
  // 1,4 (0)   →   4,1

  auto transposed{ma};

  cout << "given matrix:" << endl;
  print_matrix(ma, rows, cols);

  // transpose
  for (int i {0}; i < rows; i++){
    for (int j{0} ; j<cols ; j++){
      transposed[j * rows + i] = ma[i * cols + j];
    }
  }

  cout << "transposed in another matrix: " << endl;
  print_matrix(transposed, cols, rows);

  cout << "swapping..." << endl;
  swap(ma, transposed);

  cout << "original matrix now transposed:" << endl;
  print_matrix(ma, cols, rows);
}


void print_matrix(array<double, 10>& ma, int rows, int cols) {
  for (int r{0}; r<rows; r++){
    for (int c{0}; c < cols; c++) {
      cout << ma[cols * r + c] << " ";
    }
    cout << endl;
  }
}
