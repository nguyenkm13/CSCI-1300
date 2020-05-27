// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 – Sravanth Yajamanam
// Project 1 - Problem #3

#include <iostream>
using namespace std;

/*
* This function returns a new string with all characters converted to uppercase.
* Parameters: input - string that will be converted to upper case
* Return: string with all upper cases
*/

string toUpper(string input)
{
    string output = "";
    for(int i = 0; i < input.length(); i++)
    {
        if(input[i] >= 'a' && input[i] <='z')
        {
            output += input[i] - 32;
        }
        else
        {
           output += input[i];
        }
    }
    return output;
}

int main()
{
    // User enters the string to be converted
    string orig;
    cout << "Enter the string: ";
    getline(cin, orig);
    
    // Program calls toUpper fucntion and prints result
    cout << toUpper(orig);

	return 0;
}