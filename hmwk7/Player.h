// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 – Sravanth Yajamanam
// Homework 7 - Problem 1

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream> 
using namespace std; 

class Player{
    private: 
        string name; // Player's name 
        double points; // Player's points
    public: 
        Player(); 
        Player(string name_, double points_); 

        //member fucntions
        string getName();
        double getPoints();
        void setName(string name_);
        void setPoints(double points_);
}; 

#endif 
