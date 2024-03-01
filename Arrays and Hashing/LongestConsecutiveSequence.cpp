class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> uset; // Create an unordered set to store unique numbers
        int n = nums.size();     // Get the size of the input vector
        int longestStreak = 0;   // Initialize the longest streak to 0
        for (int i = 0; i < n; i++)
        { // Insert all elements of nums into the unordered set
            uset.insert(nums[i]);
        }
        for (int num : nums)
        { // Iterate through each element in nums
            if (uset.find(num - 1) == uset.end())
            {                            // Check if the current number forms the start of a consecutive sequence
                int currentNumber = num; // Initialize the current number
                int currentStreak = 1;   // Initialize the current streak to 1
                while (uset.find(currentNumber + 1) != uset.end())
                {                    // Continue counting consecutive numbers greater than the current number
                    currentNumber++; // Increment the current number
                    currentStreak++; // Increment the current streak
                }
                longestStreak = max(longestStreak, currentStreak); // Update the longest streak
            }
        }
        return longestStreak; // Return the length of the longest consecutive sequence
    }
};
