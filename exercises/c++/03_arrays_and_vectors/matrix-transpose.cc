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

int main () {
  array<double,10> ma{1, 2, 3, 4, 5,
                      6, 7, 8, 9, 0};

  transpose(ma, 2, 5);
  //TODO cout
}


void transpose(array<double, 10>& ma, int rows, int cols){


  // transposed = 1, 6
  //              2, 7
  //              3, 8
  //              4, 9
  //              5, 0

  // 0,0 (0)   →  0,0 (0
  // 0,1 (1)   →  1,0 (2
  // 0,2 (2)   →  2,0 (4
  // 0,3 (3)   →  3,0 (6
  // 0,4 (4)   →  4,0 (8
  // 1,0 (5)   →  0,1 (1
  // 1,1 (6)   →  1,1 (3
  // 1,2 (7)   →  2,1 (5
  // 1,3 (8)   →  3,1 (7
  // 1,4 (9)   →  4,1 (9



  auto transposed{ma};

  cout << "given matrix:" << endl;
  for (int r{0}; r<rows; r++){
    for (int c{0}; c<cols; c++){
      cout << ma[cols*r + c] << " ";
    }
    cout << endl;
  }


  for (int i {0}; i < rows; i++){
    for (int j{0} ; j<cols ; j++){

    // int ma_r = i / cols;
    // int ma_c = i % cols;
    // // int tra_r = i / rows;
    // // int tra_c = i % rows;

    // int tra_r = ma_c;
    // int tra_c = ma_r;

    // cout << ma_r << "," << ma_c
    //      << " " << ma_r*cols + ma_c << " "
    //      << "  →  " << tra_r << "," << tra_c
    //      << " " << tra_r*rows + tra_c << " "
    //      << endl;
    // transposed[tra_r * rows + tra_c] = ma[ma_r * cols + ma_c];
      transposed[j * rows + i] = ma[i * cols + j];
    }
  }

  cout << "transposed: " << endl;
  for (int r{0}; r<cols; r++){
    for (int c{0}; c<rows; c++){
      cout << transposed[rows*r + c] << " ";
    }
    cout << endl;
  }

  cout << "swapping..." << endl;
  swap(ma, transposed);

  cout << "original matrix now transposed:" << endl;
  for (int r{0}; r<cols; r++){
    for (int c{0}; c<rows; c++){
      cout << ma[rows*r + c] << " ";
    }
    cout << endl;
  }

}
