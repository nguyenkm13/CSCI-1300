// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 - Sravanth Yajamanam
// Homework 3 - Problem #2

#include <iostream>
#include <iomanip> 
using namespace std;

//The following program calculates the user's paycheck given an hourly pay rate and a number of hours worked

int main() {
    float hours_worked;
    float pay_rate;
    
    //User enters the number of hours worked and their pay rate
    cout << "Enter the number of hours worked" << endl;
    cin >> hours_worked;
    cout << "Enter an hourly pay rate" << endl;
    cin >> pay_rate;
    
    //If either input is negative, the program displays the following message: Invalid input
    if (hours_worked < 0 || pay_rate < 0) {
        cout << "Invalid input" << endl;
    }
    
    //If both inputs are positive, the program calculates the paycheck
    else {
        
        //Calculation if the user qualifies for overtime pay (ie. they worked longer than 40 hours)
        if (hours_worked > 40) {
            
            //Program calculates overtime pay as: hours worked past 40 hours * 1.5 * pay rate
            double overtime_pay = (hours_worked - 40) * 1.5 * pay_rate;
            
            //Programs calculates full time pay as 40 hours * pay rate
            double full_time_pay = 40 * pay_rate;
            
            //Total pay is overtime pay + full time pay
            double total_pay = overtime_pay + full_time_pay;
            
            //Displays the user's paycheck
            cout << "Paycheck: " << fixed << setprecision(2) << total_pay << endl;
        }
        
        //Calculation if the user worked 40 hours or less
        else {
          //Calculates the user's paycheck as hours worked * pay_rate
          double pay = hours_worked * pay_rate;
          
          //Displays paycheck
          cout << "Paycheck: " << fixed << setprecision(2) << pay << endl;
        }
    }
    return 0;
}