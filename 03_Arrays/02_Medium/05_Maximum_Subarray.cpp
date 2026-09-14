#include <bits/stdc++.h>
using namespace std;

// Kadalen's Algorithm
int maxSubArray(vector<int> &nums)
{
    int maxSum = nums[0];
    int currentSum = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        currentSum = max(nums[i], currentSum + nums[i]);
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}
int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int result = maxSubArray(nums);
    cout << "Maximum Subarray Sum: " << result << endl;

    return 0;
}

// Examples:
// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.

// Input: nums = [1]
// Output: 1
// Explanation: The subarray [1] has the largest sum 1.

// Input: nums = [5,4,-1,7,8]
// Output: 23
// Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

// Time Complexity: O(n), where n is the number of elements in the input array. We traverse the array once to find the maximum subarray sum.
// Space Complexity: O(1), as we are using a constant amount of space for variables maxSum and currentSum.
