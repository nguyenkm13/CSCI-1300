// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 - Sravanth Yajamanam
// Homework 5 - Problem #6

#include <iostream>
using namespace std;

/*
* This function takes a string, splits it at every occurance of a delimiter, and then populates an array of strings with the split pieces, up to the provided maximum number of pieces.
* Parameters: input - a string to be split, delimiter - separator character which marks where the string should be split up, 
    arr - array of string, where the split-apart string pieces will be stored, size - size of the array
* Return: number of pieces the string was split into, as an integer.
*/

int split(string input, char delimiter, string arr[], int size)
{
    input.push_back(delimiter);
    int pos = 0;
    for(int i = 0; i < input.length(); i++)
    {
        //Deletes multiple occurances of delimiters
        while(input[0] == delimiter)
        {
            input.erase(0,1);
        }
        
        //places the substring piece between delimiters into the array
        if(input[i] == delimiter)
        {
            arr[pos] = input.substr(0, i);
            
            //clears the begining of the string 
            input.erase(0, i + 1);
            
            //resets i
            i = 0;
            
            // Adds one to the piece counter
            pos ++;
        }
    }
    
    // If the string is split into more pieces than the size of the array, then it returns -1.
    if(pos > size)
    {
        return -1;
    }
    
    // Otherwise, the function returns the number of pieces was split into
    else 
    {
        return pos;
    }
}

int main()
{
    
    string text; 
    string myArray[4];
    char separator;
    const int SIZE = 4;
    
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the separator: ";
    cin >> separator;
   
    cout << "Return value: " << split(text, separator, myArray, SIZE) << endl;
   
    for(int i = 0; i < SIZE; i++)
    {
       if(myArray[i] != "")
       {
           cout << "myArray["  << i << "]:" << myArray[i] << endl;
       }
    }
    
    return 0; 
}