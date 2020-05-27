// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 - Sravanth Yajamanam
// Homework 5 - Problem #2

#include <iostream>
#include <iomanip>
using namespace std;

/*
* This function computes and prints the minimum value, maximum value, and the average value of all the values in an array.
* Parameters: my_array - an array of doubles, elements - the elements in stored the array
* Outputs: maximum, minimum, and average of the elements in the array
*/


void stats(double my_array[], int elements)
{
    double max = my_array[0], min = my_array[0], avg, sum = 0;
    for(int i = 0; i < elements; i++)
    {
        // Finds the maximum of the array elements
        if(my_array[i] > max)
        {
            max = my_array[i];
        }
        
        // Finds the minimum of the array elements
        if(my_array[i] < min)
        {
            min = my_array[i];
        }
        
        // calculates the average of the elements in the array
        sum = sum + my_array[i];
        avg = sum / elements;
    }
    
    // Outputs the minimum, maximum, and average of the elements in the array
    cout << "Min: " << fixed << setprecision(2) << min << endl;
    cout << "Max: " << max << endl;
    cout << "Avg: " << avg;
}

int main()
{
    //sample run 1
    // double test1[] = {10.4, 3.2, 1.4, 5.1, 6.7};
    // stats(test1, 5);
    
    //sample run2
    //double test2[] = {1, 2, 3};
    //stats(test2, 3);
    
    //sample run3
    double test3[] = {-1.2, -12.8, 5, 10.4, 11, 2.2, -1};
    stats(test3, 7);

    return 0;
}