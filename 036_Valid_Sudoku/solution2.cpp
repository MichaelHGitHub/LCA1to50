#include <unordered_set>
#include "header.h"

// This can be solved in 3 iterations while each iteration does onething, 
// or use 1 Iteration that does 3 thing at a time.
// 1 iteration doesn't neccessarily guareenty better performance. 
// In face my 3 iteration-solution achieved 95% faster while 1 iteration
// just made 35% faster Also 3 iteration-solution uses less space than
// 1 iteration does. 
// The 3 things need to be done:
//      1. Check if any element duplicates in the same row
//      2. Check if any element duplicates in the same colum.
//      3. Check if any element duplicates in the same sub-box
// Note: 
// 2. Use an unordered_set in the check to reduce interations that
// otherwise would be required.
bool isValidSudoku2(vector<vector<char>>& board)
{
    unordered_set<char> chares;

    for (int i = 0; i < board.size(); i++)
    {
        chares.clear();
        for (int j = 0; j < board[i].size(); j++)
        {
            if (chares.find(board[i][j]) != chares.end())
            {
                return false;
            }
            else if (board[i][j] != '.')
            {
                chares.insert(board[i][j]);
            }
        }
    }

    for (int j = 0; j < board[0].size(); j++)
    {
        chares.clear();
        for (int i = 0; i < board.size(); i++)
        {
            if (chares.find(board[i][j]) != chares.end())
            {
                return false;
            }
            else if (board[i][j] != '.')
            {
                chares.insert(board[i][j]);
            }
        }
    }

    for (int i = 0; i < board.size(); i += 3)
    {
        for (int j = 0; j < board[i].size(); j += 3)
        {
            if (i <= board.size() - 3 && j <= board[i].size() - 3)
            {
                chares.clear();

                for (int k = 0; k < 3; k++)
                {
                    for (int l = 0; l < 3; l++)
                    {
                        if (chares.find(board[i + k][j + l]) != chares.end())
                        {
                            return false;
                        }
                        else if (board[i + k][j + l] != '.')
                        {
                            chares.insert(board[i + k][j + l]);
                        }
                    }
                }
            }
        }
    }

    return true;
}

