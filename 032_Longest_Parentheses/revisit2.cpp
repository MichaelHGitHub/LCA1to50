#include <stack>
#include "header.h"

// Use stack
// Count on the index of the latest invalid ')' to include multiple phase of valid
// parenthes. push '-1' at the very beginning for this purpose.
// Whenever we get '(', push its index to stack.
// Whenever we get ')', we calculate length substructing 
// the current index by the index of the element before the matching '('.
// or the index of the latest invalid ')'.

int longestValidParentheses_r2(string s)
{
    stack<int> pending;
    int max_len = 0;

    pending.push(-1);

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            pending.push(i);
        }
        else
        {
            pending.pop();

            if (pending.empty())
            {
                // push the index of the latest invalid ')'
                pending.push(i);
            }
            else
            {
                // Matching '(' is popped. 
                max_len = max(max_len, i - pending.top());
            }
        }
    }
    return max_len;
}