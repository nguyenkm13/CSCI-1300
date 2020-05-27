// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 - Sravanth Yajamanam
// Homework 4 - Problem #4

#include <iostream>
using namespace std;

//This program calculates the number of months needed to afford the down payment on one's dream house.

int main()
{
    double annual_salary, savings_rate, dream_house_cost, interest_rate = 0.04, savings = 0; 
    int months = 0, months_per_year = 12;
    
    //User inputs annual salary, expected savings rate, and the cost of one's dream home
    cout << "Enter your annual salary:" << endl;
    cin >> annual_salary;
    cout << "Enter the percent of your salary to save, as a decimal:" << endl;
    cin >> savings_rate;
    cout << "Enter the cost of your dream home:" << endl;
    cin >> dream_house_cost;
    
    double down_payment = 0.25 * dream_house_cost, salary_savings = savings_rate * (annual_salary / months_per_year);
    
    //Loop continues until savings are equal to or greater than down payment. Each time the loop runs, one month is added to the running total
    while(savings < down_payment)
    {
        //Calculates monthly savings as previous savings + monthly salary savings + monthly interest earnings
        savings = (savings * (1 + (interest_rate/months_per_year))) + salary_savings;
        months++;
    }
    
    //Outputs the number of months
    cout << "Number of months: " << months;
    
    return 0;
}