/*
 * @Author: uiemUI
 * @Date: 2021-02-19 17:04:30
 * @LastEditTime: 2021-02-19 17:22:23
 * @LastEditors: uiemUI
 * @Description:474. 一和零
给你一个二进制字符串数组 strs 和两个整数 m 和 n 。

请你找出并返回 strs 的最大子集的大小，该子集中 最多 有 m 个 0 和 n 个 1 。

如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。
 * @FilePath: \leetcode_personal\ti_474.cpp
 */

#include"stand.h"

/**
 * @brief 由于是最多 ，不是正好，所以初始状态设置为0。
 * 
 *
 * @brief  dp[i][j] 代表target 为 i,j时，子集的个数
 * 
 */

class Solution {

private:
    auto getZeroAndOneCounts(const string & str)
    {
        int zeroCount =0;
        int oneCount =0;
        for(const auto& ele : str)
        {
            if(ele =='0')
                zeroCount++;
            else 
                oneCount++;

        }
        return tuple{zeroCount,oneCount};
        
    }
    
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        int sz = strs.size();
        for (int i = 0; i < sz;++i)
        {
            auto [zeroCount,oneCount]=getZeroAndOneCounts(strs[i]);
            for(int j=m;j>=zeroCount;j--)
            {
                for(int k=n;k>=oneCount;k--)
                {
                    dp[j][k]=max(dp[j][k],1+dp[j-zeroCount][k-oneCount]);
                }
            }
        }
        return dp[m][n];
    }
};

int main(int argc, char const *argv[])
{
    /* code */

    vector<string>  vec = {"10", "0001", "111001", "1", "0"};
    int ret = Solution().findMaxForm(vec,5,3);
    std::cout<<ret<<std::endl;
    return 0;
}


