// Class Solution to implement the trap function
class Solution
{
public:
    // Function to calculate the amount of water that can be trapped between the bars
    int trap(vector<int> &height)
    {
        // Get the size of the height array
        int n = height.size();
        // Initialize vectors to store left and right maximum heights
        vector<int> leftMax(n);
        vector<int> rightMax(n);

        // Calculate left maximum heights
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++)
        {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        // Calculate right maximum heights
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        // Calculate trapped water by subtracting current height from minimum of left and right maximum heights
        int trapWater = 0;
        for (int i = 1; i < n - 1; i++)
        {
            trapWater += (min(leftMax[i], rightMax[i]) - height[i]);
        }

        // Return the total trapped water
        return trapWater;
    }
};
