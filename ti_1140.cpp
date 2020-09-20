/*
亚历克斯和李继续他们的石子游戏。许多堆石子 排成一行，每堆都有正整数颗石子 piles[i]。游戏以谁手中的石子最多来决出胜负。

亚历克斯和李轮流进行，亚历克斯先开始。最初，M = 1。

在每个玩家的回合中，该玩家可以拿走剩下的 前 X 堆的所有石子，其中 1 <= X <= 2M。然后，令 M = max(M, X)。

游戏一直持续到所有石子都被拿走。

假设亚历克斯和李都发挥出最佳水平，返回亚历克斯可以得到的最大数量的石头。

 

示例：

输入：piles = [2,7,9,4,4]
输出：10
解释：
如果亚历克斯在开始时拿走一堆石子，李拿走两堆，接着亚历克斯也拿走两堆。在这种情况下，亚历克斯可以拿到 2 + 4 + 4 = 10 颗石子。 
如果亚历克斯在开始时拿走两堆石子，那么李就可以拿走剩下全部三堆石子。在这种情况下，亚历克斯可以拿到 2 + 7 = 9 颗石子。
所以我们返回更大的 10。 
 

提示：

1 <= piles.length <= 100
1 <= piles[i] <= 10 ^ 4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/stone-game-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
/*
状态dp[i][j]表示为剩余[i,len-1]堆时m=j的情况下，最大数量。最终结果是dp[0][1]
*/
/*sum用于表示pile[i:len-1]的和*/
#include "stand.h"


class Solution
{
public:
    int stoneGameII(vector<int> &piles)
    {
        int len = piles.size();
        vector<vector<int>> dp(len+1, vector<int>(len+1, 0));
        int sum = 0;
        for (int i = len - 1; i >= 0;--i)
        {
            sum += piles[i];
            for (int m = 1; m <=len;++m)
            {
                if((i+2*m)>len)//全部选择,可以一次性选择，全选
                {
                    dp[i][m] = sum;
                    continue;
                }
                for (int x = 1; (i + x) <=len && x <=2 * m;++x)
                {
                    dp[i][m] = max(dp[i][m], sum - dp[i + x][max(m, x)]);
                    //遍历可能的x选择符合条件的最大值
                }
            }
        }
        return dp[0][1];
    }
};

void trimLeftTrailingSpaces(string &input)
{
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
                    return !isspace(ch);
                }));
}

void trimRightTrailingSpaces(string &input)
{
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
                    return !isspace(ch);
                }).base(),
                input.end());
}

vector<int> stringToIntegerVector(string input)
{
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim))
    {
        output.push_back(stoi(item));
    }
    return output;
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        vector<int> piles = stringToIntegerVector(line);

        int ret = Solution().stoneGameII(piles);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}