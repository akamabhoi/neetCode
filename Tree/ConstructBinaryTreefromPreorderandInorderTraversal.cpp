class Solution
{
public:
    /**
     * Helper function to construct the binary tree from preorder and inorder traversals.
     * @param preorder: The preorder traversal of the tree.
     * @param inorder: The inorder traversal of the tree.
     * @param start: The start index of the current inorder subarray.
     * @param end: The end index of the current inorder subarray.
     * @param index: The current index in the preorder traversal.
     * @return: The root of the constructed subtree.
     */
    TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int start, int end, int &index)
    {
        // Base case: if the start index is greater than the end index, return null.
        if (start > end)
        {
            return nullptr;
        }

        // The current root value is the element at the current index in the preorder traversal.
        int rootVal = preorder[index];

        // Find the index of the root value in the inorder traversal.
        int i = start;
        for (; i <= end; ++i)
        {
            if (inorder[i] == rootVal)
            {
                break;
            }
        }

        // Increment the preorder index to point to the next root value.
        ++index;

        // Create the root node with the current root value.
        TreeNode *root = new TreeNode(rootVal);

        // Recursively construct the left subtree.
        root->left = helper(preorder, inorder, start, i - 1, index);

        // Recursively construct the right subtree.
        root->right = helper(preorder, inorder, i + 1, end, index);

        return root;
    }

    /**
     * Main function to construct the binary tree from preorder and inorder traversals.
     * @param preorder: The preorder traversal of the tree.
     * @param inorder: The inorder traversal of the tree.
     * @return: The root of the constructed binary tree.
     */
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = preorder.size(); // Get the size of the preorder traversal.
        int index = 0;           // Initialize the index to 0 for preorder traversal.

        // Call the helper function with the full range of inorder traversal.
        return helper(preorder, inorder, 0, n - 1, index);
    }
};