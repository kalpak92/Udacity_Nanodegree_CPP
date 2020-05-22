// Include iostream for output
#include <cassert>
#include <iostream>

// Define a simple structure
struct Date {
  int day;
  int month;
  int year;
};

struct DateIni {
  int day{1};
  int month{1};
  int year{2000};
};

// Define a main function to instantiate and test 
int main()
{
    Date date;
    
    date.day = 29;
    date.month = 8;
    date.year = 1981;
    
    
    // TEST
    assert(date.day == 29);
    assert(date.month == 8);
    assert(date.year == 1981);

    // Print the data in the structure
    std::cout << date.day << "/" << date.month << "/" << date.year << "\n";

    DateIni date1;
    assert(date1.day == 1);
    assert(date1.month == 1);
    assert(date1.year == 2000);
    std::cout << date1.day << "/" << date1.month << "/" << date1.year << "\n";


}