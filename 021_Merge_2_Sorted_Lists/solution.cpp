#include "header.h"

//
// The solution is pretty straight foreward, just need to pay attention to the
// first node, which is explained in in-line comments.
// 
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    ListNode* head = nullptr;
    ListNode* p_merge = nullptr;
    ListNode* p1 = l1;
    ListNode* p2 = l2;

    // in the following block, (p_merge == 0  or head == 0) means first node, 
    // otherwise later nodes.
    while (p1 || p2)
    {
        if (p1 && p2)
        {
            if (p1->val < p2->val)
            {
                p_merge? (p_merge->next = p1) : (p_merge = p1);
                p1 = p1->next;
            }
            else
            {
                p_merge ? (p_merge->next = p2) : (p_merge = p2);
                p2 = p2->next;
            }

            (head ) ? (p_merge = p_merge->next) : (head = p_merge);
        }
        // List 2 is finished
        else if (p1)
        {
            p_merge ? (p_merge->next = p1) : (p_merge = p1);
            p1 = p1->next;
            (head) ? (p_merge = p_merge->next) : (head = p_merge);
        }
        // List 1 is finished
        else if (p2)
        {
            p_merge ? (p_merge->next = p2) : (p_merge = p2);
            p2 = p2->next;
            (head) ? (p_merge = p_merge->next) : (head = p_merge);
        }
    }

    return head;

}