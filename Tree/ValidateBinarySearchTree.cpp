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
    /**
     * Helper function to validate the binary search tree.
     *
     * @param root The current node being checked.
     * @param left The minimum value that the current node's value must be greater than.
     * @param right The maximum value that the current node's value must be less than.
     * @return True if the subtree rooted at 'root' is a valid BST, false otherwise.
     */
    bool valid(TreeNode *root, long long left, long long right)
    {
        // If the node is null, it is a valid BST (base case)
        if (!root)
            return true;

        // If the current node's value does not satisfy the BST property, return false
        if (root->val >= right || root->val <= left)
        {
            return false;
        }

        // Recursively validate the left and right subtrees
        // For the left subtree, update the right bound to the current node's value
        // For the right subtree, update the left bound to the current node's value
        return valid(root->left, left, root->val) && valid(root->right, root->val, right);
    }

    /**
     * Main function to check if a binary tree is a valid BST.
     *
     * @param root The root node of the binary tree.
     * @return True if the binary tree is a valid BST, false otherwise.
     */
    bool isValidBST(TreeNode *root)
    {
        // Start the recursion with the entire range of valid values for a BST
        return valid(root, LLONG_MIN, LLONG_MAX);
    }
};
