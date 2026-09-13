#include <bits/stdc++.h>
using namespace std;

// Boyer-Moore Voting Algorithm
int majorityElements(vector<int> &nums)
{
    int res = 0, majority = 0;
    for (int n : nums)
    {
        if (majority == 0)
        {
            res = n;
        }
        majority += n == res ? 1 : -1;
    }
    return res;
}

int main()
{
    vector<int> nums = {3, 2, 3};
    cout << majorityElements(nums) << endl;
    return 0;
}

// Example 1:
// Input: nums = [3,2,3]
// Output: 3

// Example 2:
// Input: nums = [2,2,1,1,1,2,2]
// Output: 2

// Time Complexity: O(n)
// Space Complexity: O(1)

// Boyer-Moore Voting Algorithm
// Objective: Find the majority element (appears more than ⌊n / 2⌋ times) in O(n) time and O(1) space.

// Logic:
// • Initialize: Start with result (the candidate) and count (its frequency) both set to 0.
// • Iterate: For each number in the array:
//     ○ If count is 0, set result to the current number.
//     ○ Increment count if the current number matches result, otherwise decrement it. 
//     ○ Return: After the loop, result holds the majority element.