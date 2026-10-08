#include <bits/stdc++.h>
using namespace std;

// You are given a sorted array of integers arr and an integer target. Your task is to determine how many times target appears in arr.
// Return the count of occurrences of target in the array.

int firstOccurrence(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {
            ans = mid;
            high = mid - 1; // Search left
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}

int lastOccurrence(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {
            ans = mid;
            low = mid + 1; // Search right
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}

int countOccurrences(vector<int> &arr, int target)
{
    int first = firstOccurrence(arr, target);

    // Target doesn't exist
    if (first == -1)
        return 0;

    int last = lastOccurrence(arr, target);

    return last - first + 1;
}

int main()
{
    vector<int> arr = {0, 0, 1, 1, 1, 2, 3};
    int target = 1;

    int count = countOccurrences(arr, target);
    cout << count << endl;
    
    return 0;
}

// Example 1:
// Input: arr = [0, 0, 1, 1, 1, 2, 3], target = 1
// Output: 3
// Explanation: The number 1 appears 3 times in the array.

// Example 2:
// Input: arr = [5, 5, 5, 5, 5, 5], target = 5
// Output: 6
// Explanation: All elements in the array are 5, so the target appears 6 times.

// Time Complexity: O(log n)
// Space Complexity: O(1)