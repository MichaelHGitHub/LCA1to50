#include "header.h"

ListNode* swapPairs_r(ListNode* head)
{
    ListNode dummy;
    dummy.next = head;

    ListNode* p1 = &dummy;
    ListNode* p2 = p1->next;
    ListNode* p3 = p2 ? p2->next : nullptr;
    ListNode* p4 = p3? p3->next : nullptr;

    while (p3)
    {
        p1->next = p3;
        p3->next = p2;
        p2->next = p4;

        p1 = p1->next->next;
        p2 = p1->next;
        p3 = p2 ? p2->next : nullptr;
        p4 = p3 ? p3->next : nullptr;
    }
    return dummy.next;
}