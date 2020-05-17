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



# Pointers

<img src="https://video.udacity-data.com/topher/2019/February/5c6dfebb_pointer/pointer.png" alt="img" style="zoom:33%;" />

Pointers have traditionally been a stumbling block for many students learning C++, but they do not need to be! 

> *A C++ pointer is just a variable that stores the memory address of an object in your program.*

That is the most important thing to understand and remember about pointers - they essentially keep track of *where* a variable is stored in the computer's memory. 

In the previous lessons, you implemented A* search in a single file without using C++ pointers, except in `CellSort` code that was provided for you; a C++ program can be written without using pointers extensively (or at all). However, pointers give you better control over how your program uses memory. However, much like the pass-by-reference example that you saw previously, it can often be far more efficient to perform an operation with a pointer to an object than performing the same operation using the object itself.

Pointers are an extremely important part of the C++ language, and as you are exposed to more C++ code, you will certainly encounter them. In this notebook, you will become familiar with basic pointers so you get comfortable with the syntax, and you will be ready to use them in the course project code.

```cpp
#include <iostream>
using std::cout;

int main() {
    int i = 5;
    int j = 6;
    
    // Print the memory addresses of i and j
    cout << "The address of i is: " << &i << "\n";
    cout << "The address of j is: " << &j << "\n";
}
```

At this point, you might be wondering why the same symbol `&` can be used to both access memory addresses and, as you've seen before, pass references into a function. This is a great thing to wonder about. The overloading of the ampersand symbol `&` and the `*` symbol probably contribute to much of the confusion around pointers.

> **The symbols `&` and `\*` have a different meaning, depending on which side of an equation they appear.**

*This is extremely important to remember.* 

For the `&` symbol, if it appears on the **left side of an equation** (e.g. when declaring a variable), it means that the variable is **declared** as a reference. If the `&` appears on the **right side of an equation**, or before a previously defined variable, it is used to ***return a memory address***, as in the example above.

```cpp
#include <iostream>
using std::cout;

int main() 
{
    int i = 5;
    // A pointer pointer_to_i is declared and initialized to the address of i.
    int* pointer_to_i = &i;
    
    // Print the memory addresses of i and j
    cout << "The address of i is:          " << &i << "\n";
    cout << "The variable pointer_to_i is: " << pointer_to_i << "\n";
}
```

As you can see from the code, the variable `pointer_to_i` is declared as a pointer to an `int` using the `*` symbol, and `pointer_to_i` is set to the address of `i`. From the printout, it can be seen that `pointer_to_i` holds the same value as the address of `i`.

## Passing Pointers to a Function

Pointers can be used in another form of pass-by-reference when working with functions. When used in this context, they work much like the references that you used for pass-by reference previously. 

If the pointer is pointing to a large object, it can be much more efficient to pass the pointer to a function than to pass a copy of the object as with pass-by-value.

In the following code, a pointer to an int is created, and that pointer is passed to a function. The object pointed to is then modified in the function.

```cpp
#include <iostream>
using std::cout;

void AddOne(int* j)
{
    // Dereference the pointer and increment the int being pointed to.
    (*j)++;
}

int main() 
{
    int i = 1;
    cout << "The value of i is: " << i << "\n";
    
    // Declare a pointer to i:
    int* pi = &i;
    AddOne(pi);
    cout << "The value of i is now: " << i << "\n";
}
```

When using pointers with functions, some care should be taken. If a pointer is passed to a function and then assigned to a variable in the function that goes out of scope after the function finishes executing, then the pointer will have undefined behavior at that point - the memory it is pointing to might be overwritten by other parts of the program.

## Returning a Pointer from a Function

You can also return a pointer from a function. As mentioned just above, if you do this, you must be careful that the object being pointed to doesn't go out of scope when the function finishes executing. If the object goes out of scope, the memory address being pointed to might then be used for something else.

In the example below, a reference is passed into a function and a pointer is returned. This is safe since the pointer being returned points to a reference - a variable that exists outside of the function and will not go out of scope in the function.

```cpp
// Declare a pointer and initialize to the value
    // returned by AddOne:
    int* my_pointer = AddOne(i);
    cout << "The value of i is now: " << i << "\n";
    cout << "The value of the int pointed to by my_pointer is: " << *my_pointer << "\n";
}
```



## References vs Pointers

Pointers and references can have similar use cases in C++. As seen previously both references and pointers can be used in pass-by-reference to a function. Additionally, they both provide an alternative way to access an existing variable: pointers through the variable's address, and references through another name for that variable. But what are the differences between the two, and when should each be used? The following list summarizes some of the differences between pointers and references, as well as when each should be used:

| References                                                   | Pointers                                                     |
| :----------------------------------------------------------- | :----------------------------------------------------------- |
| References must be initialized when they are declared. This means that a reference will always point to data that was intentionally assigned to it. | Pointers can be declared without being initialized, which is dangerous. If this happens mistakenly, the pointer could be pointing to an arbitrary address in memory, and the data associated with that address could be meaningless, leading to undefined behavior and difficult-to-resolve bugs. |
| References can not be null. This means that a reference should point to meaningful data in the program. | Pointers can be null. In fact, if a pointer is not initialized immediately, it is often best practice to initialize to `nullptr`, a special type which indicates that the pointer is null. |
| When used in a function for pass-by-reference, the reference can be used just as a variable of the same type would be. | When used in a function for pass-by-reference, a pointer must be dereferenced in order to access the underlying object. |

References are generally easier and safer than pointers. As a decent rule of thumb, references should be used in place of pointers when possible. 

However, there are times when it is not possible to use references. One example is object initialization. You might like one object to store a reference to another object. However, if the other object is not yet available when the first object is created, then the first object will need to use a pointer, not a reference, since a reference cannot be null. The reference could only be initialized once the other object is created.



# Maps

A map (alternatively [hash table](https://en.wikipedia.org/wiki/Hash_table), hash map, or dictionary) is a data structure that uses *key/value* pairs to store data, and provides efficient lookup and insertion of the data. The name "dictionary" should provide an excellent idea of how these work, since a dictionary is a real life example of a map. Here is a slightly edited entry from [www.dictionary.com](https://www.dictionary.com/browse/word?s=t) defining the word "word":

> word
>
> - a unit of language, consisting of one or more spoken sounds or their written representation, that functions as a principal carrier of meaning. 
> - speech or talk: to express one's emotion in words.
> - a short talk or conversation: "Marston, I'd like a word with you."
> - an expression or utterance: a word of warning.

## Data Representation

If you were to store this data in your program, you would probably want to be able to quickly look up the definitions using the *key* "word". With a map, a vector of definitions could be stored as the *value*corresponding to the "word" key: 

| Key `string` | Value `vector`                                               |
| :----------- | :----------------------------------------------------------- |
| `"word"`     | `<"a unit of language, consisting of one or more spoken sounds or their written representation, that functions as a principal carrier of meaning.", "speech or talk: to express one's emotion in words.", "a short talk or conversation: 'Marston, I'd like a word with you.'", "an expression or utterance: a word of warning.">'` |

In the following notebook, you will learn how to use an `unordered_map`, which is the C++ standard library implementation of a map. Although C++ has several different implementations of map data structures which are similar, `unordered_map` is the structure that you will use in your project.



In the code below, we check if the `key` is in the `unordered_map` using the `.find()`method. If the key does not exist in the map, then `.find()` returns an `unordered_map::end()` type. Otherwise, `.find()` returns a [C++ iterator](http://www.cplusplus.com/reference/iterator/), which is a pointer that points to the beginning of the iterable key-value pair.

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using std::vector;
using std::cout;
using std::unordered_map;
using std::string;


int main() {
    // Create strings to use in the hash table.
    string key = "word";
    string def_1 = "a unit of language, consisting of one or more spoken sounds or their written representation, that functions as a principal carrier of meaning";
    string def_2 = "speech or talk: to express one's emotion in words";
    string def_3 = "a short talk or conversation: 'Marston, I'd like a word with you.'";
    string def_4 = "an expression or utterance: a word of warning";
    unordered_map <string, vector<string>> my_dictionary;

    // Check if key is in the hash table.
    if (my_dictionary.find(key) == my_dictionary.end()) {
        cout << "The key 'word' is not in the dictionary." << "\n";
        cout << "Inserting a key-value pair into the dictionary." << "\n\n";
        // Set the value for the key.
        my_dictionary[key] = vector<string> {def_1, def_2, def_3, def_4};
    }

    // The key should now be in the hash table. You can access the
    // value corresponding to the key with square brackets [].
    // Here, the value my_dictionary[key] is a vector of strings.
    // We iterate over the vector and print the strings.
    cout << key << ": \n";
    auto definitions = my_dictionary[key];
    for (string definition : definitions) {
        cout << definition << "\n";
    }
}


```

