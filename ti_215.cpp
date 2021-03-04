/*
 * @Author: uiemUI
 * @Date: 2021-03-03 20:35:10
 * @LastEditTime: 2021-03-03 21:18:50
 * @LastEditors: uiemUI
 * @Description:
 * 
 * 295. 数据流的中位数
215. 数组中的第K个最大元素
面试题40. 最小的k个数
347. 前 K 个高频元素
 * @FilePath: \leetcode_personal\ti_215.cpp
 */
 //堆排序，二叉堆排序，先利用下沉操作，构建堆
#include"stand.h"

class Solution {
    // 最大堆
    //
private:
    void sink(vector<int>& nums, int target, int len) // 下沉
    {
        for (int i = 2 * target + 1;i < len;i = 2 * i + 1)
        {
            if ((i + 1) < len && nums[i] < nums[i + 1]) // 选择较大值进行交换
                i = i + 1;
            if (nums[target] < nums[i])
            {
                swap(nums[target], nums[i]);
                target = i;// 注意这里
            }

            else
                return;
        }
    }
public:
    int findKthLargest(vector<int>& nums, int k) {

        // 建立堆
        int sz = nums.size();
        for (int i = sz / 2 - 1;i >= 0;i--)
            sink(nums, i, sz);
        // 找到第k个最大元素，最大堆
        for (int i = 0;i < k - 1;i++)
        {
            swap(nums[0], nums[sz - i - 1]);// 注意这里长度-1
            sink(nums, 0, sz - i - 1);
        }
        return nums[0];

    }
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);

        int ret = Solution().findKthLargest(nums, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}