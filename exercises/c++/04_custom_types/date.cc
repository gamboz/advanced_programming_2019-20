// # Exercises - session 04

// ## Class Date
// Implement a class `Date`. This class must meet the following requirements:
// - it has three **private** attributes to represent day, month and year
// - use a scoped enum for month
// - it has the following **public** functions:
// 	- constructor that takes as arguments a day, a month and a year. (Forget about the validation for now)
// 	- `day()` function that returns the day
// 	- `month()` function that returns the month
// 	- `year()` function that returns the year
// 	- `add_days(const unsigned int n)` which adds `n` days. You have to take care to increment months and years accordingly (neglect leap years)

// *Hints*:
// - you can add more functions, maybe private, to simplify the implementation of the above (e.g., you can implement a function that adds 1 single day)
// - remember to properly mark the member functions that do not modify the class as `const`
// - you should think where to implement the member functions, i.e. inside the class declaration or outside
// ```c++
// class Foo{
// public:

// int foo() const {return an_int;} // note no ; at the end

// int bar();

// private:
// int an_int;
// }; // note the ; at the end of class declaration

// int Foo::bar(){
// ...
// } // note no ; at the end of function implementation

// ```

// Member functions that are *defined* inside the class are **inlined**
// meaning that the compiler will replace the function call to its
// implementation (thus the executable becomes bigger). A good rule of
// thumb is that functions that are simple (e.g. a simple return or few
// lines of code) should be inlined. Bigger functions are recommended to
// be implemented outside the class. Remember that the name of the
// function is prefixed with the class name (see the implementation of
// `bar()` above).

// - In a switch-case statement you can use several `case` labels for a single case
// ```c++
// int a;
// ...
// switch (a){
// 	case 0: case 2: case 4:
// 	case 6: case 8: case 10:
// 		std::cout << "a is even\n";
// 		break;

// 	case 1: case 3: case 5:
// 	case 7: case 9:
// 		std::cout << "a is odd\n";
// 		break;
// 	default:
// 		std::cout << "a > 10\n";
// 		break;
// }
// ```

#include <iostream>
#include <string>

using std::cout;
using std::endl;

enum class Month {
                  jan, // jan = 31,... nope
                  feb,
                  mar,
                  apr,
                  may,
                  jun,
                  jul,
                  aug,
                  sep,
                  oct,
                  nov,
                  dec
};



// overload ++ for Month
// https://stackoverflow.com/a/2571531
// prefix (++my_month)
Month& operator++(Month& orig)
{
  if (orig == Month::dec) {
    orig = Month::jan;
  } else {
    orig = static_cast<Month>(static_cast<int>(orig) + 1);
  }
  return orig;
}

// postfix (my_month++)
Month operator++(Month& orig, int)
{
  Month rVal = orig;
  ++orig;
  return rVal;
}



class Date {
  unsigned short _day;
  unsigned short _year;
  Month _month;

  void add_one_day();

public:
  const auto  day() const {return _day;}
  auto const year() const {return _year;}
  Month const month() const {return _month;}

  void add_days(const unsigned int n);

  Date(const unsigned short year,
       const Month month,
       const unsigned short day):
    _year{year},
    _month{month},
    _day{day}
  {
    // TODO: verify date (i.e. no February 31)
  }
};

void Date::add_days(const unsigned int n){
  for(int i=0; i<n; i++){
    add_one_day();
  }
};


void Date::add_one_day(){

  _day++;

  unsigned short max{30};

  switch (_month) {
  case Month::jan:
    case Month::mar:
    case Month::may:
    case Month::jul:
    case Month::aug:
    case Month::oct:
    case Month::dec:
    max = 31;
    break;
  case Month::feb:
    max = 28;  // TODO: fixme leap years
    break;
  default: // ridondante
    max = 30;
    break;
    }


  if (_day > max){
    _day = 1;
    if (_month == Month::dec) {
      _year++;
    }
    _month++; // dec+1 = jan  (because of way ++ has been overloaded)
  }

}


// overload << for Date
std::ostream& operator<<(std::ostream& os, const Date& d) {
  std::string month_name{};
  Month month{d.month()};

  switch (month) {
  case Month::jan:
    month_name="January";
    break;
  case Month::feb:
    month_name="February";
    break;
  case Month::mar:
    month_name="March";
    break;
  case Month::apr:
    month_name="April";
    break;
  case Month::may:
    month_name="May";
    break;
  case Month::jun:
    month_name="June";
    break;
  case Month::jul:
    month_name="July";
    break;
  case Month::aug:
    month_name="August";
    break;
  case Month::sep:
    month_name="September";
    break;
  case Month::oct:
    month_name="October";
    break;
  case Month::nov:
    month_name="November";
    break;
  case Month::dec:
    month_name="December";
    break;
  default:
    month_name="ERROR";
    break;
  }



  os << d.year() << "-" <<
    month_name
    // static_cast<int>(d.month()) // TODO: fixme with month name
     << "-" << d.day() ; // TODO: fixme with 0-padding
  return os;
}

// ## Helper functions
// Implement the following external helper functions (i.e., they are not part of the class):
// - `bool operator==(const Date& lhs, const Date& rhs);`
// - `bool operator!=(const Date& lhs, const Date& rhs);`
// - `std::ostream& operator<<(std::ostream& os, const Date& d);`
// - **optional** `bool is_leap(const int y);`

// *Hints*:
// - a year is leap if it is divisible by 4. If it is also divisible by 100 is not leap. However, it is leap if it is divisible by 400.
// - try to avoid code duplication

// overload == for two Dates
bool operator==(const Date& lhs, const Date& rhs){
  if (lhs.year() == rhs.year()
      and lhs.month() == rhs.month()
      and lhs.day() == rhs.day()) {
    return true;
  } else {
    return false;
  }
}
bool operator!=(const Date& lhs, const Date& rhs){
  return ! (lhs == rhs);
}


// leap year
bool is_leap(const int y){
  // a year is leap if it is divisible by 4. If it is also divisible
  // by 100 is not leap. However, it is leap if it is divisible by
  // 400.
  if (y % 4 == 0) {
    if (y % 100 == 0){
      if (y % 400 == 0){
        return true;
      } else {
        return false;
      }
    } else {
      // divibile per 4 ma non per 100  →  leap
      return 100;
    }
  } else {
    // NON divisible solo per 4 → NON leap
    return false;
  }
}

int main() {
  cout << "\n## Class Date\n\n";

  Date x{2000, Month::jan, 29};
  cout <<x <<std::endl;
  x.add_days(2);
  cout <<x <<std::endl;

  Date y{2000, Month::mar, 29};
  cout <<y <<std::endl;
  y.add_days(2);
  cout <<y <<std::endl;

  Date z{2000, Month::dec, 29};
  cout <<z <<std::endl;
  z.add_days(2);
  cout <<z <<std::endl;

  cout << "\n## noperator== (followed by !=)\n\n";

  cout << "x == x?\n"
       << (x == x)
       << (x != x)
       << endl;

  cout << "x == y?\n"
       << (x == y)
       << (x != y)
       << endl;

  Date xprime{2000, Month::jan, 31};
  cout << "x == xprime?\n"
       << (x == xprime)
       << (x != xprime)
       << endl;

  cout << "\n## Leap years\n\n";
  // x.year() is unsigned short, automagically casted into int
  cout << x.year() << ": " << is_leap(x.year()) << endl;

  int years[6]{1, 4, 100, 400, 500, 404};
  //           0  1    0    1    0    1
  for(auto y: years){
      cout << y << ": " << is_leap(y) << endl;
  }

}
