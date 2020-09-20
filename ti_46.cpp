#include"stand.h"
#include"output_container.h"
class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> track;
        track.reserve(nums.size());
        backTrack(nums, track, ans);
        return ans;
    }
    void backTrack(vector<int> nums, vector<int> &track, vector<vector<int>> &ans)
    {
        if(track.size()==nums.size())
        {
            ans.push_back(track);
            return;//结束条件
        }

        for (int i = 0; i < nums.size();++i)
        {
            if (std::find(track.begin(), track.end(), nums[i]) != track.end())
                continue;//track之前已存在i
            track.push_back(nums[i]);
            backTrack(nums, track, ans);//可以看成分成两支，一个该项加入，继续加入，
            track.pop_back();//回溯，不加入到下一项
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums{1, 2, 3,};
    auto ans(Solution().permute(nums));
    cout << ans << endl;
    return 0;
}
