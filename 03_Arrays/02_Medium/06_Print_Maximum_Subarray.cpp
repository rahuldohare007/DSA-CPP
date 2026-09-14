#include <bits/stdc++.h>
using namespace std;

vector<int> maxSubArray(vector<int> &nums)
{
    int maxSum = nums[0];
    int currentSum = nums[0];
    int start = 0, end = 0, tempStart = 0;

    for (int i = 1; i < nums.size(); i++)
    {
        if (currentSum + nums[i] < nums[i])
        {
            currentSum = nums[i];
            tempStart = i;
        }
        else
        {
            currentSum += nums[i];
        }

        if (currentSum > maxSum)
        {
            maxSum = currentSum;
            start = tempStart;
            end = i;
        }
    }

    return vector<int>(nums.begin() + start, nums.begin() + end + 1);
}

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> result = maxSubArray(nums);

    for (int num : result)
    {
        cout << num << " ";
    }

    return 0;
}

// Examples:
// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: [4,-1,2,1]
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.

// Input: nums = [1]
// Output: [1]
// Explanation: The subarray [1] has the largest sum 1.

// Input: nums = [5,4,-1,7,8]
// Output: [5,4,-1,7,8]
// Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

// Time Complexity: O(n), where n is the number of elements in the input array. We traverse the array once to find the maximum subarray.
// Space Complexity: O(k), where k is the length of the maximum subarray.
// We store the elements of the maximum subarray in a new vector to return it.