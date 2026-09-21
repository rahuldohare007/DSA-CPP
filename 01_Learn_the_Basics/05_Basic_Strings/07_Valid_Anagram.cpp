#include <bits/stdc++.h>
using namespace std;

bool anagramStrings(string &s, string &t)
{
    if (s.size() != t.size())
        return false;

    vector<int> cnt(26, 0);

    for (int i = 0; i < s.size(); i++)
    {
        cnt[s[i] - 'a']++;
        cnt[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] != 0)
            return false;
    }

    return true;
}

int main()
{

    string s, t;
    cin >> s >> t;
    cout << anagramStrings(s, t) << endl;

    return 0;
}

// Example 1:
// Input: s = "anagram", t = "nagaram"
// Output: true
// Explanation: "anagram" and "nagaram" are anagrams.

// Example 2:
// Input: s = "rat", t = "car"
// Output: false
// Explanation: "rat" and "car" are not anagrams.

// Time Complexity: O(n)
// Space Complexity: O(1)