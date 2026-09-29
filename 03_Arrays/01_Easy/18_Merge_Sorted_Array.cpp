#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int left = m - 1;
    int right = n - 1;
    int index = m + n - 1;

    while (left >= 0 && right >= 0)
    {
        if (nums1[left] > nums2[right])
        {
            nums1[index--] = nums1[left--];
        }
        else
        {
            nums1[index--] = nums2[right--];
        }
    }

    while (right >= 0)
    {
        nums1[index--] = nums2[right--];
    }
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;
    merge(nums1, m, nums2, n);

    for (int num : nums1)
    {
        cout << num << " ";
    }

    return 0;
}

// Example 1:
// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]
// Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
// The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

// Example 2:
// Input: nums1 = [1], m = 1, nums2 = [], n = 0
// Output: [1]
// Explanation: The arrays we are merging are [1] and [].
// The result of the merge is [1].

// Example 3:
// Input: nums1 = [0], m = 0, nums2 = [1], n = 1
// Output: [1]
// Explanation: The arrays we are merging are [] and [1].
// The result of the merge is [1].
// Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.

// Time Complexity: O(m + n), where m and n are the sizes of nums1 and nums2, respectively.
// Space Complexity: O(1), as we are modifying nums1 in-place.