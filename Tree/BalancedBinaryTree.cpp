/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution
{
public:
    // Function to calculate the height of the tree rooted at the current node
    int dfsHeight(TreeNode *root)
    {
        // Base case: If the node is null, return 0
        if (!root)
            return 0;

        // Recursively calculate the height of the left subtree
        int leftHeight = dfsHeight(root->left);

        // If the left subtree is unbalanced, propagate the unbalance upward
        if (leftHeight == -1)
            return -1;

        // Recursively calculate the height of the right subtree
        int rightHeight = dfsHeight(root->right);

        // If the right subtree is unbalanced, propagate the unbalance upward
        if (rightHeight == -1)
            return -1;

        // If the absolute difference in heights of left and right subtrees is greater than 1,
        // the current subtree is unbalanced, so return -1 to propagate the unbalance upward
        if (abs(leftHeight - rightHeight) > 1)
            return -1;

        // Return the maximum height of the left and right subtrees, plus 1 for the current node
        return max(leftHeight, rightHeight) + 1;
    }

    // Function to check if the given binary tree is balanced
    bool isBalanced(TreeNode *root)
    {
        // If the height of the tree rooted at the current node is -1, it is unbalanced
        if (dfsHeight(root) == -1)
            return false;

        // Otherwise, the tree is balanced
        return true;
    }
};
