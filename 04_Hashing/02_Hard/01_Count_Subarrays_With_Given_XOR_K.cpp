#include <bits/stdc++.h>
using namespace std;

// Given an array of integers nums and an integer k, return the total number of subarrays whose XOR equals to k.

int subarraysWithXorK(vector<int> &nums, int k)
{
    unordered_map<int, int> freq;

    int prefixXor = 0, count = 0;
    freq[0] = 1;

    for (int num : nums)
    {
        prefixXor ^= num;

        if (freq.find(prefixXor ^ k) != freq.end())
        {
            count += freq[prefixXor ^ k];
        }

        freq[prefixXor]++;
    }

    return count;
}

int main()
{
    vector<int> nums = {4, 2, 2, 6, 4};
    int k = 6;

    cout << subarraysWithXorK(nums, k) << endl;

    return 0;
}

// Example 1:
// Input : nums = [4, 2, 2, 6, 4], k = 6
// Output : 4
// Explanation : The subarrays having XOR of their elements as 6 are [4, 2],  [4, 2, 2, 6, 4], [2, 2, 6], and [6]

// Example 2:
// Input :nums = [5, 6, 7, 8, 9], k = 5
// Output : 2
// Explanation : The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]

// Time Complexity: O(n)
// Space Complexity: O(n)