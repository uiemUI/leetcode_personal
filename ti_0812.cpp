#include"stand.h"
class Solution
{
private:
    vector<vector<string>> ans_;
    bool isValid(vector<string>& path,int row,int col)
    {
        int rows = path.size();
        for (int i = 0; i < rows;++i)
        {
            if(path[i][col]=='Q')
                return false;//判断列
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < rows; i--,j++)
        {
            if(path[i][j]=='Q')
                return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--,j--)
        {
            if(path[i][j]=='Q')
                return false;
        }
        return true;
    }
    void backTrack(vector<string> &path, int row)
    {
        if(row==path.size()) //路径满足条件
        {
            ans_.push_back(path);
            return;
        }
        int cols = path[row].size();//row的每col枚举
        for (int col = 0; col < cols; ++col)
        {
            if(!isValid(path,row,col)
            
            
            )
                continue; //跳过不合法的
            path[row][col] = 'Q';
            backTrack(path, row + 1);
            path[row][col] = '.';

        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> path(n, string(n, '.'));
        backTrack(path, 0);
        return ans_;
    }

  
};