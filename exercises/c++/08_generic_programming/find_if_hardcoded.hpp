// every headers must be guarded
#ifndef __find_if_hardcoded

#define __find_if_hardcoded

// use the "sentinel" approach
// use the iterator pattern (iterators are a generalization of pointers)
template <class I, typename T>
I find_if_hardcoded(I first, I last, const T& value){
  // precodition: [first, last)
  // there is not real way of checking this (e.g. if the iterators came from a linked list)
  
  // requires that I is Iterator
  // *I is of type T
  while (first != last && *first != value){
    //                          ^^^^  hardcoded predicate
    //                          (i.e. cannot check <, >, something else)
    ++first;
  }
  return first;
}




// template <class I, typename T>
// I find_if_with_function(I first, I last,
//                          bool (*predicate)(const T&)
//                          ){
//   while (first != last &&
//          ! predicate(*first)
//          ){
//     ++first;
//   }
//   return first;
// }




template <class I, typename P>
// P has operator(T) and returns a bool
// we can pass a function
// but also a class/object ???
// but also a lambda function
I find_if_with_template(I first, I last,
                        P predicate
                        ){
  while (first != last &&
         ! predicate(*first)
         ){
    ++first;
  }
  return first;
}


template <typename T>
class PredicateBase {
public:
  virtual bool operator()(const T&) const = 0;
};

  
template <typename I, typename T>
// requires that *I is compatible with predicate
I find_if_with_virtual(I first, I last,
                       const PredicateBase<T>& predicate
                       ){
  while (first != last &&
         ! predicate(*first)
         ){
    ++first;
  }
  return first;
}



#endif

//#pragma once
//is a shortcut to saying "include only once"
//same as ifndef/define
