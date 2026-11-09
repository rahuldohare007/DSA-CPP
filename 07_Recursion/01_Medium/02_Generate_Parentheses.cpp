#include <bits/stdc++.h>
using namespace std;

// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

vector<string> generateParenthesis(int n){
    vector<string> combinations;
    if(n < 0) return combinations;

    string current;
    function<void(int, int)> backtrack = [&](int open, int close){
        if(open == n && close == n){
            combinations.push_back(current);
            return;
        }

        if(open < n){
            current.push_back('(');
            backtrack(open + 1, close);
            current.pop_back();
        }

        if(close < open){
            current.push_back(')');
            backtrack(open, close + 1);
            current.pop_back();
        }
    };

    backtrack(0, 0);
    return combinations;
}

int main()
{
    int n;
    cout << "Enter the number of pairs: ";
    if(!(cin >> n)) return 1;

    vector<string> combinations = generateParenthesis(n);
    cout << "Well-formed combinations:" << endl;
    for(const string& combination : combinations){
        cout << combination << endl;
    }
    return 0;
}

// Example 1:
// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]

// Example 2:
// Input: n = 1
// Output: ["()"]

// Time Complexity: O(4^n / sqrt(n)) - The number of valid combinations is given by the nth Catalan number, which is approximately 4^n / (n * sqrt(n)). Each combination takes O(n) time to construct, leading to the overall time complexity.
// Space Complexity: O(n) - The space required to store the combinations is proportional to the depth of the recursion tree, which is at most n.