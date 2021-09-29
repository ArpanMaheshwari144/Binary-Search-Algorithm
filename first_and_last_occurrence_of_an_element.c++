/*FIND FIRST AND LAST POSITIONS OF AN ELEMENT IN A SORTED ARRAY:
Given a sorted array with possibly duplicate elements, the task is to find indexes of first and last occurrences of an element x in the given array.
Example:
Input : arr[] = {1, 3, 5, 5, 5, 5 ,67, 123, 125}    
        x = 5
Output : First Occurrence = 2
         Last Occurrence = 5*/
#include <bits/stdc++.h>
using namespace std;

int binarySearchForFirstOccurrence(int arr[], int n, int element)
{
    int start = 0;
    int end = n - 1;
    int result = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == element)
        {
            result = mid;
            end = mid - 1;
        }
        else if (arr[mid] > element)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return result;
}

int binarySearchForLastOccurrence(int arr[], int n, int element)
{
    int start = 0;
    int end = n - 1;
    int result = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == element)
        {
            result = mid;
            start = mid + 1;
        }
        else if (arr[mid] > element)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return result;
}

int main()
{
    int arr[] = {2, 4, 10, 10, 10, 10, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    int element = 10;

    int firstOccurrenecFoundAtIndex = binarySearchForFirstOccurrence(arr, n, element);
    int lastOccurrenecFoundAtIndex = binarySearchForLastOccurrence(arr, n, element);

    if (firstOccurrenecFoundAtIndex == -1)
    {
        cout << "The first occurrence of element " << element << " is not found in the array" << endl;
    }
    else
    {
        cout << "The first occurrence of element " << element << " is found at index: " << firstOccurrenecFoundAtIndex << endl;
    }

    if (lastOccurrenecFoundAtIndex == -1)
    {
        cout << "The last occurrence of element " << element << " is not found in the array" << endl;
    }
    else
    {
        cout << "The last occurrence of element " << element << " is found at index: " << lastOccurrenecFoundAtIndex << endl;
    }

    return 0;
}