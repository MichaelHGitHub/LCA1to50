#include <unordered_set>
#include "header.h"

bool canPlace(vector<vector<char>>& board, char c, int i, int j)
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

bool buildSudoku(vector<vector<char>>& board, int i, int j)
{
    // Why need to reset J and enumerate i again?
    if (i < 9 && j == 9)
    {
        return buildSudoku(board, i + 1, 0);
    }

    if (i == 9)
    {
        return true;
    }

    if (board[i][j] == '.')
    {
        for (char c = '1'; c <= '9'; c++)
        {
            if (canPlace(board, c, i, j))
            {
                board[i][j] = c;
                if (buildSudoku(board, i, j + 1))
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
    else
    {
        return buildSudoku(board, i, j + 1);
    }
}

void solveSudoku(vector<vector<char>>& board)
{
    buildSudoku(board, 0, 0);
}