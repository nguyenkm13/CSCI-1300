// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 - Sravanth Yajamanam
// Homework 5 - Extra Credit

#include <iostream>
#include<vector>
using namespace std;

//This program populates the counts of each character in the given string

int main()
{
    vector<int> alpha;
    int count = 0;
    string word;
     
    //User enters a word
    cout << "Enter a word:\n";
    cin >> word;
 
    // Populates a vector of integers with occurances of eacb letter
    for(char i = 'a'; i <= 'z'; i++)
    {
        for(int j = 0; j < word.length(); j++)
        {
            if(word[j] == i)
            {
                count++;
            }
        }
        
        alpha.push_back(count);
        count = 0;
    }
    
    // Prints the occurances of each letter in the string in alphabetical order
    for(int i = 0; i < alpha.size(); i++)
    {
        if(alpha[i] > 0)
        {
            cout << char(i + 97) << ": " << alpha[i] << endl;
        }
    }
    
    return 0;
}