#include <bits/stdc++.h>
using namespace std;

// Given a sorted array of nums and an integer x, write a program to find the upper bound of x.
// The upper bound of x is defined as the smallest index i such that nums[i] > x.
// If no such index is found, return the size of the array.

int upperBound(vector<int> &nums, int target){
    int low = 0, high = nums.size() - 1;
    int upperBoundVal = nums.size();

    while(low < high){
        int mid = low + (high - low) / 2;
        if(nums[mid] > target){
            high = mid - 1;
            upperBoundVal = mid;
        }else
            low = mid + 1;
    }
    return upperBoundVal;
}

int main() {
 
 
    return 0;
}

// Example 1:
// Input : n= 4, nums = [1,2,2,3], x = 2
// Output:3
// Explanation:
// Index 3 is the smallest index such that arr[3] > x.

// Example 2:
// Input : n = 5, nums = [3,5,8,15,19], x = 9
// Output: 3
// Explanation:
// Index 3 is the smallest index such that arr[3] > x.

// Time Complexity: O(log n)
// Space Complexity: O(1)