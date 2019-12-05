
// _malloc_ (from C) allocates memory on the heap (reserves memory)
// _new_ allocates memory and call the default constructor

new T[7];

malloc(7 * sizeof(T) );


auto p = static_cast<T*>(malloc(7 * sizeof(T) ));

// _new_ accepts an argument
// and I can pass the place where I want the new object be constructed

new(p) T{};
new(p+1) T{};

// to destroy, do not use _delete_ in this case, but call the destructor explicitly
p-> ~T();
(p+1)-> ~T();


// now we can de-allocate memory
free(p);
// no need for free(p+1): the OS knows how long "p" is

// an allocator must provide 4 functions
// allocate
// construct
// destroy
// deallocate



// a map is particular type of bynary-tree called red-black tree


// maps store key/value in a pair
// pair.first is the key
// pair.second is the value


// iterators define first and last
// but last is equal to the last+1 element/coordinate
// so that
// while ( first != last )
// is flexible and can manage empty lists


// iterators need 5 things

// value_type: the type of the value stored in each node

// difference_type: the type obtained when we subtract two iterators
//                  99% of the times this is std::ptrdiff_f

// iterator_type: random access OR binary OR ...
//                (to optimize algos)

// reference: value_type&

// pointer: value_type*


// duck-typing means implementing something that is not really X, but behaves like X


// TODO: override ++, ==, != and ???


// NB: iterator.end() returns a pointer that must NOT be dereferenced,
//     because it does not point to an allocated piece of memory
