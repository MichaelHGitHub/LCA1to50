#include "header.h"

// Use two pointers so that we don't need extra space allocated for 
// all the nodes.
// Move p1 n pos first so that the gap between p1 and p2 is n.
// Then move both pointer together until p1 to the last node(not the one behind)
// , at this time p2 will be pointing at the one node before to-be-removed.
// Special case: input has only 1 node and n = 1.(because p2 will point 
// at the one before to-be-removed, therefore can't cover this case. 

ListNode* removeNthFromEnd2(ListNode* head, int n)
{
    if (head == nullptr || 0 == n)
    {
        return head;
    }

    if (head->next == nullptr && 1 == n)
    {
        return nullptr;
    }

    ListNode* node = head;
    ListNode* before_remove = head;

    for (int i = 0; i < n; i++)
    {
        node = node->next;
    }

    // To remove the head
    if (node == nullptr)
    {
        head = head->next;
        return head;
    }

    // As we are moving to the node before to-be-removed,
    // node can't to to null.
    while (node->next)
    {
        node = node->next;
        before_remove = before_remove->next;
    }

    if (before_remove && before_remove->next)
    {
        before_remove->next = before_remove->next->next;
    }

    return head;
}