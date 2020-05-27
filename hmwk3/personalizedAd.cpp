// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 - Sravanth Yajamanam
// Homework 3 - Problem #6

#include <iostream>
using namespace std;

// This program displays an advertisement based on a user preference for personalization.

int main() {
    
    //User enters how personalized they would like the ad, on a scale 1-3.
    int ad_personalization;
    cout << "How personalized should the ad be? (1-3)" << endl;
    cin >> ad_personalization;
    
    //The program then asks the user a question (or two) based on the preference they chose
    switch (ad_personalization) {
        
        // If the user chose 1, the program asks if the user owns a dog, then displays an ad based on their response.
        case 1: {
            string dog_ownership;
            cout << "Do you own a dog?" << endl;
            cin >> dog_ownership;
            
            if (dog_ownership == "yes" || dog_ownership == "Yes") {
                cout << "Meat's the need of dogs like yours!" << endl;
            }
            
            else {
                cout << "Dirty mouth? Clean it up with new Orbit Raspberry Mint." << endl;
            }
            
            break;
        }
        
        //If the user chose 2, the program asks how many facebook friends they have. It then displays an ad based on if  the input is 500 or greater.
        case 2: {
            int facebook_friends;
            cout << "How many Facebook friends do you have?" << endl;
            cin >> facebook_friends;
            
            if (facebook_friends >= 500) {
                cout << "Don't like cleaning up after your dog? Call Doody Free to sign up for backyard cleanup or dog walking service." << endl;
            }
            
            else {
                cout << "Who doesn't need another cat? Adopt a shelter pet right meow." << endl;
            }
            
            break;
        }
        
        //If the user chose 3, the program asks for their zip code and their age. It then displays an ad based on their inputs. 
        case 3: {
            int zip_code;
            int age;
            cout << "What is your zip code?" << endl;
            cin >> zip_code;
            cout << "What is your age?" << endl;
            cin >> age;
            
            if (zip_code < 80311 && zip_code > 80300 && age >= 25) {
                cout << "You are surrounded by professional athletes. Up your exercise game in the privacy of your home with a Peloton bike." << endl;
            }
            
            else if (zip_code < 80311 && zip_code > 80300 && age < 25) {
                cout << "Looking for dinner that won't break the bank? Tacos. Come grab a $3 at Centro Latin Kitchen." << endl;
            }
            
            else {
                cout << "Feeling Uninspired? The Boulder Flatirons are calling. Come hike to inspiring views, delicious food, and enjoy the hospitality of Boulder, CO." << endl;
            }
            
            break;
        } 
        
        //If the user chose a number that is not 1, 2, or 3, the program displays: "Invalid option."
        default: {
            cout << "Invalid option." << endl;
        }
    }
   return 0; 
}