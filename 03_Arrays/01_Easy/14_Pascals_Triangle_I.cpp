#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans;
    ans.push_back(vector<int>{1});
    if (numRows == 1)
    {
        return ans;
    }
    ans.push_back(vector{1, 1});
    if (numRows == 2)
    {
        return ans;
    }
    for (int i = 2; i < numRows; i++)
    {
        vector<int> row(i + 1);
        row[0] = row[i] = 1;

        for (int p = 1; p < i; p++)
        {
            row[p] = ans[i - 1][p - 1] + ans[i - 1][p];
        }

        ans.push_back(row);
    }
    return ans;
}

int main()
{
    int numRows = 5;
    vector<vector<int>> ans = generate(numRows);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// Example 1:
// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

// Example 2:
// Input: numRows = 1
// Output: [[1]]

// Time Complexity: O(n^2)
// Space Complexity: O(n^2)