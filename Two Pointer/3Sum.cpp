// Class Solution to implement the threeSum function
class Solution
{
public:
    // Function to find all unique triplets in the array that sum up to zero
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        // Sort the input array
        sort(nums.begin(), nums.end());
        // Initialize a vector to store the result triplets
        vector<vector<int>> ans;
        // Get the size of the input array
        int n = nums.size();

        // Iterate through the array
        for (int i = 0; i < n - 2; i++)
        {
            // Skip duplicates
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            // Initialize left pointer
            int left = i + 1;
            // Initialize right pointer
            int right = n - 1;
            // Calculate the target sum
            int target = -nums[i];

            // Use two-pointer technique to find pairs summing up to target
            while (left < right)
            {
                // Calculate the current sum
                int sum = nums[left] + nums[right];

                // If sum equals target, add the triplet to result and skip duplicates
                if (sum == target)
                {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    left++;
                    right--;
                }
                // If sum is less than target, move left pointer to the right
                else if (sum < target)
                {
                    left++;
                }
                // If sum is greater than target, move right pointer to the left
                else
                {
                    right--;
                }
            }
        }

        // Return the result vector
        return ans;
    }
};
