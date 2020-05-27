// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 – Sravanth Yajamanam
// Homework 7 - Problem 2

#include <iostream>
#include <fstream>
#include "Team.h"

// Defines the member functions
using namespace std; 

int split(string input, char delimiter, string arr[], int size)
{
    input.push_back(delimiter);
    int pos = 0;
    for(int i = 0; i < input.length(); i++)
    {
        //Deletes multiple occurances of delimiters
        while(input[0] == delimiter)
        {
            input.erase(0,1);
        }
        
        //places the substring piece between delimiters into the array
        if(input[i] == delimiter)
        {
            arr[pos] = input.substr(0, i);
            
            //clears the begining of the string 
            input.erase(0, i + 1);
            
            //resets i
            i = 0;
            
            // Adds one to the piece counter
            pos ++;
        }
    }
    
    // If the string is split into more pieces than the size of the array, then it returns -1.
    if(pos > size)
    {
        return -1;
    }
    
    // Otherwise, the function returns the number of pieces was split into
    else 
    {
        return pos;
    }
}

//default constructor with empty team name and 0 players
Team::Team()
{
    teamName = "";
    numPlayers = 0;
}

//constructor with set team name
Team::Team(string teamName_)
{
    teamName = teamName_;
    numPlayers = 0;
}

// changes team name
void Team::setTeamName(string teamName_)
{
    teamName = teamName_;
}

// reads a file of players names and scores. 
// returns the number of players 
int Team::readRoster(string filename)
{
    // opens file
    ifstream file(filename);

    if(!file.is_open())
    {
        return -1;
    }
    else
    {
        string line; 
        numPlayers = 0; //player counter
        while(getline(file, line)) 
        {
            // doesn't parse empty lines
            if(line != "")
            {
                string arr[2]; // temporary array for player names and scores
                split(line, ',', arr, 2); //splits line by delimiter
                if(numPlayers < 50)
                {
                    player[numPlayers] = Player(arr[0], stod(arr[1])); //stores player name and score into a "player" object
                    numPlayers++; 
                }
                
            }

        }
        return numPlayers;
    }    
    
    file.close();
}

// returns player name of index i
string Team::getPlayerName(int i)
{
    if(i >= 0 && i < numPlayers)
    {
        return player[i].getName();
    }
    else
    {
        return "ERROR";
    }
    
}

// returns points of index i
double Team::getPlayerPoints(int i)
{
    if(i >= 0 && i < numPlayers)
    {
        return player[i].getPoints();
    }
    else
    {
        return -1;
    }
    
}

// returns number of players on team
int Team::getNumPlayers()
{
    return numPlayers;
}

// returns team name
string Team::getTeamName()
{
    return teamName;
}