// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 - Sravanth Yajamanam
// Homework 2 - Problem #6

#include <iostream>
using namespace std;

//The following program converts a number of seconds into hours, minutes, and seconds, respectively

int main() {
    //User inputs a number of seconds
    cout << "Enter a number of seconds:" << endl;
    int time;
    cin >> time;
    
    //The number of hours is the user input divided by (60 seconds x 60 minutes)
    int hours = time / (60 * 60);
    
    //The remaining minutes is the difference between the user input and the calulated hours (in seconds) divided by 60 seconds
    int minutes = (time - hours * (60 * 60)) / 60;
    
    //The remaining seconds is the difference between the user input and the sum of the calculated hours and minutes (in seconds)
    int seconds = (time - (hours * (60 * 60) + minutes * 60));
    
    //Outputs the following string of text: "x hour(s) y minute(s) and z second(s)" where x, y and z are hours, minutes, and seconds, respectively
    cout << hours << " hour(s) " << minutes << " minute(s) " << seconds << " second(s) " << endl;
    return 0;
}