#include <bits/stdc++.h>
using namespace std;

// Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

vector<vector<string>> partition(string s)
{
    vector<vector<string>> result;
    vector<string> current;
    int n = s.size();

    vector<vector<bool>> dp(n, vector<bool>(n, false));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            dp[i][j] = (s[i] == s[j]) && (j - i <= 2 || dp[i + 1][j - 1]);
        }
    }

    function<void(int)> backtrack = [&](int start)
    {
        if (start == n)
        {
            result.push_back(current);
            return;
        }

        for (int end = start; end < n; end++)
        {
            if (dp[start][end])
            {
                current.push_back(s.substr(start, end - start + 1));
                backtrack(end + 1);
                current.pop_back();
            }
        }
    };

    backtrack(0);
    return result;
}

int main()
{
    string s;
    cin >> s;

    vector<vector<string>> ans = partition(s);

    for (const vector<string> &v : ans)
    {
        for (const string &s : v)
        {
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}

// Example 1:
// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]

// Example 2:
// Input: s = "a"
// Output: [["a"]]

// Time Complexity: O(n * 2^n), where n is the length of the input string s. The backtracking function explores all possible partitions, and for each partition, we check if the substring is a palindrome using the precomputed dp table.
// Space Complexity: O(n^2) for the dp table and O(n) for the recursion stack, where n is the length of the input string s.