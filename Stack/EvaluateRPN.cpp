class Solution
{
public:
    // Function to evaluate the RPN expression
    int evalRPN(vector<string> &tokens)
    {
        // Stack to store operands
        stack<int> st;

        // Iterate through each token in the expression
        for (auto ch : tokens)
        {
            // If the token is an operand (a number), convert it to an integer and push onto the stack
            if (ch != "+" && ch != "-" && ch != "*" && ch != "/")
            {
                st.push(std::stoi(ch));
            }
            // If the token is an operator, perform the corresponding arithmetic operation
            else
            {
                // Pop the top two elements from the stack
                int secondNumber = st.top();
                st.pop();
                int firstNumber = st.top();
                st.pop();
                int result;

                // Perform the arithmetic operation based on the operator
                if (ch == "+")
                    result = firstNumber + secondNumber;
                else if (ch == "-")
                    result = firstNumber - secondNumber;
                else if (ch == "*")
                    result = firstNumber * secondNumber;
                else if (ch == "/")
                    result = firstNumber / secondNumber;

                // Push the result back onto the stack
                st.push(result);
            }
        }
        // The result will be the only element left on the stack
        return st.top();
    }
};
