// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 - Sravanth Yajamanam
// Homework 2 - Problem #4

#include <iostream>
#include <cmath>
using namespace std;

//This program converts a user inputed radius to volume and surface area

int main() {
    //User inputs a radius
    cout << "Enter a radius:" << endl;
    double radius;
    cin >> radius;
    
    //User input is plugged into the volume equation: V = (4/3) * pi * r^3, where r is the radius
    double volume = (4.0/3.0) * M_PI * pow(radius, 3);
    cout << "Volume: " << volume << endl;
    
    //User input is plugged into the surface area equation: SA = 4 * pi * r^2, where r is the radius
    double surface_area = 4 * M_PI * pow(radius, 2);
    cout << "Surface area: " << surface_area << endl;
}