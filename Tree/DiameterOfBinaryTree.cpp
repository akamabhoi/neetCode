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
    // Recursive function to calculate the diameter of the binary tree
    int solve(TreeNode *node, int &result)
    {
        // Base case: If the current node is null, return 0
        if (!node)
            return 0;

        // Recursively calculate the height of the left subtree
        int left = solve(node->left, result);

        // Recursively calculate the height of the right subtree
        int right = solve(node->right, result);

        // Update the result with the maximum diameter found so far
        result = max(result, left + right);

        // Return the maximum height of the left and right subtrees, plus 1 for the current node
        return max(left, right) + 1;
    }

    // Function to calculate the diameter of the binary tree
    int diameterOfBinaryTree(TreeNode *root)
    {
        // Initialize the result to the minimum integer value
        int result = INT_MIN;

        // Call the solve function to calculate the diameter of the binary tree
        solve(root, result);

        // Return the result
        return result;
    }
};
