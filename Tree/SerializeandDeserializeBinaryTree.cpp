class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (!root)
            return ""; // If the root is null, return an empty string.

        string s = "";       // Initialize the result string.
        queue<TreeNode *> q; // Use a queue for level order traversal.
        q.push(root);        // Start with the root node.

        while (!q.empty())
        {
            TreeNode *curr = q.front(); // Get the front node from the queue.
            q.pop();                    // Remove the front node from the queue.

            if (!curr)
            {
                s.append("#,"); // If the current node is null, append "#," to the result string.
            }
            else
            {
                s.append(to_string(curr->val) + ','); // Append the current node's value followed by a comma.
                q.push(curr->left);                   // Add the left child to the queue.
                q.push(curr->right);                  // Add the right child to the queue.
            }
        }

        return s; // Return the serialized string.
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.size() == 0)
            return NULL; // If the data string is empty, return null.

        stringstream s(data); // Create a stringstream object from the data string.
        string str;

        getline(s, str, ',');                     // Get the first value (root value) from the string.
        TreeNode *root = new TreeNode(stoi(str)); // Create the root node.

        queue<TreeNode *> q; // Use a queue to reconstruct the tree level by level.
        q.push(root);        // Start with the root node.

        while (!q.empty())
        {
            TreeNode *node = q.front(); // Get the front node from the queue.
            q.pop();                    // Remove the front node from the queue.

            // Process the left child
            getline(s, str, ','); // Get the next value from the string.
            if (str == "#")
            {
                node->left = NULL; // If the value is "#", the left child is null.
            }
            else
            {
                TreeNode *leftNode = new TreeNode(stoi(str)); // Create the left child node.
                node->left = leftNode;                        // Attach the left child node to the current node.
                q.push(leftNode);                             // Add the left child node to the queue.
            }

            // Process the right child
            getline(s, str, ','); // Get the next value from the string.
            if (str == "#")
            {
                node->right = NULL; // If the value is "#", the right child is null.
            }
            else
            {
                TreeNode *rightNode = new TreeNode(stoi(str)); // Create the right child node.
                node->right = rightNode;                       // Attach the right child node to the current node.
                q.push(rightNode);                             // Add the right child node to the queue.
            }
        }

        return root; // Return the root of the reconstructed tree.
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
