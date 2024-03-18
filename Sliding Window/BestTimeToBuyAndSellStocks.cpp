class Solution
{
public:
    // Function to find the maximum profit that can be achieved
    int maxProfit(vector<int> &prices)
    {
        int maxProfit = INT_MIN;  // Initialize maximum profit to a very small value
        int minTillNow = INT_MAX; // Initialize minimum price seen so far to a very large value

        // Iterate through each price
        for (auto price : prices)
        {
            minTillNow = min(minTillNow, price);            // Update minimum price seen so far
            maxProfit = max(maxProfit, price - minTillNow); // Update maximum profit
        }

        return maxProfit; // Return the maximum profit achieved
    }
};
