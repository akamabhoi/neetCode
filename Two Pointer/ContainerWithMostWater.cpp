// Class Solution to implement the maxArea function
class Solution
{
public:
    // Function to find the maximum area of water that can be contained between vertical lines
    int maxArea(vector<int> &height)
    {
        // Initialize variables for the maximum area, size of the height array, and pointers for left and right ends
        int ans = 0;
        int n = height.size();
        int left = 0;
        int right = n - 1;

        // Iterate until left pointer is less than right pointer
        while (left < right)
        {
            // Calculate the area between the vertical lines at left and right positions
            int area = (right - left) * min(height[left], height[right]);
            // Update the maximum area
            ans = max(ans, area);
            // Move the pointer pointing to the shorter vertical line towards the other end
            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        // Return the maximum area
        return ans;
    }
};

/*
Idea
    The widest container (using first and last line) is a good candidate, because of its width.
    Its water level is the height of the smaller one of first and last line. All other containers
    are less wide and thus would need a higher water level in order to hold more water. The smaller
    one of first and last line doesn't support a higher water level and can thus be safely removed from further consideration.
*/
