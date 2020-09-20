#include<string>
#include<iostream>
#include<sstream>
#include<istream>
#include<vector>
#include<algorithm>
#include<assert.h>
#include<tuple>
#include<typeinfo>
using namespace std;
class test_pair
{
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {

        int height = grid.size(), width=grid[0].size();
        if (height==0||width==0) return 0;
        vector<vector<vector<int>>> dp(height+1, vector<vector<int>>(width+1, vector<int>(2, 0)));//多一行一列用于边界
        int maxLen=0;
        for(int i=1;i<=height ;++i)
        { 
            for(int j=1;j<=width; ++j) //0是左侧连续为1的数量，1是上方连续为1的数量
            { 
                if(grid[i-1][j-1]) //该点为1
               {
                     dp[i][j][0]=dp[i][j-1][0]+1;
                    dp[i][j][1]=dp[i-1][j][1]+1;

                }
                int len=min(dp[i][j][0],dp[i][j][1]);
                while(len>0)
                { 
                    if(dp[i-len+1] [j][0]>=len&&dp[i][j-len+1][1]>=len)
                          break;
                    len--;
                    maxLen=max(len,maxLen);
                }
            }

        }
        return maxLen*maxLen;
    }
};













pair<int, int> get_pair(int, int);
tuple<int, int, float> get3_tuple(int i, int j, float k);


int main(int argc, char const *argv[])
{
    pair<int, int> m{ 1, 2 };
    auto [n, p] = m;

    auto [xx, mm]=get_pair(3, 4);
    auto&& a3=get3_tuple(3, 4, 5.1);
    auto& [fr,se,th]=a3;
    fr=4;
    //remove_reference
    auto asize = tuple_size<remove_reference<decltype(a3)>::type>::value;
    using ass = remove_reference<decltype(a3)>::type;
    ass tts;
    auto asss=typeid(a3).name();
    using a = decltype(get3_tuple(3,4,5));
    cout<<" "<<" "<<th<<endl;
    cout<<fr<< endl;
    cout<<get<0>(a3)<<endl;
    cout<<asss<<endl;


    /* code */
    vector<vector<int>> grid{ { 1, 1, 1 }, { 1, 0, 1 }, { 1, 1, 1 } };

    auto val = test_pair().largest1BorderedSquare(grid);
    return 0;
}

auto get_pair(int i,int k)->pair<int,int>
{
    return make_pair(i, k);

}

auto get3_tuple(int i,int j,float k)->tuple<int,int,float>
{
    return make_tuple(i, j, k);
}





