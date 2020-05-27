// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 - Sravanth Yajamanam
// Homework 3 - Problem #5

#include <iostream>
using namespace std;

//This program displays the number of days, given a month and year.

int main() {
    
    //User inputs a year and a month.
    int year;
    int month;
    cout << "Enter a year:" << endl;
    cin >> year;
    cout << "Enter a month:" << endl;
    cin >> month;
    
    /*A year is a leap year if:
    Before 1582: the year is divisible by 4
    After 1582: the year is divisible by 4 or 400, but not divisible by 100 */
    
   switch(month) {
       //If the month is Feburary
       case 2: {
           //If the year is a leap year
            if ((year < 1582 && year % 4 == 0) || (year > 1582 && year % 4 == 0 && (year % 100 != 0 || year % 400 ==0))){
                cout << "29 days" << endl;
            }
            
            //If the year is not a leap year
            else {
                cout << "28 days" << endl;
            }
        break;
       }
       
        //If the month is Jan, Mar, May, Jul, Aug, Oct, or Dec
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: {
            cout << "31 days" << endl;
            break;
        }
        
        //If the month is Apr, Jun, Sep, or Nov
        case 4:
        case 6:
        case 9:
        case 11: {
            cout << "30 days" << endl;
            break;
        }
        
        //If the month is < 1 or > 12
        default: {
            cout << "Invalid month" << endl;
            break;
        }

   }
   return 0;
}