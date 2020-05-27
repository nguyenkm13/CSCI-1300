// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 - Sravanth Yajamanam
// Homework 2 - Problem #7

#include <iostream>
using namespace std;

/* This program outputs the projected population in one year assuming the following conditions:
there is 1 birth every 8 seconds
there is 1 death every 12 seconds
there is 1 new immigrant every 27 seconds */

int main() {
    // User inputs the current population
    cout << "Enter the current population:" << endl;
    int population;
    cin >> population;
    
    // year in seconds is calculated as 60 seconds in a minute * 60 minutes in a hour * 24 hours in a day * 365 days in a year
    int year_in_secs = 60 * 60 * 24 * 365;
    
    // projected population, given: a birth every 8 seconds, a death every 12 seconds, and an immigrant every 27 seconds
    int population_new = population + (year_in_secs / 8) - (year_in_secs / 12) + (year_in_secs / 27);
    cout << "The population in one year: " << population_new << endl;
    return 0;
}
    
