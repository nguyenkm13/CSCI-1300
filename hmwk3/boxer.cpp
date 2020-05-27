// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 - Sravanth Yajamanam
// Homework 3 - Problem #4

#include <iostream>
using namespace std;

//This program tells the user whether the inputed weights of three boxers are in ascending order, descending order, or neither

int main() {
    //User inputs three weights as integer values
    int boxer1_weight;
    int boxer2_weight;
    int boxer3_weight;
    cout << "Enter boxers' weights" << endl;
    cin >> boxer1_weight;
    cin >> boxer2_weight;
    cin >> boxer3_weight;
    
    
    //If the the inputed weights are in ascending order, the program will display: "Ascending order"
    if (boxer1_weight < boxer2_weight && boxer2_weight < boxer3_weight) {
        cout << "Ascending order" << endl;
    }
    
    //If the the inputed weights are in descending order, the program will display: "Descending order"
    else if (boxer3_weight < boxer2_weight && boxer2_weight < boxer1_weight) {
        cout << "Descending order" << endl;
    }
    
    /*If the the inputed weights are in neither in ascending nor descending order, or, two or more of the values are the same
    the program will display: "Descending order" */ 
    else {
        cout << "Neither" << endl;
    }
    return 0;
}