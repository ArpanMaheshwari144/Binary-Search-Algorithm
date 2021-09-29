/*FIND AN ELEMENT IN A ROTATED SORTED ARRAY:
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.
Your algorithm's runtime complexity must be in the order of O(log n).
Example:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4*/
#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int element, int start, int end)
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

// it returns the index of the minimum element
int numberOfTimesASortedArrayIsRotated(int arr[], int n)
{
    int start = 0;
    int end = n - 1;

    if (arr[start] < arr[end])
    {
        return 0;
    }

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        int next = (mid + 1) % n;

        int prev = (mid - 1 + n) % n;

        if (arr[prev] >= arr[mid] && arr[mid] <= arr[next])
        {
            // if array is right rotated(clockwise direction) means 1,2,3,4 -> right rotated is -> 2,3,4,1
            return n - mid;

            // if array is left rotated(anti-clockwise direction) means 1,2,3,4 -> left rotated is -> 4,1,2,3
            // return mid;
        }
        else if (arr[mid] <= arr[end])
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

void findAnElementInARotatedSortedArray(int arr[], int n)
{
    int element = 8;

    // it returns the index of the minimum element
    int ans = numberOfTimesASortedArrayIsRotated(arr, n);

    int ans1 = binarySearch(arr, element, 0, ans - 1);
    int ans2 = binarySearch(arr, element, ans, n - 1);

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
    int arr[] = {11, 12, 15, 18, 2, 5, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    findAnElementInARotatedSortedArray(arr, n);

    return 0;
}