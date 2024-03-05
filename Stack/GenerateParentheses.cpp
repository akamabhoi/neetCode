class Solution
{
public:
    // Global variable to store the generated parentheses combinations.
    vector<string> ans;

    // Recursive function to generate valid parentheses combinations.
    void solver(int open, int close, int n, string s)
    {
        // Base case: If the count of open and close parentheses reaches n, add the combination to the answer vector.
        if (open == close && open == n)
        {
            ans.push_back(s);
            return;
        }

        // Recursive calls to generate valid combinations.
        // We can add an open parenthesis '(' if the count of open parentheses is less than n.
        if (open < n)
            solver(open + 1, close, n, s + '(');

        // We can add a close parenthesis ')' if the count of close parentheses is less than the count of open parentheses.
        if (close < open)
            solver(open, close + 1, n, s + ')');
    }

    // Main function to generate parentheses combinations.
    vector<string> generateParenthesis(int n)
    {
        // Clear the answer vector.
        ans.clear();
        // Start the recursive process with 0 open and close parentheses and an empty string.
        solver(0, 0, n, "");
        // Return the generated combinations.
        return ans;
    }
};
