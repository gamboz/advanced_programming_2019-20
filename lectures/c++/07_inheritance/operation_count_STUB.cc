// #include <stdli

template <class T>
struct measure {
  T value;
  
  measure () { ++default_ctor; }


  // Types can be 

  // semiregular: copy & move semantics are define
  // regural: equal operator are defined
  // totally: ordered < and > operators are defined

  // define all operations,
  // and step counters for each type of operation
  // (no need for the counter to be in the class)

};


