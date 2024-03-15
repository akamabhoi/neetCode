class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1; // Initialize left and right pointers

        // Perform binary search
        while (left <= right)
        {
            int mid = left + (right - left) / 2; // Calculate mid index

            // Check if the target is found
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] >= nums[left])
            { // Check if left half is sorted
                // Check if the target lies within the sorted half
                if (target >= nums[left] && target < nums[mid])
                {
                    right = mid - 1; // Adjust right pointer
                }
                else
                {
                    left = mid + 1; // Adjust left pointer
                }
            }
            else
            { // Right half is sorted
                // Check if the target lies within the sorted half
                if (target > nums[mid] && target <= nums[right])
                {
                    left = mid + 1; // Adjust left pointer
                }
                else
                {
                    right = mid - 1; // Adjust right pointer
                }
            }
        }

        return -1; // Return -1 if target is not found
    }
};
