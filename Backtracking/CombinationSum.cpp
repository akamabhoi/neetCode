class Solution
{
public:
    // Helper function to find all combinations that sum up to the target
    void helper(vector<int> &candidates, int target, vector<vector<int>> &set, vector<int> &subSet, int i, int currSum)
    {
        // If current sum exceeds the target, terminate this path
        if (currSum > target)
        {
            return;
        }

        // If we have considered all candidates
        if (i == candidates.size())
        {
            // If the current sum is equal to the target, add the subset to the result set
            if (currSum == target)
            {
                set.push_back(subSet);
            }
            return; // Return as we can't consider more elements
        }

        // Include candidates[i] in the current subset
        currSum += candidates[i];
        subSet.push_back(candidates[i]);

        // Recur with the current element included (allowing multiple uses of the same element)
        helper(candidates, target, set, subSet, i, currSum);

        // Backtrack: Remove the last added element and reduce the current sum
        currSum -= candidates[i];
        subSet.pop_back();

        // Recur without including the current element (move to the next element)
        helper(candidates, target, set, subSet, i + 1, currSum);
    }

    // Main function to initiate the combination sum search
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> set; // This will store all the valid subsets
        vector<int> subSet;      // Temporary subset to store the current combination

        // Start the helper function with initial parameters
        helper(candidates, target, set, subSet, 0, 0);

        // Return the set of all valid combinations
        return set;
    }
};
