#include <cassert>
#include <stdexcept>
#include <string>

using std::string;

// TODO: Define "Student" class
class Student {
 public:
  // constructor
  Student(string name, int grade, double gpa) : name_(name), grade_(grade), gpa_(gpa) {
      Validate();
  }
  // accessors
  string Name() const {
      return name_;
  }
  int Grade() const {
      return grade_;
  }
  double GPA() const {
      return gpa_;
  }
    
  // mutators
  void Name(string name) {
      name_ = name;
      Validate();
  }
  void Grade(int grade) {
      grade_ = grade;
      Validate();
  }
  void GPA(double gpa) {
      gpa_ = gpa;
      Validate();
  }

 private:
 string name_;
 int grade_;
 double gpa_;
 void Validate() {
     if(Grade() < 0 || Grade() > 12 || GPA() < 0.0 || GPA() > 4.0)
         throw std::invalid_argument("argument out of bounds");
 }
};

// TODO: Test
int main() {
    Student david("Kalpak Seal", 11, 3.83);
    assert(david.Name() == "Kalpak Seal");
    assert(david.Grade() == 11);
    assert(david.GPA() == 3.83);
    
    bool caught{false};
    try {
        david.Grade(20);
    }
    catch(...) {
        caught = true;
    }
    assert(caught);
}