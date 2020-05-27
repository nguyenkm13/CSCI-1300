// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 – Sravanth Yajamanam
// Project 2 - Problem 3

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include "Library.h"
#include "User.h"
using namespace std;

// converts all lowercase letters in a string to upper case
string toUpper(string input)
{
    string output = "";
    for(int i = 0; i < input.length(); i++)
    {
        // if the character is a lowercase letter, convert to upper case
        if(input[i] >= 'a' && input[i] <='z')
        {
            output += input[i] - 32;
        }

        // if the character is not a lowercase letter, do nothing
        else
        {
           output += input[i];
        }
    }

    // returns the converted string
    return output;
}

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

//default constructor sets the number of books and the number of users both to zero
Library::Library()
{
    numBooks = 0;
    numUsers = 0;
}

int Library::getNumBooks()
{
    return numBooks;
}

int Library::getNumUsers()
{
    return numUsers;
}

// reads a txt file of books and returns the number of books in the file
int Library::readBooks(string filename)
{
    ifstream file(filename);
    
    if(file.is_open())
    {
        string line; //temporary sting that will hold a line of the file
        string arr[2]; // temporary array 
        while(getline(file, line))
        {
            split(line, ',', arr, 2); // splits the line by a delimeter
            if(numBooks < 50)
            {
                books[numBooks] = Book(arr[1], arr[0]); // stores the title and author of a book into the temporary array
                numBooks++; 
            }
        }
        return numBooks;
    }
    
    // if file cannot be opened, return -1
    else
    {
        return -1;
    }

}

// reads a .txt file of users and book ratings given a filename and stores them into the users array
int Library::readRatings(string filename)
{
    ifstream file(filename);

    if(file.is_open())
    {
        int lineCount = 0; // counts number of lines in the .txt file
        string line; // temporary string
        string arr[50]; // temporary array
        while(getline(file, line) && numUsers < 100)
        {
            lineCount++;
            if(lineCount % 2 != 0) // even numbered lines hold usernames
            {
                users[numUsers].setUsername(line); // stores username into the users array
            }
            else // odd numbered line hold ratings
            {
                if(line != "")
                {
                    split(line, ',', arr, 50); // splits each rating by a delimeter and stores them into the temporary array
                    for(int i = 0; i < split(line, ',', arr, 50); i++)
                    {
                        users[numUsers].setRatingAt(i, stod(arr[i]));
                    }
                }
                numUsers++;
            }
        }
        return numUsers;
    }
    else // if file cannot be opened, return -1
    {
        return -1;
    }
    
}

// views all the ratings above a minimum rating given by a user
void Library::viewRatings(string username_, int minRating)
{
    if(numBooks == 0 || numUsers == 0) // if there are no books or no users in the library
    {
        cout << "The library has not been fully initialized.\n"; 
    }
    else 
    {
        int matches = 0, ratingCount = 0;
        for(int i = 0; i < numUsers; i++)
        {
            string search = toUpper(username_); // search string is case insensitive
            
            if(search == toUpper(users[i].getUsername())) // finds matching users
            {
                // counts the number of books that a certain user rated at or higher than a minimum rating
                for(int k = 0; k < numBooks; k++)
                {
                    if(users[i].getRatingAt(k) >=  minRating) 
                    {
                        ratingCount++;
                    }
                }
                if(ratingCount == 0) // if the user has not rated any book at or above minimum rating
                {
                    cout << username_ << " has not rated any books with " << minRating << " or higher.\n";
                }
                else // returns the title and rating of books a user rated above the minimum rating
                {
                    cout << "Here are the books that " << username_ << " rated\n";
                    for(int j = 0; j < numBooks; j++)
                    {
                        if(users[i].getRatingAt(j) >=  minRating)
                        {
                            cout << "Title : " << books[j].getTitle() << endl;
                            cout << "Rating : " << users[i].getRatingAt(j) << endl;
                            cout << "-----\n"; 

                        }
                    }
                }
                
                matches++; 
            }
        }
        if(matches == 0) // if no users match the input username
        {
            cout << username_ << " does not exist.\n";
        }
    } 
}

// this function prints all book titles in the library and their average rating
void Library::printAllBooks()
{
    if(numUsers == 0 || numBooks == 0) // no books or users in the library
    {
        cout << "The library has not been fully initialized.\n";
    }
    else
    {  
        for(int i = 0; i < numBooks; i++)
        {
            int numRaters = numUsers;
            double sumRatings = 0;
            for(int j = 0; j < numUsers; j++)
            {
                // the sum of all user ratings for each book
                sumRatings = sumRatings + users[j].getRatingAt(i);

                // if the user rated 0 for a given book, that observation is removed from the average calculation
                if(users[j].getRatingAt(i) == 0)
                {
                    numRaters--;
                }
            }

            // returns the average rating and title of each book in the library
            double avg = sumRatings / numRaters;
            cout << fixed << setprecision(2) << "(" << avg << ")" << " " << books[i].getTitle();
            cout << " by " << books[i].getAuthor() << endl;
        }
    }
    
}


// adds a user to the library
void Library::addUser(string username_)
{
    string search = toUpper(username_); // search string is case insensitve
    int userMatch = 0;

    // determines if there is a matching user that already exists in the library
    for(int i = 0; i < numUsers; i++)
    {
        if(search == toUpper(users[i].getUsername()))
        {
            userMatch++;
        }
    }

    // if library is full
    if(numUsers == 100)
    {
        cout << "The library is already full. " << username_ << " was not added.\n"; 
    }

    // if there is a matching user in the library already
    else if(userMatch > 0)
    {
        cout << username_ << " already exists in the library.\n";
    }

    // adds user to the library
    else
    {
        users[numUsers].setUsername(username_);
        cout << "Welcome to the library " << username_ << endl;
        numUsers++;
    } 
}

// Extra Credit: adds a book to the library
void Library::addBook(string title_)
{
    string search = toUpper(title_); // search string is case insensitive
    int bookMatch = 0;

    // determines if the book already exists in the library
    for(int i = 0; i < numUsers; i++)
    {
        if(search == toUpper(books[i].getTitle()))
        {
            bookMatch++;
        }
    }

    // if the library is full
    if(numBooks == 50)
    {
        cout << "The library is already full. " << title_ << " was not added.\n"; 
    }

    // if the book already exists in the library
    else if(bookMatch > 0)
    {
        cout << title_ << " already exists in the library.\n";
    }

    // adds book to the library
    else
    {
        books[numBooks].setTitle(title_);
        cout << "Welcome to the library " << title_ << endl;
        numBooks++;
    } 
}

// this fuction changes a user's rating for a book
void Library::updateRating(string username_, string title_, int rating)
{
    string searchName = toUpper(username_), searchTitle = toUpper(title_); // username and book title are case insensitive
    int userMatch = 0, titleMatch = 0, userIndex = 0, titleIndex = 0;

    // if the user exists in the library, this loop finds their index in the users array
    for(int i = 0; i < numUsers; i++)
    {
        if(searchName == toUpper(users[i].getUsername()))
        {
            userMatch++;
            userIndex = i;
        }
    }

    // if the book exists in the library, this loop finds its index in the books array
    for(int j = 0; j < numBooks; j++)
    {
        if(searchTitle == toUpper(books[j].getTitle()))
        {
            titleMatch++;
            titleIndex = j;
        }
    }

    //if there are no books or no users in the library
    if(numUsers == 0 || numBooks == 0) 
    {
        cout << "The library has not been fully initialized.\n";
    }

    // if the user does not exist in the library
    else if(userMatch == 0)
    {
        cout << username_ << " does not exist.\n";
    }

    // if the rating arguement is out of bounds (0-5)
    else if(rating > 5 || rating < 0)
    {
        cout << rating << " is not valid.\n";
    }

    // if the book doesn't exist in the library
    else if(titleMatch == 0)
    {
        cout << title_ << " does not exist.\n";
    }

    // changes the user's rating of a book
    else
    {
        users[userIndex].setRatingAt(titleIndex, rating);
        cout << "The rating has been updated.\n";
    }
    
}


// this fuction prints book recommendations for a user based on other user's ratings of books
void Library::getRecommendations(string username_)
{
    int userMatch = 0, bookCount = 0, userIndex = 0, ssd = 0, difference =0, matchScore = 2500, topMatch =0, recommendations = 0;
    string searchName = toUpper(username_); // search string is case insensitive

    // finds the location of the user in the users array
    for(int i = 0; i < numUsers; i++)
    {
        if(searchName == toUpper(users[i].getUsername()))
        {
            userMatch++;
            userIndex = i;
        }
    }

    // If there are no users or no books in the library
    if(numBooks == 0 || numUsers == 0)
    {
        cout << "The library has not been fully initialized.\n";
    }

    // If there is no match for the username in the library
    else if(userMatch == 0)
    {
        cout << username_ << " does not exist.\n";
    }
    else 
    {
        int totalScore;
        for(int j = 0; j < numUsers; j++)
        {
            if(userIndex != j)
            {   
                ssd =0; 
                totalScore = 0;

                // calculates the SSD to find the user with the closest matching preferences
                for(int k = 0; k < numBooks; k++)
                {
                    difference = users[userIndex].getRatingAt(k) - users[j].getRatingAt(k);
                    ssd += pow(difference, 2);
                    totalScore += users[j].getRatingAt(k);

                }
                // cout << "match score: " << users[j].getUsername() << ' ' << ssd << endl;

                // keeps the user with the lowest SSD if they rated at least one book
                if(totalScore > 0 && ssd < matchScore)
                {
                    matchScore = ssd;
                    topMatch = j;
                }
            }
        }

        // counts the number of recommendations
        for(int l = 0; l < numBooks; l++)
        {
            if(users[userIndex].getRatingAt(l) == 0 &&  3 <= users[topMatch].getRatingAt(l) && bookCount < 5)
            {
                bookCount++;
            }
        }

        // prints the stop five recommended books
        if(bookCount > 0)
        {
            cout << "Here is the list of recommendations\n";
            for(int l = 0; l < numBooks; l++)
            {
                if(users[userIndex].getRatingAt(l) == 0 &&  3 <= users[topMatch].getRatingAt(l) && recommendations < 5)
                {
                    cout << books[l].getTitle() << " by " << books[l].getAuthor() << endl;
                    recommendations++;
                }
            }
        } 

        // if there are no recomendations
        else
        {
            cout << "There are no recommendations for " << username_ << " at present.\n";
        }
        
    }
}


