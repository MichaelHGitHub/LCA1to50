#include "header.h"

// Use 4 pointers
// p0: points to the node prior to the pair to be swapped
// p1: points to the first node in the pair
// p2: points at the second node in the pair
// p3: points at the node next to the pair
// Key points:
//  1. create a dummy node to facilitate the operation
//  2. after each swapping, p1 becomes the second node in the pair.
// .3. handle p3 and p3->next so that it won't cause dereferencing null pointer.

ListNode* swapPairs(ListNode* head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ListNode dummy = ListNode(-1, head);

    ListNode* p0 = &dummy;
    ListNode* p1 = head;
    ListNode* p2 = p1->next;
    ListNode* p3 = p2->next;

    while (p1->next != nullptr)
    {
        p0->next = p2;
        p2->next = p1;
        p1->next = p3;

        // After swapping, p1 becomes the second node in the pair.
        p0 = p1;
        p1 = p3;

        if (p3 != nullptr)
        {
            p2 = p3->next;
        }
        else
        {
            break;
        }
        
        if (p3->next != nullptr)
        {
            p3 = p3->next->next;
        }
    }

    return dummy.next;
}