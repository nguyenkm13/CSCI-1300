// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 – Sravanth Yajamanam
// Homework 8 - Problem 1

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string decimalToBinaryIterative(int x)
{
    int remainder = x;
    string result = "";
    vector <char> binary;
    while(remainder > 0)
    {
        
        if(remainder % 2 != 0)
        {
            binary.insert(binary.begin(), '1');
        }
        else
        {
            binary.insert(binary.begin(), '0');
        }
        remainder = remainder / 2;
    }

    for(int i = 0; i < binary.size(); i++)
    {
        result += binary[i];
    }

    if(x != 0)
    {
        return result;
    }
    else
    {
        return "0";
    }
    
    
}

int main()
{

    cout << decimalToBinaryIterative(5) << endl;
    return 0;
}