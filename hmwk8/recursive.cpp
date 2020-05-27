// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 – Sravanth Yajamanam
// Homework 8 - Problem 2

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string decimalToBinaryRecursive(int x) {
    if(x == 0)
    {
        return "0";
    } else if (x == 1)
    {
        return "1";
    }
    
    else {
        int mod = x % 2;
        string add = to_string(mod);
        string out = decimalToBinaryRecursive(x / 2);
        return (out + add);
    }
}


int main() {
    
    cout << decimalToBinaryRecursive(10) << endl;

    return 0;
}
