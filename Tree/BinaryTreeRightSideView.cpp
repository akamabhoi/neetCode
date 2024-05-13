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
    // Returns the values of the right side view of a binary tree.
    vector<int> rightSideView(TreeNode *root)
    {
        // If the root is null, return an empty vector.
        if (!root)
            return {};

        // Queue to perform level-order traversal.
        queue<TreeNode *> q;

        // Vector to store the values of the right side view.
        vector<int> ans;

        // Push the root node into the queue.
        q.push(root);

        // Perform level-order traversal.
        while (!q.empty())
        {
            // Get the number of nodes at the current level.
            int n = q.size();

            // Initialize a variable to store the value of the rightmost node at the current level.
            int rightMostValue = 0;

            // Process all nodes at the current level.
            while (n--)
            {
                // Get the front node from the queue.
                TreeNode *curr = q.front();
                q.pop();

                // Update the value of the rightmost node.
                rightMostValue = curr->val;

                // If the left child exists, push it into the queue.
                if (curr->left)
                    q.push(curr->left);

                // If the right child exists, push it into the queue.
                if (curr->right)
                    q.push(curr->right);
            }

            // Add the value of the rightmost node at the current level to the result vector.
            ans.push_back(rightMostValue);
        }

        // Return the vector containing the values of the right side view.
        return ans;
    }
};
