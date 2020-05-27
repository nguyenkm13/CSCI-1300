// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 – Sravanth Yajamanam
// Project 1 - Problem #2

#include <iostream>
#include <cmath>
using namespace std;

/*
* This function calculates the displacement of a braking vehicle.
* Parameters: I - initial velocity, F - final velocity, a - Deceleration
* Return: displacement
*/

double displacement(double I, double F, double a)
{
    int i = 0;
    
    //if I or F are negative, the function prints "Velocity should be greater than zero"
    if(I < 0 || F < 0)
    {
        cout << "Velocity should be greater than zero.\n";
        i++;
    }
    
    //If decceleration is 0, function prints "No brakes were applied"
    if (a == 0) 
    {
        cout << "No brakes were applied.\n";
        i++;
    }
    
    //If decceleration is negative, function prints "The vehicle is speeding up"
    if(a < 0)
    {
        cout << "The vehicle is speeding up.\n";
        i++;
    }
    
    //If final velocity is greater than initial velocity, function prints "Error in acceleration values"
    if(F > I)
    {
        cout << "Error in acceleration values.\n";
        i++;
    }
    
    //If any of the above conditions are true, function returns zero.
    if(i > 0)
    {
        return 0;
    }
    
    //If none of the above conditions are true, fucntion calculates displacement 
    // as (F^2 -I^2) / (-2 * a)
    else
    {
        double D = (pow(F, 2) - pow(I,2)) / (-2 * a);
        return D;
    }
}

int main()
{
    //User enters initial velocity, final velocity, and deceleration
    double initial_velocity, final_velocity, deceleration;
    cout << "Enter initial velocity:\n";
    cin >> initial_velocity;
    cout << "Enter final velocity:\n";
    cin >> final_velocity;
    cout << "Enter deceleration:\n";
    cin >> deceleration;
    
    //Program displays displacement if none of the conditions in the fucntion are true.
    if(displacement(initial_velocity, final_velocity, deceleration) > 0)
    {
        cout << "Displacement is: " << displacement(initial_velocity, final_velocity, deceleration);
    }
    
    return 0;
}