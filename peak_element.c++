/*FIND PEAK ELEMENT IN AN ARRAY:
A peak element is an element that is greater than its neighbors.
Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.
The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
You may imagine that nums[-1] = nums[n] = -∞.
Example :
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
*/
#include <bits/stdc++.h>
using namespace std;

int binarySearchOnPeakElement(int arr[], int n)
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

int main()
{
    int arr[] = {5, 10, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    // A peak element is an element that is strictly greater than its neighbors.
    int peakElement = binarySearchOnPeakElement(arr, n);

    cout << "Peak element found at index is: " << peakElement;

    return 0;
}