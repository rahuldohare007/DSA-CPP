#include <bits/stdc++.h>
using namespace std;

void rotateArray(vector<int>& arr, int k, string dir)
{
    int size = arr.size();

    if (size == 0 || k == 0) return;

    k = k % size;

    if (dir == "right")
    {
        reverse(arr.begin(), arr.end());
        reverse(arr.begin(), arr.begin() + k);
        reverse(arr.begin() + k, arr.end());
    }
    else if (dir == "left")
    {
        reverse(arr.begin(), arr.begin() + k);
        reverse(arr.begin() + k, arr.end());
        reverse(arr.begin(), arr.end());
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    string dir = "right";

    rotateArray(arr, k, dir);

    for (int num : arr)
        cout << num << " ";

    return 0;
}

// Example - Right
// Input: arr = [1, 2, 3, 4, 5, 6, 7], k = 3
// Output: 5 6 7 1 2 3 4

// Example - Left
// Input: arr = [1, 2, 3, 4, 5, 6, 7], k = 3
// Output: 4 5 6 7 1 2 3

// Time Complexity: O(n), where n is the number of elements in the array.
// The reverse operation takes linear time, and we perform it three times.

// Space Complexity: O(1), as we are modifying the array in place and not using any additional data structures.