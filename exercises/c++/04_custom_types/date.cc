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

enum class Month {
                  jan = 31,
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
  }
};

void Date::add_days(const unsigned int n){
  for(int i=0; i<n; i++){
    add_one_day();
  }
};


void Date::add_one_day(){

  _day++;

  unsigned short max = 30;
  switch (_month) {
  case Month::jan:
    // Month::mar:
    // Month::may:
    // Month::jul:
    // Month::aug:
    // Month::oct:
    // Month::dec:
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
    _month++;
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


int main() {
  Date x{2000, Month::jan, 2};
  cout <<x <<std::endl;
  x.add_days(11);
  cout <<x <<std::endl;

  Date y{2000, Month::mar, 29};
  cout <<y <<std::endl;
  y.add_days(2);
  cout <<y <<std::endl;

}
