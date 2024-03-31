class Solution
{
public:
    // Function to find the duplicate number in the given array
    int findDuplicate(vector<int> &nums)
    {
        // Initialize two pointers slow and fast
        int slow = 0, fast = 0;

        // Move slow one step and fast two steps until they meet
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Reset slow to the beginning and move both pointers one step at a time until they meet
        slow = 0;
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        // Return the duplicate number
        return slow;
    }
};
