// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 – Sravanth Yajamanam
// Project 2 - Problem 1

#ifndef BOOK_H
#define BOOK_H

#include <iostream>
using namespace std;

class Book
{
    private: 
        string title; // title of book
        string author; // author name
    public:
        Book();
        Book(string title_, string author_);

        // member functions
        string getTitle();
        string getAuthor();
        void setTitle(string title_);
        void setAuthor(string author_);
};

#endif