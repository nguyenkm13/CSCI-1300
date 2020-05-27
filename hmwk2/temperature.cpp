// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 - Sravanth Yajamanam
// Homework 2 - Problem #5

#include <iostream>
#include <iomanip>
using namespace std;

//This program converts tempurature in Fahrenheit to tempurature in Celcius

int main() {
    //User inputs a temperture in Fahrenheit
    cout << "Enter a temperature in Fahrenheit: " << endl;
    double fahrenheit;
    cin >> fahrenheit;
    
    //Calculates the tempurature in celcius using the formula: Celcius = (5/9) * (fahrenheit-32)
    double celcius = (5.0/9.0) * (fahrenheit - 32);
    
    //Outputs the phrase: "The tempurature <user input in fahrenheit> degrees Fahrenheit is <celcius, to two decimal places> degrees Celcius"
    cout << "The temperature " << fahrenheit << " degrees Fahrenheit is " << fixed << setprecision(2) << celcius << " degrees Celsius.";
    return 0;
}