// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 - Sravanth Yajamanam
// Homework 4 - Problem #1

#include <iostream>
using namespace std;

// This program outputs the sum of all even numbers from 0 to given positive integer, inclusive.

int main()
{
    //User inputs a positive integer
    int number, even, sum = 0;
    cout << "Enter a positive number:" << endl;
    cin >> number;
    
    //Sums all positive even numbers less than or equal to the input
    for(int i = 0; i <= number / 2; i++)
    {
        even = i * 2;
        sum = sum + even;
    }
    
    //Outputs the sum
    cout << "Sum: " << sum;
    
    return 0;
}