#include <unordered_set>
#include "header.h"

bool isValidSudoku_r(vector<vector<char>>& board)
{
    unordered_set<char> row_maps[9];
    unordered_set<char> col_maps[9];
    unordered_set<char> squ_maps[3][3];

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == '.')
            {
                continue;
            }

            if (row_maps[i].find(board[i][j]) != row_maps[i].end())
            {
                return false;
            }
            else
            {
                row_maps[i].insert(board[i][j]);
            }
            if (col_maps[j].find(board[i][j]) != col_maps[j].end())
            {
                return false;
            }
            else
            {
                col_maps[j].insert(board[i][j]);
            }
            if (squ_maps[i/3][j/3].find(board[i][j]) != squ_maps[i / 3][j / 3].end())
            {
                return false;
            }
            else
            {
                squ_maps[i / 3][j / 3].insert(board[i][j]);
            }
        }
    }
    return true;
}