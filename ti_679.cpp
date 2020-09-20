/*
你有 4 张写有 1 到 9 数字的牌。你需要判断是否能通过 *，/，+，-，(，) 的运算得到 24。

示例 1:

输入: [4, 1, 8, 7]
输出: True
解释: (8-4) * (7-1) = 24
示例 2:

输入: [1, 2, 1, 2]
输出: False
注意:

除法运算符 / 表示实数除法，而不是整数除法。例如 4 / (1 - 2/3) = 12 。
每个运算符对两个数进行运算。特别是我们不能用 - 作为一元运算符。例如，[1, 1, 1, 1] 作为输入时，表达式 -1 - 1 - 1 - 1 是不允许的。
你不能将数字连接在一起。例如，输入为 [1, 2, 1, 2] 时，不能写成 12 + 12 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/24-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include "stand.h"

class Solution
{
    static constexpr int TARGET = 24;
    static constexpr double EPSILON = 1e-6;//浮点数为0
    static constexpr int ADD = 0, MULTIPLY = 1, SUBTRACT = 2, DIVIDE = 3;
    bool solve(vector<double> &list)
    {
        if(list.empty())
            return false;
        if(list.size()==1)
            return abs(list[0] - TARGET) < EPSILON;
        int sz = list.size();
        for (int i = 0; i < sz;++i)
        {
            for (int j = 0; j < sz;++j)
            {
                if(i!=j)//选择不同的两个数
                {
                    //新的list
                    vector<double> newlist;
                    for (int k = 0; k < sz;++k)
                    {
                        //另外的数加入newlist
                        if(k!=i &&k!=j)
                            newlist.emplace_back(list[k]);
                    }

                    for (int k = 0; k < 4;++k)//遍历4中符号，这个操作在后面，因为有回溯操作
                    {
                        if(k<2&&i>j)
                            continue; //加和乘法两种情况避免重复
                        if(k==ADD)
                        {
                            newlist.emplace_back(list[i] + list[j]);
                        }
                        else if (k==MULTIPLY)
                        {
                            newlist.emplace_back(list[i] * list[j]);
                        }
                        else if(k==SUBTRACT)
                        {
                            newlist.emplace_back(list[i] - list[j]);
                        }
                        else if(k==DIVIDE)
                        {
                            if(list[j]<EPSILON)
                                continue;//除数为0
                            newlist.emplace_back(list[i] / list[j]);
                        }
                        if (solve(newlist))
                            return true;
                        newlist.pop_back(); //回溯
                    }

                    
                }
            }
        }
        return false;
    }

public:

    bool judgePoint24(vector<int> &nums)
    {
        vector<double> dList;
        for(auto num:nums)
        {
            dList.emplace_back(static_cast<double>(num));
        }
        return solve(dList);
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

string boolToString(bool input)
{
    return input ? "True" : "False";
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        vector<int> nums = stringToIntegerVector(line);

        bool ret = Solution().judgePoint24(nums);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}