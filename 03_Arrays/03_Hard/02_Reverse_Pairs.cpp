#include <bits/stdc++.h>
using namespace std;

// Given an integer array nums, return the number of reverse pairs in the array.
// A reverse pair is a pair (i, j) where:
// 0 <= i < j < nums.length and
// nums[i] > 2 * nums[j].

void merge(vector<int> &nums, vector<int> &temp,
           int low, int mid, int high, int &count)
{

    // Count reverse pairs
    int j = mid + 1;

    for (int i = low; i <= mid; i++)
    {
        while (j <= high &&
               (long long)nums[i] > 2LL * nums[j])
        {
            j++;
        }

        count += j - (mid + 1);
    }

    // Merge two sorted halves
    int i = low;
    j = mid + 1;
    int k = low;

    while (i <= mid && j <= high)
    {

        if (nums[i] <= nums[j])
            temp[k++] = nums[i++];
        else
            temp[k++] = nums[j++];
    }

    while (i <= mid)
        temp[k++] = nums[i++];

    while (j <= high)
        temp[k++] = nums[j++];

    // Copy back
    for (i = low; i <= high; i++)
        nums[i] = temp[i];
}

void mergeSort(vector<int> &nums, vector<int> &temp,
               int low, int high, int &count)
{

    if (low >= high)
        return;

    int mid = low + (high - low) / 2;

    mergeSort(nums, temp, low, mid, count);
    mergeSort(nums, temp, mid + 1, high, count);

    merge(nums, temp, low, mid, high, count);
}

int reversePairs(vector<int> &nums)
{

    int n = nums.size();
    vector<int> temp(n);

    int count = 0;

    mergeSort(nums, temp, 0, n - 1, count);

    return count;
}

int main()
{
    vector<int> nums = {1, 3, 2, 3, 1};
    cout << reversePairs(nums) << endl;

    return 0;
}

// Example 1:
// Input: nums = [1,3,2,3,1]
// Output: 2
// Explanation: The reverse pairs are:
// (1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
// (3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1

// Example 2:
// Input: nums = [2,4,3,5,1]
// Output: 3
// Explanation: The reverse pairs are:
// (1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
// (2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
// (3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1

// Time Complexity: O(nlogn)
// Space Complexity: O(n)