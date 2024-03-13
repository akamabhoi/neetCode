// Class Solution to implement the searchMatrix function
class Solution
{
public:
    // Function to search for target in a matrix
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        // Get the number of rows and columns in the matrix
        int row = matrix.size();
        int col = matrix[0].size();

        // Initialize pointers to the top-right corner of the matrix
        int i = 0;
        int j = col - 1;

        // Loop until the pointers stay within the matrix boundaries
        while (i < row && j >= 0)
        {
            // If target is less than the element at (i, j), move left
            if (target < matrix[i][j])
            {
                j--;
            }
            // If target is greater than the element at (i, j), move down
            else if (target > matrix[i][j])
            {
                i++;
            }
            // If target is found, return true
            else
            {
                return true;
            }
        }
        // If target is not found within the matrix, return false
        return false;
    }
};
