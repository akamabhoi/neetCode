class Solution
{
public:
    /**
     * Helper function to perform DFS traversal of the BST.
     * @param root: The root of the current subtree.
     * @param k: The number of smallest elements to track.
     * @param q: The max-heap (priority queue) to store the smallest k elements.
     */
    void dfs(TreeNode *root, int k, priority_queue<int> &q)
    {
        if (!root)
            return; // Base case: if the node is null, return.

        // Push the current node's value into the max-heap.
        q.push(root->val);

        // If the size of the max-heap exceeds k, pop the largest element.
        if (q.size() > k)
        {
            q.pop();
        }

        // Recursively traverse the left and right subtrees.
        dfs(root->left, k, q);
        dfs(root->right, k, q);
    }

    /**
     * Main function to find the k-th smallest element in the BST.
     * @param root: The root of the BST.
     * @param k: The k-th smallest element to find.
     * @return: The k-th smallest element in the BST.
     */
    int kthSmallest(TreeNode *root, int k)
    {
        // Initialize a max-heap (priority queue) to store the smallest k elements.
        priority_queue<int> q;

        // Perform DFS traversal to populate the max-heap with the smallest k elements.
        dfs(root, k, q);

        // The top element of the max-heap is the k-th smallest element.
        return q.top();
    }
};