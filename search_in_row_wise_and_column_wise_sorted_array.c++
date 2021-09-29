/*SEARCH IN A ROW WISE AND COLUMN WISE SORTED MATRIX:
Given an n x n matrix and a number x, find the position of x in the matrix if it is present in it. Otherwise, print “Not Found”. In the given matrix, every row and column is sorted in increasing order. The designed algorithm should have linear time complexity.
Example :
Input : mat[4][4] = {{10, 20, 30, 40},
                     {15, 25, 35, 45},
                     {27, 29, 37, 48},
                     {32, 33, 39, 50}
                    };
              x = 29
Output : Found at (2, 1)
*/
#include <bits/stdc++.h>
using namespace std;

#define R 4 // size of row in a matrix
#define C 4 // size of column in a matrix

pair<int, int> binarySearchOn2DArray(int arr[R][C], int n, int m, int element, pair<int, int> &p)
{
    int i = 0;
    int j = m - 1;

    while (i >= 0 && i < n && j >= 0 && j < m)
    {
        if (arr[i][j] == element)
        {
            p.first = i;
            p.second = j;

            return p;
        }
        else if (arr[i][j] > element)
        {
            j = j - 1;
        }
        else
        {
            i = i + 1;
        }
    }
    p.first = -1;
    p.second = -1;
    return p;
}

int main()
{
    int arr[R][C] = {{10, 20, 30, 40},
                     {15, 25, 35, 45},
                     {27, 29, 37, 48},
                     {32, 33, 39, 50}};

    int n = sizeof(arr) / sizeof(arr[0]); // size of row
    int m = sizeof(arr[0]) / n;           // size of column

    pair<int, int> p;

    int element = 33;

    p = binarySearchOn2DArray(arr, n, m, element, p);

    if (p.first && p.second == (-1, -1))
    {
        cout << "The element " << element << " is not found in the array" << endl;
    }
    else
    {
        cout << "The element " << element << " is found at index: " << p.first << "," << p.second << endl;
    }

    return 0;
}