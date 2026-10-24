#include <bits/stdc++.h>
using namespace std;

// Given a string s, return the longest palindromic substring in s.

string longestPalindrome(string s)
{
    int n = s.size();
    int start = 0, maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        // Odd-length palindrome
        int left = i, right = i;

        while (left >= 0 && right < n &&
               s[left] == s[right])
        {
            left--;
            right++;
        }

        if (right - left - 1 > maxLen)
        {
            maxLen = right - left - 1;
            start = left + 1;
        }

        // Even-length palindrome
        left = i;
        right = i + 1;

        while (left >= 0 && right < n &&
               s[left] == s[right])
        {
            left--;
            right++;
        }

        if (right - left - 1 > maxLen)
        {
            maxLen = right - left - 1;
            start = left + 1;
        }
    }

    return s.substr(start, maxLen);
}

// Manacher's Algorithm
string longestPalindrome_Manacher(string s) {
    string t = "^#";

    for (char c : s) {
        t += c;
        t += '#';
    }

    t += '$';

    int n = t.size();
    vector<int> p(n, 0);

    int center = 0, right = 0;
    int maxLen = 0, start = 0;

    for (int i = 1; i < n - 1; i++) {
        int mirror = 2 * center - i;

        if (i < right)
            p[i] = min(right - i, p[mirror]);

        while (t[i + 1 + p[i]] == t[i - 1 - p[i]])
            p[i]++;

        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }

        if (p[i] > maxLen) {
            maxLen = p[i];
            start = (i - maxLen) / 2;
        }
    }

    return s.substr(start, maxLen);
}

int main()
{
    string s;
    cin >> s;

    cout << longestPalindrome(s) << endl;
    cout << longestPalindrome_Manacher(s) << endl;
    return 0;
}

// Example 1:
// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.

// Example 2:
// Input: s = "cbbd"
// Output: "bb"

// Standard Approach
// Time Complexity: O(n^2)
// Space Complexity: O(1)

// Manacher's Algorithm
// Time Complexity: O(n)
// Space Complexity: O(n)