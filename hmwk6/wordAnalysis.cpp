#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// I couldn't solve this one

int main()
{
    string filename;
    int duplicates = 0, n;
    
    // chooses file to be opened
    cout << "Enter a filename:\n";
    cin >> filename;
    ifstream file;
    file.open(filename);

    string line, temp_word, unique[200][2], row[50];
    int words = 0;
    int pos = 0, count = 0;

    // if file not opened, display message
    if(file.fail())
    {
        cout << "Could not open the file.\n";
    }
    else
    {
        cout << "Enter the value of n: \n";
        cin >> n;
        
        cout << endl;
        
        //select each line from file
        while(getline(file, line))
        {
            line.push_back(' ');
            for(int i = 0; i < line.length(); i++)
            {
                // stores each word into an array, row
                if(line[i] == ' ')
                {
                    row[pos] = line.substr(0, i);
                    // cout << row[pos] << "|";
                    pos++;
                    line.erase(0, i + 1);
                    i = 0;
                }
            }
            
            //finds number of duplicates for each word in the line
            for(int j = 0; j < pos; j++)
            {
                for(int k = j + 1 ; k < pos; k++)
                {
                    if(row[j] == row[k])
                    {
                        row[k] = "";
                        duplicates++;
                    }
                }
                
                // partial output
                if(row[j] != "") 
                {
                    unique[count][1] = to_string(duplicates);
                    // cout << unique[count][1] << endl;
                    cout << duplicates + 1 << " - " << row[j] << endl;
                    count++;
                }
                
                // resets the duplicate count
                duplicates = 0;
            }
            // for(int l = 0; l < pos; l++)
            // {
            //     if(row[l] != "")
            //     {
            //         unique[count] = row[l];
            //         cout << unique[count] << "|" << count << endl;
            //         count++;
            //     }
            // }
            
            // counts the number of words
            words += pos;

            pos = 0; 
        }
        
        // Outputs the total and unique words
        cout << "\nUnique words: " << count << endl;
        cout << "Total words: " << words - 1<< endl;
    }
    
    file.close();
    return 0; 
}