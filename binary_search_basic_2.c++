/*BINARY SEARCH ON REVERSE SORTED ARRAY:
Let's suppose that we have an array sorted in descending order and we want to find index of an element e within this array. Binary search in every step picks the middle element (m) of the array and compares it to e. If these elements are equal, than it returns the index of m. If e is greater than m, than e must be located in the left subarray. On the contrary, if m greater than e, e must be located in the right subarray. At this moment binary search repeats the step on the respective subrarray.
Because the algoritm splits in every step the array in half (and one half of the array is never processed) the input element must be located (or determined missing) in at most \\log_{2}{n} steps.
*/
#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int element)
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
    int arr[] = {20, 17, 15, 14, 13, 12, 10, 9, 8, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int element = 19;

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