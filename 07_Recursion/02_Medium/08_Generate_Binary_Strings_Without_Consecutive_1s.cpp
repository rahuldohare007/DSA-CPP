#include <bits/stdc++.h>
using namespace std;

// Given an integer n, return all binary strings of length n that do not contain consecutive 1s. Return the result in lexicographically increasing order.
// A binary string is a string consisting only of characters '0' and '1'.

vector<string> generateBinaryStrings(int n){
    
    vector<string> result;
    string current = "";
    
    function<void(int, char)> backtrack = [&](int length, char lastChar) {
        if (length == n) {
            result.push_back(current);
            return;
        }
        
        current.push_back('0');
        backtrack(length + 1, '0');
        current.pop_back();
        
        if (lastChar != '1') {
            current.push_back('1');
            backtrack(length + 1, '1');
            current.pop_back();
        }
    };
    
    backtrack(0, '0');
    
    return result;
}

int main()
{
    vector<string> result = generateBinaryStrings(3);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}

// Example 1:
// Input: n = 3
// Output: ["000", "001", "010", "100", "101"]
// Explanation: All strings are of length 3 and do not contain consecutive 1s.

// Example 2:
// Input: n = 2
// Output: ["00", "01", "10"]

// Time Complexity: O(2^n) in the worst case, as we are generating all possible binary strings of length n.
// Space Complexity: O(2^n) in the worst case, as we are storing all possible binary strings in the result vector.