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
    // Function to remove the nth node from the end of a linked list
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // Create a dummy node to handle edge cases
        ListNode *dummy = new ListNode();
        dummy->next = head;

        // Initialize two pointers slow and fast
        ListNode *slow = dummy, *fast = dummy;

        // Move the fast pointer n steps ahead
        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        }

        // Move both pointers until the fast pointer reaches the end
        while (fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }

        // Remove the nth node from the end
        ListNode *temp = slow->next;
        slow->next = slow->next->next;
        delete (temp); // Deallocate memory for the removed node

        // Return the head of the modified linked list
        return dummy->next;
    }
};
