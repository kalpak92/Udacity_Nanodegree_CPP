# Header Files

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



# Classes and Object-Oriented Programming

![img](https://video.udacity-data.com/topher/2019/February/5c6f2d05_object/object.png)

OOP is a style of coding that collects related data (object *attributes*) and functions (object *methods*) together to form a single data structure, called an *object*. This allows that collection of attributes and methods to be used repeatedly in your program without code repetition.

In C++ the attributes and methods that make up an object are specified in a code *class*, and each object in the program is an *instance* of that class. 

This concept is intended to provide you with the basic syntax for writing classes in C++.

```cpp
#include <iostream>
#include <string>
using std::string;
using std::cout;

class Car {
  public:
    void PrintCarData() 
    {
        cout << "The distance that the " << color << " car " << number << " has traveled is: " << distance << "\n";
    }

    void IncrementDistance() 
    {
        distance++;
    }
    
    // Adding a constructor here:
    Car(string c, int n) 
    {
        // Setting the class attributes with
        // The values passed into the constructor.
        color = c;
        number = n;
    }
    
    string color;
    int distance = 0;
    int number;
};

int main() 
{
    // Create class instances for each car.
    Car car_1 = Car("green", 1);
    Car car_2 = Car("red", 2);
    Car car_3 = Car("blue", 3);

    // Increment car_1's position by 1.
    car_1.IncrementDistance();

    // Print out the position and color of each car.
    car_1.PrintCarData();
    car_2.PrintCarData();
    car_3.PrintCarData();
}
```



## Inheritance

It is possible for a class to use methods and attributes from another class using class *inheritance*. For example, if you wanted to make a `Sedan` class with additional attributes or methods not found in the generic `Car` class, you could create a `Sedan` class that inherited from the `Car` by using the colon notation:

```cpp
class Sedan : public Car {
    // Sedan class declarations/definitions here.
};
```

By doing this, each `Sedan` class instance will have access to any of the *public* methods and attributes of `Car`. In the code above, these are`IncrementDistance()` and `PrintCarData()`. You can add additional features to the `Sedan` class as well. In the example above, `Car` is often referred to as the *parent* class, and `Sedan` as the *child* or *derived* class.



If you were planning to build a larger program, at this point it might be good to put your class definition and function declarations into a separate file. Just as when we discussed header files before, putting the class definition into a separate header helps to organize your code, and prevents problems with trying to use class objects before the class is defined.

There are two things to note in the code below. 

1. When the class methods are defined outside the class, the ***scope resolution operator*** `::` must be used to indicate which class the method belongs to. For example, in the definition of the `PrintCarData` method you see:

   ```cpp
   void Car::PrintCarData()
   ```

   This prevents any compiler issues if there are are two classes with methods that have the same name.
   

2. We have changed how the constructor initializes the variables. Instead of the previous constructor:

   ```cpp
   Car(string c, int n) {
      color = c; 
      number = n;
   }
   ```

   the constructor now uses an [*initializer list*](https://en.cppreference.com/w/cpp/language/initializer_list):

   ```cpp
   Car(string c, int n) : color(c), number(n) {}
   ```

   Here, the class members are initialized before the body of the constructor (which is now empty). 
   ***Initializer lists are a quick way to initialize many class attributes in the constructor.***
   Additionally, the compiler treats attributes initialized in the list slightly differently than if they are initialized in the constructor body. 
   ***For reasons beyond the scope of this course, if a class attribute is a reference, it must be initialized using an initializer list.***

3. Variables that don't need to be visible outside of the class are set as `private`. This means that they can not be accessed outside of the class, which [prevents them from being accidentally changed](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rc-private).



```cpp
#ifndef CAR_H
#define CAR_H

#include <string>
using std::string;
using std::cout;

class Car {
  public:
    void PrintCarData();
    void IncrementDistance();
    
    // Using a constructor list in the constructor:
    Car(string c, int n) : color(c), number(n) {}
  
  // The variables do not need to be accessed outside of
  // functions from this class, so we can set them to private.
  private:
    string color;
    int distance = 0;
    int number;
};

#endif
```

```c++
#include <iostream>
#include "car.h"

// Method definitions for the Car class.
void Car::PrintCarData() 
{
    cout << "The distance that the " << color << " car " << number << " has traveled is: " << distance << "\n";
}

void Car::IncrementDistance() 
{
    distance++;
}
```

**car_main.cpp**

```cpp
#include <iostream>
#include <string>
#include "car.h"
using std::string;
using std::cout;

int main() 
{
    // Create class instances for each car.
    Car car_1 = Car("green", 1);
    Car car_2 = Car("red", 2);
    Car car_3 = Car("blue", 3);

    // Increment car_1's position by 1.
    car_1.IncrementDistance();

    // Print out the position and color of each car.
    car_1.PrintCarData();
    car_2.PrintCarData();
    car_3.PrintCarData();

}
```



## Scaling Up

In this concept and the previous one, you took code without classes and converted it into an object-oriented format.

In case you aren't convinced that organizing the code using OOP saved you some trouble, the next cell redefines `main.cpp` to generate 100 cars with different colors, move each, and print data about each. This would have been extremely difficult to do if you had to manually create new variables for each car!

There is a lot going on in the code to unpack, including the `new` keyword and the `->`operator. The arrow operator `->` is used to simultaneously 

- dereference a pointer to an object and 
- access an attribute or method. 

For example, in the code below, `cp` is a pointer to a Car object, and the following two are equivalent:

```cpp
// Simultaneously dereference the pointer and 
// access IncrementDistance().
cp->IncrementDistance();

// Dereference the pointer using *, then 
// access IncrementDistance() with traditional 
// dot notation.
(*cp).IncrementDistance();
```

The `new` operator allocates memory on the "heap" for a new Car. In general, this memory must be manually managed (deallocated) to avoid memory leaks in your program. Memory management is the primary focus of one of the later courses in this Nanodegree program, so we won't go into greater depth about the difference between stack and heap in this lesson.

Click on the explanation button for a discussion of the code. 

**Note:** This `main.cpp` uses the class files defined above, so be sure you have run the previous example before running this one.

```c++
#include <iostream>
#include <string>
#include <vector>
#include "car.h"
using std::string;
using std::cout;
using std::vector;

int main() {
    // Create an empty vector of pointers to Cars 
    // and a null pointer to a car.
    vector<Car*> car_vect;
    Car* cp = nullptr;
    
    // The vector of colors for the cars:
    vector<string> colors {"red", "blue", "green"};

    // Create 100 cars with different colors and 
    // push pointers to each of those cars into the vector.
    for (int i=0; i < 100; i++) {;
        cp = new Car(colors[i%3], i+1);
        car_vect.push_back(cp);
    }

    // Move each car forward by 1.
    for (Car* cp: car_vect) {
        cp->IncrementDistance();
    }

    // Print data about each car.
    for (Car* cp: car_vect) {
        cp->PrintCarData();
    }
}
```



# This Pointer

When working with classes it is often helpful to be able to refer to the current class instance or object. For example, given the following `Car` class from a previous lesson, the `IncrementDistance()` method implicitly refers to the current `Car` instance's `distance` attribute:

```cpp
// The Car class
class Car {
  public:
    // Method to print data.
    void PrintCarData() {
        cout << "The distance that the " << color << " car " << number << " has traveled is: " << distance << "\n";
    }

    // Method to increment the distance travelled.
    void IncrementDistance() {
        distance++;
    }

    // Class/object attributes
    string color;
    int distance = 0;
    int number;
};
```



It is possible to make this explicit in C++ by using the `this` pointer, which points to the current class instance. Using `this` can sometimes be helpful to add clarity to more complicated code:

```cpp
// The Car class
class Car {
  public:
    // Method to print data.
    void PrintCarData() {
        cout << "The distance that the " << this->color << " car " << this->number << " has traveled is: " << this->distance << "\n";
    }

    // Method to increment the distance travelled.
    void IncrementDistance() {
        this->distance++;
    }

    // Class/object attributes
    string color;
    int distance = 0;
    int number;
};
```

