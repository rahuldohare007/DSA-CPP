#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string str)
{
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
    {
        if (str[i] != str[n - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string str;
    cin >> str;

    if (isPalindrome(str))
    {
        cout << "The given string is a palindrome." << endl;
    }
    else
    {
        cout << "The given string is not a palindrome." << endl;
    }

    return 0;
}
// Example 1:
// Input: str = "racecar"
// Output: The given string is a palindrome.

// Example 2:
// Input: str = "hello"
// Output: The given string is not a palindrome.

// Time Complexity: O(n)
// Space Complexity: O(1)