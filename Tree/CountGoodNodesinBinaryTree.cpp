// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution
{
public:
    // Depth-first search to count the number of good nodes in the binary tree.
    int dfs(TreeNode *root, int M)
    {
        // If the root is null, return 0.
        if (!root)
            return 0;

        // Initialize the answer variable.
        int ans = 0;

        // If the value of the current node is greater than or equal to M, it's a good node.
        if (root->val >= M)
        {
            ans++;
            // Update the maximum value encountered so far.
            M = root->val;
        }

        // Recursively calculate the number of good nodes in the left subtree and right subtree.
        return ans + dfs(root->left, M) + dfs(root->right, M);
    }

    // Function to find the number of good nodes in the binary tree.
    int goodNodes(TreeNode *root)
    {
        // Start the DFS traversal with the minimum possible value as the maximum encountered value so far.
        return dfs(root, INT_MIN);
    }
};
