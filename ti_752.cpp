// 752. 打开转盘锁
//     你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0',
//     '1', '2', '3', '4', '5', '6', '7', '8', '9' 。
//每个拨轮可以自由旋转：例如把 '9' 变为 '0'， '0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。

//                                                 锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。

//                                                 列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。

//                                                 字符串 target 代表可以解锁的数字，你需要给出最小的旋转次数，如果无论如何不能解锁，返回 -

//                                                 1。
/*
四位数总共8个选择，可以认为，每个选择可扩散8个选择，相当于图，广度优先图遍历
双向bdf
*/
#include "stand.h"
class Solution
{

private:
    string plusOne(const string &strp, int i)
    {
        string str(strp);
        if (str[i] =='9')
            str[i] = '0';
        else
            str[i] += 1;
        return str;
    }

    string minusOne(const string &strp, int i)
    {
        string str(strp);
        if (str[i] == '0')
            str[i] = '9';
        else
        {
            str[i] -= 1;
        }
        return str;
    }

public:
    int openLock(vector<string> &deadends, string target)
    {
        unordered_set<string> deads;
        unordered_set<string> visited;
        for (string str : deadends)
            deads.insert(str);
        for (auto str : deads)
            cout << str << endl;

        auto q1 = make_shared<unordered_set<string>>();
        auto q2 = make_shared<unordered_set<string>>();
        int step = 0;
        q1->insert("0000");
        q2->insert(target);
        //auto temp = make_shared<unordered_set<string>>();
        while ((!q1->empty()) && (!q2->empty()))
        {
            auto temp = make_shared<unordered_set<string>>();
            //temp->clear();
            for (auto cur : *q1)
            {
                //cout << cur << endl;
                /*判断是否在deads后者到达终点*/
                if (deads.count(cur))
                    continue;//此路不通
                if (q2->count(cur))
                    return step;
                visited.insert(cur);
                for (int i = 0; i < 4; ++i)
                {
                    string up = plusOne(cur, i);
                    if (visited.count(up) == 0)
                        temp->insert(up);
                    string down = minusOne(cur, i);
                    if (visited.count(down) == 0)
                        temp->insert(down);
                }
            }
            step++;
            q1 = q2;
            q2 = temp;
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> deads = {"0201",
                            "0101",
                            "0102",
                            "1212",
                            "2002"};
    //vector<string> deads{"8888"};
    string target("0202");
    auto ans = Solution().openLock(deads, target);
    cout << ans << endl;

    return 0;
}
