#include <bits/stdc++.h>
using namespace std;

// Given an m x n grid of characters board and a string word, return true if word exists in the grid.
// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

bool exist(vector<vector<char>> &board, string word){
    int m = board.size();
    int n = board[0].size();

    function<bool(int, int, int)> dfs = [&](int i, int j, int index) {
        if (index == word.size()) return true;
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[index]) return false;

        char temp = board[i][j];
        board[i][j] = '#';

        bool found = dfs(i + 1, j, index + 1) ||
                     dfs(i - 1, j, index + 1) ||
                     dfs(i, j + 1, index + 1) ||
                     dfs(i, j - 1, index + 1);

        board[i][j] = temp;
        return found;
    };

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (dfs(i, j, 0)) return true;
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                  {'S', 'F', 'C', 'S'},
                                  {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";

    cout << exist(board, word) << endl;

    return 0;
}

// Example 1:
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output: true

// Example 2:
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
// Output: true

// Example 3:
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
// Output: false

// Time Complexity: O(m * n * 4^L), where m is the number of rows, n is the number of columns, and L is the length of the word. In the worst case, we may explore all 4 directions for each cell in the grid for each character in the word.
// Space Complexity: O(L), where L is the length of the word. The space complexity is due to the recursion stack used in the depth-first search (DFS) algorithm. In the worst case, the recursion stack can go as deep as the length of the word.