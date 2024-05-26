class Solution
{
public:
    // Helper function to generate permutations using recursion and backtracking
    void solve(int index, vector<int> &nums, vector<vector<int>> &ans)
    {
        // Base case: if we have considered all elements
        if (index == nums.size())
        {
            ans.push_back(nums); // Add the current permutation to the result
            return;
        }

        // Iterate through the array to generate all permutations starting with index
        for (int i = index; i < nums.size(); i++)
        {
            swap(nums[index], nums[i]);  // Swap the current element with the element at index
            solve(index + 1, nums, ans); // Recur for the next index
            swap(nums[index], nums[i]);  // Backtrack: undo the swap to restore the original order
        }
    }

    // Main function to initiate the generation of permutations
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans; // This will store all the permutations
        solve(0, nums, ans);     // Start the recursive permutation generation from index 0
        return ans;              // Return the result containing all permutations
    }
};
