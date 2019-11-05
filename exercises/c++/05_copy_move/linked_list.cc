// # Exercises - session 05

// ## Linked list
// Implement a linked list with the following design. You are free to add more functions.

// ```c++
// enum class Insertion_method { push_back, push_front };

// template <class value_type>
// class List {
//  public:
//   // insert a new node with the value v according to the method m
//   // this method should be used to fill the list
//   void insert(const value_type& v, const Insertion_method m);

//   // return the size of the list
//   std::size_t size() const;

//   // delete all the nodes of the list
//   void reset();

//   // constructor(s) for List

//   // copy semantics
//   // move semantics

//   // destructor

//  private:

//   // private struct node with the proper value_type
//   struct node {
//     value_type value;
//     std::unique_ptr<node> next;

//     // implement suitable constructor(s) for node

//     // copy and move semantics if needed

//     // destructor
//   };

//   // append the newly created node at the end of the list
//   void push_back(const value_type& v);

//   // insert the newly created node in front of the list
//   void push_front(const value_type& v);

//   std::unique_ptr<node> head;
//   std::size_t size;
// };

// template <class T>
// std::ostream& operator<<(std::ostream& os, const List<T>& l);

// ```

// #### *Hints*:

// - `std::move` is defined in header `utility`

// - `std::unique_ptr` is defined in header `memory`

// - A `std::unique_ptr<T> p` has the following functions

//    - `T* get() const` Returns a pointer to the managed object or `nullptr` if
//    no object is owned.
//
//    - `T* release()` Releases the ownership of the managed object if any.
//    `get()` returns `nullptr` after the call.
//
//    - `void reset(T* ptr)` Delete `current_ptr` (if any) and set `current_ptr
//    = ptr`.
//
//    - To check if a `std::unique_ptr<T> p` is different from `nullptr` you can
//    simply use `if(p)` (there is no need to write `if (p.get())`).


// -  For a class `Foo`

//     ```C++
//     class Foo{
//       Foo(); // default ctor
//       Foo(const Foo& f); // copy ctor
//       Foo(Foo&& f); // move ctor

//       Foo& operator=(const Foo& f); // copy assignment
//       Foo& operator=(Foo& f); // move assignment
//     };
//     ```



// You are required to use blocks of memory (*heap*) locations which are linked
// together. Each of these blocks contains one component that may refer to
// another block. If each block (except the final one) contains a pointer to the
// next block, so that they form a chain, then the entire collection of linked
// blocks is called a **linked list**. The blocks of memory locations of a
// linked list are usually called *nodes*.


// Every node of a linked list, except the final one, contains a pointer to its
// immediate *successor*, and every node except the first one is pointed to by
// its immediate *predecessor*. The pointer member of the last node has the
// value `nullptr`.


// The private member `head` points to the first element of the list.

// ![linked_list.png](./.aux/list2.png)

#include <iostream>
#include <utility>
#include <memory>


using std::cout;
using std::endl;


enum class Insertion_method { push_back, push_front };

template <class value_type>
class List {
 public:
  // insert a new node with the value v according to the method m
  // this method should be used to fill the list
  void insert(const value_type& v, const Insertion_method m);

  // (move semantics)
  void insert(value_type&& v, const Insertion_method m);

  // return the size of the list
  std::size_t size() const;

  // delete all the nodes of the list
  void reset();

  // constructor(s) for List

  // List constructor
  // produces a list os size 0
  // with head pointing to nullptr
  List()
    :
    head{},
    _size{}
  {
    cout << "List ctor\n";
  }


  // Q: order matters... why???
  // head{}, _size{}   !=   _size{}, head{}

  // Constructor with one value
  // produces a list of size 1
  // with head pointing to node(v)
  // and node.next points to nullptr
  List(const value_type &v)
    :
    head{},
    _size{1}
  {
    node x = node{v};  //TODO: use move
    x.next.release();
    head.reset(&x);
    cout << "List ctor with value\n";
  }


  // copy semantics
  // move semantics

  // destructor
  ~List(){
    // Q: walk the list and release all nodes?
    //    starting from the last (?)
    head.release();
  }

  // TODO:
  // check_size() { _size ?= traverse-the-list-and-count }

 private:

  // private struct node with the proper value_type
  struct node {
    value_type value;
    std::unique_ptr<node> next;

    // implement suitable constructor(s) for node
    node(const value_type& v)
      :
      value{v}
    {
      cout << "node ctor\n";
    }

    // copy and move semantics if needed

    // destructor
  };

  // append the newly created node at the end of the list
  // Q: do I need a pointer to "tail"?
  void push_back(const value_type& v);
  void push_back(value_type&& v);

  // insert the newly created node in front of the list
  void push_front(const value_type& v);
  void push_front(value_type&& v);

  std::unique_ptr<node> head;
  // std::unique_ptr<node> tail;
  std::size_t _size;

//   // experiments
// public:
//   List::node first(){
//     return head;
//   }


};


// template <class T>
// List<T>::node(const T& value)
//   :
//   value{value}
// {}


// template <class T>
// void List<T>::push_back(const T& v){
//   // v.tail = &v
// }


template <class T>
void List<T>::insert(T&& v, const Insertion_method m){
  switch (m) {
  case Insertion_method::push_front:
    cout << "push front\n";
  default:
    cout << "ERROR\n";
  }
}

template <class T>
void insert(const T& v, const Insertion_method m){
  switch (m) {
  case Insertion_method::push_front:
    cout << "push front\n";
  default:
    cout << "ERROR\n";
  }
}


template <class T>
void List<T>::push_front(const T& v){
  //  new node
  //  node.value = v
  //  node.next = &head
  //
  //  head = &v;
  List::node new_node{v};
  new_node.next = &head;
  head = &new_node;
  ++_size;
}


// List.size()
template <typename T>
std::size_t List<T>::size() const {
  return _size;
}


// overload << for List
template <class T>
std::ostream& operator<<(std::ostream& os, const List<T>& l){
  os << "l(" << l.size() << ") "
    // << l.first()
    ;
  return os;
}



int main() {
  cout << "l{}:\n";
  List<int> l{};
  cout << l << endl;


  cout << "l{1}:\n";
  List<int> ll{1};
  cout << ll << endl;

  cout << "l{1} + push_front(2):\n";
  List<int> lll{1};
  lll.insert(2, Insertion_method::push_front);
  cout << lll << endl;
}
