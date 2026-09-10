#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums){
    int result = 0;
    for(int num : nums){
            result ^= num;
    }
    return result;
}

int main() {
    vector<int> nums = {4, 1, 2, 1, 2};
    int result = singleNumber(nums);

    cout << "The single number is: " << result << endl;
 
    return 0;
}

// Example:
// Input: nums = [4, 1, 2, 1, 2]
// Output: 4

// Time Complexity: O(n)
// Space Complexity: O(1)