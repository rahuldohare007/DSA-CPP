#include <bits/stdc++.h>
using namespace std;

// You are given a string s consisting of lowercase English letters from 'a' to 'j'.
// A substring is considered valid if at most one character occurs an odd number of times in that substring.
// Return the total number of valid substrings in s.
// A substring is a contiguous, non-empty sequence of characters within a string.

long long countSubstrings(string s){
    long long ans = 0;
    int mask = 0;

    unordered_map<int, int> mp;
    mp[0] = 1;

    for (char c : s) {
        mask ^= (1 << (c - 'a'));

        // All character frequencies are even
        ans += mp[mask];

        // Exactly one character has an odd frequency
        for (int i = 0; i < 10; i++) {
            ans += mp[mask ^ (1 << i)];
        }

        mp[mask]++;
    }

    return ans;
}

int main(){
    string s;
    cin >> s;

    cout << countSubstrings(s) << endl;
    return 0;
}

// Example 1:
// Input: s = "aba"
// Output: 4
// Explanation: The valid substrings are "a", "b", "a", and "aba". Each contains at most one character with an odd frequency.

// Example 2:
// Input: s = "aabb"
// Output: 9
// Explanation: There are 10 substrings in total. The only invalid substring is "ab", where both 'a' and 'b' occur an odd number of times. Hence, the answer is 9.

// Time Complexity: O(n)
// Space Complexity: O(n)