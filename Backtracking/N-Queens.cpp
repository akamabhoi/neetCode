// T.C : O(N!) - Read the reason above
// S.C : O(N) to store the result
class Solution
{
public:
    vector<vector<string>> result;
    bool isValid(vector<string> &board, int row, int col)
    {
        // look for up
        for (int i = row; i >= 0; i--)
        {
            if (board[i][col] == 'Q')
                return false;
        }

        // check left diagonal upwards
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q')
                return false;
        }

        // check right diagonal upwards
        for (int i = row, j = col; i >= 0 && j < board.size(); i--, j++)
        {
            if (board[i][j] == 'Q')
                return false;
        }

        /*
            Wait a second, Why didn't I check any squares downwards ???
            If you notice, every time I am calling dfs(board, row+1); i.e. after
            placing a Queen at a row, I move down. So, It's guaranteed I will
            not get any Queen downwards.
            Example :

            For n = 4

                    _   _    _  Q   (Put int the first row)
                    Q  _   _   _    (While putting here, I only need to see above of me because I have not populated any Q in downwards)
                    _   _   Q  _    (Same,  While putting here, I only need to see above of me because I have not populated any Q in downwards)

                    So, on

    */

        return true;
    }
    void solve(vector<string> &board, int row)
    {
        if (row == board.size())
        {
            result.push_back(board);
            return;
        }

        /*
            place one queen at every row and check before placing
            in every directions where there is risk if being attackes
            i.e. up, diagonally because we are placing queens from
            top row to bottom row, so we need to check if we put a queen
            vertically up in some row or diagonally upwards in some row
        */
        for (int i = 0; i < board.size(); i++)
        {
            if (isValid(board, row, i))
            {
                board[row][i] = 'Q';

                solve(board, row + 1);

                board[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        if (n == 0)
            return {};
        vector<string> board(n, string(n, '.'));
        // For, n = 3, board = {"...", "...", "..."} initially

        solve(board, 0);

        return result;
    }
};