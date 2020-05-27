// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 – Sravanth Yajamanam
// Project 2 - Problem 3

#ifndef LIBRARY_H
#define LIBRARY_H  

#include <iostream>
#include "Book.h"
#include "User.h"
using namespace std;

class Library
{
    private:
        Book books[50];
        User users[100];
        int numBooks;
        int numUsers;

    public:
        Library();
        
        int getNumBooks(); 
        int getNumUsers();
        int readBooks(string filename);
        int readRatings(string filename);
        void viewRatings(string username_, int minRating);
        void printAllBooks();
        void addUser(string username_);
        void addBook(string title_);
        void updateRating(string username_, string title_, int rating);
        void getRecommendations(string username_);

};

#endif