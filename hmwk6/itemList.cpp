#include<iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//This program outputs the number of lines, most expensive product, and least expensive product

int main()
{
    string file, price_high, price_low;
    string line;
    char delim = ',';
    int lines = 0;
    
    // Choose the file to be opened
    cout << "Enter the file name: \n";
    cin >> file;
    ifstream my_file;
    my_file.open(file);
    double valueHigh = 0, valueLow = 99999;
    
    if(!my_file.is_open()) {
        cout << "Could not open file.\n"; // If file is not open, display message
    } else {
        while(getline(my_file, line)){
            for(int i = 0; i < line.length(); i++) {
                if(line[i] == ',') {
                    double price = stod(line.substr(i+1));
                    
                    //Finds the highest price
                    if(price > valueHigh) { 
                        valueHigh = price;
                        price_high = line.substr(0, i);
                    } 
                    
                    //Finds the lowest price
                    if(price < valueLow) {
                        valueLow = price;
                        price_low = line.substr(0, i);
                    }
                }
            }
            
            // finds the number of lines
            if(line != "") {
                lines++;
            }
        }
        
        //output
        cout << "The number of lines: " << lines << endl;
        cout << "The most expensive product: " << price_high << endl;
        cout << "The least expensive product: " << price_low << endl;
    }
    
    my_file.close();
    return 0; 
}