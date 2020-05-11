#include <iostream>
#include <vector>

int sum(const std::vector<int> &v)
{
    int sum = 0;
    for(int i : v)
        sum += i;
    return sum;
}

int main()
{
    int i;
    std::cout << "Enter an integer value for i: ";
    std::cin >> i;
    const int j = i * 2;  // "j can only be evaluated at run time."
                          // "But I promise not to change it after it is initialized."
    
    constexpr int k = 3;  // "k, in contrast, can be evaluated at compile time."
    
    std::cout << "j = " << j << "\n";
    std::cout << "k = " << k << "\n";

    const int i = 2;    // "I promise not to change this."
    i++;                // "I just broke my promise."

    constexpr int i = 2;    // "i can be evaluated at compile time."
     i++;                   // "But changing a constexpr variable triggers an error."

    // The compiler will catch a constexpr variable that cannot be evaluated at compile time.
    int i;
    std::cout << "Enter an integer value for i: ";
    std::cin >> i;
    constexpr int j = i * 2;  // "j can only be evaluated at run time."
                              // "constexpr must be evaluated at compile time."
                              // "So this code will produce a compilation error."

    // A common usage of const is to guard against accidentally changing a variable, 
    // especially when it is passed-by-reference as a function argument.

    std::vector<int> v {0, 1, 2, 3, 4};
    std::cout << sum(v) << "\n";

    // The distinction between const and constexpr is subtle.
    // In general, though, const is much more common than constexpr.
    // When in doubt, use const, especially to guard against accidentally modifying a variable.
}