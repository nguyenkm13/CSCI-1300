#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//This program calculates a score for college applicants

int main() 
{
    string fileName, line;
    
    // Chooses the file to be opened
    cout << "Enter the file name:\n";
    cin >> fileName;
    ifstream file;
    file.open(fileName);

    vector< vector<string> > vec_data; 

    vector<string> rows;
    
    int line_count = 0;
    
    
    if(!file.is_open())
    {
       cout << "Could not open file.\n";
    } 
    else
    {
        while(getline(file, line))
        {
            if(line != "" && line != "Student,SAT,GPA,Interest,High School Quality,Sem1,Sem2,Sem3,Sem4")
            {
                line.push_back(',');
                line_count++;
                
                // stores each applicant's data into a vector
                for(int i = 0; i < line.length(); i++)
                {
                    if(line[i] == ',')
                    {
                        rows.push_back(line.substr(0, i));
                        line.erase(0, i + 1);
                        i = 0;
                    }
                }
                
                // stores rows vector into another vector, indexed by student
                vec_data.push_back(rows);
                rows.clear();
            }
        }
        cout << endl << "Results: \n";
        double scores[line_count - 1];
        for(int i = 0; i < line_count; i++)
        {
            
            // calculates scores for each student
            scores[i] = (stod(vec_data[i][2]) * 2 * 0.4) + (stod(vec_data[i][3]) * 0.1) + ((stod(vec_data[i][1]) / 160) * 0.3) + (stod(vec_data[i][4]) * 0.2); 
            cout << vec_data[i][0] << "," << scores[i];

            // score if higher or equal to 6
            if(scores[i] >= 6)
            {
                cout << ",score";
            } 
            
            // outlier if interest = 0, or the difference between scaled SAT and scaled GPA > 2
            else if((stoi(vec_data[i][3]) == 0 || (stod(vec_data[i][2]) * 2) - ((stod(vec_data[i][1]) / 160)) > 2) && scores[i] >= 5)
            {
                cout << ",outlier" ;
            } 
            
            // grade improvement if GPA improved in each of last 4 semesters
            else if(stod(vec_data[i][8]) > stod(vec_data[i][7]) && stod(vec_data[i][7]) > stod(vec_data[i][6]) && stod(vec_data[i][6]) > stod(vec_data[i][5]))
            {
                cout << ",grade improvement";
            }

            cout << endl;
        } 
    }

    file.close();
    return 0;
}