// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 - Sravanth Yajamanam
// Homework 5 - Problem #4

#include <iostream>
using namespace std;

/*
* This function returns the sum of the maximum value from each row of a given array.
* Parameters: arr[] - a two dimensional array of integers with 10 columns, rows - number of rows in the array
* Return: sum of the maximum value from each row of a given array
*/

int maxSum(int arr[][10], int rows)
{
    int sum = 0;
    for(int j = 0; j < rows; j++)
    {
        int max = arr[j][0];
        
        //finds the maximum of each row
        for(int i = 0; i < 10; i++)
        {
            if(arr[j][i] > max)
            {
                max = arr[j][i];
            }
        } 
        
        // calculates the sum of the maximums
        sum = sum + max;
    }
    
    return sum;
}

int main()
{
    // sample run 1
    // int myArray[2][10] = 
    // {
    //     {9, 2 ,2, 3, 5, 7, 9, 7, 6, 8},
    //     {6, 8, 3, 9, 0, 2, 3, 3, 10, 6},
    // };
    
    // sample run 2
    int myArray[3][10] = 
    {
        {5, 2, 8, -8, 9, 9, 8, -5, -1, -5},
        {4, 1, 8, 0, 10, 7, 6, 1, 8, -5},
        {11, 2, -3, 8, 7, 10, 0, 3, 9, 11},
    };
    
    cout << "max sum: " << maxSum(myArray, 3); 
    
    return 0;
}