#include "header.h"

// Recursive solution:
// swap current pair.
// the next of second node is the return pointer of next recursive call
ListNode* swapPairs2(ListNode* head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ListNode* p1 = head;
    ListNode* p2 = p1->next;
    ListNode* p3 = p2->next;

    p2->next = p1;
    p1->next = swapPairs2(p3);

    // Note: p2 becomes the head now. 
    return p2;
}