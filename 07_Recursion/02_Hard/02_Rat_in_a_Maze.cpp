#include <bits/stdc++.h>
using namespace std;

// Given a grid of dimensions n x n. A rat is placed at coordinates (0, 0) and wants to reach at coordinates (n-1, n-1).
// Find all possible paths that rat can take to travel from (0, 0) to (n-1, n-1). The directions in which rat can move are 'U' (up) , 'D' (down) , 'L' (left) , 'R' (right).
// The value 0 in grid denotes that the cell is blocked and rat cannot use that cell for travelling, whereas value 1 represents that rat can travel through the cell. If the cell (0, 0) has 0 value, then mouse cannot move to any other cell.
// Note :
// • In a path no cell can be visited more than once.
// • If there is no possible path then return empty vector.

vector<string> findPath(vector<vector<int>> &grid)
{
    int n = grid.size();

    vector<string> result;

    if (n == 0 || grid[0][0] == 0 || grid[n - 1][n - 1] == 0)
        return result;

    vector<vector<int>> visited(n, vector<int>(n, 0));

    string path = "";

    int dx[] = {1, 0, 0, -1};
    int dy[] = {0, -1, 1, 0};
    char dir[] = {'D', 'L', 'R', 'U'};

    function<void(int, int)> dfs = [&](int row, int col)
    {
        if (row == n - 1 && col == n - 1)
        {
            result.push_back(path);
            return;
        }

        visited[row][col] = 1;

        for (int k = 0; k < 4; k++)
        {
            int nr = row + dx[k];
            int nc = col + dy[k];

            if (nr >= 0 && nr < n &&
                nc >= 0 && nc < n &&
                grid[nr][nc] == 1 &&
                !visited[nr][nc])
            {

                path.push_back(dir[k]);

                dfs(nr, nc);

                path.pop_back();
            }
        }

        visited[row][col] = 0;
    };

    dfs(0, 0);

    return result;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<string> ans = findPath(grid);

    for (const string &p : ans)
    {
        cout << p << " ";
    }

    if (ans.empty())
        cout << "No path found";

    cout << endl;

    return 0;
}

// Example 1:
// Input : n = 4 , grid = [ [1, 0, 0, 0] , [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1] ]
// Output : [ "DDRDRR" , "DRDDRR" ]
// Explanation : The rat has two different path to reach (3, 3).
// The first path is (0, 0) => (1, 0) => (2, 0) => (2, 1) => (3, 1) => (3, 2) => (3, 3).
// The second path is (0,0) => (1,0) => (1,1) => (2,1) => (3,1) => (3,2) => (3,3).

// Example 2:
// Input : n = 2 , grid = [ [1, 0] , [1, 0] ]
// Output : [ ]
// Explanation : There is no path that rat can choose to travel from (0,0) to (1,1).

// Time Complexity: O(4^n)
// Space Complexity: O(n^2)