#include <bits/stdc++.h>
using namespace std;

// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
// Return the minimum integer k such that she can eat all the bananas within h hours.

int minEatingSpeed(vector<int> &piles, int h)
{
    int left = 1, right = *max_element(piles.begin(), piles.end());

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        int hours = 0;

        for (int pile : piles)
            hours += (pile + mid - 1) / mid; // Calculate hours needed at speed mid

        if (hours <= h)
            right = mid; // Try a smaller speed
        else
            left = mid + 1; // Increase speed
    }
    return left;
}

int main()
{
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    cout << "Minimum eating speed for example 1: " << minEatingSpeed(piles, h) << endl;
    return 0;
}

// Example 1:
// Input: piles = [3,6,7,11], h = 8
// Output: 4

// Example 2:
// Input: piles = [30,11,23,4,20], h = 5
// Output: 30

// Example 3:
// Input: piles = [30,11,23,4,20], h = 6
// Output: 23

// Time Complexity: O(n log m), where n is the number of piles and m is the maximum number of bananas in a pile. The binary search runs in log m time, and for each mid value, we iterate through all piles to calculate the total hours needed.
// Space Complexity: O(1)