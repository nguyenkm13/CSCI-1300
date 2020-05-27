// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 - Sravanth Yajamanam
// Homework 4 - Extra Credit Problem

#include <iostream>
using namespace std;

// This program prints a diamond

int main()
{
    int rows;
    
    //User enters the desired number of rows
    cout << "Enter the length: " << endl;
    cin >> rows;
    int space = rows, space2 = rows - 2;
    
    //Prints the top half of the diamond
    for(int i = 0; i < rows; i++)
    {
        cout << string(space - 1, ' ');
        cout << string(2 * i + 1, '*') << endl;
        space--;
    }
    
    //Prints the bottom half of the diamond
    for(int i2 = 2; i2 <= rows; i2++)
    {
        cout << string(i2 - 1, ' ');
        cout << string(2* space2 + 1, '*') << endl;
        space2 --;
    }
  
    return 0;
}