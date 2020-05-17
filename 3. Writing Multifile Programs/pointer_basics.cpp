#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int main() {
    int i = 5;
    int j = 6;
    
    // Print the memory addresses of i and j
    cout << "The address of i is: " << &i << "\n";
    cout << "The address of j is: " << &j << "\n";

    int k = 5;
    // A pointer pointer_to_i is declared and initialized to the address of i.
    int* pointer_to_k = &k;
    
    // Print the memory addresses of i and j
    cout << "The address of k is:          " << &k << "\n";
    cout << "The variable pointer_to_k is: " << pointer_to_k << "\n";
    cout << "The value of the variable pointed to by pointer_to_k is: " << *pointer_to_k << "\n";

    k = 7;
    cout << "The new value of k is:          " << k << "\n";
    cout << "The value of the variable pointed to by pointer_to_k is: " << *pointer_to_k << "\n";

    // Vector v is declared and initialized to {1, 2, 3}
    vector<int> v {1, 2, 3};
    
    // Declare and initialize a pointer to the address of v here:
    vector<int>* pointer_to_v = &v;

    // The following loops over each int a in the vector v and prints.
    // Note that this uses a "range-based" for loop:
    // https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Res-for-range
    for (int a: v) {
        cout << a << "\n";
    }
    
    // Dereference your pointer to v and print the int at index 0 here (note: you should print 1):
    cout << "Value at index 0: " << (*pointer_to_v)[0] << "\n";
}