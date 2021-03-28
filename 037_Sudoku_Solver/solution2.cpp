#include <unordered_set>
#include "header.h"


static bool canPlace(vector<vector<char>>& board, char c, int i, int j)
{
    for (int k = 0; k < 9; k++)
    {
        if (board[i][k] == c || board[k][j] == c)
        {
            return false;
        }
    }

    int l = (i / 3) * 3;
    int m = (j / 3) * 3;
    for (int u = l; u < l + 3; u++)
    {
        for (int v = m; v < m + 3; v++)
        {
            if (board[u][v] == c)
            {
                return false;
            }
        }
    }

    return true;
}

// Fill one cell and do a complete scan to check if it is good. 
// Not good at performance
static bool buildSudoku(vector<vector<char>>& board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == '.')
            {
                for (char c = '1'; c <= '9'; c++)
                {
                    if (canPlace(board, c, i, j))
                    {
                        board[i][j] = c;
                        if (buildSudoku(board))
                        {
                            return true;
                        }
                        else
                        {
                            board[i][j] = '.';
                        }
                    }
                }

                return false;
            }
        }
    }

    return true;
}

void solveSudoku2(vector<vector<char>>& board)
{
    buildSudoku(board);
}