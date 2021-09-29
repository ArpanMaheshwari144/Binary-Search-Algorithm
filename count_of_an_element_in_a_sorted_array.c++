/*COUNT NUMBER OF OCURRENCES(or frequency) IN A SORTED ARRAY:
Given a sorted array arr[] and a number x, write a function that counts the occurrences of x in arr[]. Expected time complexity is O(Logn)
Examples:
Input: arr[] = {1, 1, 2, 2, 2, 2, 3,},   x = 2
Output: 4 // x (or 2) occurs 4 times in arr[]
Input: arr[] = {1, 1, 2, 2, 2, 2, 3,},   x = 3
Output: 1 */
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

void countOfAnElementInASortedArray(int arr[], int n, int element)
{
    int firstOccurrenecFoundAtIndex = binarySearchForFirstOccurrence(arr, n, element);
    int lastOccurrenecFoundAtIndex = binarySearchForLastOccurrence(arr, n, element);

    if (firstOccurrenecFoundAtIndex == -1 || lastOccurrenecFoundAtIndex == -1)
    {
        cout << "The element " << element << " is not present in the array" << endl;
    }
    else
    {
        int ans = lastOccurrenecFoundAtIndex - firstOccurrenecFoundAtIndex + 1;
        cout << "The element " << element << " is occurs in the array is: " << ans;
    }
}

int main()
{
    int arr[] = {2, 4, 10, 10, 10, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    int element = 10;

    countOfAnElementInASortedArray(arr, n, element);

    return 0;
}