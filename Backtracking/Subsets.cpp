class Solution
{
public:
    /**
     * Helper function to generate all subsets.
     * @param nums: The input vector of numbers.
     * @param set: The 2D vector to store all subsets.
     * @param subSet: The current subset being constructed.
     * @param index: The current index in the nums vector.
     */
    void helper(vector<int> &nums, vector<vector<int>> &set, vector<int> &subSet, int index)
    {
        // Base case: If index reaches the size of nums, add the current subset to the set.
        if (index == nums.size())
        {
            set.push_back(subSet); // Add the current subset to the set of all subsets.
            return;
        }

        // Include the current element in the subset.
        subSet.push_back(nums[index]);        // Add the current element to the subset.
        helper(nums, set, subSet, index + 1); // Recurse to the next element.

        // Backtrack: Exclude the current element from the subset.
        subSet.pop_back();                    // Remove the last element added.
        helper(nums, set, subSet, index + 1); // Recurse to the next element without including the current one.
    }

    /**
     * Function to return all possible subsets of the given vector nums.
     * @param nums: The input vector of numbers.
     * @return: A 2D vector containing all subsets of nums.
     */
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> set;      // Initialize the 2D vector to store all subsets.
        vector<int> subSet;           // Initialize the current subset being constructed.
        helper(nums, set, subSet, 0); // Call the helper function to start generating subsets.
        return set;                   // Return the set of all subsets.
    }
};
