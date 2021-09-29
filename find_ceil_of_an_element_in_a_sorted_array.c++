/*CEILING OF AN ELEMENT IN A SORTED ARRAY:
Given a sorted array and a value x, the ceiling of x is the smallest element in array greater than or equal to x, and the floor is the greatest element smaller than or equal to x. Assume than the array is sorted in non-decreasing order. Write efficient functions to find floor and ceiling of x.
Examples :
For example, let the input array be {1, 2, 8, 10, 10, 12, 19}
For x = 0:    floor doesn't exist in array,  ceil  = 1
For x = 1:    floor  = 1,  ceil  = 1
For x = 5:    floor  = 2,  ceil  = 8
For x = 20:   floor  = 19,  ceil doesn't exist in array*/
#include <bits/stdc++.h>
using namespace std;

int binarySearchForFindCeilElementInASortedArray(int arr[], int n, int element)
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
            result = arr[mid];
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return result;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 8, 10, 10, 12, 19};
    int n = sizeof(arr) / sizeof(arr[0]);

    /*According to the question -> If the element is present inside the array, then the ceil of that element
    will be the element itself. If the element is not present inside the array, then the ceil of that element
    will be greater element that is present inside the array.*/
    /*according to question the ceil of 5 => element 5 itself, if 5 is not present in the array so,
    ceil of 5 => smallest element which is greater than 5 present inside the array */
    int element = 5;

    int foundAtIndex = binarySearchForFindCeilElementInASortedArray(arr, n, element);

    if (foundAtIndex == -1)
    {
        cout << "The ceil of the element " << element << " is not found in the array" << endl;
    }
    else
    {
        cout << "The ceil of the element " << element << " is: " << foundAtIndex << endl;
    }

    return 0;
}

//*****************************FOR DOUBLE VALUES STORED IN THE ARRAY**************************

// #include <bits/stdc++.h>
// using namespace std;

// double binarySearchForFindCeilElementInASortedArray(double arr[], int n, double element)
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
//             result = arr[mid];
//             end = mid - 1;
//         }
//         else
//         {
//             start = mid + 1;
//         }
//     }
//     return result;
// }

// int main()
// {
//     double arr[] = {1.2, 2.4, 3.5, 4.9, 5.4, 5.7, 6};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     /*According to the question -> If the element is present inside the array, then the ceil of that element
//     will be the element itself. If the element is not present inside the array, then the ceil of that element
//     will be greater element that is present inside the array.*/
//     /*according to question the ceil of 5.8 => element greater than 5.8 present inside the array yaa phir
//     element equal to 5.8 present inside the array */
//     double element = 5.8;

//     double foundAtIndex = binarySearchForFindCeilElementInASortedArray(arr, n, element);

//     if (foundAtIndex == -1)
//     {
//         cout << "The ceil of the element " << element << " is not found in the array" << endl;
//     }
//     else
//     {
//         cout << "The ceil of the element " << element << " is: " << foundAtIndex << endl;
//     }

//     return 0;
// }