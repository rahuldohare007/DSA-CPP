#include <bits/stdc++.h>
using namespace std;

void Frequency(int arr[], int n)
{
    unordered_map<int, int> freqMap;

    for (int i = 0; i < n; i++)
    {
        freqMap[arr[i]]++;
    }

    cout << "Element Frequencies:\n";
    for (const auto &pair : freqMap)
    {
        cout << "Element: " << pair.first << ", Frequency: " << pair.second << endl;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 2, 1, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    Frequency(arr, n);

    return 0;
}

// Time Complexity: O(n), where n is the number of elements in the array.
// This is because we traverse the array once to count frequencies.

// Space Complexity: O(k), where k is the number of unique elements in the array.
// This is because we use an unordered_map to store the frequencies of unique elements.