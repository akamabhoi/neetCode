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
    // Function to check if two binary trees are the same
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        // Check if both nodes are nullptr, indicating equality
        if (p == nullptr && q == nullptr)
            return true;

        // Check if one of the nodes is nullptr, indicating inequality
        if (p == nullptr || q == nullptr)
            return false;

        // Check if the current node values are equal and recursively check left and right subtrees
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
