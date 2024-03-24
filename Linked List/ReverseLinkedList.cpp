// This code defines a solution class with a method to reverse a singly-linked list.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution
{
public:
    // Function to reverse a singly-linked list
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prevNode = NULL, *currNode = head, *nextNode = NULL;

        // Iterate through the list
        while (currNode)
        {
            // Store the next node
            nextNode = currNode->next;

            // Reverse the link
            currNode->next = prevNode;

            // Move to the next nodes
            prevNode = currNode;
            currNode = nextNode;
        }

        // Return the new head of the reversed list
        return prevNode;
    }
};
