#include"stand.h"

/***
 *79. 单词搜索
给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

 

示例:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true
给定 word = "SEE", 返回 true
给定 word = "ABCB", 返回 false 
 */
class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        //字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

        int m = board.size();
        if (!m)
            return false;
        int n = board[0].size();
        if (!n)
            return false;
        vector<vector<int>> mark(m, vector<int>(n, 0));
        int dx[4] = {0, 1, -1, 0};
        int dy[4] = {1, 0, 0, -1};
        function<bool(int, int, int)> dfs = [&](int sx, int sy, int step) {
            if(step==word.size()-1)
            {
                return board[sx][sy] == word[step];
            }
            if(board[sx][sy] == word[step])
            {
                mark[sx][sy] = 1;
                for (int i = 0; i < 4;i++)
                {
                    int x = sx + dx[i];
                    int y = sy + dy[i];
                    if (x >= 0 && x < m && y >= 0 && y < n && !mark[x][y])
                    {
                        if(dfs(x,y,step+1))
                            return true;
                    }

                }
                mark[sx][sy] = 0;//不能重复使用同一个字母
            }

            return false;
        };

        for (int i = 0; i < m;i++)
        {
            for(int j = 0; j<n;j++)
                if(dfs(i,j,0)) 
                    return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
