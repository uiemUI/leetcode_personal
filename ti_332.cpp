#include "stand.h"

/*

332. 重新安排行程
给定一个机票的字符串二维数组 [from, to]，子数组中的两个成员分别表示飞机出发和降落的机场地点，对该行程进行重新规划排序。
所有这些机票都属于一个从 JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。

说明:

如果存在多种有效的行程，你可以按字符自然排序返回最小的行程组合。例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"] 相比就更小，排序更靠前
所有的机场都用三个大写字母表示（机场代码）。
假定所有机票至少存在一种合理的行程。
示例 1:

输入: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
输出: ["JFK", "MUC", "LHR", "SFO", "SJC"]
示例 2:

输入: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
输出: ["JFK","ATL","JFK","SFO","ATL","SFO"]
解释: 另一种有效的行程是 ["JFK","SFO","ATL","JFK","ATL","SFO"]。但是它自然排序更大更靠后。
*/
class Solution
{
private:
    unordered_map<string, map<string, int>> adj;

    bool dfs(vector<string> &path, const string &node, int used, int maxSz) //这道题只需要找到一个符合题意的路径，所以返回bool可以提前结束，而不是void遍历所有。
    {
        if (used >= maxSz)
            return true;
        if (!adj.count(node))
            return false;
        for (auto &[nextNode, number] : adj[node]) //迭代是一个pair
        {
            if (number <= 0)
                continue; //如果该路线已被删除
            path.push_back(nextNode);
            used++;
            number--; //引用
            if (dfs(path, nextNode, used, maxSz))
                return true;
            number++; //此路不通回溯
            used--;
            path.pop_back();
        }
        return false;
    }

public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        if (tickets.empty())
            return {};
        int maxSz = tickets.size();
        vector<string> path{"JFK"};
        for (auto &ticket : tickets)
        {
            adj[ticket[0]][ticket[1]]++;
        }
        dfs(path, "JFK", 0, maxSz);
        return path;
    }
};

void Test(const string &testName, vector<vector<string>> &tricks, const vector<string> &expectedResult)
{
    auto path = Solution().findItinerary(tricks);
    bool flag = (path.size() == expectedResult.size());
    if (!flag)
    {
        cout << "****" << testName << "****\n"
             << "****failed****" << endl;
        return;
    }
    for (int i = 0; i < path.size(); i++)
    {
        if (path[i] != expectedResult[i])
        {
            cout << "****" << testName << "****\n"
                 << "****failed****" << endl;
            return;
        }
    }
    cout << "****" << testName << "****\n"
         << "****successed*****" << endl;
}

void Test01()
{
    vector<vector<string>> tricks{{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    // unordered_map<string, map<string, int>> adj;//邻接表，因为这里map可自动排序
    // for(auto &trick:tricks)
    // {
    //     adj[trick[0]][trick[1]]++;//建立邻接表
    // }
    vector<string> expectedRe{"JFK", "MUC", "LHR", "SFO", "SJC"};
    Test("test01", tricks, expectedRe);
}

int main(int argc, char const *argv[])
{
    Test01();

    return 0;
}
