// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 – Sravanth Yajamanam
// Project 1 - Problem #1

#include <iostream>
#include <cmath>
using namespace std;

/*
* This function calculates and returns the surface area of a square pyramid.
* Parameters: b - base length, s - slant height
* Return: surface area 
*/

double surfaceArea(double b, double s)
{
    double surface_area = 2 * b* s + pow(b, 2);
    if (s < 0 || b < 0) 
    {
        return -1;
    }
    else 
    {
       return surface_area; 
    }
}

int main() 
{
    //User enters base length and slant height
    double base, slant_length;
    cout << "Enter the base length:\n";
    cin >> base;
    cout << "Enter the slant height:\n";
    cin >> slant_length;
    
    //If any of the inputs are negative, the program displays "Invalid values"
    if(surfaceArea(base, slant_length) == -1) 
    {
        cout << "Invalid values";
    }
    
    //If both inputs are positive, the program calls the surfaceArea fuction
    else 
    {
        cout << "The surface area: " << surfaceArea(base, slant_length);
    }
    
    return 0;
}