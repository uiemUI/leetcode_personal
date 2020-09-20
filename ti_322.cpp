#include "stand.h"
// 给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 - 1。

//  

//     示例 1 :

//     输入 : coins = [ 1, 2, 5 ],
//            amount = 11 输出 : 3 解释 : 11 = 5 + 5 + 1 示例 2 :

//     输入 : coins = [2],
//            amount = 3 输出 : -1

//                              来源：力扣（LeetCode）
//                                  链接：https : //leetcode-cn.com/problems/coin-change
//                                                著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 class Solution

/*
什么时候无效，至少amout小于coins中最小值的时候是无效的，基于此递推的数也是无效的
状态设为dp[amount]，amount时，次数， d
题中有个选择最小，则需要比较，dp[amount]=min(dp[amount],1+dp[amount-coin]),在各个coins中枚举选择最小
where coin is in coins
这是自底向上滚动求状态转移，如果是自顶向下递归求状态转移，则需要剪枝和记忆化。
*/
class Solution
{

public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 0; i <= amount; i++)
        {
            for (auto &coin : coins)
            {
                if ((i - coin) < 0)
                    continue; //子问题无解，看下一个coin
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
        return dp[amount] >= (amount + 1) ? -1 : dp[amount];
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

int stringToInteger(string input)
{
    return stoi(input);
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        vector<int> coins = stringToIntegerVector(line);
        getline(cin, line);
        int amount = stringToInteger(line);

        int ret = Solution().coinChange(coins, amount);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}