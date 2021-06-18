#include <stack>
#include "header.h"

bool isValid_r(string s)
{
    stack<char> pending;

    for (int i = 0; i < s.length(); i++)
    {
        switch (s[i])
        {
        case ')':
            if (pending.empty() || pending.top() != '(')
            {
                return false;
            }
            pending.pop();
            break;

        case ']':
            if (pending.empty() || pending.top() != '[')
            {
                return false;
            }
            pending.pop();
            break;

        case '}':
            if (pending.empty() || pending.top() != '{')
            {
                return false;
            }
            pending.pop();
            break;

        default:
            pending.push(s[i]);
            break;
        }
    }
    return pending.size() == 0;
}