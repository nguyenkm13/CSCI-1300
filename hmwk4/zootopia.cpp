// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 - Sravanth Yajamanam
// Homework 4 - Problem #3

#include <iostream>
using namespace std;

//This program displays a menu which allows the user to calculate a hire score based on inputs

int main()
{
    int selection = 0;
    double agility, speed, strength, hire_score;
    
    //Program loops until user inputs 4 (Quit)
    while(selection != 4)
    {
        //Displays a menu that asks for a selection of fox, bunny, sloth, or quit
        cout << "Select a numerical option:" << endl << "=== menu ===" << endl 
        << "1. Fox" << endl << "2. Bunny " << endl << "3. Sloth" << endl << "4. Quit" << endl;
        cin >> selection;
        
        switch(selection)
        {
            //If the user enters 1 (Fox)
            case 1: 
            {
                //Program asks for agility and strength
                cout << "Enter agility:" << endl;
                cin >> agility; 
                cout << "Enter strength:" << endl;
                cin >> strength;
                
                //Program calculates and displays a hire score based on inputs
                hire_score = 1.8 * agility + 2.16 * strength;
                cout << "Hire Score: " << hire_score << endl;
                break;
            }
            
            //If the user inputs 2 (Bunny)
            case 2: 
            {
                //Program asks for agility and speed
                cout << "Enter agility:" << endl;
                cin >> agility;
                cout << "Enter speed:" << endl;
                cin >> speed;
                
                //Program calculates and displays a hire score based on inputs
                hire_score = 1.8 * agility + 3.24 * speed;
                cout << "Hire Score: " << hire_score << endl;
                
                break;
            }
            
            //If the user inputs 3 (Sloth)
            case 3: 
            {
                //Program asks for strength and speed
                cout << "Enter strength:" << endl;
                cin >> strength; 
                cout << "Enter speed:" << endl;
                cin >> speed;
               
                //Program calculates and displays a hire score based on inputs
                hire_score = 3.24 * speed + 2.16 * strength;
                cout << "Hire Score: " << hire_score << endl;
                
                break;
            }
            
            //If user inputs 4 (Quit)
            case 4: 
            {
                //Program displays "Good bye!"
                cout << "Good bye!" << endl;
                break;
            }
            
            //If user inputs a number outside of the range (1,4), program displays "Invalid Option"
            default:
            {
                cout << "Invalid Option" << endl;
                break;
            }
        }
    }
   
   return 0;
}