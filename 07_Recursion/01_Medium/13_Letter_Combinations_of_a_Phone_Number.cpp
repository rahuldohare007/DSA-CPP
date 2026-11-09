#include <bits/stdc++.h>
using namespace std;

// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

vector<string> letterCombinations(string digits)
{
    if (digits.empty())
        return {};

    vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> result;
    string current;

    function<void(int)> backtrack = [&](int index)
    {
        if (index == digits.size())
        {
            result.push_back(current);
            return;
        }

        string letters = mapping[digits[index] - '0'];
        for (char ch : letters)
        {
            current.push_back(ch);
            backtrack(index + 1);
            current.pop_back();
        }
    };

    backtrack(0);
    return result;
}

int main()
{
    string digits;
    cin >> digits;

    vector<string> ans = letterCombinations(digits);

    for (const string &s : ans)
    {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}

// Example 1:
// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

// Example 2:
// Input: digits = "2"
// Output: ["a","b","c"]

// Time Complexity: O(3^N * 4^M), where N is the number of digits that map to 3 letters (2, 3, 4, 5, 6, 8) and M is the number of digits that map to 4 letters (7, 9). The total number of combinations is the product of the number of letters for each digit.
// Space Complexity: O(N), where N is the length of the input digits string. The space is used for the recursion stack and the current combination being built.