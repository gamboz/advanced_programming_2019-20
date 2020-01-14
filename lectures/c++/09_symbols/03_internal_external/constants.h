#ifndef __constants__
#define __constants__

constexpr double pi{3.14159265358};
//static double pi{3.14159265358};
const double phi{1.6180339887};

/* static double pi{3.14159265358}; */
/* static double phi{1.6180339887}; */
// static means "internal linkage"
// i.e. each compilation unit has its own copy

// in C++, "const" implies "static"
// C:   static const
// C++:        const
// (same for constexpr)

// constexpr -> requires that computation is done at compile-time (not run-time)


// NB: static inside a function means that the variable is initialized only once
//     see 03/01_functions.cc & co.

#endif
