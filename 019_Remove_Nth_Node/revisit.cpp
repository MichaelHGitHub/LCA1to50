#include "header.h"

ListNode* removeNthFromEnd_r(ListNode* head, int n)
{
    ListNode dummy;
    dummy.next = head;

    ListNode* node1 = &dummy;
    ListNode* node2 = &dummy;
    int steps = 0;
    while (node1->next && node2->next)
    {
        if (steps < n)
        {
            node2 = node2->next;
            ++steps;
        }
        else
        {
            node1 = node1->next;
            node2 = node2->next;
        }
    }

    if (node1->next)
    {
        ListNode* temp = node1->next;
        node1->next = node1->next->next;
        delete temp;
    }

    return dummy.next;
}