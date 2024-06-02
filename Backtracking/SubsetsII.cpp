class Solution
{
public:
    // Helper function to generate all subsets
    void helper(vector<vector<int>> &Set, vector<int> &subSet, vector<int> &nums, int i)
    {
        // Base case: if we've considered all elements
        if (i == nums.size())
        {
            // Add the current subset to the set of all subsets
            Set.push_back(subSet);
            return;
        }

        // Include nums[i] in the current subset
        subSet.push_back(nums[i]);
        // Recur with the element included
        helper(Set, subSet, nums, i + 1);
        // Backtrack: remove the last element to consider the next possibility
        subSet.pop_back();

        // Exclude nums[i] from the current subset and recur
        helper(Set, subSet, nums, i + 1);
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> Set; // This will store all the subsets
        vector<int> subSet;      // Temporary vector to store each subset

        // Sort nums to handle duplicates by ensuring duplicates are adjacent
        sort(nums.begin(), nums.end());

        // Generate all subsets
        helper(Set, subSet, nums, 0);

        // Use a set to eliminate duplicates from the list of subsets
        set<vector<int>> uniqueSet(Set.begin(), Set.end());

        // Convert the set of unique subsets back to a vector
        vector<vector<int>> ans(uniqueSet.begin(), uniqueSet.end());

        // Return the final list of unique subsets
        return ans;
    }
};
