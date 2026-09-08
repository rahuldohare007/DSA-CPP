#include <bits/stdc++.h>
using namespace std;

bool checkSortedAndRotated(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[(i + 1) % n])
        {
            count++;
        }
    }
    return count <= 1;
}

int main()
{
    int arr[] = {3, 4, 5, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (checkSortedAndRotated(arr, n))
    {
        cout << "The array is sorted and rotated." << endl;
    }
    else
    {
        cout << "The array is not sorted and rotated." << endl;
    }

    return 0;
}

// (arr[i] > arr[(i + 1) % n])
// Explanation: The expression (arr[i] > arr[(i + 1) % n]) is used to compare the current element arr[i] with the next element arr[(i + 1) % n] in a circular manner.
// The modulo operator (%) ensures that when we reach the last element of the array, we wrap around and compare it with the first element.
// This is crucial for checking if the array is sorted and rotated, as it allows us to handle the rotation case where the last element may be greater than the first element.

// Example: For an array arr = [3, 4, 5, 1, 2], when i = 4 (the last index), arr[(i + 1) % n] will be arr[0], which is 3.
// Output: True

// Example: For an array arr = [2, 1, 3, 4], when i = 3 (the last index), arr[(i + 1) % n] will be arr[0], which is 2.
// Output: False

// Time Complexity: O(n)
// Space Complexity: O(1)