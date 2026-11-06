#include <bits/stdc++.h>
using namespace std;

// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> result;
    vector<string> board(n, string(n, '.'));

    vector<int> col(n, 0);
    vector<int> diagonal1(2 * n - 1, 0); 
    vector<int> diagonal2(2 * n - 1, 0); 

    function<void(int)> backtrack = [&](int row)
    {
        if (row == n)
        {
            result.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++)
        {

            if (col[c] || diagonal1[row - c + n - 1] ||
                diagonal2[row + c])
            {
                continue;
            }

            board[row][c] = 'Q';
            col[c] = 1;
            diagonal1[row - c + n - 1] = 1;
            diagonal2[row + c] = 1;

            backtrack(row + 1);

            board[row][c] = '.';
            col[c] = 0;
            diagonal1[row - c + n - 1] = 0;
            diagonal2[row + c] = 0;
        }
    };

    backtrack(0);
    return result;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<string>> result = solveNQueens(n);

    for (const auto& board : result) {
        for (const string& row : board) {
            cout << row << endl;
        }
        cout << endl;
    }

    cout << "Total Solutions: " << result.size() << endl;

    return 0;
}

// Example 1:
// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

// Example 2:
// Input: n = 1
// Output: [["Q"]]

// Time Complexity: O(N!) - The time complexity is O(N!) because we are trying to place queens in N rows, and for each row, we have N choices for columns. However, due to the constraints of the problem (no two queens can attack each other), the number of valid placements reduces significantly as we progress through the rows.
// Space Complexity: O(N^2) - The space complexity is O(N^2) because we are storing the board configuration in a 2D vector of size N x N. Additionally, we use extra space for the column and diagonal tracking vectors, which are of size O(N) and O(2N-1) respectively, but these are dominated by the board storage.