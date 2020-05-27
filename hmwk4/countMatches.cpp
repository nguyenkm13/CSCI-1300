// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 - Sravanth Yajamanam
// Homework 4 - Problem #5

#include <iostream>
using namespace std;

//This programs counts the number of times a certain substring occurs in a mother string

int main() 
{
    string input, search_string;
    
    //User enters the mother string and the substring
    cout << "Enter the search string:" << endl;
    cin >> input;
    cout << "Enter the substring to be searched:" << endl;
    cin >> search_string;
    int occurances = 0;
    
    //The loop find all occurances of the substring
    for(int i = 0; i < input.length(); i++)
    {
        if(search_string == input.substr(i, search_string.length()))
        {
            occurances++;
        }
    }
    
    //Outputs the number of substring occurances
    cout << "Number of occurrences: " << occurances;
    
    return 0;
}