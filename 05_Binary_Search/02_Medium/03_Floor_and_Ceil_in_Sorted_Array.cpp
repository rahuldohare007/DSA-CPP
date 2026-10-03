#include <bits/stdc++.h>
using namespace std;

// Given a sorted array nums and an integer x.
// Find the floor and ceil of x in nums.
// The floor of x is the largest element in the array which is smaller than or equal to x.
// The ceiling of x is the smallest element in the array greater than or equal to x.
// If no floor or ceil exists, output -1.

vector<int> getFloorAndCeil(vector<int> &nums, int x)
{
    int floor = -1, ceil = -1;
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == x)
        {
            floor = ceil = x;
            break;
        }
        else if (nums[mid] < x)
        {
            floor = nums[mid];
            low = mid + 1;
        }
        else
        {
            ceil = nums[mid];
            high = mid - 1;
        }
    }
    return {floor, ceil};
}

// Using STL lower_bound to find the floor and ceil of x in nums.
vector<int> getFloorAndCeil(vector<int> &nums, int x)
{
    auto it = lower_bound(nums.begin(), nums.end(), x);

    int ceilVal = (it != nums.end()) ? *it : -1;
    int floorVal = -1;

    if (it != nums.end() && *it == x)
        floorVal = x;
    else if (it != nums.begin())
        floorVal = *(it - 1);

    return {floorVal, ceilVal};
}

int main()
{
    vector<int> nums = {3, 4, 4, 7, 8, 10};
    int x = 5;

    vector<int> result = getFloorAndCeil(nums, x);
    cout << "Floor: " << result[0] << ", Ceil: " << result[1] << endl;

    return 0;
}

// Example 1:
// Input : nums =[3, 4, 4, 7, 8, 10], x= 5
// Output: 4 7
// Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in the array is 7.

// Example 2:
// Input : nums =[3, 4, 4, 7, 8, 10], x= 8
// Output: 8 8
// Explanation: The floor of 8 in the array is 8, and the ceiling of 8 in the array is also 8.

// Time Complexity: O(log n), where n is the size of the array.
// Space Complexity: O(1).