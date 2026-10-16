#include <bits/stdc++.h>
using namespace std;

// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
// The overall run time complexity should be O(log (m+n)).

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2){
    
    if (nums1.size() > nums2.size())
        return findMedianSortedArrays(nums2, nums1);

    int x = nums1.size();
    int y = nums2.size();

    int low = 0, high = x;

    while (low <= high) {
        int partitionX = low + (high - low) / 2;
        int partitionY = (x + y + 1) / 2 - partitionX;

        int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];

        int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];

        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            if ((x + y) % 2 == 0)
                return (double)(max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2;
            else
                return (double)max(maxLeftX, maxLeftY);
        } else if (maxLeftX > minRightY) {
            high = partitionX - 1; 
        } else {
            low = partitionX + 1; 
        }
    }

    throw invalid_argument("Input arrays are not sorted.");
}

int main()
{
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};

    cout << findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}

// Example 1:
// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.

// Example 2:
// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

// Time Complexity: O(log(min(m, n))) where m and n are the sizes of the two arrays.
// Space Complexity: O(1)