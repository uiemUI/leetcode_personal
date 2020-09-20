#include "stand.h"
#include"output_container.h"
/*----------------------------------------------------------------
39. 组合总和
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 
示例 1：

输入：candidates = [2,3,6,7], target = 7,
所求解集为：
[
  [7],
  [2,2,3]
]
示例 2：

输入：candidates = [2,3,5], target = 8,
所求解集为：
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]

题目要求取若干次，则回溯选择时，idx可以重复若干次
*/

class Solution
{
private:
    void dfs(vector<int> &candidates, vector<int> &candidate, int target, int idx, vector<vector<int>> &res)
    {
        if (idx >= candidates.size())
            return;
        if (target == 0)
        {
            res.emplace_back(candidate);
            return;
        }
        dfs(candidates, candidate, target, idx + 1, res); //跳过该idx
        if (target - candidates[idx] >= 0)
        {
            candidate.emplace_back(candidates[idx]);
            //idx可选择无数次
            dfs(candidates, candidate, target - candidates[idx], idx, res);
            candidate.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> candidate;
        dfs(candidates, candidate, target, 0, res);
        return res;
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
    int target;
    while (getline(cin, line))
    {
        vector<int> nums = stringToIntegerVector(line);
        cin >> target;
        //bool ret = Solution().judgePoint24(nums);

        auto out = Solution().combinationSum(nums,target);
        
        cout << out << endl;
    }
    return 0;
}