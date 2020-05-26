// This example demonstrates the privacy levels
// between parent and child classes
#include <iostream>
#include <string>
using std::string;

class Vehicle {
public:
    int wheels = 0;
    string color = "blue";
    
    void Print() const
    {
        std::cout << "This " << color << " vehicle has " << wheels << " wheels!\n";
    }
};

class Car : public Vehicle {
public:
    bool sunroof = false;
};

class Bicycle : protected Vehicle {
public:
    bool kickstand = true;
};

class Scooter : private Vehicle {
public:
    bool electric = false;
};

int main() 
{
    Car car;
    Bicycle bicycle;
    Scooter scooter;
    
    std::cout << bicycle.kickstand << "\n";
    std::cout << scooter.electric << "\n";
    
    // the color variable cannot be accessed outside because the classes Scooter and Bicycle restricts usage of it.
 
    // std::cout << bicycle.color << "\n";
    //std::cout << scooter.color << "\n";

};