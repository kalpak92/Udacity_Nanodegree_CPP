#include <iostream>
#include <cassert>

class  Date 
{
    public:
        int Day()
        {
            return day;
        }
        
        void Day(int d)
        {
            if(d >= 1 && d <= 31)
                day = d;
        }
    
        int Month()
        {
            return month;
        }
        
        void Month(int m)
        {
            if(m >= 1 && m <= 12)
                month = m;
        }
    
        int Year()
        {
            return year;
        }
        
        void Year(int y)
        {
            if(y >= 1 && y <= 2999)
                year = y;
        }
    
    private:
        int day;
        int month;
        int year;
};

// Test in main
int main()
{
    Date date;
    date.Day(-1);
    date.Month(14);
    date.Year(2000);
    assert(date.Day() != -1);
    assert(date.Month() != 14);
    assert(date.Year() == 2000);
}

