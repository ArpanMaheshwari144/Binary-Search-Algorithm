/*ALLOCATE MINIMUM NUMBER OF PAGES -> Given number of pages in n different books and m students. The books are arranged in ascending order of number of pages. Every student is assigned to read some consecutive books. The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum.
Example:
Input1: pages[] = {10, 20, 30, 40}
m = 1
Explanation:
There are 1 number of students. Books can be distributed in following fashion : 
1. [10, 20, 30, 40] -> Max number of pages is allocated to student 1 with 10 + 20 + 30 + 40 = 100 pages
Of the 1 cases, Option 1 has the minimum pages = 100. 

Input2: pages[] = {10, 20, 30, 40}
m = 2
Explanation:
There are 2 number of students. Books can be distributed in following fashion : 
1. [10] and [20, 30, 40] -> Max number of pages is allocated to student 2 with 20 + 30 + 40 = 90 pages
2. [10, 20] and [30, 40] -> Max number of pages is allocated to student 2 with 30 + 40 = 70 pages 
3. [10, 20, 30] and [40] -> Max number of pages is allocated to student 1 with 10 + 20 + 30 = 60 pages
Of the 3 cases, Option 3 has the minimum pages = 60. 

Input3: pages[] = {10, 20, 30, 40}
m = 3
Explanation:
There are 3 number of students. Books can be distributed in following fashion : 
1. [10], [20] and [30, 40] -> Max number of pages is allocated to student 3 with 30 + 40 = 70 pages
2. [10, 20], [30] and [40] -> Max number of pages is allocated to student 3 with 40 = 40 pages 
Of the 2 cases, Option 2 has the minimum pages = 40.

Input4: pages[] = {10, 20, 30, 40}
m = 4
Explanation:
There are 4 number of students. Books can be distributed in following fashion : 
1. [10], [20] [30] and [40] -> Max number of pages is allocated to student 4 with 40 = 40 pages
Of the 1 cases, Option 1 has the minimum pages = 40.
*/

#include <bits/stdc++.h>
using namespace std;

int maxInArray(int arr[], int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

int sumOfArray(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    return sum;
}

bool isValid(int arr[], int n, int numberOfStudents, int mid)
{
    int student = 1;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
        if (sum > mid)
        {
            student = student + 1;
            sum = arr[i];
        }
        if (student > numberOfStudents)
        {
            return false;
        }
    }
    return true;
}

int allocateMinimumNumberOfPages(int arr[], int n, int numberOfStudents)
{
    // return -1 if number of books is less than number of students
    if (n < numberOfStudents)
    {
        return -1;
    }

    int start = maxInArray(arr, n);
    int end = sumOfArray(arr, n);
    int result = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (isValid(arr, n, numberOfStudents, mid) == true)
        {
            result = mid;
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
    // arr[0] represents a book with 10 number of pages
    int arr[] = {10, 20, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int numberOfStudents = 2;

    int ans = allocateMinimumNumberOfPages(arr, n, numberOfStudents);

    if (ans == -1)
    {
        cout << "Cannot find minimum number of pages that one student can read" << endl;
    }
    else
    {
        cout << "Minimum number of pages that one student can read is: " << allocateMinimumNumberOfPages(arr, n, numberOfStudents) << endl;
    }

    return 0;
}