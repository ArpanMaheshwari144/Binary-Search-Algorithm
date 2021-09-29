/*Given an array of letters sorted in ascending order, find the smallest letter in the the array which is greater than a given key letter.*/
#include <bits/stdc++.h>
using namespace std;

char nextAlphabeticalElement(char alpabets[], int n, char element)
{
    int start = 0;
    int end = n - 1;
    char result = '#';

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (alpabets[mid] == element)
        {
            start = mid + 1;
        }
        else if (alpabets[mid] > element)
        {
            result = alpabets[mid];
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
    char alpabets[] = {'a', 'b', 'c', 'f', 'h', 'i', 'l'};
    int n = sizeof(alpabets) / sizeof(alpabets[0]);

    char element = 'f'; // find next alphabetical element which is present in the array

    char foundElement = nextAlphabeticalElement(alpabets, n, element);

    if (foundElement == '#')
    {
        cout << "The next alphabetical element " << element << " is not found in the array" << endl;
    }
    else
    {
        cout << "The next alphabetical element of " << element << " is: " << foundElement << endl;
    }

    return 0;
}