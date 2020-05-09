#include <iostream>
#include <sstream>
#include <string>

using std::istringstream;
using std::string;
using std::cout;

int main()
{
    string a = "1 2 3";
    istringstream my_stream(a); // stream the string
    int n;

    while(my_stream)
    {
        my_stream >> n; // extract the part of the string from the stream object
        if(my_stream)
            cout << "That stream was successfull: " << n << "\n";
        else
        {
            cout << "That stream was not successfull." << "\n";
        }  
    }
}