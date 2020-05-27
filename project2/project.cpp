// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 – Sravanth Yajamanam
// Project 2 - Problem 4

#include <iostream>
#include <string>
#include "Library.h"
using namespace std;

int main()
{
    // Library library;
    // int numBooks = library.readBooks("books_mini.txt");
    // int numUsers = library.readRatings("ratings_mini.txt");

    // library.getRecommendations("vipra");

    Library library;
    int input, books = 0, users = 0, minRating, rating =0;
    string filename, username, title, author;
    

    do
    {
        // main menu of the program
        cout << "Select a numerical option:\n";
        cout << "======Main Menu=====\n"; 
        cout << "1. Read books\n2. Read ratings\n";
        cout << "3. View ratings\n4. Print all books\n";
        cout << "5. Update a rating\n6. Add a user\n";
        cout << "7. Get recommendations\n8. Quit\n";
        // extra credit feature
        // cout << "9. Add a new book\n";
        cin >> input;
        switch (input)
        {
            // reads a .txt file of books to store into the library
            case 1:
                cout << "Enter a book file name:\n";
                cin >> filename;
                books = library.readBooks(filename);
                if(books > 0)
                {
                    cout << "Total books in the library: " << books << endl;
                }
                else
                {
                    cout << "No books saved to the library.\n";
                }
                break;

            // reads a .txt file of names and ratings to store into the library
            case 2:
                cout << "Enter a user file name:\n";
                cin >> filename;
                users = library.readRatings(filename);

                if(users > 0)
                {
                    cout << "Total users in the library: " << users << endl;
                }
                else
                {
                    cout << "No users saved to the library.\n";
                }
                
                break;


            // prints all ratings for a specific user above or equal to a minimum rating
            case 3:
                cout << "Enter a user name:\n";
                cin >> username;
                cout << "Enter a minimum rating:\n";
                cin >> minRating;

                library.viewRatings(username, minRating);
                break;

            // prints all books in the library with their average rating
            case 4:
                library.printAllBooks();
                break;

            // changes a user's rating of a book
            case 5:
                cout << "Enter a user name:\n";
                cin >> username;
                
                cout << "Enter a book title:\n";
                cin.ignore();
                getline(cin, title);
                // cout << "!" << title << "!" << endl;
                
                cout << "Enter a new rating:\n";
                cin >> rating;

                library.updateRating(username, title, rating);
                break;

            // adds a user to the library
            case 6:
                cout << "Enter a user name:\n";
                cin >> username;

                library.addUser(username);
                break;

            // prints book recommendations for a user
            case 7:
                cout << "Enter a user name:\n";
                cin >> username;

                library.getRecommendations(username);
                break;

            // Exit condition
            case 8:
                cout << "Good bye!\n";
                break;

            // Extra credit feature: adds a book to the library
            // case 9:
            //     cout << "Enter a book title:\n";
            //     cin.ignore();
            //     getline(cin, title);

            //     break;

            // if user selection is out of bounds (1-9)
            default:
                cout << "Invalid option.\n";
                break;
        }
    } while (input != 8); // program loops until the user enters 8
    
    return 0; 
}