// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 – Sravanth Yajamanam
// Homework 7 - Problem 2

#ifndef TEAM_H
#define TEAM_H

#include <iostream> 
#include "Player.h"
using namespace std; 

// Team class 

class Team 
{
    private: 
        string teamName; // Team's name
        Player player[50]; // Array of 50 "Player" objects
        int numPlayers; // Number of players on the team
    public: 
        Team(); // default constructor
        Team(string teamName_); 

        // member functions
        void setTeamName(string teamName_); 
        int readRoster(string filename);
        string getPlayerName(int i);
        double getPlayerPoints(int i);
        int getNumPlayers();
        string getTeamName();
}; 

#endif

