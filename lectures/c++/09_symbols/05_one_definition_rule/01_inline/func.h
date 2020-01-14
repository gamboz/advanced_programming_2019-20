#ifndef _FUNC_H_
#define _FUNC_H_

#include <iostream>

// when functions are defined inside headers
// they should be defined static or inline

inline void dummy() {
  // "inline" implies static in c++
  // can be explicitly defined as "static inline"
  std::cout << "dummy\n";
}

#endif /* _FUNC_H_ */
