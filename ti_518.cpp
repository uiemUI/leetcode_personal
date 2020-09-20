#include "stand.h"
// 给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。假设每一种面额的硬币有无限个。 

//  

//     示例 1 :

//     输入 : amount = 5,
//            coins = [ 1, 2, 5 ] 输出 : 4 解释 : 有四种方式可以凑成总金额 : 5 = 5 5 = 2 + 2 + 1 5 = 2 + 1 + 1 + 1 5 = 1 + 1 + 1 + 1 + 1 示例 2 :

//     输入 : amount = 3,
//            coins = [2] 输出 : 0 解释 : 只用面额2的硬币不能凑成总金额3。 示例 3 :

//     输入 : amount = 10,
//            coins = [10] 输出 : 1

//            来源：力扣（LeetCode）
//                链接：https : //leetcode-cn.com/problems/coin-change-2
//                              著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
/*
正确的子问题定义应该是，problem(k,i) = problem(k-1, i) + problem(k, i-k)

即前k个硬币凑齐金额i的组合数等于前k-1个硬币凑齐金额i的组合数加上在原来i-k的基础上使用硬币的组合数。说的更加直白一点，那就是用前k的硬币凑齐金额i，要分为两种情况开率，一种是没有用前k-1个硬币就凑齐了，一种是前面已经凑到了i-k，现在就差第k个硬币了。

*/
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (auto & coin:coins) //这个顺序是组合数，如果顺序对调则是排列数
        {
            for (int i = coin; i <= amount; ++i)
            {
                
                dp[i] += (dp[i - coin]); //之前的dp[i]是用前coins[k-1]前个硬币的组合
            }
        }
        return dp[amount];
    }
};

int stringToInteger(string input)
{
    return stoi(input);
}

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
        int amount = stringToInteger(line);
        getline(cin, line);
        vector<int> coins = stringToIntegerVector(line);

        int ret = Solution().change(amount, coins);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}