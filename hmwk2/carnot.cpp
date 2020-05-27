// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 - Sravanth Yajamanam
// Homework 2 - Problem #3

#include <iostream>
using namespace std;

//The following program calculates the Carnot efficiency given the tempuratures of a cold reservior and a hot reservior

int main() {
    //User inputs cold reservior tempurature
    cout << "Enter cold reservoir temperature:"<< endl;
    double temperature_cold;
    cin >> temperature_cold;
    
    //User inputs hot reservior tempurature
    cout << "Enter hot reservoir temperature:" << endl;
    double temperature_hot;
    cin >> temperature_hot;
    
    //Outputs the Carnot efficiency using the equation: Carnot efficiency = 1 - (Tempurature of cold reservior/tempurature of hot reservior)
    double carnot = 1 - (temperature_cold / temperature_hot);
    cout << "Carnot efficiency: " << carnot << endl;
    return 0;
}