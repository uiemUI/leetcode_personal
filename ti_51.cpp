#include "stand.h"
/*----------------------------------------------------------------

n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
主要是判断是否合法的代码
*/
class Solution
{
private:
    vector<vector<string>> res;
    bool isValid(int row, int col, vector<string> &board)
    {
        if (row >= board.size() || col >= board[row].size())
            return false;
        for (int i = 0; i < row; i++) //判断所在列
        {
            if (board[i][col] == 'Q')
                return false;
        }
        int sz = board[row].size();
        for (int i = row - 1, j = col + 1; i >= 0 && j < sz; i--, j++)//判断右上对角线
        {
            if (board[i][j] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)//判断左上对角线
        {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }
    void backTrace(int row, vector<string> &board)
    {
        if (row >= board.size())
        //该board完成
        {
            res.push_back(board);
            return;
        }
        int cols = board[row].size();
        for (int col = 0; col < cols; col++)
        {
            if (!isValid(row, col, board))
                continue; //排除不合法的
            board[row][col] = 'Q';
            backTrace(row + 1, board);
            board[row][col] = '.';
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board(n, string(n, '.'));
        backTrace(0, board);
        return res;
        
    }
};

