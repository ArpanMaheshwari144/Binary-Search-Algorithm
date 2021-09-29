/*FIND AN ELEMENT IN BITONIC ARRAY:
Given a bitonic sequence of n distinct elements, write a program to find a given element x in the bitonic sequence in O(log n) time. A Bitonic Sequence is a sequence of numbers which is first strictly increasing then after a point strictly decreasing.
Examples:
Input :  arr[] = {-3, 9, 8, 20, 17, 5, 1};
         key = 20
Output : Found at index 3*/
#include <bits/stdc++.h>
using namespace std;

int searchIndexOfGreaterElementInBitonicArray(int arr[], int n)
{
    if (n == 1)
    {
        return 0;
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
                return mid;
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
                return 0;
            }
            else
            {
                return 1;
            }
        }
        else if (mid == n - 1)
        {
            if (arr[n - 1] > arr[n - 2])
            {
                return n - 1;
            }
            else
            {
                return n - 2;
            }
        }
    }
    return -1;
}

int binarySearchOnAscendingArray(int arr[], int n, int element, int start, int end)
{
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

int binarySearchOnDescendingArray(int arr[], int n, int element, int start, int end)
{
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

void searchIndexOfAnElementInBitonicArray(int arr[], int n)
{
    int element = 2;

    int indexOfGreaterElement = searchIndexOfGreaterElementInBitonicArray(arr, n);

    int ans1 = binarySearchOnAscendingArray(arr, n, element, 0, indexOfGreaterElement - 1);
    int ans2 = binarySearchOnDescendingArray(arr, n, element, indexOfGreaterElement, n - 1);

    if (ans1 == -1 && ans2 == -1)
    {
        cout << "The element " << element << " is not present in the array" << endl;
    }
    else
    {
        if (ans1 >= 0)
        {
            cout << "The element " << element << " is found at index: " << ans1 << endl;
        }
        else if (ans2 >= 0)
        {
            cout << "The element " << element << " is found at index: " << ans2 << endl;
        }
    }
}

int main()
{
    int arr[] = {1, 3, 8, 12, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    searchIndexOfAnElementInBitonicArray(arr, n);

    return 0;
}