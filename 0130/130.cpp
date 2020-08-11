#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // 对能到边缘的'O' 进行标记
    void markZoom(vector<vector<char>> board, int x, int y, vector<vector<bool>> &mark)
    {
        mark[x][y] = true;
        // up
        if (x - 1 >= 0 && board[x - 1][y] == 'O' && !mark[x - 1][y])
        {
            markZoom(board, x - 1, y, mark);
        }
        // down
        if (x + 1 < board.size() && board[x + 1][y] == 'O' && !mark[x + 1][y])
        {
            markZoom(board, x + 1, y, mark);
        }
        // left
        if (y - 1 >= 0 && board[x][y - 1] == 'O' && !mark[x][y - 1])
        {
            markZoom(board, x, y - 1, mark);
        }
        // right
        if (y + 1 < board[0].size() && board[x][y + 1] == 'O' && !mark[x][y + 1])
        {
            markZoom(board, x, y + 1, mark);
        }
    }
    void solve(vector<vector<char>> &board)
    {
        int row = board.size();
        if (row == 0)
        {
            return;
        }
        int col = board[0].size();
        vector<vector<bool>> mark(row, vector<bool>(col, false));
        // up down
        for (int i = 0; i < col; i++)
        {
            if (board[0][i] == 'O' && !mark[0][i])
            {
                markZoom(board, 0, i, mark);
            }
            if (board[row - 1][i] == 'O' && !mark[row - 1][i])
            {
                markZoom(board, row - 1, i, mark);
            }
        }
        // left right
        for (int i = 0; i < row; i++)
        {
            if (board[i][0] == 'O' && !mark[i][0])
            {
                markZoom(board, i, 0, mark);
            }
            if (board[i][col - 1] == 'O' && !mark[i][col - 1])
            {
                markZoom(board, i, col - 1, mark);
            }
        }
        // fill zoom
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (board[i][j] == 'O' && !mark[i][j])
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};