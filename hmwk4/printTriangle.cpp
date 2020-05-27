// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 - Sravanth Yajamanam
// Homework 4 - Problem #6

#include <iostream>
using namespace std;

//Program prints an alphabetical triangle

int main()
{
    int length, counter = 0;
    string primary, alphabet = "abcdefghijklmnopqrstuvwxyz";
    
    //User enters the desired height of the triangle
    cout << "Enter the height: " << endl;
    cin >> length;
    
    //Creates a repeating string of alphabet characters
    for(int i = 0; i <=50; i++)
    {
        primary += alphabet;
    }
    
    //Prints the triangle
    while (length >= 0)
    {  
      cout << primary.substr(counter, length) << endl;
      counter = counter + (length);
      length--; 
    }    
    
    return 0;
}