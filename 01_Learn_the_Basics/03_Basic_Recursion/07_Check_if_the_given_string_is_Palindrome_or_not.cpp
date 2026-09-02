#include <bits/stdc++.h>
using namespace std;

// Iterative Approach
bool isPalindrome_Iterative(string str)
{
    int start = 0;
    int end = str.length() - 1;

    while (start < end)
    {
        if (str[start] != str[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

// Recursive Approach
bool isPalindrome_Recursive(string str, int start, int end)
{
    if (start >= end)
    {
        return true;
    }
    if (str[start] != str[end])
    {
        return false;
    }
    return isPalindrome_Recursive(str, start + 1, end - 1);
}

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    isPalindrome_Iterative(str) ? cout << "The given string is a palindrome." << endl : cout << "The given string is not a palindrome." << endl;
    isPalindrome_Recursive(str, 0, str.length() - 1) ? cout << "The given string is a palindrome." << endl : cout << "The given string is not a palindrome." << endl;

    return 0;
}

// Iterative Approach
// Time Complexity: O(n)
// Space Complexity: O(1)

// Recursive Approach
// Time Complexity: O(n)
// Space Complexity: O(n) (due to recursion stack)