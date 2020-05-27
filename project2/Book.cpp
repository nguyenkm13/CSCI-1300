// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 – Sravanth Yajamanam
// Project 2 - Problem 1

#include <iostream>
#include "Book.h"
using namespace std;

// default constructor sets title and author to empty strings
Book::Book()
{
    title = "";
    author = "";
}

Book::Book(string title_, string author_)
{
    title = title_;
    author = author_;
}

string Book::getTitle()
{
    return title;
}

string Book::getAuthor()
{
    return author;
}

void Book::setTitle(string title_)
{
    title = title_;
}

void Book::setAuthor(string author_)
{
    author = author_;
}