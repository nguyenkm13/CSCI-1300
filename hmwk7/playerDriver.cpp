// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 – Sravanth Yajamanam
// Homework 7 - Problem 1

#include <iostream>
#include "Player.h"
using namespace std;

// Tests for constructor
int main()
{
    // Default test
    Player hector("Hector", 6.2);
    cout << hector.getName() << endl; 
    cout << hector.getPoints() << endl;

    // Test 2
    hector.setPoints(5.9);
    hector.setName("Pedro");
    cout << "name: "<< hector.getName() << endl; 
    cout << "points: " << hector.getPoints() << endl;

    return 0; 
}
