#include <bits/stdc++.h>
using namespace std;

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