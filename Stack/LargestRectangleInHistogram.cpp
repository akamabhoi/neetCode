// Class Solution to implement the largestRectangleArea function
class Solution
{
public:
    // Function to calculate the largest rectangle area in a histogram
    int largestRectangleArea(vector<int> &heights)
    {
        // Get the size of the heights vector
        int n = heights.size();
        // Initialize a stack to maintain indices of bars
        stack<int> st;
        // Initialize arrays to store indices of the first smaller bar on the left and right of each bar
        vector<int> left(n), right(n);

        // Calculate left[] array
        for (int i = 0; i < n; i++)
        {
            // Find the index of the first bar on the left that is shorter than the current bar
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        // Clear the stack for the next calculation
        while (!st.empty())
            st.pop();

        // Calculate right[] array
        for (int i = n - 1; i >= 0; i--)
        {
            // Find the index of the first bar on the right that is shorter than the current bar
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Initialize variable to store the maximum area
        int maxArea = 0;
        // Iterate through all bars
        for (int i = 0; i < n; ++i)
        {
            // Calculate the width of the rectangle with the current bar as height
            int width = right[i] - left[i] - 1;
            // Update the maximum area if necessary
            maxArea = max(maxArea, heights[i] * width);
        }

        // Return the maximum area
        return maxArea;
    }
};
