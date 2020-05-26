#include <assert.h>

// TODO: Create a generic function Product that multiplies two parameters
template <typename T>
T Product(T a, T b)
{
    return a * b;
};

template <typename T>
T Max(T a, T b)
{
    return a > b ? a : b;
}

template <typename T>
T average(T a, T b)
{
    return (a + b) / 2;
}

int main() { 
  assert(Product<int>(10, 2) == 20); 

  assert(Max(10, 50) == 50);
  assert(Max(5.7, 1.436246) == 5.7);

  assert(average(2.0,5.0) == 3.5);
}