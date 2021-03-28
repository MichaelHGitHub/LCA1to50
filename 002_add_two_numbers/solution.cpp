#include "header.h"

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    if (!l1 || !l2)
    {
        return nullptr;
    }

    ListNode* pSum = nullptr;
    ListNode* pSumEnd = nullptr;
    ListNode* p1 = l1;
    ListNode* p2 = l2;
    bool hasRemain = false;

    while (p1 || p2)
    {
        int val = 0;
        if (p1)
        {
            val += p1->val;
            p1 = p1->next;
        }

        if (p2)
        {
            val += p2->val;
            p2 = p2->next;
        }

        // Remember remainer for next round to add 1
        if (hasRemain)
        {
            ++val;
        }

        if (val > 9)
        {
            val = val % 10;
            hasRemain = true;
        }
        else
        {
            hasRemain = false;
        }

        ListNode* pTemp = new ListNode(val);
        if (!pSumEnd)
        {
            pSumEnd = pTemp;
            pSum = pSumEnd;
        }
        else
        {
            pSumEnd->next = pTemp;
            pSumEnd = pSumEnd->next;
        }

    }

    if (hasRemain)
    {
        ListNode* pTemp = new ListNode(1);
        pSumEnd->next = pTemp;
    }

    return pSum;
}

