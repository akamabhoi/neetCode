class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        // Get the number of rows (m) and columns (n) in the grid
        int m = grid.size();
        int n = grid[0].size();

        // Initialize a queue to store the coordinates of rotten oranges and the time they rot
        queue<pair<pair<int, int>, int>> q;

        // Loop through the grid to find initially rotten oranges
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // If the orange is rotten, push its coordinates and time (0) into the queue
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                }
            }
        }

        // Variable to keep track of the maximum time taken for oranges to rot
        int maxTime = 0;

        // Possible directions for adjacent cells (up, down, left, right)
        int directions[4][2] = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Perform BFS to rot all reachable fresh oranges
        while (!q.empty())
        {
            // Get the current cell's coordinates and time from the front of the queue
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();

            // Update the maximum time
            maxTime = max(maxTime, t);

            // Check all four possible directions
            for (auto dir : directions)
            {
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                // If the adjacent cell is within bounds and has a fresh orange, rot it
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[newRow][newCol] == 1)
                {
                    q.push({{newRow, newCol}, t + 1});
                    grid[newRow][newCol] = 2; // Mark the orange as rotten
                }
            }
        }

        // Check if there are any remaining fresh oranges
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    // If there's any fresh orange left, return -1
                    return -1;
                }
            }
        }

        // Return the maximum time taken for all oranges to rot
        return maxTime;
    }
};