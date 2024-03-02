class Solution
{
public:
    // This function checks whether the given string contains valid parentheses, square brackets, and curly braces.
    bool isValid(string s)
    {
        // Initialize a stack to store opening brackets.
        stack<char> st;
        // Iterate through each character in the string.
        for (char c : s)
        {
            // If the character is an opening bracket, push it onto the stack.
            if (c == '(' || c == '[' || c == '{')
            {
                st.push(c);
            }
            // If the character is a closing bracket.
            else
            {
                // If the stack is empty, there's no matching opening bracket for this closing bracket, return false.
                if (st.empty())
                    return false;
                // Otherwise, retrieve the top of the stack.
                char top = st.top();
                // If the current closing bracket does not match the corresponding opening bracket at the top of the stack, return false.
                if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{'))
                {
                    return false;
                }
                // If the brackets match, pop the opening bracket from the stack.
                st.pop();
            }
        }
        // After iterating through the entire string, if the stack is empty, all brackets are matched, return true; otherwise, return false.
        return st.empty();
    }
};
