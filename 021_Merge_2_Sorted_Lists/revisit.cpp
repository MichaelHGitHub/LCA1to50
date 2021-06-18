#include "header.h"

ListNode* mergeTwoLists_r(ListNode* l1, ListNode* l2)
{
    ListNode dummy;
    ListNode* node = &dummy;

    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            node->next = l1;
            l1 = l1->next;
        }
        else
        {
            node->next = l2;
            l2 = l2->next;
        }
        node = node->next;
    }

    if (l1)
    {
        node->next = l1;
    }
    if (l2)
    {
        node->next = l2;
    }
    return dummy.next;
}