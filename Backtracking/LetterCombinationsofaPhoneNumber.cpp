class Solution
{
public:
    // Initialize the phone map with digit-to-letters mapping
    unordered_map<char, string> phone = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}};

    // Vector to store the final results
    vector<string> ans;

    // Helper function to perform backtracking
    void helper(string digits, string temp, int i)
    {
        // Base case: if the current index equals the size of digits, a complete combination is formed
        if (i == digits.size())
        {
            ans.push_back(temp); // Add the current combination to the results
            return;
        }

        // Loop through the letters corresponding to the current digit
        for (char c : phone[digits[i]])
        {
            // Append the current letter and move to the next digit
            helper(digits, temp + c, i + 1);
        }
    }

    // Function to return all possible letter combinations for the input digits
    vector<string> letterCombinations(string digits)
    {
        ans.clear(); // Clear any previous results
        if (digits.empty())
            return ans;        // If the input is empty, return an empty result
        helper(digits, "", 0); // Start the backtracking process from the first digit
        return ans;            // Return the final results
    }
};