/*FIND FLOOR OF AN ELEMENT IN A SORTED ARRAY:
Given a sorted array and a value x, the floor of x is the largest element in array smaller than or equal to x. Write efficient functions to find floor of x.
Example:
Input : arr[] = {1, 2, 8, 10, 10, 12, 19}, x = 5
Output : 2
2 is the largest element in arr[] smaller than 5.*/
#include <bits/stdc++.h>
using namespace std;

int binarySearchForFindFloorElementInASortedArray(int arr[], int n, int element)
{
    int start = 0;
    int end = n - 1;
    int result = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == element)
        {
            return arr[mid];
        }
        else if (arr[mid] > element)
        {
            end = mid - 1;
        }
        else
        {
            result = arr[mid];
            start = mid + 1;
        }
    }
    return result;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 8, 10, 10, 12, 19};
    int n = sizeof(arr) / sizeof(arr[0]);

    /*According to the question -> If the element is present inside the array, then the floor of that element
    will be the element itself. If the element is not present inside the array, then the floor of that element
    will be smaller element that is present inside the array.*/
    /*according to question the floor of 5 => element 5 itself, if 5 is not present in the array so,
    floor of 5 => greatest element which is smaller than 5 present inside the array */
    int element = 5;

    int foundAtIndex = binarySearchForFindFloorElementInASortedArray(arr, n, element);

    if (foundAtIndex == -1)
    {
        cout << "The floor of the element " << element << " is not found in the array" << endl;
    }
    else
    {
        cout << "The floor of the element " << element << " is: " << foundAtIndex << endl;
    }

    return 0;
}

//*****************************FOR DOUBLE VALUES STORED IN THE ARRAY**************************

// #include <bits/stdc++.h>
// using namespace std;

// double binarySearchForFindFloorElementInASortedArray(double arr[], int n, double element)
// {
//     int start = 0;
//     int end = n - 1;
//     double result = -1.0;

//     while (start <= end)
//     {
//         int mid = start + (end - start) / 2;

//         if (arr[mid] == element)
//         {
//             return arr[mid];
//         }
//         else if (arr[mid] > element)
//         {
//             end = mid - 1;
//         }
//         else
//         {
//             result = arr[mid];
//             start = mid + 1;
//         }
//     }
//     return result;
// }

// int main()
// {
//     double arr[] = {1.2, 2.4, 3.5, 4.9, 5.4, 5.7};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     /*According to the question -> If the element is present inside the array, then the floor of that element
//     will be the element itself. If the element is not present inside the array, then the floor of that element
//     will be smaller element that is present inside the array.*/
//     /*according to question the floor of 5.6 => element smaller than 5.6 present inside the array yaa phir
//     element equal to 5.6 present inside the array.*/
//     double element = 5.6;

//     double foundAtIndex = binarySearchForFindFloorElementInASortedArray(arr, n, element);

//     if (foundAtIndex == -1)
//     {
//         cout << "The floor of the element " << element << " is not found in the array" << endl;
//     }
//     else
//     {
//         cout << "The floor of the element " << element << " is: " << foundAtIndex << endl;
//     }

//     return 0;
// }