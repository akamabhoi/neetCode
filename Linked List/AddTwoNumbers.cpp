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
    // Function to add two numbers represented by linked lists
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // Create a dummy head node for the result list
        ListNode *dummyHead = new ListNode();
        ListNode *curr = dummyHead;        // Pointer to traverse the result list
        ListNode *temp1 = l1, *temp2 = l2; // Pointers to traverse the input lists
        int carry = 0;                     // Variable to store the carry while adding digits

        // Iterate until both input lists are exhausted
        while (temp1 or temp2)
        {
            int sum = carry; // Initialize sum with the carry
            // Add the current digits of l1 and l2 (if available) to the sum
            if (temp1)
                sum += temp1->val;
            if (temp2)
                sum += temp2->val;

            // Create a new node with the sum modulo 10
            ListNode *newNode = new ListNode(sum % 10);
            // Update the carry for the next iteration
            carry = sum / 10;

            // Append the new node to the result list
            curr->next = newNode;
            curr = curr->next; // Move curr to the next node

            // Move temp1 and temp2 to their respective next nodes
            if (temp1)
                temp1 = temp1->next;
            if (temp2)
                temp2 = temp2->next;
        }

        // If there is a remaining carry after iterating both lists
        if (carry)
        {
            ListNode *newNode = new ListNode(carry); // Create a new node with the carry
            curr->next = newNode;                    // Append the node to the result list
        }

        return dummyHead->next; // Return the next node of the dummy head (the head of the result list)
    }
};
