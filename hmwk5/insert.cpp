// CS1300 Spring 2020
// Author: Kevin Nguyen
// Recitation: 106 - Sravanth Yajamanam
// Homework 5 - Problem #3

#include <iostream>
using namespace std;

/*
* This function inserts the given integer into the given array so the array remains in sorted order
* Parameters: my_array - an array of integers, elements - number of elements in the array, size - size of the array, new_element - new element to be added
* Return: number of elements in the array after the insert
*/

int insert(int myArray[], int elements, int size, int newElement)
{
    // the program only inserts if the current number of elements is less than the size of the array
    if(elements < size)
    {
        int pos = 0;
        
        // finds the position where the new element should be inserted
        for(int j = 0; j < elements; j++)
        {
            if(newElement > myArray[pos])
            {
                pos++;
            }
        }
        
        // shifts all the elements after the insert position back one space
        for(int i = elements; i > pos; i--)
        {
            myArray[i] = myArray[i-1];
        }
        
        // inserts the new element into the sorted position
        myArray[pos] = newElement;
        elements++;
    }
    
    return elements;
}


int main()
{
    // sample run 1
    // int arr[10] = {1,1,3,4,5,5,5,6};
    // int currentElements = 8, arrSize = 10, insertValue = 2;
    // int insertElements = insert(arr, currentElements, arrSize, insertValue);
    
    // sample run 2
    int arr[10] = {1,1,3,4,5,5,5,6};
    int currentElements = 8, arrSize = 10, insertValue = 0;
    int insertElements = insert(arr, currentElements, arrSize, insertValue);
    
    for(int i = 0; i < insertElements; i++)
    {
        cout << arr[i] << ' ';
    }
   
    return 0; 
}