// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 - Sravanth Yajamanam
// Homework 4 - Problem #2

#include <iostream>
using namespace std;

//This program prints a Collatz sequence

int main()
{
    //User inputs a positive integer
    int number;
    cout << "Enter a positive number: " << endl;
    cin >> number;
    cout << number << endl;
    
    //This loop continues until the resulting number is one
    while(number != 1)
    {
        //If the number is even, it is divided by 2
        if(number % 2 == 0)
        {
            number = number / 2;
            cout << number << endl;
        }
        
        //If the number is odd, it is multiplied by 3 then added to 1
        else
        {
            number = (3 * number) + 1;
            cout << number << endl;
        }
    }
    
    return 0;
}