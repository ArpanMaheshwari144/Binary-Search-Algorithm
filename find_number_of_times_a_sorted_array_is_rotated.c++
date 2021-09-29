/*Find the Rotation Count in Rotated Sorted array
Consider an array of distinct numbers sorted in increasing order. The array has been rotated (clockwise) k number of times. Given such an array, find the value of k.
Examples:
Input : arr[] = {15, 18, 2, 3, 6, 12}
Output: 2
Explanation : Initial array must be {2, 3, 6, 12, 15, 18}. We get the given array after rotating the initial array twice.
Input : arr[] = {7, 9, 11, 12, 5}
Output: 4
Input: arr[] = {7, 9, 11, 12, 15};
Output: 0
*/
#include <bits/stdc++.h>
using namespace std;

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
        // yaha index out of bound excpetion na aa jaye isliye mod n kara hai
        int next = (mid + 1) % n; // jab ending index par phuch jayega to mod n karne ki wajah se dobara starting index par phuch jayega

        // yaha index minus mei na phuch jaye isliye mod n or + n kara hai
        int prev = (mid - 1 + n) % n; // jab starting index par phuch jayega to + n and mod n karne ki wajah se dobara ending index par phuch jayega

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

int main()
{
    int arr[] = {11, 12, 15, 18, 2, 5, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = numberOfTimesASortedArrayIsRotated(arr, n);
    cout << "Number of times a sorted array is rotated is: " << result;

    return 0;
}