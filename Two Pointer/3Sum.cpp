class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int n = nums.size();

        // Sort the array to use the two-pointer technique
        sort(nums.begin(), nums.end());

        // Outer loop to fix the first element
        for (int i = 0; i < n - 2; i++)
        {
            // Skip duplicate elements
            if (i > 0 and nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = n - 1;

            // Two-pointer technique
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0)
                {
                    ans.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicates for left pointer
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    // Skip duplicates for right pointer
                    while (left < right && nums[right] == nums[right - 1])
                        right--;

                    // Move both pointers inward
                    left++;
                    right--;
                }
                else if (sum < 0)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }

        return ans;
    }
};