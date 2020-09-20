#include"stand.h"
#include"output_container.h"
//----------------------------------------------------------------
/**
 * 数独，先循环遍历board得到要填的格子，以及更新cols,rows,cells的状态
 * 
 * 
 * 
 * 
 */

class Solution
{
private:
    vector<bitset<9>> cols;
    vector<bitset<9>> rows;
    vector<vector<bitset<9>>> cells;
    vector<pair<int, int>> nexts;
    
    bool dfs(vector<vector<char>> &board,int pos)
    {
        if(pos==nexts.size())
            return true;
        auto&& [x,y]=nexts[pos];
        auto possible = getPossible(x, y);
        for (int i = 0;i<possible.size();i++)
        {
            if(!possible.test(i))
                continue;
            fillName(x,y,i,true);
            board[x][y] = i + '1';
            if(dfs(board,pos+1)) return true;
            fillName(x,y,i,false);
            board[x][y] = '.';
        }

        return false;
    }

    void fillName(int x, int y, int n, bool fillFlag)
    {
        rows[x][n] = (fillFlag) ? 1 : 0;
        cols[y][n] = (fillFlag) ? 1 : 0;
        cells[x/3][y/3][n] = (fillFlag) ? 1: 0;
    }

    bitset<9> getPossible(int x,int y)
    {
        return ~(rows[x] | cols[y] | cells[x / 3][y / 3]);//x行y列可行的数字
    }
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        cols=vector<bitset<9>>(9,bitset<9>());
        rows = vector<bitset<9>>(9, bitset<9>());
        cells=vector<vector<bitset<9>>>(3,vector<bitset<9>>(3,bitset<9>()));
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]=='.')
                {
                    nexts.emplace_back(pair{i,j});
                }
                else
                {
                    int n = board[i][j] - '1';
                    rows[i] |= (1 << n);
                    cols[j] |= (1 << n);
                    // rows[i] |= 1 << n;
                    cells[i / 3][j / 3] |= (1 << n);
                }
                
            }
        }

        dfs(board, 0);


    }
};


int main(int argc, char const *argv[])
{
    vector<vector<char>> board(9, vector<char>(9, '.'));
    Solution().solveSudoku(board);
    cout << board << endl;
    auto a = u8"朱闯";
    cout << a << endl;

    return 0;
}

