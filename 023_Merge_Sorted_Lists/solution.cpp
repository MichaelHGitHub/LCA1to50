#include "header.h"


ListNode* mergeKLists(vector<ListNode*>& lists)
{
    int k = lists.size();

    if (0 == k)
    {
        return nullptr;
    }

    ListNode** pos = new ListNode*[k];
    memset(pos, 0, k * sizeof(ListNode*));

    for (int i = 0; i < k; i++)
    {
        pos[i] = lists[i];
    }

    ListNode* head = nullptr;
    ListNode* end = nullptr;
    bool firs_node = true;

    while (firs_node || nullptr != end)
    {
        int smallest_index = 0;
        for(int j = 1; j < k; j++)
        {
            if (nullptr == pos[j])
            {
                continue;
            }
            else if(nullptr == pos[smallest_index])
            {
                smallest_index = j;
            }
            else if (pos[j]->val < pos[smallest_index]->val)
            {
                smallest_index = j;
            }
        }

        if (firs_node)
        {
            end = pos[smallest_index];
            head = end;
            firs_node = false;
        }
        else
        {
            end->next = pos[smallest_index];
            end = end->next;
        }

        if (nullptr != pos[smallest_index])
        {
            pos[smallest_index] = pos[smallest_index]->next;
        }
    }

    delete[] pos;

    return head;
}