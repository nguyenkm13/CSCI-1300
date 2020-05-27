// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 – Sravanth Yajamanam
// Project 2 - Problem 2

#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;

class User
{
    private:
        string username;
        int ratings[50];
    public:
        User();
    
        void setUsername(string username_);
        bool setRatingAt(int index, int value);
        string getUsername();
        int getRatingAt(int index);
};

#endif