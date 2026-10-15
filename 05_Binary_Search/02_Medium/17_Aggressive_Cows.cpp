#include <bits/stdc++.h>
using namespace std;

// Given an array nums of size n, which denotes the positions of stalls, and an integer k, which denotes the number of aggressive cows, assign stalls to k cows such that the minimum distance between any two cows is the maximum possible.
// Find the maximum possible minimum distance.

bool canPlace(vector<int>& nums, int k, int dist) {
    int cows = 1;
    int lastPos = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] - lastPos >= dist) {
            cows++;
            lastPos = nums[i];

            if (cows >= k)
                return true;
        }
    }

    return false;
}

int aggressiveCows(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());

    int low = 1;
    int high = nums.back() - nums.front();
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlace(nums, k, mid)) {
            ans = mid;
            low = mid + 1;  
        } else {
            high = mid - 1; 
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {0, 3, 4, 7, 10, 9};
    int n = 6, k = 4;

    cout << aggressiveCows(nums, k) << endl;
    return 0;
}

// Example 1:
// Input: n = 6, k = 4, nums = [0, 3, 4, 7, 10, 9]
// Output: 3
// Explanation: The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions [0, 3, 7, 10]. Here the distances between cows are 3, 4, and 3 respectively.
// In no manner can we increase the minimum distance beyond 3.

// Example 2:
// Input : n = 5, k = 2, nums = [4, 2, 1, 3, 6]
// Output: 5
// Explanation: The maximum possible minimum distance between any two cows will be 5 when 2 cows are placed at positions [1, 6]. 

// Time Complexity: O(n log n + n log D), where (D = max(nums) - min(nums)).
// Space Complexity : O(log n) for sorting's typical recursion stack; the greedy check uses (O(1)).