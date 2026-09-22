#include <bits/stdc++.h>
using namespace std;

// Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
vector<int> generateZeroIndexed(int rowIndex)
{
    vector<int> ans(rowIndex + 1);
    long long temp = 1;
    ans[0] = ans[rowIndex] = 1;
    for (int i = 1, up = rowIndex, down = 1; i <= rowIndex; i++, up--, down++)
    {
        temp = temp * up / down;
        ans[i] = temp;
    }
    return ans;
}

// Given an integer rowIndex, return all the values in the rowIndexth (1-indexed) row of the Pascal's triangle.
vector<int> generateOneIndexed(int rowIndex)
{
    vector<int> ans(rowIndex);
    long long temp = 1;
    ans[0] = 1;

    for (int i = 1; i < rowIndex; i++)
    {
        temp = temp * (rowIndex - i) / i;
        ans[i] = temp;
    }

    return ans;
}

// Example:

int main()
{
    int rowIndex = 5;
    vector<int> ans = generateZeroIndexed(rowIndex);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    ans = generateOneIndexed(rowIndex);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}

// Example for 0-indexed:
// Example 1:
// Input: numRows = 5
// Output: [1,5,10,10,5,1]

// Example 2:
// Input: numRows = 4
// Output: [1,4,6,4,1]

// ------------------------------------------------

// Example for 1-indexed:
// Example 1:
// Input: rowIndex = 4
// Output: [1,3,3,1]

// Example 2:
// Input: numRows = 5
// Output: [1,4,6,4,1]

// ------------------------------------------------

// Time Complexity for both cases: O(n)
// Space Complexity: O(n)