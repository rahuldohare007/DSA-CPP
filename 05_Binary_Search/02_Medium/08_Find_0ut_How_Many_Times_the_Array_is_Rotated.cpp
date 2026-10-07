#include <bits/stdc++.h>
using namespace std;

// Given an integer array nums of size n, sorted in ascending order with distinct values. The array has been right rotated an unknown number of times, between 0 and n-1 (including). Determine the number of rotations performed on the array.

int findKRotation(vector<int> &nums){
    int n = nums.size();
    int low = 0, high = n - 1;

    while(low <= high){
        if(nums[low] <= nums[high]){
            return low;
        }

        int mid = low + (high - low) / 2;
        int next = (mid + 1) % n;
        int prev = (mid - 1 + n) % n;

        if(nums[mid] <= nums[next] && nums[mid] <= nums[prev]){
            return mid;
        }
        else if(nums[mid] <= nums[high]){
            high = mid - 1;
        }
        else if(nums[mid] >= nums[low]){
            low = mid + 1;
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2, 3};

    int rotations = findKRotation(nums);
    cout << "The array has been rotated " << rotations << " times." << endl;

    return 0;
}

// Example 1:
// Input : nums = [4, 5, 6, 7, 0, 1, 2, 3]
// Output: 4
// Explanation: The original array should be [0, 1, 2, 3, 4, 5, 6, 7]. So, we can notice that the array has been rotated 4 times.

// Example 2:
// Input: nums = [3, 4, 5, 1, 2]
// Output: 3
// Explanation: The original array should be [1, 2, 3, 4, 5]. So, we can notice that the array has been rotated 3 times.

// Time Complexity: O(log n)
// Space Complexity: O(1)