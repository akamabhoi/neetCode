/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    // Map to store the original node to its clone
    unordered_map<Node *, Node *> nodeMap;

    // DFS function to clone the graph
    void dfs(Node *originalNode, Node *clonedNode)
    {
        // Traverse all neighbors of the original node
        for (auto neighbor : originalNode->neighbors)
        {
            // If the neighbor hasn't been cloned yet
            if (nodeMap.find(neighbor) == nodeMap.end())
            {
                // Clone the neighbor node
                Node *clonedNeighbor = new Node(neighbor->val);
                // Map the original neighbor to the cloned neighbor
                nodeMap[neighbor] = clonedNeighbor;
                // Add the cloned neighbor to the current cloned node's neighbors
                clonedNode->neighbors.push_back(clonedNeighbor);
                // Recursively clone the neighbors
                dfs(neighbor, clonedNeighbor);
            }
            else
            {
                // If the neighbor is already cloned, just add it to the current cloned node's neighbors
                clonedNode->neighbors.push_back(nodeMap[neighbor]);
            }
        }
    }

    // Function to clone the graph
    Node *cloneGraph(Node *node)
    {
        // If the input node is null, return null
        if (!node)
        {
            return nullptr;
        }
        // Clear the map for fresh cloning
        nodeMap.clear();
        // Create the clone for the input node
        Node *clonedNode = new Node(node->val);
        // Map the original node to its clone
        nodeMap[node] = clonedNode;
        // Start DFS from the input node
        dfs(node, clonedNode);
        // Return the cloned graph's starting node
        return clonedNode;
    }
};
