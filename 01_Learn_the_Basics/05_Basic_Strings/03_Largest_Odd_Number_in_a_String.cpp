#include <bits/stdc++.h>
using namespace std;

string largestOddNumber(string num)
{
    int n = num.length();

    // Find rightmost odd digit
    int end = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        if ((num[i] - '0') % 2 != 0)
        {
            end = i;
            break;
        }
    }

    if (end == -1)
        return "";

    // Remove leading zeros
    int start = 0;
    while (start < end && num[start] == '0')
        start++;

    return num.substr(start, end - start + 1);
}

int main()
{
    string num;
    cin >> num;
    string result = largestOddNumber(num);
    cout << result << endl;

    return 0;
}

// Example Input: num = "5347"
// Example Output: "5347"

// Example: "0214638"
// Output: "21463"
// Explanation: The odd numbers formed by given string are -> 5,3,53,347,5347. The largest odd number is "5347".

// Time Complexity: O(n)
// Space Complexity: O(1)