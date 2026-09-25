#include <bits/stdc++.h>
using namespace std;

// Given an integer array of size n, find all elements that appear more than ⌊n / 3⌋ times.

vector<int> majorityElement(vector<int> &nums)
{
    int count1 = 0, count2 = 0;
    int candidate1 = -1, candidate2 = -1;

    for (int num : nums)
    {
        if (num == candidate1)
        {
            count1++;
        }
        else if (num == candidate2)
        {
            count2++;
        }
        else if (count1 == 0)
        {
            candidate1 = num;
            count1 = 1;
        }
        else if (count2 == 0)
        {
            candidate2 = num;
            count2 = 1;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    count1 = 0;
    count2 = 0;

    for (int num : nums)
    {
        if (num == candidate1)
            count1++;
        else if (num == candidate2)
            count2++;
    }

    vector<int> result;
    if (count1 > nums.size() / 3)
        result.push_back(candidate1);
    if (count2 > nums.size() / 3)
        result.push_back(candidate2);

    return result;
}

int main()
{
    vector<int> nums = {3, 2, 3};
    vector<int> result = majorityElement(nums);

    for (int num : result)
    {
        cout << num << " ";
    }

    return 0;
}

// Example 1:
// Input: nums = [3,2,3]
// Output: [3]

// Example 2:
// Input: nums = [1]
// Output: [1]

// Example 3:
// Input: nums = [1,2]
// Output: [1,2]

// Time Complexity: O(n)
// Space Complexity: O(1)