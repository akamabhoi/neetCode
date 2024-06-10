class Solution
{
public:
    // Class members to store the final answer and temporary partitions
    vector<vector<string>> ans; // Stores all possible palindrome partitions
    vector<string> temp;        // Stores the current partition

    // Function to check if a substring s[i:index] is a palindrome
    bool isPalindrome(string s, int i, int index)
    {
        int left = i;
        int right = index;

        // Check characters from both ends moving towards the center
        while (left < right)
        {
            if (s[left] != s[right])
            {
                return false; // Not a palindrome if characters don't match
            }
            left++;
            right--;
        }

        return true; // It is a palindrome if all characters match
    }

    // Recursive helper function to generate palindrome partitions
    void helper(string s, int index)
    {
        // If we have reached the end of the string, add the current partition to the answer
        if (index == s.size())
        {
            ans.push_back(temp);
            return;
        }

        // Try to partition the string at different positions
        for (int i = index; i < s.size(); i++)
        {
            // If the substring s[index:i] is a palindrome
            if (isPalindrome(s, index, i))
            {
                // Add the palindrome substring to the current partition
                temp.push_back(s.substr(index, i - index + 1));

                // Recur to find the next partition starting from i+1
                helper(s, i + 1);

                // Backtrack to explore other partitions by removing the last added substring
                temp.pop_back();
            }
        }
    }

    // Main function to generate all palindrome partitions of the string s
    vector<vector<string>> partition(string s)
    {
        // Start the helper function with the initial index 0
        helper(s, 0);

        // Return the final list of palindrome partitions
        return ans;
    }
};
