/*FIND MAXIMUM ELEMENT IN AN BITONIC ARRAY:
Problem statement:
Given a bitonic array find the maximum value of the array. An array is said to be bitonic if it has an increasing sequence of integers followed immediately by a decreasing sequence of integers.
Example:
Input:
1 4 8 3 2
Output:
8*/
#include <bits/stdc++.h>
using namespace std;

int binarySearchOnFindMaximumElementInBitonicArray(int arr[], int n)
{
    if (n == 1)
    {
        return arr[0];
    }

    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (mid > 0 && mid < n - 1)
        {
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            {
                return arr[mid];
            }
            else if (arr[mid - 1] > arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        else if (mid == 0)
        {
            if (arr[0] > arr[1])
            {
                return arr[0];
            }
            else
            {
                return arr[1];
            }
        }
        else if (mid == n - 1)
        {
            if (arr[n - 1] > arr[n - 2])
            {
                return arr[n - 1];
            }
            else
            {
                return arr[n - 2];
            }
        }
    }
    return -1;
}

int main()
{
    /*Bitonic Array -> An array is said to be bitonic if it has an monotonically increasing sequence of integers
    followed immediately by a monotonically decreasing sequence of integers.*/
    int arr[] = {1, 3, 8, 12, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int foundElement = binarySearchOnFindMaximumElementInBitonicArray(arr, n);

    cout << "The maximum element in bitonic array is: " << foundElement;

    return 0;
}