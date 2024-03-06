class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temp)
    {
        // Initialize a vector to store the result, initially filled with zeros.
        vector<int> ans(temp.size(), 0);
        // Create a stack to store the indices of temperatures.
        stack<int> st;
        // Iterate through the temperatures.
        for (int i = 0; i < temp.size(); i++)
        {
            // While the stack is not empty and the current temperature is greater than the temperature at the top of the stack:
            while (!st.empty() and temp[i] > temp[st.top()])
            {
                // Update the wait time for the temperature at the top of the stack.
                ans[st.top()] = i - st.top();
                // Pop the index from the stack.
                st.pop();
            }
            // Push the current index onto the stack.
            st.push(i);
        }
        // Return the result vector.
        return ans;
    }
};
