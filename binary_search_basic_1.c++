/*Given a sorted array arr[] of n elements, write a function to search a given element x in arr[].
Binary Search: Search a sorted array by repeatedly dividing the search interval in half. Begin with an interval covering the whole array. If the value of the search key is less than the item in the middle of the interval, narrow the interval to the lower half. Otherwise narrow it to the upper half. Repeatedly check until the value is found or the interval is empty.*/
#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int element)
{
    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        // int mid = (start + end) / 2; // In this integer can be overflow

        int mid = start + (end - start) / 2; // In this integer cannot be overflow

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

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    int element = 10;

    int foundAtIndex = binarySearch(arr, n, element);

    if (foundAtIndex == -1)
    {
        cout << "The element " << element << " is not found in the array" << endl;
    }
    else
    {
        cout << "The element " << element << " is found at index: " << foundAtIndex << endl;
    }

    return 0;
}