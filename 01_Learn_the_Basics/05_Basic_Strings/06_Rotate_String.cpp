#include <bits/stdc++.h>
using namespace std;

bool isRotated(string str1, string str2)
{
    if (str1.size() != str2.size())
        return false;
    string temp = str1 + str1;
    return temp.find(str2) != string::npos;
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    cout << isRotated(str1, str2) << endl;

    return 0;
}

// Example 1:
// Input: s = "abc", t = "bca"
// Output: true
// Explanation: "abc" can be rotated to "bca".

// Example 2:
// Input: s = "abc", t = "bad"
// Output: false
// Explanation: "abc" cannot be rotated to "bad".

// Time Complexity: O(n)
// Space Complexity: O(1)
