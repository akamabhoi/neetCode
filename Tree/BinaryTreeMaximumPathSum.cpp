class Solution
{
public:
    /**
     * Helper function to calculate the maximum path sum.
     * @param root: The root of the current subtree.
     * @param M: A reference to the maximum path sum found so far.
     * @return: The maximum path sum including the current node as the highest node.
     */
    int helper(TreeNode *root, int &M)
    {
        // Base case: if the current node is null, return 0.
        if (!root)
            return 0;

        // Recursively calculate the maximum path sum for the left and right subtrees.
        // If the path sum is negative, consider it as 0 (do not include that subtree).
        int leftSum = max(0, helper(root->left, M));
        int rightSum = max(0, helper(root->right, M));

        // Update the maximum path sum found so far.
        // This includes the current node's value and the maximum path sums of the left and right subtrees.
        M = max(M, root->val + leftSum + rightSum);

        // Return the maximum path sum including the current node and one of its subtrees.
        return root->val + max(leftSum, rightSum);
    }

    /**
     * Function to find the maximum path sum in the binary tree.
     * @param root: The root of the binary tree.
     * @return: The maximum path sum.
     */
    int maxPathSum(TreeNode *root)
    {
        int M = INT_MIN; // Initialize the maximum path sum to the smallest possible value.
        helper(root, M); // Call the helper function to update the maximum path sum.
        return M;        // Return the maximum path sum found.
    }
};