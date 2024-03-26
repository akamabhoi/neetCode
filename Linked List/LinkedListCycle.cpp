/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution
{
public:
    // Function to check if a linked list has a cycle
    bool hasCycle(ListNode *head)
    {
        // If the head is NULL, there can't be a cycle
        if (head == NULL)
            return false;

        ListNode *slow = head, *fast = head->next; // Pointers to traverse the list

        // Traverse the list until either of the pointers reaches the end
        while (slow && fast && slow->next && fast->next)
        {
            // If the pointers meet, there is a cycle
            if (slow == fast)
                return true;

            slow = slow->next;       // Move the slow pointer one step forward
            fast = fast->next->next; // Move the fast pointer two steps forward
        }

        // If we reach here, it means we traversed the list without finding a cycle
        return false;
    }
};
