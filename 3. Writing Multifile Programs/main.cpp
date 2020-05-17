#include <iostream>
#include <vector>
#include "increment_and_sum.h"

using std::vector;
using std::cout;

int main() 
{
    vector<int> v{1, 2, 3, 4};
    int total = IncrementAndComputeVectorSum(v);
    cout << "The total is: " << total << "\n";
}


/**
 * If you look carefully at the files above, you will see several things:
 * vect_add_one.h is included in increment_and_sum.cpp.
 * 
 * This is because AddOneToEach is used in IncrementAndComputeVectorSum. 
 * Including the vect_add_one.h header means that the AddOneToEach function declaration is pasted into increment_and_sum.cpp, 
 * so no compiler error will occur when the AddOneToEach function is used.
 * 
 * Only the header file needs to be included in another file.
 * As long as the header file is included, the corresponding function declarations will be included. 
 * When the compiler finds an undefined function, it has already seen the function's declaration. 
 * This means the compiler can continue on without error until it finds the definition of the function, regardless of where that definition is.
 * 
 * Some libraries, like <vector> are included in multiple files.
 * Each file is compiled alone and must have all the declarations and libraries necessary to compile, so the necessary libraries must be included. 
 * This is another reason why include guards are important - if multiple headers were included in main, each with the same #include <vector> statement, 
 * you wouldn't want the vector header pasted multiple times into the code.
 * 
 * The g++ compile command from the "Run Code" button is:
 * g++ -std=c++17 ./code/main.cpp ./code/increment_and_sum.cpp ./code/vect_add_one.cpp && ./a.out
 * 
 * When compiling, each of the relevant .cpp files must be included in the compile command. 
 * The -std=c++17 specifies that we are using the C++ 17 standard (which happens automatically in the terminal).
*/
