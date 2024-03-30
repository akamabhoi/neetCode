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
    // Function to reorder a linked list
    void reorderList(ListNode *head)
    {
        // Initialize two pointers slow and fast to find the middle of the list
        ListNode *slow = head, *fast = head;
        while (fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the list
        ListNode *prev = nullptr, *curr = slow, *nex = nullptr;
        while (curr)
        {
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }

        // Merge the first half and the reversed second half of the list
        ListNode *head1 = head, *head2 = prev;
        while (head2->next)
        {
            ListNode *temp = head1->next;
            head1->next = head2;
            head1 = temp;
            temp = head2->next;
            head2->next = head1;
            head2 = temp;
        }
    }
};
