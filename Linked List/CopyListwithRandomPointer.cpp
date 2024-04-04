/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};
*/

class Solution
{
public:
    // Function to copy a linked list with random pointers
    Node *copyRandomList(Node *head)
    {
        // Map to store the mapping from original nodes to their copies
        unordered_map<Node *, Node *> nodeMap;

        // Pointer to traverse the original list
        Node *curr = head;

        // Iterate over the original list to create copies of nodes
        while (curr)
        {
            // Create a new node with the same value as the current node
            Node *newNode = new Node(curr->val);

            // Map the current node to its copy
            nodeMap[curr] = newNode;

            // Move to the next node in the original list
            curr = curr->next;
        }

        // Reset the pointer to the head of the original list
        curr = head;

        // Iterate over the original list to set next and random pointers of copies
        while (curr)
        {
            // Set the next pointer of the copy node to the copy of the next node
            nodeMap[curr]->next = nodeMap[curr->next];

            // Set the random pointer of the copy node to the copy of the random node
            nodeMap[curr]->random = nodeMap[curr->random];

            // Move to the next node in the original list
            curr = curr->next;
        }

        // Return the head of the copied list
        return nodeMap[head];
    }
};

class Solution
{
public:
    // Function to copy a linked list with random pointers
    Node *copyRandomList(Node *head)
    {
        // If the original list is empty, return nullptr
        if (!head)
            return nullptr;

        // Step 1: Create a copy of each node and insert it after the original node
        Node *curr = head;
        while (curr)
        {
            // Create a new node with the same value as the current node
            Node *new_node = new Node(curr->val);
            // Insert the new node after the current node
            new_node->next = curr->next;
            curr->next = new_node;
            // Move to the next original node
            curr = new_node->next;
        }

        // Step 2: Update the random pointers of the copied nodes
        curr = head;
        while (curr)
        {
            // If the current node has a random pointer, update the random pointer of its copy
            if (curr->random)
            {
                curr->next->random = curr->random->next;
            }
            // Move to the next original node
            curr = curr->next->next;
        }

        // Step 3: Separate the original and copied lists
        Node *old_head = head;
        Node *new_head = head->next;
        Node *curr_old = old_head;
        Node *curr_new = new_head;
        while (curr_old)
        {
            // Update the next pointers of the original list
            curr_old->next = curr_old->next->next;
            // Update the next pointers of the copied list
            curr_new->next = curr_new->next ? curr_new->next->next : nullptr;
            // Move to the next nodes in both lists
            curr_old = curr_old->next;
            curr_new = curr_new->next;
        }

        // Return the head of the copied list
        return new_head;
    }
};
