TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    TreeNode *curr = root; // Start the search from the root node

    // Continue searching while there is a node to process
    while (curr)
    {
        // If both nodes p and q are smaller than the current node,
        // the LCA must be in the left subtree.
        if (p->val < curr->val && q->val < curr->val)
            curr = curr->left;
        // If both nodes p and q are greater than the current node,
        // the LCA must be in the right subtree.
        else if (p->val > curr->val && q->val > curr->val)
            curr = curr->right;
        // If the nodes are on different sides or one is the current node,
        // then the current node is the LCA.
        else
            return curr;
    }
    // Return the found LCA
    return curr;
}