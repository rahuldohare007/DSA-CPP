#include <bits/stdc++.h>
using namespace std;
int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> st(nums.begin(), nums.end());
    int longest = 0;

    for (int num : st)
    {
        if (!st.count(num - 1))
        {
            int current = num;
            int length = 1;

            while (st.count(current + 1))
            {
                current++;
                length++;
            }
            longest = max(longest, length);
        }
    }
    return longest;
}
int main()
{
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    int result = longestConsecutive(nums);
    cout << "The length of the longest consecutive sequence is: " << result << endl;

    return 0;
}

// Example 1:
// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

// Example 2:
// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9

// Example 3:
// Input: nums = [1,0,1,2]
// Output: 3

// Time Complexity: O(n)
// Space Complexity: O(n)