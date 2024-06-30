class Solution
{
public:
    // Depth-First Search (DFS) to mark reachable cells
    void dfs(vector<vector<int>> &h, vector<vector<bool>> &vis, int i, int j)
    {
        int m = h.size();
        int n = h[0].size();

        vis[i][j] = true; // Mark the cell as visited

        // Move up
        if (i - 1 >= 0 && !vis[i - 1][j] && h[i - 1][j] >= h[i][j])
        {
            dfs(h, vis, i - 1, j);
        }

        // Move down
        if (i + 1 < m && !vis[i + 1][j] && h[i + 1][j] >= h[i][j])
        {
            dfs(h, vis, i + 1, j);
        }

        // Move left
        if (j - 1 >= 0 && !vis[i][j - 1] && h[i][j - 1] >= h[i][j])
        {
            dfs(h, vis, i, j - 1);
        }

        // Move right
        if (j + 1 < n && !vis[i][j + 1] && h[i][j + 1] >= h[i][j])
        {
            dfs(h, vis, i, j + 1);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        vector<vector<int>> ans;   // Resultant vector to store the coordinates
        int m = heights.size();    // Number of rows
        int n = heights[0].size(); // Number of columns

        // Vectors to keep track of cells reachable from Pacific and Atlantic oceans
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // Perform DFS for cells adjacent to the Pacific Ocean (left and top edges)
        for (int i = 0; i < m; ++i)
        {
            dfs(heights, pacific, i, 0);      // Left edge
            dfs(heights, atlantic, i, n - 1); // Right edge
        }

        for (int j = 0; j < n; ++j)
        {
            dfs(heights, pacific, 0, j);      // Top edge
            dfs(heights, atlantic, m - 1, j); // Bottom edge
        }

        // Collect cells that can reach both the Pacific and Atlantic oceans
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (pacific[i][j] && atlantic[i][j])
                {
                    ans.push_back({i, j});
                }
            }
        }

        return ans; // Return the result
    }
};

/*

The dfs function is a recursive function that marks cells as visited if they can flow to the respective ocean.
The function checks the four possible directions (up, down, left, right) and performs a recursive DFS if the adjacent cell is within bounds, has not been visited yet, and its height is greater than or equal to the current cell's height.

pacificAtlantic Function:

Initialization: Initialize two 2D boolean vectors, pacific and atlantic, to keep track of cells that can flow to the respective oceans.
DFS from Borders: Perform DFS starting from the borders connected to the Pacific Ocean (left and top edges) and the Atlantic Ocean (right and bottom edges). This will mark all cells that can flow to the respective oceans.
Result Compilation: Iterate through all cells in the matrix and collect the cells that can flow to both the Pacific and Atlantic oceans.
*/