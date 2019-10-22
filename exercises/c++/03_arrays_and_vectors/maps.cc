// ## **Optional**: Use `std::map` and `std::unordered_map`

// Read the `LittleWomen.txt` and then print all the read words
// (without repetitions) followed by the number of repetitions of that
// word. Compare the time to do the same using `std::vector`,
// `std::map`, `std::unordered_map`. The order in which the words are
// printed is **not** relevant.

// - You can measure the elapsed time as follows:
// ```c++
// #include <chrono>

// auto t0 = std::chrono::high_resolution_clock::now();
// ...
// auto t1 = std::chrono::high_resolution_clock::now();

// auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(t1-t0);
// std::cout << "Elapsed " << elapsed.count() << " [milliseconds]" << std::endl;
// ```

// - You can avoid to repeat `std::chrono::` if you use
// ```c++

// using namespace std::chrono;

// auto t0 = high_resolution_clock::now();
// ```

// run some times I get very variable result with vector
// ./maps.x
//          Vector: 146 [milliseconds]  ←  123--160
//             Map: 268 [milliseconds]  ←  261--268
//   Unorderer map: 112 [milliseconds]  ←  106--112


#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <map>
#include <unordered_map>
#include <chrono>
#include <iomanip>

using namespace std;

// do the task using a vector
void use_vector(ifstream&, ofstream&);

// do the task using a map
void use_map(ifstream&, ofstream&);

// do the task using a map
void use_u_map(ifstream&, ofstream&);

int main(int argc, char** argv) {
  string filename = "LittleWomen.txt";

  //NB: LittleWomen.txt has ZERO WIDTH NO-BREAK SPACE (U+FEFF)
  // as first char...

  if (argc == 2) {
    istringstream is{argv[1]};
    is >> filename;
  }

  // std::ifstream infile(...);
  ifstream infile = ifstream(filename);
  ofstream outfile;

  // VECTOR

  // infile.seekg(0);
  outfile = ofstream("v.txt");

  auto t0 = chrono::high_resolution_clock::now();
  use_vector(infile, outfile);
  auto t1 = chrono::high_resolution_clock::now();
  auto elapsed = chrono::duration_cast<chrono::milliseconds>(t1-t0);
  cout << setw(17) << "Vector: " << elapsed.count() << " [milliseconds]" << endl;

  infile.clear();
  infile.seekg(0);
  outfile = ofstream("m.txt");
  t0 = chrono::high_resolution_clock::now();
  use_map(infile, outfile);
  t1 = chrono::high_resolution_clock::now();
  elapsed = chrono::duration_cast<chrono::milliseconds>(t1-t0);
  cout << setw(17) << "Map: " << elapsed.count() << " [milliseconds]" << endl;

  infile.clear();
  infile.seekg(0);
  outfile = ofstream("um.txt");
  t0 = chrono::high_resolution_clock::now();
  use_u_map(infile, outfile);
  t1 = chrono::high_resolution_clock::now();
  elapsed = chrono::duration_cast<chrono::milliseconds>(t1-t0);
  cout << setw(17) << "Unorderer map: " << elapsed.count() << " [milliseconds]" << endl;

}

void use_vector(ifstream& infile, ofstream& outfile){
  vector<string> words {};
  string temp {};

  while (infile >> temp) {
    words.push_back(temp);
  }

  sort(words.begin(), words.end());

  string prev{};
  int count = -1;
  for (vector<string>::iterator iter = words.begin() ; iter != words.end(); ++iter) {
    if (*iter != prev){

      // first iteration is special:
      // emit count only if we have something;
      // this is the count of the previous word
      if (count > -1) {
        outfile << " " << count << endl;
      }

      // emit word everytime it's new
      outfile << *iter;
      prev = *iter;
      count = 1;
    } else {
      count++;
    }
  }

  // emit count of last word
  outfile << " " << count << endl;
  outfile.close();
}

void use_map(ifstream &infile, ofstream &outfile) {
  map<string,int> words;
  string temp {};

  while (infile >> temp) {
    if (words.count(temp) > 0) {
      words[temp] = words[temp] + 1;
    } else {
      words[temp] = 1;
    }
  }

  for (auto& x: words)
    outfile << x.first << ' ' << x.second << endl;

  outfile.close();
}


// same identical algorithm as "use_map"
// TODO: is it possible to generalize use_x<T>(...)
void use_u_map(ifstream &infile, ofstream &outfile) {
  unordered_map<string,int> words;
  string temp {};

  while (infile >> temp) {
    if (words.count(temp) > 0) {
      words[temp] = words[temp] + 1;
    } else {
      words[temp] = 1;
    }
  }

  for (auto& x: words)
    outfile << x.first << ' ' << x.second << endl;

  outfile.close();
}
