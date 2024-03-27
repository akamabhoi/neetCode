class Solution
{
public:
    // Function to reorder a linked list
    void reorderList(ListNode *head)
    {
        // Base case: linked list is empty
        if (!head)
            return;

        // Finding the middle with the help of two-pointer approach
        ListNode *tmp = head, *half = head, *prev = NULL;
        while (tmp->next && tmp->next->next)
        {
            tmp = tmp->next->next;
            half = half->next;
        }

        // Adding one step in case of lists with even length
        if (tmp->next)
            half = half->next;

        // Now reverse the second half
        while (half)
        {
            tmp = half->next;
            half->next = prev;
            prev = half;
            half = tmp;
        }
        half = prev;

        // After reversing the second half, let's merge both the halves
        while (head && half)
        {
            tmp = head->next;
            prev = half->next;
            head->next = half;
            half->next = tmp;
            head = tmp;
            half = prev;
        }

        // Base case: closing when we had even-length arrays
        if (head && head->next)
            head->next->next = NULL;
    }
};