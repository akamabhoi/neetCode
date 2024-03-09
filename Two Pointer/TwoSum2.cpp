// Class Solution to implement the twoSum function
class Solution
{
public:
    // Function to find two numbers in the vector that sum up to the target
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        // Initialize a vector to store the result
        vector<int> ans;
        // Initialize left pointer at the beginning of the vector
        int left = 0;
        // Get the size of the numbers vector
        int n = numbers.size();
        // Initialize right pointer at the end of the vector
        int right = n - 1;

        // Two-pointer approach to find the pair summing up to the target
        while (left < right)
        {
            // Calculate the sum of the elements at left and right pointers
            int sum = numbers[left] + numbers[right];
            // If the sum equals the target, add the indices of the two numbers to the result vector and exit the loop
            if (sum == target)
            {
                ans.push_back(left + 1);
                ans.push_back(right + 1);
                break;
            }
            // If the sum is greater than the target, move the right pointer to the left
            else if (sum > target)
            {
                right--;
            }
            // If the sum is less than the target, move the left pointer to the right
            else
            {
                left++;
            }
        }

        // Return the result vector
        return ans;
    }
};
