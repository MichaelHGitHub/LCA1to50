#include <stack>

#include "header.h"

// help function to check if two chars make up a parentheses
// have to pass the two chars in valid parenthesis order
bool areCharsParentheses(char c1, char c2);

/*
* Constraints:
1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/
bool isValid(string s)
{
    bool result = false;

    stack<char> pending_letters;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s.at(i);
        if ((pending_letters.empty() == false) && (areCharsParentheses(pending_letters.top(), c)))
        {
            pending_letters.pop();
        }
        else
        {
            pending_letters.push(c);
        }
    }

    if (pending_letters.empty())
    {
        result = true;
    }

    return result;

}

bool areCharsParentheses(char c1, char c2)
{
    bool result = false;

    switch (c1)
    {
    case '(':
        if (c2 == ')')
        {
            result = true;
        }
        break;

    case '[':
        if (c2 == ']')
        {
            result = true;
        }
        break;

    case '{':
        if (c2 == '}')
        {
            result = true;
        }
        break;

    default:

        break;
    }

    return result;
}