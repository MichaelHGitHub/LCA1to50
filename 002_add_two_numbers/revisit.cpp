#include "header.h"

ListNode* addTwoNumbers_r(ListNode* l1, ListNode* l2)
{
    int carry_on = 0;
    ListNode dummy;
    ListNode* node = &dummy;

    while (l1 || l2)
    {
        int sum = carry_on;

        if (l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        node->next = new ListNode(sum % 10);
        carry_on = sum / 10;
        node = node->next;
    }

    if (carry_on)
    {
        node->next = new ListNode(carry_on);
    }

    return dummy.next;
}