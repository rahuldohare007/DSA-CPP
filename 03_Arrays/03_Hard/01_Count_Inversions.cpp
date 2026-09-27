#include <bits/stdc++.h>
using namespace std;

long long merge(vector<int> &nums, int low, int mid, int high)
{
    vector<int> temp;
    int i = low;
    int j = mid + 1;

    long long count = 0;

    while (i <= mid && j <= high)
    {
        if (nums[i] <= nums[j])
        {
            temp.push_back(nums[i++]);
        }
        else
        {
            temp.push_back(nums[j++]);

            // All remaining elements in left half
            // form an inversion with nums[j - 1]
            count += mid - i + 1;
        }
    }

    while (i <= mid)
        temp.push_back(nums[i++]);

    while (j <= high)
        temp.push_back(nums[j++]);

    for (int k = low; k <= high; k++)
        nums[k] = temp[k - low];

    return count;
}

long long mergeSort(vector<int> &nums, int low, int high)
{
    if (low >= high)
        return 0;

    int mid = low + (high - low) / 2;

    long long count = 0;

    count += mergeSort(nums, low, mid);
    count += mergeSort(nums, mid + 1, high);
    count += merge(nums, low, mid, high);

    return count;
}

long long numberOfInversions(vector<int> nums)
{
    return mergeSort(nums, 0, nums.size() - 1);
}

int main()
{
    vector<int> nums = {1, 3, 5, 2, 4, 6};
    long long int result = numberOfInversions(nums);

    cout << result << endl;

    return 0;
}

// Example 1:
// Input: nums = [2, 3, 7, 1, 3, 5]
// Output: 5
// Explanation: The responsible indexes are:
// nums[0], nums[3], values: 2 > 1 & indexes: 0 < 3
// nums[1], nums[3], values: 3 > 1 & indexes: 1 < 3
// nums[2], nums[3], values: 7 > 1 & indexes: 2 < 3
// nums[2], nums[4], values: 7 > 3 & indexes: 2 < 4
// nums[2], nums[5], values: 7 > 5 & indexes: 2 < 5

// Example 2:
// Input: nums = [-10, -5, 6, 11, 15, 17]
// Output: 0
// Explanation: nums is sorted, hence no inversions present.

// Time Complexity: O(nlogn)
// Space Complexity: O(n)