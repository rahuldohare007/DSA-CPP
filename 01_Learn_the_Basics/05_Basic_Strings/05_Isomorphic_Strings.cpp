#include <bits/stdc++.h>
using namespace std;

bool isomorphicString(string s, string t)
{
    if (s.length() != t.length())
        return false;
    unordered_map<char, char> mp;
    for (int i = 0; i < s.length(); i++)
    {
        if (mp.find(s[i]) == mp.end())
        {
            if (mp.find(t[i]) != mp.end())
                return false;
            mp[s[i]] = t[i];
        }
        else
        {
            if (mp[s[i]] != t[i])
                return false;
        }
    }
    return true;
}
int main()
{
    string s = "egg", t = "add";
    cout << isomorphicString(s, t) << endl;

    return 0;
}

// Example 1:
// Input: s = "egg", t = "add"
// Output: true
// Explanation: The 'e' in string s can be replaced with 'a' in string t.
// The 'g' in string s can be replaced with 'd' in string t.
// Hence all the characters can be replaced.

// Exapmle 2:
// Input: s = "apple", t = "bbnbm"
// Output: false
// Explanation: Strings are matched Index by index.
// At index 0: 'a' != 'b'
// At index 1: 'p' != 'n'
// At index 2: 'p' != 'b'
// At index 3: 'l' != 'm'
// At index 4: 'e' != 'b'
// Hence the strings are not isomorphic.

// Time Complexity: O(n)
// Space Complexity: O(n)