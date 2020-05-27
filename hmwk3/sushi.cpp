// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 - Sravanth Yajamanam
// Homework 3 - Problem #3

#include <iostream>
#include <iomanip>
using namespace std;

//This program calculates a student's bill at Ashwin's sushi resturant, given the number of pieces the student ate.

int main() {
    double total_price = 0.0;

    //The price per piece is $1.99
    double price_per_piece = 1.99; 
    
    //The user inputs the number of pieces the student ate
    int pieces_eaten;
    cout << "Enter the number of sushi:" << endl;
    cin >> pieces_eaten;
    
    //If the input is negative, the program will display: "Invalid input"
    if (pieces_eaten < 1) { 
        cout << "Invalid input" << endl;
    }
    
    //If the input is positive, the bill is calcualted based on Ashwin's discount scale
    else {
        
        //If the student ate less than 10 pieces, they pay full price
        if (pieces_eaten < 10) {
            total_price = (pieces_eaten * price_per_piece);
        }
        
        //If the student ate 10-19 pieces, they recieve a 10% discount
        else if (pieces_eaten > 9 && pieces_eaten < 20) {
            total_price = (pieces_eaten * price_per_piece) * 0.9;
        }
        
        //If the student ate 20-49 pieces, they recieve a 15% discount
        else if (pieces_eaten >= 20 && pieces_eaten < 50) {
            total_price = (pieces_eaten * price_per_piece) * 0.85;
        }
        
        //If the student ate 50-99 pieces, they recieve a 20% discount
        else if (pieces_eaten >= 50 && pieces_eaten < 100) {
            total_price = (pieces_eaten * price_per_piece) * 0.80;
        }
        
        //If the student 100 or more pieces, they recieve a 25% discount
        else if (pieces_eaten >= 100) {
            total_price = (pieces_eaten * price_per_piece) * 0.75;
        }
    }
    
    if (pieces_eaten >= 1) {
    cout << "Total price: $" << fixed << setprecision(2) << total_price << endl;
    }
    return 0;
}
