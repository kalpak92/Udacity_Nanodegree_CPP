#include <iostream>
#include "car.h"

// Method definitions for the Car class.
void Car::PrintCarData() 
{
    cout << "The distance that the " << this->color << " car " << this->number << " has traveled is: " << this->distance << "\n";
}

void Car::IncrementDistance() 
{
    this->distance++;
}