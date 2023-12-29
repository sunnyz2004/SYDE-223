// Write a program that finds the length of a text using pointers. 
// Text is input as a string 
// The maximum length of the text is 500 characters 

// Use a for loop from the first character of the array

#include <iostream>
#define MAX_SIZE 500 // Maximum size of the string
using namespace std;
 
int main() {
 
    char text[MAX_SIZE]; // setting max to 500
    char * str = text; // set the pointer to point to the first character of the text
    int count = 0; // initialize the count to 0
 
    // Inputtin string from user
    cout<<"Enter any string: ";
    cin>>text;
 
    // Iterating though last element of the string
    while(*(str++) != '\0'){
        count++; // while the next pointer is not zero, move the string to the next character and add the count
    }
    
    cout<<"Length of "<<text<<" is "<<count;
 
    return 0;
}

//This line uses a while loop to iterate through the characters of the string. 
// It starts by incrementing the str pointer until it points to the null character '\0', 
// which marks the end of the string. During each iteration of the loop, the count variable is incremented.

