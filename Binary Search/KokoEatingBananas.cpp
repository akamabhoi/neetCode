class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int minSpeed = 1;                                        // Minimum possible eating speed
        int maxSpeed = *max_element(piles.begin(), piles.end()); // Maximum possible eating speed
        int result = maxSpeed;                                   // Initialize result to maximum eating speed

        while (minSpeed <= maxSpeed)
        {
            int midSpeed = minSpeed + (maxSpeed - minSpeed) / 2; // Calculate mid eating speed
            double totalHours = 0;
            for (int pile : piles)
            {
                totalHours += ceil((double)(pile) / midSpeed); // Calculate hours required to eat all piles
            }

            if (totalHours <= h)
            {
                result = min(result, midSpeed); // Update minimum eating speed
                maxSpeed = midSpeed - 1;        // Adjust maxSpeed pointer
            }
            else
            {
                minSpeed = midSpeed + 1; // Adjust minSpeed pointer
            }
        }

        return result; // Return minimum eating speed
    }
};
