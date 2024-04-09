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
    // Function to invert the binary tree
    TreeNode *invertTree(TreeNode *root)
    {
        // Base case: If the current node is null, return null
        if (!root)
            return NULL;

        // Swap the left and right children of the current node
        swap(root->left, root->right);

        // Recursively invert the left subtree
        invertTree(root->left);

        // Recursively invert the right subtree
        invertTree(root->right);

        // Return the root of the inverted binary tree
        return root;
    }
};
