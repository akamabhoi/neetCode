class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int ans = nums[0];                     // Initialize ans to the first element of nums
        int left = 0, right = nums.size() - 1; // Initialize left and right pointers

        // Perform binary search to find the minimum element
        while (left <= right)
        {
            // If the array is already sorted in ascending order, return the first element
            if (nums[left] < nums[right])
            {
                ans = min(ans, nums[left]); // Update ans with the minimum of current ans and nums[left]
                break;                      // Exit the loop
            }

            int mid = left + (right - left) / 2; // Calculate mid index

            ans = min(ans, nums[mid]); // Update ans with the minimum of current ans and nums[mid]

            // Adjust the pointers based on the comparison between nums[left] and nums[mid]
            if (nums[left] <= nums[mid])
            {
                left = mid + 1; // Move left pointer to the right
            }
            else
            {
                right = mid - 1; // Move right pointer to the left
            }
        }

        return ans; // Return the minimum element
    }
};
