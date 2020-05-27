#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// This function stores the sales data into an array

int readSales(string filename, string names[], int sales[][12], int size) 
{
    int line_count = 0, count_names = 0, count_sales = 0;
    string line;
    ifstream file;
    file.open(filename);

    // if file is not open, return -1
    if(!file.is_open()) 
    {
        return -1;
    } 
    else 
    {
        while(getline(file, line) && line_count / 2 < size) 
        {   
            line_count++;
            int k = 0;
            
            // stores employee names into an array
            if(line_count % 2 == 1)
            {
                names[count_names] = line; 
                count_names++;
            } 
            
            // stores sales data into another two dimesnional array
            else 
            {
                line.push_back(',');
                for(int i = 0; i < line.length(); i++) 
                {
                    if(line[i] == ',')
                    {
                        sales[(line_count / 2) - 1][count_sales] = stoi(line.substr(0, i));
                        
                        line.erase(0, i + 1);
                        i = 0;
                        count_sales++;
                    }
                }
                count_sales = 0;
            }
        }   
        return line_count / 2;
    }
    
    file.close();
}       



int main() 
{
    // string filename = "sales.txt";
    // string names[3] = {"Vipra", "Chandan", "Malvika"};
    // int sales[3][12];
    // int size = 3;

    string fileName;
    const int SIZE = 10;
    string names[SIZE];
    int sales[SIZE][12];
    int sum[SIZE];

    
    cout << "Enter the file name: \n";
    cin >> fileName;
    
    int numPeople = readSales(fileName, names, sales, SIZE);
    
    cout << "Returned value (number of employees): " << numPeople << endl;
    
    
    // Outputs the average sales of the employees
    for(int j = 0; j < SIZE; j++)
    {
        for(int k = 0; k < 12; k++)
        {
            sum[j] += sales[j][k];
            // cout << sum[j] << " " << j << ' ' << k << endl;
        }
        
        double avg = sum[j] / 12.0;
        cout << fixed << setprecision(2) << names[j] << ": " << avg << endl;
        
    }

    // for (int i = 0; i < SIZE; i++)
    // {
    //     // cout << "Name " << i << ": " << names[i] << endl; 
    // }
    // cout << sales[0][0] << " sales" << endl;

    

    return 0; 
}