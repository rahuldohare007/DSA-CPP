#include <bits/stdc++.h>
using namespace std;

// The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.
// For example, the beauty of "abaacc" is 3 - 1 = 2.
// Given a string s, return the sum of beauty of all of its substrings.

int beautySum(string s){
    int n = s.size();
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int freq[26] = {};

        for (int j = i; j < n; j++) {
            freq[s[j] - 'a']++;

            int mx = 0, mn = INT_MAX;

            for (int f : freq) {
                if (f > 0) {
                    mx = max(mx, f);
                    mn = min(mn, f);
                }
            }

            ans += mx - mn;
        }
    }

    return ans;
}

int main()
{
    string s = "aabcb";
    cout << beautySum(s) << endl;
    return 0;
}

// Example 1:
// Input: s = "aabcb"
// Output: 5
// Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.

// Example 2:
// Input: s = "aabcbaa"
// Output: 17

// Time Complexity: O(n^2)
// Space Complexity: O(1)