# Header Files

<img src="https://video.udacity-data.com/topher/2019/February/5c6dea9e_header-file/header-file.png" alt="img" style="zoom:50%;" />

Header files, or `.h` files, allow related function, method, and class declarations to be collected in one place. The corresponding definitions can then be placed in `.cpp` files. The compiler considers a header declaration a "promise" that the definition will be found later in the code, so if the compiler reaches a function that hasn't been defined yet, it can continue on compiling until the definition is found. This allows functions to be defined (and declared) in arbitrary order.

- The function declarations in the header file don't need variable names, just variable types. You can put names in the declaration, however, and doing this often makes the code easier to read.

- The `#include` statement for the header used quotes `" "` around the file name, and not angle brackets `<>`. We have stored the header in the same directory as the `.cpp` file, and the quotes tell the preprocessor to look for the file in the same directory as the current file - not in the usual set of directories where libraries are typically stored.

- Finally, there is a preprocessor directive:

  ```cpp
  #ifndef HEADER_EXAMPLE_H
  #define HEADER_EXAMPLE_H
  ```

  at the top of the header, along with an `#endif`  at the end. This is called an "**include guard**". 

  Since the header will be included into another file, and `#include` just pastes contents into a file, the include guard prevents the same file from being pasted multiple times into another file. This might happen if multiple files include the same header, and then are all included into the same `main.cpp`, for example. 

  The `ifndef`  checks if

  ```cpp
  HEADER_EXAMPLE_H
  ```

   has not been defined in the file already. 

  If it has not been defined yet, then it is defined with 

  ```cpp
  #define HEADER_EXAMPLE_H
  ```

  , and the rest of the header is used. 

  If `HEADER_EXAMPLE_H`  has already been defined, then the preprocessor does not enter the `ifndef` block.

   

  Note:

  There are other ways to do this. Another common way is to use an `#pragma once. preprocessor directive, but we won't cover that in detail here.

   

## Using Headers with Multiple Files

![img](https://video.udacity-data.com/topher/2019/February/5c6f0084_c-and-h-2/c-and-h-2.png)

If you look carefully at the files above, you will see several things:

- `vect_add_one.h` is included in `increment_and_sum.cpp`.

  > This is because `AddOneToEach` is used in `IncrementAndComputeVectorSum`. Including the `vect_add_one.h` header means that the `AddOneToEach` function declaration is pasted into `increment_and_sum.cpp`, so no compiler error will occur when the `AddOneToEach` function is used.

- Only the header file needs to be included in another file. 

  > As long as the header file is included, the corresponding function declarations will be included. When the compiler finds an undefined function, it has already seen the function's declaration. This means the compiler can continue on without error until it finds the definition of the function, regardless of where that definition is.

- Some libraries, like `` are included in multiple files.

  > Each file is compiled alone and must have all the declarations and libraries necessary to compile, so the necessary libraries must be included. This is another reason why [include guards](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rs-guards) are important - if multiple headers were included in `main`, each with the same `#include ` statement, you wouldn't want the `vector`header pasted multiple times into the code.

- The `g++` compile command from the "Run Code" button is:

  ```bash
  g++ -std=c++17 ./code/main.cpp ./code/increment_and_sum.cpp ./code/vect_add_one.cpp && ./a.out
  ```

  > When compiling, each of the relevant `.cpp` files must be included in the compile command. The `-std=c++17` specifies that we are using the C++ 17 standard (which happens automatically in the terminal).



# References

You have seen references used previously, in both pass-by-reference for functions, and in a range-based`for` loop example that used references to modify a vector. As you write larger C++ programs, you will find references useful in a variety of situations. In this short notebook, you will see a few more examples of references to solidify your knowledge.

> As mentioned previously, a reference is another name given to an existing variable. 
>
> On the left hand side of any variable declaration, the `&` operator can be used to declare a reference.

```cpp
#include <iostream>
using std::cout;

int main() 
{
    int i = 1;
    
    // Declare a reference to i.
    int& j = i;
    cout << "The value of j is: " << j << "\n";
    
    // Change the value of i.
    i = 5;
    cout << "The value of i is changed to: " << i << "\n";
    cout << "The value of j is now: " << j << "\n";
    
    // Change the value of the reference.
    // Since reference is just another name for the variable,
    // th
    j = 7;
    cout << "The value of j is now: " << j << "\n";
    cout << "The value of i is changed to: " << i << "\n";
}
```

