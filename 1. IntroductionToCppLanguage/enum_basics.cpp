#include <iostream>
using std::cout;

int main()
{
    enum class Color {white, black, red, green, blue};

    Color my_color =  Color::blue;

    if(my_color == Color::red)
    {
        cout << "The color of my car is red!" << "\n";
    }
    else
        cout << "The color of my car is not red" << "\n";

    enum class Direction {kUp, kDown, kLeft, kRight};

    Direction a = Direction::kDown;

    switch (a) 
    {
      case Direction::kUp : cout << "Going up!" << "\n";
        break;
      case Direction::kDown : cout << "Going down!" << "\n";
        break;
      case Direction::kLeft : cout << "Going left!" << "\n";
        break;
      case Direction::kRight : cout << "Going right!" << "\n";
        break;
    }

}