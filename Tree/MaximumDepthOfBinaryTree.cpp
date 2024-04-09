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
    // Function to find the maximum depth of a binary tree
    int maxDepth(TreeNode *root)
    {
        // Base case: If the current node is null, return 0
        if (!root)
            return 0;

        // Recursively calculate the maximum depth of the left subtree
        int left = maxDepth(root->left);

        // Recursively calculate the maximum depth of the right subtree
        int right = maxDepth(root->right);

        // Return the maximum depth of the subtree rooted at the current node
        return max(left, right) + 1;
    }
};
