/*Given an infinite sorted array consisting 0s and 1s. The problem is to find the index of first ‘1’ in that array. As the array is infinite, therefore it is guaranteed that number ‘1’ will be present in the array.
Example:
Input : arr[] = {0, 0, 1, 1, 1, 1} 
Output : 2*/
#include <bits/stdc++.h>
using namespace std;

int binarySearchForFirstOccurrenceInABinarySortedInfiniteArray(int arr[], int start, int end, int element)
{
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

void findIndexOfFirst1InABinarySortedInfiniteArray(int arr[], int element)
{
    int start = 0;
    int end = 1;

    while (element > arr[end])
    {
        start = end;
        end = end + 1;
    }

    int firstOccurrenecFoundAtIndex = binarySearchForFirstOccurrenceInABinarySortedInfiniteArray(arr, start, end, element);

    if (firstOccurrenecFoundAtIndex == -1)
    {
        cout << "The first occurrence of element " << element << " is not found in the array" << endl;
    }
    else
    {
        cout << "The first occurrence of element " << element << " is found at index: " << firstOccurrenecFoundAtIndex << endl;
    }
}

int main()
{
    int arr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int element = 1;

    findIndexOfFirst1InABinarySortedInfiniteArray(arr, element);

    return 0;
}