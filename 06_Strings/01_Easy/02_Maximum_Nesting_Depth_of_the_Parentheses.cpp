#include <bits/stdc++.h>
using namespace std;

// Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.

int maxDepth(string s)
{
    int maxDepth = 0;
    int currentDepth = 0;
    for (char c : s)
    {
        if (c == '(')
        {
            currentDepth++;
            maxDepth = max(maxDepth, currentDepth);
        }
        else if (c == ')')
        {
            currentDepth--;
        }
    }
    return maxDepth;
}

int main()
{
    string s = "(1+(2*3)+((8)/4))+1";
    cout << maxDepth(s) << endl;
    
    return 0;
}

// Example 1:
// Input: s = "(1+(2*3)+((8)/4))+1"
// Output: 3
// Explanation: Digit 8 is inside of 3 nested parentheses in the string.

// Example 2:
// Input: s = "(1)+((2))+(((3)))"
// Output: 3
// Explanation: Digit 3 is inside of 3 nested parentheses in the string.

// Example 3:
// Input: s = "()(())((()()))"
// Output: 3

// Time Complexity: O(n), where n is the length of the string s. We traverse the string once to calculate the maximum depth of nested parentheses.
// Space Complexity: O(1), as we are using a constant amount of space to store the maximum depth and current depth variables.