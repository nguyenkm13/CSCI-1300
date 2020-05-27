// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 - Sravanth Yajamanam
// Homework 5 - Problem #5

#include <iostream>
#include <vector>
using namespace std;

// This program populates a vector based on user inputs

int main()
{
    int input, min, max;
    vector<int> numbers;
    
    // the array is populated with user input unless the user input is -1
    do
    {
        cout << "Please enter a number:\n";
        cin >> input;
        
        //If the vector is empty, the program inserts the user input value into the vector
        if(numbers.size() == 0 && input != -1)
        {
            numbers.push_back(input);
        }
        
        //If the user input is divisible by 5, the first element of the vector is removed
        else if(input % 5 == 0)
        {
            numbers.erase(numbers.begin());
        }
        
        //If the user input is divisible by 3, the last element of the vector is removed
        else if(input % 3 == 0)
        {
            numbers.pop_back();
        }
        
        //Otherwise, the user input is added to the end of the vector
        else if(input != -1)
        {
            numbers.push_back(input);
        }
        
    }while(input != -1);
    
    // finds the minimum of the vector elements
    min = numbers[0];
    for(int i = 0; i < numbers.size(); i++)
    {
        if(numbers.at(i) < min)
        {
            min = numbers[i];
        }
    }
    
    // finds the maximum of the vector elements
    max = numbers[0];
    for(int i = 0; i < numbers.size(); i++)
    {
        if(numbers[i] > max)
        {
            max = numbers[i];
        }
    }
    
    // Outputs the elements of the vector
    cout << "The elements in the vector are: ";
    for(int i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << ' ';
    }
    
    //Outputs the minimum and maximum of the vector elements
    cout << "\nMin = " << min << endl << "Max = " << max;
    
    return 0;
}