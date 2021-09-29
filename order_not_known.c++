/*Given a sorted array of numbers, find if a given number ‘key’ is present in the array. Though we know that the array is sorted, we don’t know if it’s sorted in ascending or descending order.*/
#include <bits/stdc++.h>
using namespace std;

int binarySearchForAscendingArray(int arr[], int n, int element)
{
    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == element)
        {
            return mid;
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
    return -1;
}

int binarySearchForDescendingArray(int arr[], int n, int element)
{
    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == element)
        {
            return mid;
        }
        else if (arr[mid] > element)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int main()
{
    // int arr[] = {5, 4, 3, 2, 1};
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int element = 5;

    if (arr[0] > arr[n - 1])
    {
        int foundAtIndex = binarySearchForDescendingArray(arr, n, element);

        if (foundAtIndex == -1)
        {
            cout << "The element " << element << " is not found in the array" << endl;
        }
        else
        {
            cout << "The element " << element << " is found at index: " << foundAtIndex << endl;
        }
    }
    else
    {
        int foundAtIndex = binarySearchForAscendingArray(arr, n, element);

        if (foundAtIndex == -1)
        {
            cout << "The element " << element << " is not found in the array" << endl;
        }
        else
        {
            cout << "The element " << element << " is found at index: " << foundAtIndex << endl;
        }
    }

    return 0;
}