/*Suppose you have a sorted array of infinite numbers, how would you search an element in the array?
Since array is sorted, the first thing clicks into mind is binary search, but the problem here is that we don’t know size of array.
If the array is infinite, that means we don’t have proper bounds to apply binary search. So in order to find position of key, first we find bounds and then apply binary search algorithm.
Let low be pointing to 1st element and high pointing to 2nd element of array, Now compare key with high index element,
-if it is greater than high index element then copy high index in low index and double the high index.
-if it is smaller, then apply binary search on high and low indices found.
*/
#include <bits/stdc++.h>
using namespace std;

int binarySearchOnInfiniteSortedArray(int arr[], int start, int end, int element)
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

void findPositionOfAnElementInAnInfiniteSortedArray(int arr[], int element)
{
    int start = 0;
    int end = 1;

    while (element > arr[end])
    {
        start = end;
        end = end + 1;
    }

    int foundAtIndex = binarySearchOnInfiniteSortedArray(arr, start, end, element);

    if (foundAtIndex == -1)
    {
        cout << "The element " << element << " is not found in the array" << endl;
    }
    else
    {
        cout << "The element " << element << " is found at index: " << foundAtIndex << endl;
    }
}

int main()
{
    int arr[] = {3, 5, 7, 9, 10, 90, 100, 130, 140, 160, 170, 200, 300, 350, 400, 800};
    int element = 800;

    findPositionOfAnElementInAnInfiniteSortedArray(arr, element);

    return 0;
}