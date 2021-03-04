/*
 * @Author: uiemUI
 * @Date: 2021-02-19 15:55:18
 * @LastEditTime: 2021-02-19 16:23:37
 * @LastEditors: uiemUI
 * @Description: 0, 1 背包问题
 * @FilePath: \leetcode_personal\ti_416.cpp
 */

 /**
  * @brief 这题不是求最大值，而是求是否符合 定义状态 dp[i][j].代表前i个数去若干个值
  * 可以正好等于 j。值为0或者1. 0-target 应该是总计 target+1.
  *
  */

#include"stand.h"

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int len = nums.size();
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false; // 奇数
        int target = sum / 2;
        vector<bool>dp(target + 1, false);
        dp[0] = true; // 0 ,第一个不装即可
        // if (nums[0] <= target)
        //     dp[nums[0]] = true;

        for (int i = 0;i < len;i++)
        {
            if (dp[target])
            {
                return true;
            }
            for (int j = target;j >= nums[i];j--)
            {

                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }

        return dp[target];
    }

    /**
     * @brief
     * class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % 2) {
            return false;
        }
        bitset<10001> dp;
        dp[0] = 1;
        for (int num : nums) {
            dp |= (dp << num);
        }
        return dp[sum / 2];
    }
};
     *
     */
};

void trimLeftTrailingSpaces(string& input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
        }));
}

void trimRightTrailingSpaces(string& input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
        }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        bool ret = Solution().canPartition(nums);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}