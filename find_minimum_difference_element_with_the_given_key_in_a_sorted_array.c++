/*Given a sorted array, find the element in the array which has minimum difference with the given number.*/
#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

int binarySearchOnFindMinDiffElementWithTheGivenKeyInASortedArray(int arr[], int n, int key)
{
    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key)
        {
            return arr[mid];
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    int result1 = arr[start];
    int result2 = arr[end];

    return min(result1, result2);
}

int main()
{
    int arr[] = {1, 3, 8, 10, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 12;

    int ans = binarySearchOnFindMinDiffElementWithTheGivenKeyInASortedArray(arr, n, key);

    cout << "The minimum difference element when it is subtracted by " << key << " is: " << ans << endl;
    cout << "The minimum absolute difference is " << key << " - " << ans << " = " << abs(ans - key) << endl;

    return 0;
}