
#include "header.h"

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    vector<ListNode*> nodes;
    ListNode* node = head;

    while (nullptr != node)
    {
        nodes.push_back(node);
        node = node->next;
    }

    int num = nodes.size();
    if (0 != n && 0 != num)
    {
        if (n == num)
        {
            head = head->next;
        }
        else if (n < num)
        {
            nodes[num - n - 1]->next = nodes[num - n]->next;
        }
    }

    return head;
}