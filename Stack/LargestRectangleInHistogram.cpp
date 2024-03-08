// solution to find the largest rectangle area in a histogram.
class Solution
{
public:
    // Function to find the indices of previous smaller elements for each element in the given vector of heights.
    vector<int> previous_smaller(vector<int> &heights)
    {
        vector<int> ans;        // Vector to store the indices of previous smaller elements
        stack<int> st;          // Stack to maintain indices of elements
        int n = heights.size(); // Get the size of the heights vector

        // Iterate through each element in the heights vector
        for (int i = 0; i < n; i++)
        {
            // While the stack is not empty and the height of the current element is less than or equal to the height of the element at the top of the stack,
            // pop elements from the stack
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            // If the stack is empty, there is no previous smaller element; otherwise, the previous smaller element is the one at the top of the stack
            int ele = (st.empty()) ? -1 : st.top();
            // Add the index of the previous smaller element to the ans vector
            ans.push_back(ele);
            // Push the current index onto the stack
            st.push(i);
        }
        // Return the vector containing indices of previous smaller elements for each element in the heights vector
        return ans;
    }

    // Function to find the indices of next smaller elements for each element in the given vector of heights.
    vector<int> next_smaller(vector<int> &heights)
    {
        vector<int> ans;        // Vector to store the indices of next smaller elements
        stack<int> st;          // Stack to maintain indices of elements
        int n = heights.size(); // Get the size of the heights vector

        // Iterate through each element in the heights vector in reverse order
        for (int i = n - 1; i >= 0; i--)
        {
            // While the stack is not empty and the height of the current element is less than or equal to the height of the element at the top of the stack,
            // pop elements from the stack
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            // If the stack is empty, there is no next smaller element; otherwise, the next smaller element is the one at the top of the stack
            int ele = (st.empty()) ? n : st.top();
            // Add the index of the next smaller element to the ans vector
            ans.push_back(ele);
            // Push the current index onto the stack
            st.push(i);
        }
        // Reverse the ans vector to get the indices of next smaller elements in the correct order
        reverse(ans.begin(), ans.end());
        // Return the vector containing indices of next smaller elements for each element in the heights vector
        return ans;
    }

    // Function to find the largest rectangle area in the given histogram represented by the vector of heights.
    int largestRectangleArea(vector<int> &heights)
    {
        int res = 0; // Variable to store the maximum area found so far
        // Get vectors containing indices of previous smaller and next smaller elements for each element in the heights vector
        vector<int> ps = previous_smaller(heights);
        vector<int> ns = next_smaller(heights);
        // Iterate through each element in the heights vector
        for (int i = 0; i < heights.size(); i++)
        {
            // Calculate the area of the rectangle with the current element as the height,
            // using the indices of previous smaller and next smaller elements
            int curr = (ns[i] - ps[i] - 1) * heights[i];
            // Update the maximum area found so far
            res = max(res, curr);
        }
        // Return the maximum area found in the histogram
        return res;
    }
};
