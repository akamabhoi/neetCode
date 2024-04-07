class Solution
{
public:
    // Utility function to count nodes in the list
    int count(ListNode *head)
    {
        int count = 0;
        while (head)
        {
            ++count;
            head = head->next;
        }
        return count;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        int num = count(head);
        if (num < k)
        {
            return head;
        }

        ListNode *next = nullptr;
        ListNode *prev = nullptr;
        ListNode *curr = head;
        int count = 0;

        while (count < k && curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            ++count;
        }

        if (next)
        {
            head->next = reverseKGroup(next, k);
        }

        return prev;
    }
};
