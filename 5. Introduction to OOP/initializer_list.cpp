#include <assert.h>
#include <string>

class Person {
public:
    Person(std::string name):name(name) {}
    
    std::string name;
    
};

// Test
int main() {
  Person alice("Alice");
  Person bob("Bob");
  assert(alice.name != bob.name);
}