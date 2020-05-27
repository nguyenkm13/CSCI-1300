// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 – Sravanth Yajamanam
// Homework 7 - Problem 2

#include <iostream>
#include "Team.h"
using namespace std;

int main()
{
    // defualt test
    Team team1("Seg Faultline");
    cout << team1.getTeamName() << endl; 
    team1.readRoster("roster1.txt");
    int n1 = team1.getNumPlayers(); cout << n1 << endl;
    for (int i = 0; i < n1; i++) 
    {
        cout << team1.getPlayerName(i) << " ";
        cout << team1.getPlayerPoints(i) << endl;
    }

    // test 2
    Team team2;
    team2.setTeamName("Tune Squad");
    cout << "team: " << team2.getTeamName() << endl;
    cout << "number of players: " << team1.getNumPlayers()<< endl;
    team2.readRoster("roster2.txt");
    for(int i = 0; i < team1.getNumPlayers(); i++)
    {
        cout << team2.getPlayerName(i) << ": ";
        cout << team2.getPlayerPoints(i) << " points\n";
    }

    return 0;
}