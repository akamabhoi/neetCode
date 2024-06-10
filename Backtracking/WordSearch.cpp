class Solution
{
public:
    // Helper function to perform DFS on the board to find the word
    bool helper(vector<vector<char>> &board, string word, int m, int n, int i, int j, int k)
    {
        // If k reaches the length of the word, it means the word has been found
        if (k == word.size())
            return true;

        // If the current position is out of bounds or the character does not match, return false
        if (i < 0 || i == m || j < 0 || j == n || board[i][j] != word[k])
            return false;

        // Mark the current cell as visited by replacing its character with '$'
        board[i][j] = '$';

        // Explore the four possible directions: down, up, right, left
        bool op1 = helper(board, word, m, n, i + 1, j, k + 1); // Move down
        bool op2 = helper(board, word, m, n, i - 1, j, k + 1); // Move up
        bool op3 = helper(board, word, m, n, i, j + 1, k + 1); // Move right
        bool op4 = helper(board, word, m, n, i, j - 1, k + 1); // Move left

        // Restore the current cell's character after exploring all directions
        board[i][j] = word[k];

        // Return true if any of the four explorations find the word
        return op1 || op2 || op3 || op4;
    }

    // Main function to check if the word exists in the board
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();    // Number of rows
        int n = board[0].size(); // Number of columns

        // Iterate through each cell in the board
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // If the word starts from the current cell, return true
                if (helper(board, word, m, n, i, j, 0))
                {
                    return true;
                }
            }
        }
        // If no starting point leads to the word, return false
        return false;
    }
};
