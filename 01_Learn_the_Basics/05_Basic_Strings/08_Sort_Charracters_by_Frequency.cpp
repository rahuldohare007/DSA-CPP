#include <bits/stdc++.h>
using namespace std;

vector<char> frequencySort(string s)
{
    vector<int> freq(256, 0);

    for (char ch : s)
        freq[ch]++;

    vector<char> result;

    for (int i = 0; i < 256; i++)
    {
        if (freq[i] > 0)
            result.push_back((char)i);
    }

    sort(result.begin(), result.end(), [&](char a, char b)
         {
            if (freq[a] != freq[b])
                return freq[a] > freq[b];

            return a < b; });

    return result;
}

int main()
{
    string s;
    cin >> s;
    vector<char> ans = frequencySort(s);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}

// Example 1:
// Input: s = "tree"
// Output: "eert"
// Explanation: 'e' appears twice while 'r' and 't' both appear once.

// Example 2:
// Input: s = "cccaaa"
// Output: "aaaccc"
// Explanation: Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
// Note that "cacaca" is incorrect, as the same characters must be together.

// Time Complexity: O(n)
// Space Complexity: O(1)