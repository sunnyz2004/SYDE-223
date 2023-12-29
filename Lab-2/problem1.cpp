#include <iostream>
using namespace std;

class Student {
private:
    string name; // private variable to use for member function

public:
    Student(string name) {
        this->name = name; // storing the name into the student class (constructor - pointers do not use .name)
    }

    string get_name() {
        return name; // return the name (as a member function)
    }
};

//Student::Student(string name){ // initializing the constructor (outside of the main)
    //this->name = name;
//};

//OR another way of making constructor
// Student(string name): name(name){};

int main() {
    string name = "Sunny"; // make a name
    Student student1(name); // make an object with name Sunny
    cout << student1.get_name() << endl; // pass in the name and print it out

    return 0;
}
