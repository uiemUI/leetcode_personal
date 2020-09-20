// 在 "100 game" 这个游戏中，两名玩家轮流选择从 1 到 10 的任意整数，累计整数和，先使得累计整数和达到 100 的玩家，即为胜者。

//     如果我们将游戏规则改为 “玩家不能重复使用整数” 呢？

//         例如，两个玩家可以轮流从公共整数池中抽取从 1 到 15 的整数（不放回），直到累计整数和 >= 100。

//     给定一个整数 maxChoosableInteger （整数池中可选择的最大数）和另一个整数 desiredTotal（累计和），判断先出手的玩家是否能稳赢（假设两位玩家游戏时都表现最佳）？

//         你可以假设 maxChoosableInteger 不会大于 20， desiredTotal 不会大于 300。

//     示例：

//         来源：力扣（LeetCode）
//             链接：https : //leetcode-cn.com/problems/can-i-win
//                           著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#include"stand.h"

class Solution
{
private:
    unordered_map<unsigned long long, bool> bm_;
    int maxChInt_;
    int desTotal_;
    bool dfs(int totalSum,std::bitset<25>&bs)
    {
        if (totalSum>=desTotal_)
            return true;
        if(bm_.count(bs.to_ullong())>0)
            return bm_[bs.to_ullong()];
        bool ret = true;//表示当前先手
        //记忆化
        for (int i = 1; i <= maxChInt_;++i)
        {
            if(bs[i])
                continue;
            bs[i] = 1;
            if(dfs(totalSum+i,bs))
            {
                bs[i] = 0;
                ret = false;
                break;
                        }
            bs[i] = 0;

        }
        return bm_[bs.to_ullong()] = ret;
    }

public:
    bool canIWin(int maxChoosableInteger, int desiredTotal)
    {
        if((maxChoosableInteger+1)*maxChoosableInteger*0.5<desiredTotal)//连续整数之和小于条件和
            return false;
        maxChInt_ = maxChoosableInteger;
        desTotal_ = desiredTotal;
        bitset<25> bs(0);
        //bool ret;
        for (int i = 1; i <= maxChInt_;i++)
        {
            bs[i] = 1;
            if( dfs(i, bs))
                return true;
            bs[i] = 0;
        }
        return false;
    }
};

int stringToInteger(string input)
{
    return stoi(input);
}

string boolToString(bool input)
{
    return input ? "True" : "False";
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        int maxChoosableInteger = stringToInteger(line);
        getline(cin, line);
        int desiredTotal = stringToInteger(line);

        bool ret = Solution().canIWin(maxChoosableInteger, desiredTotal);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}