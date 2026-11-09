#include <bits/stdc++.h>
using namespace std;

// Given a string num that contains only digits and an integer target, return all possibilities to insert the binary operators '+', '-', and/or '*' between the digits of num so that the resultant expression evaluates to the target value.
// Note that operands in the returned expressions should not contain leading zeros.
// Note that a number can contain multiple digits.

vector<string> addOperators(string num, int target)
{
    vector<string> result;
    string path;
    int n = num.size();

    function<void(int, long long, long long)> backtrack =
        [&](int index, long long value, long long last)
    {
        if (index == n)
        {
            if (value == target)
                result.push_back(path);
            return;
        }

        long long current = 0;
        int len = path.size();

        for (int i = index; i < n; i++)
        {

            if (i > index && num[index] == '0')
                break;

            current = current * 10 + (num[i] - '0');
            string part = num.substr(index, i - index + 1);

            if (index == 0)
            {
                path += part;
                backtrack(i + 1, current, current);
                path.resize(len);
            }
            else
            {
                path += "+" + part;
                backtrack(i + 1, value + current, current);
                path.resize(len);

                path += "-" + part;
                backtrack(i + 1, value - current, -current);
                path.resize(len);

                path += "*" + part;
                backtrack(i + 1,
                          value - last + last * current,
                          last * current);
                path.resize(len);
            }
        }
    };

    backtrack(0, 0, 0);
    return result;
}

int main()
{
    int num, target;
    cin >> num >> target;

    vector<string> result = addOperators(num, target);

    for (const string &expr : result)
    {
        cout << expr << endl;
    }

    return 0;
}

// Example 1:
// Input: num = "123", target = 6
// Output: ["1*2*3","1+2+3"]
// Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.

// Example 2:
// Input: num = "232", target = 8
// Output: ["2*3+2","2+3*2"]
// Explanation: Both "2*3+2" and "2+3*2" evaluate to 8.

// Example 3:
// Input: num = "3456237490", target = 9191
// Output: []
// Explanation: There are no expressions that can be created from "3456237490" to evaluate to 9191.

// Time Complexity: O(4^n), where n is the length of the input string num. In the worst case, we can have 4 choices (adding '+', '-', '*', or no operator) for each digit in the string.
// Space Complexity: O(n), where n is the length of the input string num. The space complexity is due to the recursion stack and the path string used to build expressions.