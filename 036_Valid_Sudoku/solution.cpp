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
// 1. Each element belongs to the sub-box[3 * (i/3) + j/3].
// 2. Use an unordered_set in the check to reduce interations that
// otherwise would be required.
bool isValidSudoku(vector<vector<char>>& board)
{
    vector<unordered_set<char>> row_chares;
    vector < unordered_set<char>> col_chares;
    vector < unordered_set<char>> box_chares;

    for (int i = 0; i < board.size(); i++)
    {
        row_chares.push_back(unordered_set<char>());
        col_chares.push_back(unordered_set<char>());
        box_chares.push_back(unordered_set<char>());
    }

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (row_chares[i].find(board[i][j]) != row_chares[i].end())
            {
                return false;
            }
            else if (board[i][j] != '.')
            {
                row_chares[i].insert(board[i][j]);
            }

            if (col_chares[j].find(board[i][j]) != col_chares[j].end())
            {
                return false;
            }
            else if (board[i][j] != '.')
            {
                col_chares[j].insert(board[i][j]);
            }

            if (box_chares[3 * (i / 3) + j / 3].find(board[i][j]) != box_chares[3 * (i / 3) + j / 3].end())
            {
                return false;
            }
            else if (board[i][j] != '.')
            {
                box_chares[3 * (i / 3) + j / 3].insert(board[i][j]);
            }
        }
    }

    return true;
}