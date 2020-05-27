// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 – Sravanth Yajamanam
// Homework 7 - Problem 3

#include <iostream>
#include "Team.h"
using namespace std;

/* This program reads rosters from two txt files and calculates the total scores
    * of each team and declares a winner, draw, or forfeit */

string game(Team team1, Team team2)
{
    // If either of the rosters has less than four players, the match is a forfeit
    if(team1.getNumPlayers() < 4 || team2.getNumPlayers() < 4)
    {
        return "forfeit";
    }

    double pts1 = 0, pts2 = 0; // point counter for each team

    // calculates the total score of each team
    for(int i = 0; i < 4; i++)
    {
        pts1 = pts1 + team1.getPlayerPoints(i);
        pts2 = pts2 + team2.getPlayerPoints(i);
    }

    // returns the name of the winning team

    if(pts1 > pts2)
    {
        return team1.getTeamName();
    } 
    else if(pts2 > pts1)
    {
        return team2.getTeamName();
    }

    // if the scores of both teams are the same, returns "draw"
    else
    {
        return "draw";
    }
}

int main()
{
    // Using ​roster1.txt​ and ​roster2.txt
    // from Moodle
    Team team1("Seg Faultline"); team1.readRoster("roster1.txt");
    Team team2("Team Maim"); team2.readRoster("roster2.txt");
    string winner = game(team1, team2);
    cout << "The winner is: " << winner << endl;

    return 0;
}