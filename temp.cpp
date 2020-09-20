#include"stand.h"

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size(), n=grid[0].size();
        if (m==0||n==0)
            return 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (size_t i = 1; i < m+1; i++)
        {
            for(size_t k=1;k<n+1;k++)
                { 
                dp[i][k]=max(dp[i-1][k], dp[i][k-1])+grid[i-1][k-1];
                }
        }
        return dp[m][n];
        
    }
};

class Solution2 {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size(), n=grid[0].size();
        if (m==0||n==0)
            return 0;
        vector<int> dp(n+1, 0);
        
        for(int i=0;i<m;++i)
        { 
            for(int j=1;j<n+1;++j)
            { 
                dp[j]=max(dp[j-1], dp[j])+grid[i][j-1];
            }
        }
        return dp[n];
    }
};



class Solution3 {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.size()<1) return 0;
        auto maxi=std::max_element(nums.begin(), nums.end());
        auto n=*maxi;
        if (n<1) return 0;
        vector<int> counts(n+1, 0);
        int first=0, second=0;
        for (size_t i=0;i<nums.size();++i)
        {
            counts[nums[i]]++;//计数
        }
        for(int  i=1;i<n+1;++i)
        {
            auto temp=second;
            second=max(second,first+i*counts[i]);
            first =temp;
        }
        return second;

    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> grid{ { 1, 3, 1 }, { 1, 5, 1 }, { 4, 2, 1 } };
    auto result=Solution().maxValue(grid);
    cout<<result<<endl;
    auto result2=Solution2().maxValue(grid);
    
    cout<<result2<<endl;
    vector<int> nums{ 3, 4, 2 };
    auto ans = Solution3().deleteAndEarn(nums);
    cout<<ans<<endl;

    return 0;
}

