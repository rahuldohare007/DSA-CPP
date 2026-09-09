#include <bits/stdc++.h>
using namespace std;

vector<int> unionOfSortedArrays(int arr1[], int arr2[], int n, int m)
{
    vector<int> result;

    // Initialize two pointers for both arrays
    int i = 0, j = 0;

    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            if (result.empty() || result.back() != arr1[i])
            {
                result.push_back(arr1[i]);
            }
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            if (result.empty() || result.back() != arr2[j])
            {
                result.push_back(arr2[j]);
            }
            j++;
        }
        else
        {
            if (result.empty() || result.back() != arr1[i])
            {
                result.push_back(arr1[i]);
            }
            i++;
            j++;
        }
    }

    while (i < n)
    {
        if (result.empty() || result.back() != arr1[i])
        {
            result.push_back(arr1[i]);
        }
        i++;
    }

    while (j < m)
    {
        if (result.empty() || result.back() != arr2[j])
        {
            result.push_back(arr2[j]);
        }
        j++;
    }

    return result;
}

int main()
{
    int arr1[] = {1, 2, 4, 5, 6};
    int arr2[] = {2, 3, 5, 7};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    vector<int> result = unionOfSortedArrays(arr1, arr2, n, m);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}

// Example:
// Input: arr1 = {1, 2, 4, 5, 6}, arr2 = {2, 3, 5, 7}
// Output: 1 2 3 4 5 6 7

// Time Complexity: O(n + m), where n and m are the sizes of the input arrays.
// Space Complexity: O(n + m), as we are using a vector to store the result.