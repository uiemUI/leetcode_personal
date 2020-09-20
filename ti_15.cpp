#include"stand.h"
#include"output_container.h"
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int first = 0; first < n;++first)
        {
            if(first>0&& nums[first]==nums[first-1]) //需要不重复的数
                continue;
            int third = n - 1;//c从最左端开始
            int target = -nums[first];
            for (int second = first + 1; second < n;++second)
            {
                if(second>first+1&&nums[second]==nums[second-1])
                    continue;
                while(second<third&&(nums[second]+nums[third])>target)
                {
                    third--;
                }
                if(second>=third)
                    break;//该项不符合
                if((nums[second]+nums[third])==target)
                {
                    ans.push_back({nums[first], nums[second], nums[third]});

                }
            }

        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums{-1, 0, 1, 2, -1, -4};
    auto ans = Solution().threeSum(nums);
    cout << ans << endl;
    return 0;
}
