#include <bits/stdc++.h>
using namespace std;

// Given a sorted array of nums and an integer x, write a program to find the lower bound of x.
// The lower bound algorithm finds the first and smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.
// If no such index is found, return the size of the array.
int lowerBound(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] >= target)
        {
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return low;
}

// Using in-built function lower_bound() from <algorithm> header file

// int lowerBound(vector<int> &nums, int target)
// {
//     return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
// }    


int main()
{
    vector<int> nums = {1, 2, 2, 3};
    int target = 2;

    cout << lowerBound(nums, target) << endl;

    return 0;
}

// Example 1:
// Input : nums= [1,2,2,3], x = 2
// Output:1
// Explanation:
// Index 1 is the smallest index such that arr[1] >= x.

// Example 2:
// Input : nums= [3,5,8,15,19], x = 9
// Output: 3
// Explanation:
// Index 3 is the smallest index such that arr[3] >= x.

// Time Complexity: O(log n)
// Space Complexity: O(1)