// Class Solution to implement the search function
class Solution
{
public:
    // Function to search for target in a sorted array using binary search
    int search(vector<int> &nums, int target)
    {
        // Get the size of the nums array
        int n = nums.size();
        // Initialize left and right pointers
        int left = 0;
        int right = n - 1;

        // Perform binary search
        while (left <= right)
        {
            // Calculate mid index
            int mid = left + (right - left) / 2;
            // If target is less than the value at mid, search the left half
            if (target < nums[mid])
            {
                right = mid - 1;
            }
            // If target is greater than the value at mid, search the right half
            else if (target > nums[mid])
            {
                left = mid + 1;
            }
            // If target is found, return its index
            else
            {
                return mid;
            }
        }
        // If target is not found, return -1
        return -1;
    }
};
