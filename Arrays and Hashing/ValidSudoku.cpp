class Solution
{
public:
    // Function to check if placing 'num' in the 'row' doesn't break the rules
    bool checkRow(char num, int row, int col, const vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            if (col != i && num == board[row][i])
            { // Check all elements in the row except the current cell
                return false;
            }
        }
        return true;
    }

    // Function to check if placing 'num' in the 'col' doesn't break the rules
    bool checkCol(char num, int row, int col, const vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            if (row != i && num == board[i][col])
            { // Check all elements in the column except the current cell
                return false;
            }
        }
        return true;
    }

    // Function to check if placing 'num' in the 3x3 box doesn't break the rules
    bool checkBox(char num, int row, int col, const vector<vector<char>> &board)
    {
        int startRow = 3 * (row / 3);
        int startCol = 3 * (col / 3);
        for (int i = startRow; i < startRow + 3; i++)
        {
            for (int j = startCol; j < startCol + 3; j++)
            {
                if (i != row && j != col && num == board[i][j])
                { // Check all elements in the 3x3 box except the current cell
                    return false;
                }
            }
        }
        return true;
    }

    // Function to validate the entire Sudoku board
    bool isValidSudoku(const vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    if (!(checkRow(board[i][j], i, j, board) &&
                          checkCol(board[i][j], i, j, board) &&
                          checkBox(board[i][j], i, j, board)))
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
