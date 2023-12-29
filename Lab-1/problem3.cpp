#include <iostream>
using namespace std;
#include <iomanip>

class Time {
private:
   int hour;     // 0 - 23
   int minute;   // 0 - 59
   int second;   // 0 - 59

// this declaring the constructor
public:
   Time(int h = 0, int m = 0, int s = 0); // passing in the variables into the class - set to 0
   int getHour() const;
   void setHour(int h);
   int getMinute() const;
   void setMinute(int m);
   int getSecond() const;
   void setSecond(int s);
   void setTime(int h, int m, int s);
   void print() const;
};

Time::Time(int h, int m, int s) { //construction definition
   // Call setters to perform input validation
   setHour(h);
   setMinute(m);
   setSecond(s);
}

int Time::getHour() const { // member function definition
   return hour;
}
 
void Time::setHour(int h) {  // with input validation
   if (h >= 0 && h <= 23) { 
      hour = h;
   } else {
      throw invalid_argument("Invalid hour! Hour shall be 0-23.");
            // need <stdexcept>
   }
}
 
int Time::getMinute() const { // member function definition
   return minute;
}
 
void Time::setMinute(int m) {
   if (m >= 0 && m <= 59) {
      minute = m;
   } else {
      throw invalid_argument("Invalid minute! Minute shall be 0-59.");
            // need <stdexcept>
   }
}
 
int Time::getSecond() const {
   return second;
}
 
void Time::setSecond(int s) {
   if (s >= 0 && s <= 59) {
      second = s;
   } else {
      throw invalid_argument("Invalid second! Second shall be 0-59.");
            // need <stdexcept>
   }
}
 
void Time::setTime(int h, int m, int s) {
   // Call setters to validate inputs
   setHour(h);
   setMinute(m);
   setSecond(s);
}
 
void Time::print() const {
   cout << setfill('0');
   cout << setw(2) << hour << ":" << setw(2) << minute << ":"
        << setw(2) << second << endl;
}
 
int main() {
   // Ordinary object
   Time t1(1, 2, 3);
   t1.print();  // 01:02:03
 
   // (Object Pointer - type of pointer that points to an object, which is the 01:02:03)
   Time* ptrT1 = &t1; // pointer is called ptrT1

   // These 2 are redundant functions
   (*ptrT1).print(); // 01:02:03 // print out the value
   ptrT1->print();   // 01:02:03 - does the same thing
    // anObjectPtr->member is the same as (*anObjectPtr).member
 
   // Object reference
   Time& refT1 = t1; // refT1 is an alias to t1 - making another object that is the same is t1
   refT1.print();    // 01:02:03 
 
   // Dynamic allocation
   Time* ptrT2 = new Time(4, 5, 6); // allocate dynamically (made another pointer that has those value)
   ptrT2->print(); // 04:05:06 (print it out)
   delete ptrT2;   // deallocate (delete the box)
 

    
   // Object Array
   Time tArray1[2];    // tArray1 is an array of Time with 2 elements with h, m, s
                       // Use default constructor for all elements
   tArray1[0].print();  // 00:00:00 (print it out, but all 0)
   tArray1[1].print();  // 00:00:00 (print it out, but all 0)
 
   Time tArray2[2] = {Time(7, 8, 9), Time(10)}; // Invoke constructor
   tArray2[0].print();  // 07:08:09 (initializing values for each element)
   tArray2[1].print();  // 10:00:00
 




   Time* ptrTArray3 = new Time[2]; // ptrTArray3 is a pointer to Time
            // Dynamically allocate an array of Time with 2 elements via new[]
   ptrTArray3[0].print();  // 00:00:00 (printing new array)
   ptrTArray3[1].print();  // 00:00:00
   delete[] ptrTArray3;    // Deallocate dynamic array via delete[]
 



   // C++11 syntax, compile with -std=c++0x
   Time* ptrTArray4 = new Time[2] {Time(11, 12, 13), Time(14)}; // Invoke constructor
   ptrTArray4->print();        // 11:12:13
   (ptrTArray4 + 1)->print();  // 14:00:00 - shows how incrementing a pointer that points to an array just goes to the next element of the array
   delete[] ptrTArray4;
}