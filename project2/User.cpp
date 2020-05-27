// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 – Sravanth Yajamanam
// Project 2 - Problem 2

#include <iostream>
#include "User.h"
using namespace std;

// default constructor sets username to an empty string and ratings to an array of zeroes
User::User() 
{
    username = "";
    for(int i = 0; i < 50; i++)
    {
        ratings[i] = 0;
    }
}

void User::setUsername(string username_)
{
    username = username_;
}

// this function changes the rating at an indexed position to a certain value
bool User::setRatingAt(int index, int value)
{
    // if the index is out of the bounds of the array or if the score is invalid (not 0-5)
    // function returns -1
    if(index < 0 || index >= 50 || value < 0 || value > 5)
    {
        return 0;
    }
    else
    {
        ratings[index] = value;
        return 1;
    }
    
}

string User::getUsername()
{
    return username;
}

int User::getRatingAt(int index)
{
    // if index is outside of the bounds of the array, function returns -1
    if(index < 0 || index >= 50)
    {
        return -1;
    }

    else 
    {
        return ratings[index];
    } 
}

