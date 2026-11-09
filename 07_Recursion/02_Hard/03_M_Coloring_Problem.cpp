#include <bits/stdc++.h>
using namespace std;

// Given an integer M and an undirected graph with N vertices (zero indexed) and E edges. The goal is to determine whether the graph can be coloured with a maximum of M colors so that no two of its adjacent vertices have the same colour applied to them.
// In this context, colouring a graph refers to giving each vertex a different colour. If the colouring of vertices is possible then return true, otherwise return false.

bool graphColoring(vector<vector<int>> &edges, int m, int n)
{
    vector<vector<int>> adj(n);

    for (auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> color(n, 0);

    function<bool(int)> backtrack = [&](int node)
    {
        if (node == n)
            return true;

        for (int c = 1; c <= m; c++)
        {

            bool safe = true;

            for (int neighbor : adj[node])
            {
                if (color[neighbor] == c)
                {
                    safe = false;
                    break;
                }
            }

            if (safe)
            {
                color[node] = c;

                if (backtrack(node + 1))
                    return true;

                color[node] = 0;
            }
        }

        return false;
    };

    return backtrack(0);
}

int main()
{
    int n = 4, m = 3;

    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 0},
        {0, 2}};

    cout << (graphColoring(edges, m, n) ? "true" : "false");

    return 0;
}

// Example 1:
// Input : N = 4 , M = 3 , E = 5 , Edges = [ (0, 1) , (1, 2) , (2, 3) , (3, 0) , (0, 2) ]
// Output : true
// Explanation : Consider the three colors to be red, green, blue.
// We can color the vertex 0 with red, vertex 1 with blue, vertex 2 with green, vertex 3 with blue.
// In this way we can color graph using 3 colors at most.

// Example 2:
// Input : N = 3 , M = 2 , E = 3 , Edges = [ (0, 1) , (1, 2) , (0, 2) ]
// Output : false
// Explanation : Consider the two colors to be red, green.
// We can color the vertex 0 with red, vertex 1 with green.
// As the vertex 2 is adjacent to both vertex 1 and 0 , so we cannot color with red and green.
// Hence as we could not color all vertex of graph we return false.

// Time Complexity: O(M^N) where M is the number of colors and N is the number of vertices in the graph. In the worst case, we may have to try all possible colorings for each vertex.
// Space Complexity: O(N) for the color array and O(N) for the recursion stack, leading to a total space complexity of O(N).