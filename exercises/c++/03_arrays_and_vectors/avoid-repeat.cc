// ## Avoid repeated words

// Read from stdin a sequence of words. Store each word in a
// `std::vector<std::string>`. Then, print the words without
// repetitions.

// *Hints*:

// you can print the words in any order you want (i.e., you are not
// required to print the words in the order you have read them)

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
  cout << "ciao" << endl;
  vector<string> in {};
  string word;

  int i{1};
  while ( i<argc ) {

    istringstream is { argv[i] };
    is >> word;

    cout << word << endl;
    in.push_back(word);

    i++;

  }

  sort(in.begin(), in.end());

  string prev{};
  for (vector<string>::iterator iter = in.begin() ; iter != in.end(); ++iter) {
    if (*iter != prev){
      cout << ' ' << *iter;
      prev = *iter;
    }
  }
  std::cout << '\n';

}
