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
    // Merges two sorted linked lists
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        // If one of the lists is empty, return the other list
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        // Recursive approach to merge lists
        if (l1->val <= l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
        // Unreachable code
        return NULL;
    }

    // Divide and conquer to merge lists
    ListNode *partitionAndMerge(int start, int end, vector<ListNode *> &lists)
    {
        // Base case: When the range is invalid, return NULL
        if (start > end)
        {
            return NULL;
        }
        // Base case: When the range contains only one list, return that list
        if (start == end)
        {
            return lists[start];
        }
        // Calculate the mid index
        int mid = start + (end - start) / 2;
        // Recursively divide the lists and merge them
        ListNode *L1 = partitionAndMerge(start, mid, lists);
        ListNode *L2 = partitionAndMerge(mid + 1, end, lists);

        return mergeTwoLists(L1, L2);
    }

    // Entry function to merge k sorted lists
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int k = lists.size();
        // Call the helper function to partition and merge the lists
        return partitionAndMerge(0, k - 1, lists);
    }
};
