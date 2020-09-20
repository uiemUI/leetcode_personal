#include"stand.h"
#include"output_container.h"

/**
 * 与第 39 题（组合之和）的差别
这道题与上一问的区别在于：

第 39 题：candidates 中的数字可以无限制重复被选取；
第 40 题：candidates 中的每个数字在每个组合中只能使用一次。
相同点是：相同数字列表的不同排列视为一个结果

作者：liweiwei1419
链接：https://leetcode-cn.com/problems/combination-sum-ii/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-m-3/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 * 
 * 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
示例 2:

输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[
  [1,2,2],
  [5]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/
class Solution
{
    vector<vector<int>> res_;
    vector<int> candidates_;
    vector<int> sums_;

    void dfs(vector<int> candidate, int target, int idx)
    {
        if (idx >= candidates_.size())
            return;
        if (target > sums_[idx])
            return;
        if (target == 0)
        {
            res_.emplace_back(candidate);
            return;
        }
        // dfs(candidate,target,idx+1);//不选择该项
        // if(target-candidates_[idx]>=0)
        // {
        //     candidate.emplace_back(candidates_[idx]);
        //     dfs(candidate,target-candidates_[idx],idx+1);
        //     candidate.pop_back();
        // }
        for (int i = idx; i < candidates_.size() && target - candidates_[i] >= 0; i++)
        { //组合数，
            if (i > idx && candidates_[i] == candidates_[i - 1])
                continue; //重复组合去除,避免同一层选择了同一个数，不同层仍然可以选择同一个数
            candidate.emplace_back(candidates_[i]);
            dfs(candidate, target - candidates_[i], i + 1);
            candidate.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        candidates_ = candidates;
        if (candidates.empty())
            return res_;
        sort(candidates_.begin(), candidates_.end());
        sums_ = vector<int>(candidates.size() + 1, 0);
        for (int i = candidates_.size() - 1; i >= 0; i--)
        {
            sums_[i] = sums_[i + 1] + candidates_[i];
        }
        vector<int> candidate;
        dfs(candidate, target, 0);
        return res_;
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

        auto out = Solution().combinationSum2(nums, target);

        cout << out << endl;
    }
    return 0;
}