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
    // Function to merge two sorted linked lists
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode head(0);       // Dummy head node for the merged list
        ListNode *curr = &head; // Pointer to the current node in the merged list

        // Iterate until both lists are non-empty
        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                curr->next = list1;  // Link the current node to the smaller node in list1
                list1 = list1->next; // Move list1 pointer to the next node
            }
            else
            {
                curr->next = list2;  // Link the current node to the smaller node in list2
                list2 = list2->next; // Move list2 pointer to the next node
            }
            curr = curr->next; // Move the current pointer to the next node in the merged list
        }

        // Attach the remaining nodes from the non-empty list
        curr->next = list1 ? list1 : list2;

        // Return the merged list starting from the next node of the dummy head
        return head.next;
    }
};
