// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 – Sravanth Yajamanam
// Homework 7 - Problem 1

#include <iostream>
#include "Player.h"
using namespace std; 

// default players name to empty string and points to 0
Player::Player() 
{
    name = "";
    points = 0;
}

// set player name and points.
Player::Player(string name_, double points_) 
{
    name = name_;
    points = points_;
}

// return's player's name
string Player::getName()
{
    return name;
}

// returns player's points
double Player::getPoints()
{
    return points;
}


// set player name
void Player::setName(string name_)
{
    name = name_;
}

// set player points
void Player::setPoints(double points_)
{
    points = points_;
}
