class Solution
{
public:
    // Function to check if two trees are identical
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        // If both nodes are null, they are equal
        if (!p and !q)
            return true;
        // If only one of the nodes is null, they are not equal
        if (!p or !q)
            return false;
        // Check if current nodes are equal and recursively check left and right subtrees
        return p->val == q->val and isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
    }

    // Function to check if subRoot is a subtree of root
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        // If root is null, subRoot cannot be a subtree
        if (!root)
            return false;
        // If subRoot is identical to root, it's a subtree
        if (isSameTree(root, subRoot))
            return true;
        // Check recursively if subRoot is a subtree of left or right subtree of root
        return isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
    }
};
