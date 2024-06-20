class Solution
{
public:
    // Depth-First Search (DFS) function to explore the island
    void dfs(vector<vector<char>> &grid, int i, int j, int m, int n)
    {
        // If the current cell is out of bounds or is water ('0'), return
        if (i == m || j == n || i < 0 || j < 0 || grid[i][j] == '0')
            return;

        // Mark the current cell as visited by setting it to '0' (water)
        grid[i][j] = '0';

        // Explore all four possible directions (right, left, up, down)
        dfs(grid, i, j + 1, m, n); // move right
        dfs(grid, i, j - 1, m, n); // move left
        dfs(grid, i - 1, j, m, n); // move up
        dfs(grid, i + 1, j, m, n); // move down
    }

    // Function to count the number of islands
    int numIslands(vector<vector<char>> &grid)
    {
        // Get the number of rows (m) and columns (n) in the grid
        int m = grid.size();
        int n = grid[0].size();

        // Initialize the island count to 0
        int count = 0;

        // Iterate through each cell in the grid
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // If the current cell is land ('1'), it is part of an island
                if (grid[i][j] == '1')
                {
                    count++;               // Increment the island count
                    dfs(grid, i, j, m, n); // Perform DFS to mark the entire island
                }
            }
        }

        // Return the total number of islands
        return count;
    }
};
