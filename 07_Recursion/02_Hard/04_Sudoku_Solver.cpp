#include <bits/stdc++.h>
using namespace std;

// Write a program to solve a Sudoku puzzle by filling the empty cells.
// A sudoku solution must satisfy all of the following rules:
// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.

void solveSudoku(vector<vector<char>> &board)
{
    bool row[9][10] = {};
    bool col[9][10] = {};
    bool box[9][10] = {};

    vector<pair<int, int>> empty;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {

            if (board[i][j] == '.')
            {
                empty.push_back({i, j});
            }
            else
            {
                int num = board[i][j] - '0';
                int b = (i / 3) * 3 + (j / 3);

                row[i][num] = true;
                col[j][num] = true;
                box[b][num] = true;
            }
        }
    }

    function<bool(int)> backtrack = [&](int index)
    {
        if (index == empty.size())
            return true;

        int r = empty[index].first;
        int c = empty[index].second;
        int b = (r / 3) * 3 + (c / 3);

        for (int num = 1; num <= 9; num++)
        {

            if (row[r][num] || col[c][num] || box[b][num])
                continue;

            board[r][c] = '0' + num;

            row[r][num] = true;
            col[c][num] = true;
            box[b][num] = true;

            if (backtrack(index + 1))
                return true;

            board[r][c] = '.';

            row[r][num] = false;
            col[c][num] = false;
            box[b][num] = false;
        }

        return false;
    };

    backtrack(0);
}

int main()
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    solveSudoku(board);

    for (auto &r : board)
    {
        for (char c : r)
        {
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;
}

// Example 1:
// Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
// Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
// Explanation: The input board is shown above and the only valid solution is shown below:

// Time Complexity: O(9^(n*n)) where n is the size of the board (9 in this case). In the worst case, we may have to fill all empty cells, and for each cell, we have 9 choices (digits 1-9).
// Space Complexity: O(n*n) for the recursion stack and the additional data structures used to keep track of the filled numbers in rows, columns, and boxes.