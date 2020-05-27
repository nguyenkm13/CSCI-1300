// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 - Sravanth Yajamanam
// Homework 3 - Problem #1

#include <iostream>
#include <iomanip>
using namespace std;

//This program takes a students three practium scores and outputs a message that lets them know if they have a passing average, or not. 

int main() {
    int practicum1;
    int practicum2;
    int practicum3;
    
    //User inputs the scores for practicums 1 through 3
    cout << "Enter practicum 1 score:" << endl;
    cin >> practicum1;
    cout << "Enter practicum 2 score:" << endl;
    cin >> practicum2;
    cout << "Enter practicum 3 score:" << endl;
    cin >> practicum3;
    
    //Calculate the average practicum score for the student
    double practicum_avg = (practicum1 + practicum2 + practicum3) / 3.0;
    cout << "Practicum average: " << fixed << setprecision(2) << practicum_avg << endl;
    
    
    //If the student's practicum if 67 or higher, the program displays: "You have a passing practicum average."
    if (practicum_avg >= 67) {
        cout << "You have a passing practicum average." << endl;
    }
    
    //If the student's practicum average is less than 67, the program displays: "You can retake practicums during the final."
    else {
        cout << "You can retake practicums during the final." << endl;
    }
    return 0;
    
}