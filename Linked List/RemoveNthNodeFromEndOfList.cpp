class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // Dummy node to handle special cases
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        // Initialize two pointers: fast and slow
        ListNode *fast = dummy;
        ListNode *slow = dummy;

        // Move fast pointer n+1 steps ahead
        for (int i = 0; i < n + 1; i++)
        {
            if (fast == nullptr)
                return nullptr; // n is greater than the number of nodes
            fast = fast->next;
        }

        // Move both pointers simultaneously until fast reaches the end
        while (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }

        // Remove the nth node from the end
        slow->next = slow->next->next;

        return dummy->next; // Return the modified head
    }
};
