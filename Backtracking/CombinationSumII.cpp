class Solution
{
public:
    // Helper function to generate combinations
    void helper(vector<int> &candidates, vector<vector<int>> &Set, vector<int> &subSet, int target, int currSum, int start)
    {
        // If current sum exceeds target, stop further exploration
        if (currSum > target)
        {
            return;
        }

        // If current sum equals target, add the current combination to the result set
        if (currSum == target)
        {
            Set.push_back(subSet);
            return;
        }

        // Iterate over candidates starting from the current index
        for (int i = start; i < candidates.size(); i++)
        {
            // Skip duplicates
            if (i > start && candidates[i] == candidates[i - 1])
            {
                continue;
            }
            // Include the current candidate in the combination
            subSet.push_back(candidates[i]);
            // Recurse with the updated current sum and next starting index
            helper(candidates, Set, subSet, target, currSum + candidates[i], i + 1);
            // Backtrack: remove the last added candidate
            subSet.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> Set;                       // To store all valid combinations
        vector<int> subSet;                            // Temporary vector to store each combination
        sort(candidates.begin(), candidates.end());    // Sort to handle duplicates
        helper(candidates, Set, subSet, target, 0, 0); // Generate combinations
        return Set;                                    // Return the result
    }
};
