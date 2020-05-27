// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 - Sravanth Yajamanam
// Homework 2 - Problem #2

#include <iostream>
using namespace std;

// This program prints the following message: "Hello, <name>!"

int main() {
    //User inputs their name
    cout << "Enter your name:" << endl;
    string name;
    cin >> name;
    
    //Outputs: "Hello, <name>!"
    cout << "Hello, " + name + "!" << endl;
    return 0;
}