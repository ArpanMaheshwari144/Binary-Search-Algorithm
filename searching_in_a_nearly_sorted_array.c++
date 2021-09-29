/*SEARCH IN A NEARLY SORTED ARRAY:
Given an array which is sorted, but after sorting some elements are moved to either of the adjacent positions, i.e., arr[i] may be present at arr[i+1] or arr[i-1]. Write an efficient function to search an element in this array. Basically the element arr[i] can only be swapped with either arr[i+1] or arr[i-1].
For example consider the array {2, 3, 10, 4, 40}, 4 is moved to next position and 10 is moved to previous position.
Example :
Input: arr[] =  {10, 3, 40, 20, 50, 80, 70}, key = 40
Output: 2 
Output is index of 40 in given array
*/
#include <bits/stdc++.h>
using namespace std;

int binarySearchForSearchingInANearlySortedArray(int arr[], int n, int element)
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
        else if (mid - 1 >= start && arr[mid - 1] == element)
        {
            return mid - 1;
        }
        else if (mid + 1 <= end && arr[mid + 1] == element)
        {
            return mid + 1;
        }
        else if (arr[mid] > element)
        {
            end = mid - 2;
        }
        else
        {
            start = mid + 2;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {5, 10, 30, 20, 40};
    int n = sizeof(arr) / sizeof(arr[0]);

    int element = 40;

    int foundAtIndex = binarySearchForSearchingInANearlySortedArray(arr, n, element);

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