#include "header.h"

ListNode* mergeKLists_r(vector<ListNode*>& lists)
{
    ListNode dummy;
    ListNode* node = &dummy;

    while (true)
    {
        ListNode* smallest = nullptr;
        int smallest_pos = 0;
        for (int i = 0; i < lists.size(); i++)
        {
            if (!lists[i])
            {
                continue;
            }

            if (!smallest)
            {
                smallest = lists[i];
                smallest_pos = i;
            }
            else
            {
                if (smallest->val > lists[i]->val)
                {
                    smallest = lists[i];
                    smallest_pos = i;
                }
            }
        }

        if (smallest)
        {
            node->next = smallest;
            node = node->next;
            lists[smallest_pos] = lists[smallest_pos]->next;
        }
        else
        {
            break;
        }
    }

    return dummy.next;
}