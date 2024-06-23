class Solution
{
public:
    // Depth-First Search (DFS) function to explore the island and calculate its area
    void dfs(vector<vector<int>> &grid, int i, int j, int m, int n, int &currArea)
    {
        // If the current cell is out of bounds or is water (0), return
        if (i < 0 || j < 0 || i == m || j == n || grid[i][j] == 0)
            return;

        // Mark the current cell as visited by setting it to 0 (water)
        grid[i][j] = 0;
        // Increment the current area count
        currArea = currArea + 1;

        // Explore all four possible directions (left, right, up, down)
        dfs(grid, i, j - 1, m, n, currArea); // move left
        dfs(grid, i, j + 1, m, n, currArea); // move right
        dfs(grid, i - 1, j, m, n, currArea); // move up
        dfs(grid, i + 1, j, m, n, currArea); // move down
    }

    // Function to find the maximum area of an island in the grid
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        // Get the number of rows (m) and columns (n) in the grid
        int m = grid.size();
        int n = grid[0].size();

        // Initialize the maximum area to 0
        int area = 0;

        // Iterate through each cell in the grid
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // If the current cell is land (1), it is part of an island
                if (grid[i][j] == 1)
                {
                    // Initialize the current area to 0
                    int currArea = 0;
                    // Perform DFS to calculate the area of the island
                    dfs(grid, i, j, m, n, currArea);
                    // Update the maximum area if the current island's area is larger
                    area = max(area, currArea);
                }
            }
        }

        // Return the maximum area of an island found
        return area;
    }
};
