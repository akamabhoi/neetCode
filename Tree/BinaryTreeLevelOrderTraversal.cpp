class Solution
{
public:
    // Function to perform a level order traversal on a binary tree
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        // If the tree is empty (root is nullptr), return an empty vector
        if (!root)
            return {};

        // Vector to hold the final result of the level order traversal
        vector<vector<int>> ans;

        // Queue to hold the tree nodes for processing
        queue<TreeNode *> q;
        // Start with the root node
        q.push(root);

        // Process nodes until no nodes left in the queue
        while (!q.empty())
        {
            // Current level's width (number of elements at current level)
            int n = q.size();
            // Temporary vector to store the current level's values
            vector<int> temp;

            // Process each node of the current level
            while (n--)
            {
                // Get the front node from the queue
                TreeNode *x = q.front();
                q.pop();

                // If the node is not nullptr, process it
                if (x)
                {
                    // Add the node's value to the current level's list
                    temp.push_back(x->val);
                    // If the left child exists, add it to the queue for next level processing
                    if (x->left)
                        q.push(x->left);
                    // If the right child exists, add it to the queue for next level processing
                    if (x->right)
                        q.push(x->right);
                }
            }
            // Add the current level's values to the answer list
            ans.push_back(temp);
        }
        // Return the complete list of levels
        return ans;
    }
};