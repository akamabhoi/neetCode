class Solution
{
public:
    // Depth-First Search (DFS) to mark connected 'O's from the border
    void dfs(vector<vector<char>> &board, int row, int col, int m, int n)
    {
        // Base case: if the current cell is out of bounds or already processed
        if (row < 0 || row == m || col < 0 || col == n || board[row][col] == 'X' || board[row][col] == '$')
        {
            return;
        }

        // Mark the current cell as processed
        board[row][col] = '$';

        // Explore all four possible directions
        dfs(board, row + 1, col, m, n); // Down
        dfs(board, row - 1, col, m, n); // Up
        dfs(board, row, col + 1, m, n); // Right
        dfs(board, row, col - 1, m, n); // Left
    }

    void solve(vector<vector<char>> &board)
    {
        int m = board.size();    // Number of rows
        int n = board[0].size(); // Number of columns

        // Process the first row
        for (int i = 0; i < n; i++)
        {
            if (board[0][i] == 'O')
            {

                dfs(board, 0, i, m, n); // Start DFS from border 'O'
            }
        }

        // Process the last row
        for (int i = 0; i < n; i++)
        {
            if (board[m - 1][i] == 'O')
            {
                dfs(board, m - 1, i, m, n); // Start DFS from border 'O'
            }
        }

        // Process the left column
        for (int i = 0; i < m; i++)
        {
            if (board[i][0] == 'O')
            {
                dfs(board, i, 0, m, n); // Start DFS from border 'O'
            }
        }

        // Process the right column
        for (int i = 0; i < m; i++)
        {
            if (board[i][n - 1] == 'O')
            {
                dfs(board, i, n - 1, m, n); // Start DFS from border 'O'
            }
        }

        // Flip the 'O's to 'X's and '$'s back to 'O's
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X'; // Surrounded regions
                }
                else if (board[i][j] == '$')
                {
                    board[i][j] = 'O'; // Regions connected to border
                }
            }
        }
    }
};