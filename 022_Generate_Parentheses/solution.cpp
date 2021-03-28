#include <stack>
#include "header.h"

bool isParentheses(char* s, int n);

void getAll(vector<string>& result, char* all, int current, int length);

vector<string> generateParenthesis(int n)
{
    vector<string> result;

    char* all = new char[2 * n + 1];
    memset(all, 0, 2 * n + 1);


    getAll(result, all, 0, 2*n);


    delete[] all;

    return result;
}


bool isParentheses(char* s, int n)
{
    bool result = false;
    
    int balance = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == ')')
        {
            balance--;
            // This ensure no ')' being deplay calculated.
            // As long as no '(' to match ')', return false.
            if (balance < 0)
            {
                break;
            }
        }
        else
        {
            balance++;
        }
    }

    if (balance == 0)
    {
        result = true;
    }

    return result;
}

void getAll(vector<string>& result, char* all, int current, int length)
{
    if (current == length)
    {
        if (isParentheses(all, length))
        {
            result.push_back(all);
        }
    }
    else
    {
        // Here replace one char at each position while keep others unchanged.
        // but how to make sure there are no duplication
        all[current] = '(';
        getAll(result, all, current + 1, length);
        all[current] = ')';
        getAll(result, all, current + 1, length);
    }
}

