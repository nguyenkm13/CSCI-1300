// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 - Sravanth Yajamanam
// Homework 5 - Problem #1

#include <iostream>
using namespace std;

// This program declares and populates four arrays. 

int main()
{
    // an array of 10 doubles initialized with -459.67 (absolute zero in fahrenheit).
    double temps[10];
    for(int i = 0; i < 10; i++)
    {
        temps[i] = -459.67;
        cout << temps[i] << endl;
    }
    
    cout << endl;
    
    // an array of the strings “Red”, “Blue”, “Green”, “Cyan”, and “Magenta”.
    string colors[5] = {"Red", "Blue", "Green", "Cyan", "Magenta"};
    for(int i = 0; i < 5; i++)
    {
        cout << colors[i] << endl;
    }
    
    cout << endl;
    
    // an array of the integers between 1 to 100, inclusive
    int sequence[100];
    for(int i = 0; i < 100; i++)
    {
        sequence[i] = i + 1;
        cout << sequence[i] << endl;
    }
    
    cout << endl;
    
    // a two dimensional array with the capital and lower case of each letter in alphabetical order
    char letters[26][2];
    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            if(j == 0)
            {
               letters[i][j] = char(65 + i); 
            }
            
            else 
            {
               letters[i][j] = char(97 + i); 
            }
            
            cout << letters[i][j] << " ";
            if(j % 2 == 1)
            {
                cout << endl;
            }
        }
    }

    return 0;
}